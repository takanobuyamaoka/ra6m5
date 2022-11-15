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

void EthernetServer::begin()
{
	uint32_t sockindex = Ethernet.socketBegin(FREERTOS_IPPROTO_TCP, _port);
	if (_listen_socket){
		Ethernet.socketClose(_listen_socket);
		_listen_socket = 0;
	}
	if (sockindex != 0) {
		if (Ethernet.socketListen(sockindex)) {
			_listen_socket = sockindex;
		} else {
			Ethernet.socketDisconnect(sockindex);
		}
	}
}

EthernetClient EthernetServer::available()
{
	if ( Ethernet.socketRecvAvailable(_client_socket) == eESTABLISHED){
		if (Ethernet.socketRecvAvailable(_client_socket)){
			return EthernetClient(_client_socket);
		}
		else{
			return EthernetClient(0);
		}
	}
	else{
		return accept();
	}
}

EthernetClient EthernetServer::accept()
{
	_client_socket = Ethernet.socketAccept(_listen_socket, 200);
	return EthernetClient(_client_socket);
}

EthernetServer::operator bool()
{
	if (Ethernet.socketStatus(_listen_socket) == eTCP_LISTEN) {
		return true; // server is listening for incoming clients
	}
	return false;
}

size_t EthernetServer::write(uint8_t b)
{
	return write(&b, 1);
}

size_t EthernetServer::write(const uint8_t *buffer, size_t size)
{
	if (Ethernet.socketStatus(_client_socket) == eESTABLISHED) {
		Ethernet.socketSend(_client_socket, buffer, (uint16_t)size);
	}
	return size;
}
