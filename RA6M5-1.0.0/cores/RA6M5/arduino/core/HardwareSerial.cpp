/*
  HardwareSerial.cpp - Hardware serial library for Wiring
  Copyright (c) 2006 Nicholas Zambetti.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
  
  Modified 23 November 2006 by David A. Mellis
  Modified 28 September 2010 by Mark Sproul
  Modified 14 August 2012 by Alarus
  Modified 3 December 2013 by Matthijs Kooijman
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <inttypes.h>
#ifndef _RA6M5_
#include <util/atomic.h>
#endif
#include "Arduino.h"

#include "HardwareSerial.h"
#include "HardwareSerial_private.h"

// this next line disables the entire HardwareSerial.cpp, 
// this is so I can support Attiny series and any other chip without a uart
#if defined(HAVE_HWSERIAL0) || defined(HAVE_HWSERIAL1) || defined(HAVE_HWSERIAL2) || defined(HAVE_HWSERIAL3)

// SerialEvent functions are weak, so when the user doesn't define them,
// the linker just sets their address to 0 (which is checked below).
// The Serialx_available is just a wrapper around Serialx.available(),
// but we can refer to it weakly so we don't pull in the entire
// HardwareSerial instance if the user doesn't also refer to it.
#if defined(HAVE_HWSERIAL0)
  void serialEvent() __attribute__((weak));
  bool Serial0_available() __attribute__((weak));
#endif

#if defined(HAVE_HWSERIAL1)
  void serialEvent1() __attribute__((weak));
  bool Serial1_available() __attribute__((weak));
#endif

#if defined(HAVE_HWSERIAL2)
  void serialEvent2() __attribute__((weak));
  bool Serial2_available() __attribute__((weak));
#endif

#if defined(HAVE_HWSERIAL3)
  void serialEvent3() __attribute__((weak));
  bool Serial3_available() __attribute__((weak));
#endif

void serialEventRun(void)
{
#if defined(HAVE_HWSERIAL0)
  if (Serial0_available && serialEvent && Serial0_available()) serialEvent();
#endif
#if defined(HAVE_HWSERIAL1)
  if (Serial1_available && serialEvent1 && Serial1_available()) serialEvent1();
#endif
#if defined(HAVE_HWSERIAL2)
  if (Serial2_available && serialEvent2 && Serial2_available()) serialEvent2();
#endif
#if defined(HAVE_HWSERIAL3)
  if (Serial3_available && serialEvent3 && Serial3_available()) serialEvent3();
#endif
}

// macro to guard critical sections when needed for large TX buffer sizes
#if (SERIAL_TX_BUFFER_SIZE>256)
#define TX_BUFFER_ATOMIC ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
#else
#define TX_BUFFER_ATOMIC
#endif

// Actual interrupt handlers //////////////////////////////////////////////////////////////

void HardwareSerial::_tx_udr_empty_irq(void)
{
#ifndef _RA6M5_
  // If interrupts are enabled, there must be more data in the output
  // buffer. Send the next byte
  unsigned char c = _tx_buffer[_tx_buffer_tail];
  _tx_buffer_tail = (_tx_buffer_tail + 1) % SERIAL_TX_BUFFER_SIZE;

  *_udr = c;

  // clear the TXC bit -- "can be cleared by writing a one to its bit
  // location". This makes sure flush() won't return until the bytes
  // actually got written. Other r/w bits are preserved, and zeroes
  // written to the rest.

#ifdef MPCM0
  *_ucsra = ((*_ucsra) & ((1 << U2X0) | (1 << MPCM0))) | (1 << TXC0);
#else
  *_ucsra = ((*_ucsra) & ((1 << U2X0) | (1 << TXC0)));
#endif

  if (_tx_buffer_head == _tx_buffer_tail) {
    // Buffer empty, so disable interrupts
    cbi(*_ucsrb, UDRIE0);
  }
#else
  if (_tx_buffer_head != _tx_buffer_tail) {
      R_SCI_UART_Write (&_uart_ctrl, &_tx_buffer[_tx_buffer_tail], 1);
    _tx_buffer_tail = (tx_buffer_index_t)((_tx_buffer_tail + 1) % SERIAL_TX_BUFFER_SIZE);
  } else {
    _sending = false;
  }
#endif
}

#ifdef _RA6M5_
rx_buffer_index_t HardwareSerial::get_rx_buffer_head(){

    transfer_properties_t p_properties;
    fsp_err_t err;
    err = R_DTC_InfoGet(_dtc_ctrl, &p_properties);
    if(err != FSP_SUCCESS) while(1);
    return (rx_buffer_index_t)(SERIAL_RX_BUFFER_SIZE - p_properties.transfer_length_remaining);

}
#endif
// Public Methods //////////////////////////////////////////////////////////////

void HardwareSerial::begin(unsigned long baud, byte config)
{
#ifndef _RA6M5_
  // Try u2x mode first
  uint16_t baud_setting = (F_CPU / 4 / baud - 1) / 2;
  *_ucsra = 1 << U2X0;

  // hardcoded exception for 57600 for compatibility with the bootloader
  // shipped with the Duemilanove and previous boards and the firmware
  // on the 8U2 on the Uno and Mega 2560. Also, The baud_setting cannot
  // be > 4095, so switch back to non-u2x mode if the baud rate is too
  // low.
  if (((F_CPU == 16000000UL) && (baud == 57600)) || (baud_setting >4095))
  {
    *_ucsra = 0;
    baud_setting = (F_CPU / 8 / baud - 1) / 2;
  }

  // assign the baud_setting, a.k.a. ubrr (USART Baud Rate Register)
  *_ubrrh = baud_setting >> 8;
  *_ubrrl = baud_setting;

  _written = false;

  //set the data bits, parity, and stop bits
#if defined(__AVR_ATmega8__)
  config |= 0x80; // select UCSRC register (shared with UBRRH)
#endif
  *_ucsrc = config;
  
  sbi(*_ucsrb, RXEN0);
  sbi(*_ucsrb, TXEN0);
  sbi(*_ucsrb, RXCIE0);
  cbi(*_ucsrb, UDRIE0);
#else
  if (this == &Serial){
	  if (_begin){
		  return;
	  }
	  cdc_open();
	  for ( int i = 0; i < 30; i++ ){
		  if(cdc_configured()){
			  _begin = true;
			  break;
		  }
		  delay(100);
	  }
	  return;
  }
  fsp_err_t err;

  _config = *_uart_config;
  switch(config){
      case SERIAL_8N1:
          _config.data_bits = UART_DATA_BITS_8;
          _config.parity = UART_PARITY_OFF;
          _config.stop_bits = UART_STOP_BITS_1;
          break;
      case SERIAL_8N2:
          _config.data_bits = UART_DATA_BITS_8;
          _config.parity = UART_PARITY_OFF;
          _config.stop_bits = UART_STOP_BITS_2;
          break;
      case SERIAL_8E1:
          _config.data_bits = UART_DATA_BITS_8;
          _config.parity = UART_PARITY_EVEN;
          _config.stop_bits = UART_STOP_BITS_1;
          break;
      case SERIAL_8E2:
          _config.data_bits = UART_DATA_BITS_8;
          _config.parity = UART_PARITY_EVEN;
          _config.stop_bits = UART_STOP_BITS_2;
          break;
      case SERIAL_8O1:
          _config.data_bits = UART_DATA_BITS_8;
          _config.parity = UART_PARITY_ODD;
          _config.stop_bits = UART_STOP_BITS_1;
          break;
      case SERIAL_8O2:
          _config.data_bits = UART_DATA_BITS_8;
          _config.parity = UART_PARITY_ODD;
          _config.stop_bits = UART_STOP_BITS_2;
          break;
  }

  const bool bit_mod = true;
  const uint32_t err_rate = 5;

  err = R_SCI_UART_BaudCalculate(baud, bit_mod, err_rate, &_baud);
  err = R_SCI_UART_Open (&_uart_ctrl, &_config);
  if(err != FSP_SUCCESS) while(1);
  err = R_SCI_UART_BaudSet(&_uart_ctrl, (void *) &_baud);
  if(err != FSP_SUCCESS) while(1);
  err = R_SCI_UART_Read(&_uart_ctrl, _rx_buffer, SERIAL_RX_BUFFER_SIZE);
  if(err != FSP_SUCCESS) while(1);
  _begin = true;
#endif
}

void HardwareSerial::end()
{
#ifndef _RA6M5_
  // wait for transmission of outgoing data
  flush();

  cbi(*_ucsrb, RXEN0);
  cbi(*_ucsrb, TXEN0);
  cbi(*_ucsrb, RXCIE0);
  cbi(*_ucsrb, UDRIE0);

  // clear any received data
  _rx_buffer_head = _rx_buffer_tail;
#else
  if (this == &Serial){
  }
  else{
	  if(R_SCI_UART_Close (&_uart_ctrl) != FSP_SUCCESS) while(1);
  }
#endif
}

int HardwareSerial::available(void)
{
#ifndef _RA6M5_
  return ((unsigned int)(SERIAL_RX_BUFFER_SIZE + _rx_buffer_head - _rx_buffer_tail)) % SERIAL_RX_BUFFER_SIZE;
#else
  if (this == &Serial){
	  return cdc_available();
  }
  else{
	  return ((unsigned int)(SERIAL_RX_BUFFER_SIZE + get_rx_buffer_head() - _rx_buffer_tail)) % SERIAL_RX_BUFFER_SIZE;
  }
#endif
}

int HardwareSerial::peek(void)
{
#ifndef _RA6M5_
  if (_rx_buffer_head == _rx_buffer_tail) {
    return -1;
  } else {
    return _rx_buffer[_rx_buffer_tail];
  }
#else
  if (this == &Serial){
	  return cdc_peek();
  }
  else{
	  if (get_rx_buffer_head() == _rx_buffer_tail) {
		return -1;
	  } else {
		return _rx_buffer[_rx_buffer_tail];
	  }
  }
#endif
}

int HardwareSerial::read(void)
{
#ifndef _RA6M5_
  // if the head isn't ahead of the tail, we don't have any characters
  if (_rx_buffer_head == _rx_buffer_tail) {
    return -1;
  } else {
    unsigned char c = _rx_buffer[_rx_buffer_tail];
    _rx_buffer_tail = (rx_buffer_index_t)(_rx_buffer_tail + 1) % SERIAL_RX_BUFFER_SIZE;
    return c;
  }
#else
  if (this == &Serial){
	  return (int)cdc_read();
  }
  else{
	  if (get_rx_buffer_head() == _rx_buffer_tail) {
		return -1;
	  } else {
		unsigned char c = _rx_buffer[_rx_buffer_tail];
		_rx_buffer_tail = (rx_buffer_index_t)(_rx_buffer_tail + 1) % SERIAL_RX_BUFFER_SIZE;
		return c;
	  }
  }
#endif
}

int HardwareSerial::availableForWrite(void)
{
  if (this == &Serial){
	  return 1;
  }
  tx_buffer_index_t head;
  tx_buffer_index_t tail;

  TX_BUFFER_ATOMIC {
    head = _tx_buffer_head;
    tail = _tx_buffer_tail;
  }
  if (head >= tail) return SERIAL_TX_BUFFER_SIZE - 1 - head + tail;
  return tail - head - 1;
}

void HardwareSerial::flush()
{
#ifndef _RA6M5_
  // If we have never written a byte, no need to flush. This special
  // case is needed since there is no way to force the TXC (transmit
  // complete) bit to 1 during initialization
  if (!_written)
    return;

  while (bit_is_set(*_ucsrb, UDRIE0) || bit_is_clear(*_ucsra, TXC0)) {
    if (bit_is_clear(SREG, SREG_I) && bit_is_set(*_ucsrb, UDRIE0))
	// Interrupts are globally disabled, but the DR empty
	// interrupt should be enabled, so poll the DR empty flag to
	// prevent deadlock
	if (bit_is_set(*_ucsra, UDRE0))
	  _tx_udr_empty_irq();
  }
  // If we get here, nothing is queued anymore (DRIE is disabled) and
  // the hardware finished tranmission (TXC is set).
#else
  if (this == &Serial){
	  return;
  }
  else{
	  while (_tx_buffer_head != _tx_buffer_tail){};
	  while (_sending){};
  }
#endif
}

size_t HardwareSerial::write(const uint8_t *buffer, size_t size)
{
  size_t n = 0;
  if (this == &Serial){
	  n = cdc_write_buf(buffer, size);
  }
  else{
	  while (size--) {
		n += write(*buffer++);
	  }
  }
  return n;
}


size_t HardwareSerial::write(uint8_t c)
{
#ifndef _RA6M5_
  _written = true;
  // If the buffer and the data register is empty, just write the byte
  // to the data register and be done. This shortcut helps
  // significantly improve the effective datarate at high (>
  // 500kbit/s) bitrates, where interrupt overhead becomes a slowdown.
  if (_tx_buffer_head == _tx_buffer_tail && bit_is_set(*_ucsra, UDRE0)) {
    // If TXC is cleared before writing UDR and the previous byte
    // completes before writing to UDR, TXC will be set but a byte
    // is still being transmitted causing flush() to return too soon.
    // So writing UDR must happen first.
    // Writing UDR and clearing TC must be done atomically, otherwise
    // interrupts might delay the TXC clear so the byte written to UDR
    // is transmitted (setting TXC) before clearing TXC. Then TXC will
    // be cleared when no bytes are left, causing flush() to hang
    ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
      *_udr = c;
#ifdef MPCM0
      *_ucsra = ((*_ucsra) & ((1 << U2X0) | (1 << MPCM0))) | (1 << TXC0);
#else
      *_ucsra = ((*_ucsra) & ((1 << U2X0) | (1 << TXC0)));
#endif
    }
    return 1;
  }
  tx_buffer_index_t i = (_tx_buffer_head + 1) % SERIAL_TX_BUFFER_SIZE;
	
  // If the output buffer is full, there's nothing for it other than to 
  // wait for the interrupt handler to empty it a bit
  while (i == _tx_buffer_tail) {
    if (bit_is_clear(SREG, SREG_I)) {
      // Interrupts are disabled, so we'll have to poll the data
      // register empty flag ourselves. If it is set, pretend an
      // interrupt has happened and call the handler to free up
      // space for us.
      if(bit_is_set(*_ucsra, UDRE0))
	_tx_udr_empty_irq();
    } else {
      // nop, the interrupt handler will free up space for us
    }
  }

  _tx_buffer[_tx_buffer_head] = c;

  // make atomic to prevent execution of ISR between setting the
  // head pointer and setting the interrupt flag resulting in buffer
  // retransmission
  ATOMIC_BLOCK(ATOMIC_RESTORESTATE) {
    _tx_buffer_head = i;
    sbi(*_ucsrb, UDRIE0);
  }
  
  return 1;
#else
  if (this == &Serial){
      return cdc_write(c);
  }
  else{
	  tx_buffer_index_t i = (tx_buffer_index_t)((_tx_buffer_head + 1) % SERIAL_TX_BUFFER_SIZE);
	  if (_begin) {
		while (i == _tx_buffer_tail){};
		_tx_buffer[_tx_buffer_head] = c;
		_tx_buffer_head = i;

		if (!_sending) {
		  _sending = true;
		  _tx_udr_empty_irq();
		}
	  } else {
		if (i != _tx_buffer_tail) {
		  _tx_buffer[_tx_buffer_head] = c;
		  _tx_buffer_head = i;
		}
	  }
	  return 1;
  }
#endif
}

#ifdef _RA6M5_
#if defined(HAVE_HWSERIAL0)
HardwareSerial Serial;
#endif

#if defined(HAVE_HWSERIAL1)
HardwareSerial Serial1(g_uart7_ctrl, &g_uart7_cfg, &g_transfer0_ctrl);
#endif
extern "C"

void user_uart_callback(uart_callback_args_t *p_args)
{
    switch (p_args->event){
        case UART_EVENT_RX_COMPLETE:
        {
            R_SCI_UART_Read(&Serial1._uart_ctrl, Serial1._rx_buffer, SERIAL_RX_BUFFER_SIZE);
            break;
        }
        case UART_EVENT_ERR_PARITY:
        case UART_EVENT_ERR_FRAMING:
        case UART_EVENT_ERR_OVERFLOW:
        {
            break;
        }
        case UART_EVENT_TX_COMPLETE:
        {
        	Serial1._tx_udr_empty_irq();
            break;
        }
        case UART_EVENT_RX_CHAR:
        case UART_EVENT_BREAK_DETECT:
        case UART_EVENT_TX_DATA_EMPTY:
        {
            break;
        }
    }
}
//void isr_uart4(uart_callback_args_t *p_args)
//{
//    switch (p_args->event){
//        case UART_EVENT_RX_COMPLETE:
//        {
//            R_SCI_UART_Read(&Serial._uart_ctrl, Serial._rx_buffer, SERIAL_RX_BUFFER_SIZE);
//            break;
//        }
//        case UART_EVENT_ERR_PARITY:
//        case UART_EVENT_ERR_FRAMING:
//        case UART_EVENT_ERR_OVERFLOW:
//        {
//            break;
//        }
//        case UART_EVENT_TX_COMPLETE:
//        {
//            Serial._tx_udr_empty_irq();
//            break;
//        }
//        case UART_EVENT_RX_CHAR:
//        case UART_EVENT_BREAK_DETECT:
//        case UART_EVENT_TX_DATA_EMPTY:
//        {
//            break;
//        }
//    }
//}
//
//extern "C"
//void isr_uart9(uart_callback_args_t *p_args)
//{
//    switch (p_args->event){
//        case UART_EVENT_RX_COMPLETE:
//        {
//            R_SCI_UART_Read(&Serial1._uart_ctrl, Serial1._rx_buffer, SERIAL_RX_BUFFER_SIZE);
//            break;
//        }
//        case UART_EVENT_ERR_PARITY:
//        case UART_EVENT_ERR_FRAMING:
//        case UART_EVENT_ERR_OVERFLOW:
//        {
//            break;
//        }
//        case UART_EVENT_TX_COMPLETE:
//        {
//            Serial1._tx_udr_empty_irq();
//            break;
//        }
//        case UART_EVENT_RX_CHAR:
//        case UART_EVENT_BREAK_DETECT:
//        case UART_EVENT_TX_DATA_EMPTY:
//        {
//            break;
//        }
//    }
//}
//
//#endif
#endif
#endif // whole file
