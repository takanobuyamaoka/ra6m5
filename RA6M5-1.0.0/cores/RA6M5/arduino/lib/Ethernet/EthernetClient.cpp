/* Copyright 2018 Paul Stoffregen
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this
 * software and associated documentation files (the "Software"), to deal in the Software
 * without restriction, including without limitation the rights to use, copy, modify,
 * merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to the following
 * conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
 * INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#include <Arduino.h>
#include "Ethernet.h"
#include "Dns.h"

int EthernetClient::connect(const char * host, uint16_t port)
{
	DNSClient dns; // Look up the host first
	IPAddress remote_addr;

	dns.begin(Ethernet.dnsServerIP());
	if (!dns.getHostByName(host, remote_addr)) return 0; // TODO: use _timeout
	return connect(remote_addr, port);
}

int EthernetClient::connect(IPAddress ip, uint16_t port)
{
#if defined(ESP8266) || defined(ESP32)
	if (ip == IPAddress((uint32_t)0) || ip == IPAddress(0xFFFFFFFFul)) return 0;
#else
	if (ip == IPAddress(0ul) || ip == IPAddress(0xFFFFFFFFul)) return 0;
#endif
	sockindex = Ethernet.socketBegin(FREERTOS_IPPROTO_TCP, 0);
	if (sockindex == 0){
		return 0;
	}
	Ethernet.socketConnect(sockindex, rawIPAddress(ip), port);
	uint8_t stat = Ethernet.socketStatus(sockindex);
	if (stat == eESTABLISHED) return 1;
	if (stat == eCLOSE_WAIT) return 1;
	if (stat == eCLOSED) return 0;
	Ethernet.socketClose(sockindex);
	sockindex = 0;
	return 0;
}

//int EthernetClient::availableForWrite(void)
//{
//	return Ethernet.socketSendAvailable(sockindex);
//}

size_t EthernetClient::write(uint8_t b)
{
	return write(&b, 1);
}

size_t EthernetClient::write(const uint8_t *buf, size_t size)
{
	if (sockindex == 0) return 0;
	if (Ethernet.socketSend(sockindex, buf, size)) return size;
	setWriteError();
	return 0;
}

int EthernetClient::available()
{
	if (sockindex == 0) return 0;
	return Ethernet.socketRecvAvailable(sockindex);
}

int EthernetClient::read(uint8_t *buf, size_t size)
{
	if (sockindex == 0) return 0;
	return Ethernet.socketRecv(sockindex, buf, size);
}

int EthernetClient::peek()
{
	if (sockindex == 0) return -1;
	if (!available()) return -1;
	return Ethernet.socketPeek(sockindex);
}

int EthernetClient::read()
{
	uint8_t b;
	if (Ethernet.socketRecv(sockindex, &b, 1) > 0) return b;
	return -1;
}

void EthernetClient::flush()
{
}

void EthernetClient::stop()
{
	if (sockindex == 0) return;

	// attempt to close the connection gracefully (send a FIN to other side)
	Ethernet.socketDisconnect(sockindex);
	unsigned long start = millis();
	// if it hasn't closed, close it forcefully
	Ethernet.socketClose(sockindex);
	sockindex = 0;
}

uint8_t EthernetClient::connected()
{
	if (sockindex == 0) return 0;
	uint8_t s = Ethernet.socketStatus(sockindex);
	return !(s == eTCP_LISTEN || s == eCLOSED || s == eFIN_WAIT_1 || s == eFIN_WAIT_2 || s == eCLOSE_WAIT  || s == eCLOSING || (s == eCLOSED && !available()));
}

uint8_t EthernetClient::status()
{
	if (sockindex == 0) return eCLOSED;
	return Ethernet.socketStatus(sockindex);
}

// the next function allows us to use the client returned by
// EthernetServer::available() as the condition in an if-statement.
bool EthernetClient::operator==(const EthernetClient& rhs)
{
	if (sockindex != rhs.sockindex) return false;
	if (sockindex == 0) return false;
	if (rhs.sockindex == 0) return false;
	return true;
}

// https://github.com/per1234/EthernetMod
// from: https://github.com/ntruchsess/Arduino-1/commit/937bce1a0bb2567f6d03b15df79525569377dabd
uint16_t EthernetClient::localPort()
{
	if (sockindex == 0) return 0;
	struct freertos_sockaddr local_address;
	FreeRTOS_GetLocalAddress((ConstSocket_t)sockindex, &local_address);
	return local_address.sin_port;
}

// https://github.com/per1234/EthernetMod
// returns the remote IP address: https://forum.arduino.cc/index.php?topic=82416.0
IPAddress EthernetClient::remoteIP()
{
	if (sockindex == 0) return IPAddress((uint32_t)0);
	struct freertos_sockaddr remote_address;
	FreeRTOS_GetRemoteAddress((ConstSocket_t)sockindex, &remote_address);
	IPAddress ip(remote_address.sin_addr);
	return ip;
}

// https://github.com/per1234/EthernetMod
// from: https://github.com/ntruchsess/Arduino-1/commit/ca37de4ba4ecbdb941f14ac1fe7dd40f3008af75
uint16_t EthernetClient::remotePort()
{
	if (sockindex == 0) return 0;
	struct freertos_sockaddr remote_address;
	FreeRTOS_GetRemoteAddress((ConstSocket_t)sockindex, &remote_address);
	return remote_address.sin_port;
}
