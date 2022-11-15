// Arduino DNS client for WIZnet W5100-based Ethernet shield
// (c) Copyright 2009-2010 MCQN Ltd.
// Released under Apache License, version 2.0

#include <Arduino.h>
#include "Ethernet.h"
#include "Dns.h"


#define SOCKET_NONE              255

// Possible return codes from ProcessResponse
#define SUCCESS          1
#define TIMED_OUT        -1
#define INVALID_SERVER   -2
#define TRUNCATED        -3
#define INVALID_RESPONSE -4

void DNSClient::begin(const IPAddress& aDNSServer)
{
	iDNSServer = aDNSServer;
}


int DNSClient::inet_aton(const char* address, IPAddress& result)
{
	uint16_t acc = 0; // Accumulator
	uint8_t dots = 0;

	while (*address) {
		char c = *address++;
		if (c >= '0' && c <= '9') {
			acc = acc * 10 + (c - '0');
			if (acc > 255) {
				// Value out of [0..255] range
				return 0;
			}
		} else if (c == '.') {
			if (dots == 3) {
				// Too much dots (there must be 3 dots)
				return 0;
			}
			result[dots++] = acc;
			acc = 0;
		} else {
			// Invalid char
			return 0;
		}
	}

	if (dots != 3) {
		// Too few dots (there must be 3 dots)
		return 0;
	}
	result[3] = acc;
	return 1;
}

int DNSClient::getHostByName(const char* aHostname, IPAddress& aResult, uint16_t timeout)
{
	// See if it's a numeric IP address
	if (inet_aton(aHostname, aResult)) {
		// It is, our work here is done
		return 1;
	}
	// Check we've got a valid DNS server to use
	if (iDNSServer == INADDR_NONE) {
		return INVALID_SERVER;
	}
	uint32_t host_addr=FreeRTOS_gethostbyname(aHostname);
	IPAddress hostip(host_addr);
	aResult = hostip;
	return 1;
}
