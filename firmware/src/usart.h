/**
 * @file usart.h
 *
 * @defgroup USART USART Module
 *
 * @brief Simple usart using pooling method, with basic functions used for debug
 * purpose.
 *
 */

#ifndef USART_H
#define USART_H

#include <avr/io.h>
#include <stdlib.h>
#include "../lib/bit_utils.h"
#include "conf.h"

#ifndef USART_BAUD
#define USART_BAUD 57600
#endif /* ifndef USART_BAUD */
#define MYUBRR F_CPU/16/USART_BAUD-1

#define   USART_HAS_DATA   bit_is_set(UCSR0A, RXC0)
#define   USART_READY      bit_is_set(UCSR0A, UDRE0)

void usart_send_char(char data);

char usart_receive_char(void);

void usart_send_string(const char *s);

void usart_send_int8(int8_t num);
void usart_send_uint8(uint8_t num);

void usart_send_int16(int16_t num);
void usart_send_uint16(uint16_t num);

void usart_send_int32(int32_t num);
void usart_send_uint32(uint32_t num);

void usart_send_buffer(uint8_t *b, uint8_t lenght);

void usart_init(uint16_t ubrr, uint8_t rx, uint8_t tx);

void usart_send_float(float num);

#endif
