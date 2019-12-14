/**
 * @file display.h
 *
 * @defgroup DISPLAY DISPLAY Module
 *
 * @brief Simple display using pooling method
 *
 */

#ifndef DISPLAY_H
#define DISPLAY_H

#include <avr/io.h>
#include <stdlib.h>
#include <util/delay.h>
//#include "../lib/bit_utils.h"
#include "usart.h"
#include "conf.h"
#include "../lib/oled-display/lcd.h"
#include "chronometer.h"

typedef enum {font_small=NORMALSIZE, font_big=DOUBLESIZE} display_font_size_t;

void display_init(void);
void display_test(void);
void display_clear(void);

void display_send_string(
        char *s, 
        uint8_t x, 
        uint8_t y, 
        display_font_size_t size);

void display_send_time(
        time_t time,
        uint8_t x,
        uint8_t y);

void display_send_int8(
        int8_t num, 
        uint8_t x, 
        uint8_t y, 
        display_font_size_t size);

void display_send_uint8(
        uint8_t num, 
        uint8_t x, 
        uint8_t y, 
        display_font_size_t size);

void display_send_int16(
        int16_t num, 
        uint8_t x, 
        uint8_t y, 
        display_font_size_t size);

void display_send_uint16(
        uint16_t num, 
        uint8_t x, 
        uint8_t y, 
        display_font_size_t size);

void display_send_int32(
        int32_t num, 
        uint8_t x, 
        uint8_t y, 
        display_font_size_t size);

void display_send_uint32(
        uint32_t num, 
        uint8_t x, 
        uint8_t y, 
        display_font_size_t size);

void display_send_float(
        float num, 
        uint8_t x, 
        uint8_t y, 
        display_font_size_t size);
//void display_send_double(double num, uint8_t x, uint8_t y, display_font_size_t size);

#endif
