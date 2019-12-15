/**
 * @file io.h
 *
 * @defgroup IO IO Module
 *
 * @brief Specific module for buzzer, leds and switches interfaces.
 *
 */

#ifndef IO_H
#define IO_H
           
#include <avr/io.h>
#include <stdlib.h>
#include "../lib/bit_utils.h"
#include "conf.h"
#include <util/delay.h>
#include "dbg_vrb.h"
#include "usart.h"

typedef enum { direction_input, direction_output } direction_t;
typedef enum { pullup_disabled, pullup_enabled } pullup_t;
typedef enum { switch_pressed, switch_released } switch_status_t;

typedef union{
    struct{
        uint16_t sw4    :1,  // PC0
                 sw8    :1,  // PC1
                 sw1    :1,  // PC2
                 sw6    :1,  // PC3
                        :1,  // PC4
                        :1,  // PC5
                        :1,  // PC6
                        :1,  // PC7
                        :1,  // PD0
                        :1,  // PD1
                 sw3    :1,  // PD2
                 sw2    :1,  // PD3
                 sw7    :1,  // PD4
                 sw9    :1,  // PD5
                 sw0    :1,  // PD6
                 sw5    :1;  // PD7
    };
    struct{
        uint16_t high   :8,  // C
                 low    :8;  // D
    };
    uint16_t all;
} switches_t;

#define SW_PIN 	(((PIND) << 8) | (PINC))
#define SW_PORT	(((PORTD) << 8) | (PORTC))
#define SW_DDR 	(((DDRD) << 8) | (DDRC))

switches_t switches;

typedef union{
    struct{
        uint8_t led0    :1,  // PE0
                led1    :1,  // PE1
                led2    :1,  // PE2
                led3    :1,  // PE3
                        :4;  // others
    };
    uint8_t all;
} leds_t;

typedef enum { led_off, led_on } led_state_t;

#define leds    	(*(volatile leds_t *)&PORTE)
#define LEDS_DDR 	(DDRE)

typedef union{
    struct{
        uint8_t buzzer0 :1,   // PB0
                        :7;   // others
    };
    uint8_t all;
} buzzer_t;

typedef enum { buzzer_on, buzzer_off } buzzer_state_t;
typedef enum { 
    buzzer_beep0 = 0,
    buzzer_beep1 = 1,
    buzzer_beep2 = 10,
    buzzer_beep3 = 25,
    buzzer_beep4 = 50,
    buzzer_beep5 = 100,
    buzzer_beep6 = 200,
} buzzer_beep_t;

#define buzzer    	(*(volatile buzzer_t *)&PORTB)
#define BUZZER_DDR  (DDRB)

void leds_init(void);
void switches_init(void);
void buzzer_init(void);

void switches_read(void);
void switches_direction(direction_t direction);

void buzzer_beep(uint16_t ms);

#endif
