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
#include "FreeRTOS_Stream_Buffer.h"

#if ARDUINO >= 156 && !defined(ARDUINO_ARCH_PIC32)
extern void yield(void);
#else
#define yield()
#endif

// TODO: randomize this when not using DHCP, but how?
static uint16_t local_port = 49152;  // 49152 to 65535
SocketSet_t _xSocketSet;

/*****************************************/
/*          Socket management            */
/*****************************************/


void EthernetClass::socketPortRand(uint16_t n)
{
	n &= 0x3FFF;
	local_port ^= n;
	//Serial.printf("socketPortRand %d, srcport=%d\n", n, local_port);
}

uint32_t EthernetClass::socketBegin(uint8_t protocol, uint16_t port)
{
	Socket_t xSocket;
	BaseType_t xType = FREERTOS_SOCK_STREAM;
    static const TickType_t xTimeOut = portMAX_DELAY;
	struct freertos_sockaddr xBindAddress;
    WinProperties_t xWinProps;
	if (protocol == FREERTOS_IPPROTO_UDP){
		xType = FREERTOS_SOCK_DGRAM;
	}
	_xSocketSet = FreeRTOS_CreateSocketSet();
	if( _xSocketSet == NULL ){
		return 0;
	}
	xSocket = FreeRTOS_socket( FREERTOS_AF_INET,xType, protocol );
    if( xSocket != FREERTOS_INVALID_SOCKET )
    {
        FreeRTOS_setsockopt( xSocket,
                             0,
                             FREERTOS_SO_RCVTIMEO,
                             &xTimeOut,
                             sizeof( xTimeOut ) );
        FreeRTOS_setsockopt( xSocket,
                             0,
                             FREERTOS_SO_SNDTIMEO,
                             &xTimeOut,
                             sizeof( xTimeOut ) );
        xWinProps.lTxBufSize = 4 * ipconfigTCP_MSS;
        xWinProps.lTxWinSize = 4;
        xWinProps.lRxBufSize = 2 * ipconfigTCP_MSS;
        xWinProps.lRxWinSize = 2;

        /* Set the window and buffer sizes. */
        FreeRTOS_setsockopt (xSocket, 0, FREERTOS_SO_WIN_PROPERTIES, (void*) &xWinProps, sizeof(xWinProps));
        xBindAddress.sin_port = FreeRTOS_htons( port );
        if( FreeRTOS_bind( xSocket, &xBindAddress, sizeof( &xBindAddress ) ) == 0 )
        {
        	return (uint32_t)xSocket;
        }
    }
	return 0;
}

// multicast version to set fields before open  thd
//uint8_t EthernetClass::socketBeginMulticast(uint8_t protocol, IPAddress ip, uint16_t port)
//{
//	return 0;
//}
// Return the socket's status
//
uint8_t EthernetClass::socketStatus(uint32_t s)
{
	return (uint8_t)FreeRTOS_connstatus((struct xSOCKET const *)s);
}

// Immediately close.  If a TCP connection is established, the
// remote host is left unaware we closed.
//
void EthernetClass::socketClose(uint32_t s)
{
	FreeRTOS_FD_CLR( (Socket_t)s, _xSocketSet, eSELECT_ALL );
	FreeRTOS_closesocket((Socket_t)s);
}


// Place the socket in listening (server) mode
//
uint8_t EthernetClass::socketListen(uint32_t s)
{
	const BaseType_t xBacklog = 20;
	BaseType_t result = FreeRTOS_listen( (Socket_t)s, xBacklog );
	if (result == 0){
		FreeRTOS_FD_SET( (Socket_t)s, _xSocketSet, eSELECT_READ|eSELECT_EXCEPT );
		return 1;
	}
	return 0;
}

// Place the socket in listening (server) mode
//
uint32_t EthernetClass::socketAccept(uint32_t s, uint32_t timeout)
{
	struct freertos_sockaddr client;
	socklen_t xSize = sizeof( client );
	Socket_t client_socket;

	if (!FreeRTOS_select( _xSocketSet, timeout )){
		return 0;
	}
	client_socket = FreeRTOS_accept( (Socket_t)s, &client, &xSize );
	FreeRTOS_FD_SET( client_socket, _xSocketSet, eSELECT_READ|eSELECT_EXCEPT );
	return (uint32_t)client_socket;
}


// establish a TCP connection in Active (client) mode.
//
void EthernetClass::socketConnect(uint32_t s, uint8_t * addr, uint16_t port)
{
	struct freertos_sockaddr xRemoteAddress;
    xRemoteAddress.sin_port = FreeRTOS_htons( port );
    xRemoteAddress.sin_addr = FreeRTOS_inet_addr_quick( addr[0], addr[1], addr[2], addr[3] );
	FreeRTOS_connect( (Socket_t)s, &xRemoteAddress, sizeof( xRemoteAddress ) );
}


// Gracefully disconnect a TCP connection.
//
void EthernetClass::socketDisconnect(uint32_t s)
{
	FreeRTOS_shutdown((Socket_t)s, 0);
}



/*****************************************/
/*    Socket Data Receive Functions      */
/*****************************************/


// Receive data.  Returns size, or -1 for no data, or 0 if connection closed
//
int EthernetClass::socketRecv(uint32_t s, uint8_t *buf, int16_t len)
{
	BaseType_t size= FreeRTOS_recv((Socket_t)s, buf, (unsigned int)len, 0);
	if (size < 0){
		return -1;
	}
	return size;
}

uint16_t EthernetClass::socketRecvAvailable(uint32_t s)
{
	if (s == 0){
		return 0;
	}
	if (socketStatus(s)!=eESTABLISHED){
		return 0;
	}
	return (uint16_t)FreeRTOS_recvcount((Socket_t)s);
}

// get the first byte in the receive queue (no checking)
//
uint8_t EthernetClass::socketPeek(uint32_t s)
{
	const struct xSTREAM_BUFFER *sbuffer =FreeRTOS_get_rx_buf((Socket_t)s);
	return sbuffer->ucArray[sbuffer->uxTail];
}


/**
 * @brief	This function used to send the data in TCP mode
 * @return	1 for success else 0.
 */
uint16_t EthernetClass::socketSend(uint32_t s, const uint8_t * buf, uint16_t len)
{
	BaseType_t xBytesSent;
    xBytesSent = FreeRTOS_send( (Socket_t)s, buf, len,  0 );
	return (uint16_t)xBytesSent;
}

uint16_t EthernetClass::socketSendAvailable(uint32_t s)
{
	return (uint16_t)FreeRTOS_tx_space((Socket_t)s);
}

//uint16_t EthernetClass::socketBufferData(uint32_t s, uint16_t offset, const uint8_t* buf, uint16_t len)
//{
//	return len;
//}

//uint16_t EthernetClass::socketBufferData(uint32_t s, uint16_t offset, const uint8_t* buf, uint16_t len)
//{
//	return len;
//}

//bool EthernetClass::socketStartUDP(uint32_t s, uint8_t* addr, uint16_t port)
//{
//	return true;
//}
//
//bool EthernetClass::socketSendUDP(uint32_t s)
//{
//	return true;
//}
