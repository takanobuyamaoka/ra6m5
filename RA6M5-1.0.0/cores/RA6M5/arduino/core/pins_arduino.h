/*
  pins_arduino.h - Pin definition functions for Arduino
  Part of Arduino - http://www.arduino.cc/

  Copyright (c) 2007 David A. Mellis

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General
  Public License along with this library; if not, write to the
  Free Software Foundation, Inc., 59 Temple Place, Suite 330,
  Boston, MA  02111-1307  USA
*/

#ifndef Pins_Arduino_h
#define Pins_Arduino_h

#include "avr/pgmspace.h"
#ifdef _RA6M5_
#include "bsp_api.h"
#endif

#define NUM_DIGITAL_PINS            20
#ifndef _RA6M5_
#define NUM_ANALOG_INPUTS           6
#define analogInputToDigitalPin(p)  ((p < 6) ? (p) + 14 : -1)
#else
#define NUM_ANALOG_INPUTS           4
#define analogInputToDigitalPin(p)  ((p < 4) ? (p) + 14 : -1)
#endif
#if defined(__AVR_ATmega8__)
#define digitalPinHasPWM(p)         ((p) == 9 || (p) == 10 || (p) == 11)
#else
#define digitalPinHasPWM(p)         ((p) == 3 || (p) == 5 || (p) == 6 || (p) == 9 || (p) == 10 || (p) == 11)
#endif

#define PIN_SPI_SS    (10)
#define PIN_SPI_MOSI  (11)
#define PIN_SPI_MISO  (12)
#define PIN_SPI_SCK   (13)

static const uint8_t SS   = PIN_SPI_SS;
static const uint8_t MOSI = PIN_SPI_MOSI;
static const uint8_t MISO = PIN_SPI_MISO;
static const uint8_t SCK  = PIN_SPI_SCK;

#define PIN_WIRE_SDA        (18)
#define PIN_WIRE_SCL        (19)

static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;

#ifndef _RA6M5_
#define LED_BUILTIN 13
#else
#define PIN_LED_G   (20)
#define PIN_LED_Y   (21)
#define PIN_LED_O   (22)
#define PIN_LED_R   (23)
#define PIN_USER	(24)
#endif

#define PIN_A0		(14)
#define PIN_A1		(15)
#define PIN_A2		(16)
#define PIN_A3		(17)
#define PIN_A4		(18)
#define PIN_A5		(19)

static const uint8_t A0 = PIN_A0;
static const uint8_t A1 = PIN_A1;
static const uint8_t A2 = PIN_A2;
static const uint8_t A3 = PIN_A3;
static const uint8_t A4 = PIN_A4;
static const uint8_t A5 = PIN_A5;

#define digitalPinToPCICR(p)    (((p) >= 0 && (p) <= 21) ? (&PCICR) : ((uint8_t *)0))
#define digitalPinToPCICRbit(p) (((p) <= 7) ? 2 : (((p) <= 13) ? 0 : 1))
#define digitalPinToPCMSK(p)    (((p) <= 7) ? (&PCMSK2) : (((p) <= 13) ? (&PCMSK0) : (((p) <= 21) ? (&PCMSK1) : ((uint8_t *)0))))
#define digitalPinToPCMSKbit(p) (((p) <= 7) ? (p) : (((p) <= 13) ? ((p) - 8) : ((p) - 14)))

#define digitalPinToInterrupt(p)  ((p) == 2 ? 0 : ((p) == 3 ? 1 : NOT_AN_INTERRUPT))

#ifdef ARDUINO_MAIN

const bsp_io_port_pin_t mPinToPin[] =
{
  BSP_IO_PORT_04_PIN_02, // 0
  BSP_IO_PORT_04_PIN_01, // 1
  BSP_IO_PORT_03_PIN_02, // 2
  BSP_IO_PORT_01_PIN_11, // 3
  BSP_IO_PORT_03_PIN_05, // 4
  BSP_IO_PORT_04_PIN_06, // 5
  BSP_IO_PORT_01_PIN_07, // 6
  BSP_IO_PORT_03_PIN_07, // 7
  BSP_IO_PORT_02_PIN_07, // 8
  BSP_IO_PORT_01_PIN_14, // 9
  BSP_IO_PORT_03_PIN_01, // 10
  BSP_IO_PORT_06_PIN_02, // 11
  BSP_IO_PORT_06_PIN_01, // 12
  BSP_IO_PORT_06_PIN_00, // 13
  BSP_IO_PORT_00_PIN_00, // 14
  BSP_IO_PORT_00_PIN_01, // 15
  BSP_IO_PORT_00_PIN_02, // 16
  BSP_IO_PORT_00_PIN_03, // 17
  BSP_IO_PORT_00_PIN_14, // 18: no analog, just for SDA1
  BSP_IO_PORT_00_PIN_15, // 19: no analog, just for SCL1
  BSP_IO_PORT_02_PIN_10, // 20: LED_G
  BSP_IO_PORT_02_PIN_09, // 21: LED_Y
  BSP_IO_PORT_02_PIN_08, // 22: LED_O
  BSP_IO_PORT_03_PIN_03, // 23: LED_R
  BSP_IO_PORT_00_PIN_06, // 24: USER
};

const bsp_io_port_pin_t mPinToPort[] =
{
  BSP_IO_PORT_04, // 0
  BSP_IO_PORT_04, // 1
  BSP_IO_PORT_03, // 2
  BSP_IO_PORT_01, // 3
  BSP_IO_PORT_03, // 4
  BSP_IO_PORT_04, // 5
  BSP_IO_PORT_01, // 6
  BSP_IO_PORT_03, // 7
  BSP_IO_PORT_02, // 8
  BSP_IO_PORT_01, // 9
  BSP_IO_PORT_03, // 10
  BSP_IO_PORT_06, // 11
  BSP_IO_PORT_06, // 12
  BSP_IO_PORT_06, // 13
  BSP_IO_PORT_00, // 14
  BSP_IO_PORT_00, // 15
  BSP_IO_PORT_00, // 16
  BSP_IO_PORT_00, // 17
  BSP_IO_PORT_00, // 18: no analog, just for SDA1
  BSP_IO_PORT_00, // 19: no analog, just for SCL1
  BSP_IO_PORT_02, // 20: LED_G
  BSP_IO_PORT_02, // 21: LED_Y
  BSP_IO_PORT_02, // 22: LED_O
  BSP_IO_PORT_03, // 23: LED_R
  BSP_IO_PORT_00, // 24: USER
};

#endif

// These serial port names are intended to allow libraries and architecture-neutral
// sketches to automatically default to the correct port name for a particular type
// of use.  For example, a GPS module would normally connect to SERIAL_PORT_HARDWARE_OPEN,
// the first hardware serial port whose RX/TX pins are not dedicated to another use.
//
// SERIAL_PORT_MONITOR        Port which normally prints to the Arduino Serial Monitor
//
// SERIAL_PORT_USBVIRTUAL     Port which is USB virtual serial
//
// SERIAL_PORT_LINUXBRIDGE    Port which connects to a Linux system via Bridge library
//
// SERIAL_PORT_HARDWARE       Hardware serial port, physical RX & TX pins.
//
// SERIAL_PORT_HARDWARE_OPEN  Hardware serial ports which are open for use.  Their RX & TX
//                            pins are NOT connected to anything by default.
#define SERIAL_PORT_MONITOR   Serial
#define SERIAL_PORT_HARDWARE  Serial

#endif
