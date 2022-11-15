#include "Ethernet.h"
extern "C" {
#include <stdio.h>
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOS_IP.h"
#include "FreeRTOS_Sockets.h"
#include "IPAddress.h"
}


static const uint8_t ucLocalIpAddress[ 4 ] =
{
    192, 168, 0, 100
};

static const uint8_t ucNetMask[ 4 ] =
{
    255, 255, 255, 0
};
static const uint8_t ucGatewayAddress[ 4 ] =
{
    192, 168, 0, 1
};

/* The following is the address of an OpenDNS server. */
static const uint8_t ucDNSServerAddress[ 4 ] =
{
    8, 8, 8, 8
};

int EthernetClass::begin(uint8_t *mac_address, unsigned long timeout, unsigned long responseTimeout)
{
	_dnsServerAddress = IPAddress(ucDNSServerAddress);
	FreeRTOS_IPInit(ucLocalIpAddress, ucNetMask,
			ucGatewayAddress, ucDNSServerAddress, mac_address);
	return true;
}

void EthernetClass::begin(uint8_t *mac_address, IPAddress local_ip)
{
	// Assume the DNS server will be the machine on the same network as the local IP
	// but with last octet being '1'
	begin(mac_address, local_ip, ucDNSServerAddress);
}

void EthernetClass::begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server)
{
	// Assume the gateway will be the machine on the same network as the local IP
	// but with last octet being '1'
	begin(mac_address, local_ip, dns_server, ucGatewayAddress);
}

void EthernetClass::begin(uint8_t *mac_address, IPAddress local_ip, IPAddress dns_server, IPAddress gateway)
{
	begin(mac_address, local_ip, dns_server, gateway, ucNetMask);
}

void EthernetClass::begin(uint8_t *mac, IPAddress local_ip, IPAddress dns_server, IPAddress gateway, IPAddress subnet)
{
	_dnsServerAddress = dns_server;

	FreeRTOS_IPInit(
			local_ip.raw_address(),
			subnet.raw_address(),
			gateway.raw_address(),
			dns_server.raw_address(),
			mac);

	/* We should wait for the network to be up before we run any demos. */
//	while (FreeRTOS_IsNetworkUp() == pdFALSE) {
//		vTaskDelay(3000);
//	}
}


EthernetLinkStatus EthernetClass::linkStatus()
{
	if (FreeRTOS_IsNetworkUp() == pdFALSE){
		return LinkOFF;
	}
	return LinkON;
}

IPAddress EthernetClass::localIP()
{
	uint32_t ulIPAddress, ulNetMask, ulGatewayAddress, ulDNSServerAddress;
	FreeRTOS_GetAddressConfiguration(
	  &ulIPAddress,
	  &ulNetMask,
	  &ulGatewayAddress,
	  &ulDNSServerAddress );
	return (IPAddress)ulIPAddress;
}

IPAddress EthernetClass::subnetMask()
{
	uint32_t ulIPAddress, ulNetMask, ulGatewayAddress, ulDNSServerAddress;
	FreeRTOS_GetAddressConfiguration(
	  &ulIPAddress,
	  &ulNetMask,
	  &ulGatewayAddress,
	  &ulDNSServerAddress );
	return (IPAddress)ulNetMask;
}

IPAddress EthernetClass::gatewayIP()
{
	uint32_t ulIPAddress, ulNetMask, ulGatewayAddress, ulDNSServerAddress;
	FreeRTOS_GetAddressConfiguration(
	  &ulIPAddress,
	  &ulNetMask,
	  &ulGatewayAddress,
	  &ulDNSServerAddress );
	return (IPAddress)ulGatewayAddress;
}

IPAddress EthernetClass::dnsServerIP()
{
	return _dnsServerAddress;
}

EthernetClass Ethernet;
