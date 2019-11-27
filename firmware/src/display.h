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
//#include "../lib/bit_utils.h"
#include "conf.h"
#include "../lib/DISPLAYS/SSD1306_AVR/ssd1306.h"
//#include "../lib/DISPLAYS/SSD1306_AVR/fonts/Font_9_Mono.h"
//#include "../lib/DISPLAYS/SSD1306_AVR/fonts/Font_8_Myke.h"
//#include "../lib/DISPLAYS/SSD1306_AVR/fonts/Font_8_Retro.h"
#include "../lib/DISPLAYS/SSD1306_AVR/fonts/Font_8_Default.h"
#include "../lib/DISPLAYS/SSD1306_AVR/fonts/Font_3_Picopixel.h"

#define normal_font _3_PicoPixel
//#define normal_font _9_Mono
//#define normal_font _8_Retro
//#define normal_font _8_Myke
//#define normal_font _8_Default
#define big_font    _8_Default

#define line1   8
#define line2   25
#define line3   40
#define line4   55
#define col1    0
#define col2    18
#define col3    65
#define col4    83

void display_init(void);
void test_display(void);
void display_clear(void);
void display_update(void);
void display_layout(void);

void display_send_string(char *s, uint8_t x, uint8_t y);
void display_send_string_big_font(char *s, uint8_t x, uint8_t y);

void display_send_int8(int8_t num, uint8_t x, uint8_t y);
void display_send_uint8(uint8_t num, uint8_t x, uint8_t y);

void display_send_int16(int16_t num, uint8_t x, uint8_t y);
void display_send_uint16(uint16_t num, uint8_t x, uint8_t y);

void display_send_int32(int32_t num, uint8_t x, uint8_t y);
void display_send_uint32(uint32_t num, uint8_t x, uint8_t y);

void display_send_float(float num, uint8_t x, uint8_t y);
//void display_send_double(double num, uint8_t x, uint8_t y);

#endif
