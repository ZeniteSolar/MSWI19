/**
 * @file adc.h
 *
 * @defgroup ADC    ADC Module
 *
 * @brief This module implements a simple ADC using a state machine to mux
 * between the adc channels.
 *
 */

#ifndef _ADC_H_
#define _ADC_H_

#include "avr/io.h"
#include "avr/interrupt.h"
#include "conf.h"
#include "dbg_vrb.h"
#include "usart.h"
#include "../lib/bit_utils.h"
#include "../lib/log2.h"

#ifndef ADC_FREQUENCY           
#define ADC_FREQUENCY   1000
#endif // ADC_FREQUENCY
#ifndef ADC_TIMER_PRESCALER     
#define ADC_TIMER_PRESCALER     64
#endif // ADC_TIMER_PRESCALER
#ifndef ADC_AVG_SIZE_10
#define ADC_AVG_SIZE_10 4
#endif
#ifndef ADC_AVG_SIZE_2
#define ADC_AVG_SIZE_2 2
#endif

// Equations for mode 2 (CTC with TOP OCR2A)
// Note the resolution. For example.. at 150hz, ICR1 = PWM_TOP = 159, so it
//#define QUOTIENT  (((uint32_t)MACHINE_TIMER_PRESCALER)*((uint32_t)MACHINE_TIMER_FREQUENCY))
//#define ADC_TIMER_TOP (0.5*(F_CPU)/QUOTIENT)
#define ADC_TIMER_FREQUENCY     ((uint32_t)(ADC_FREQUENCY)*(uint8_t)(ADC_LAST_CHANNEL +1))
#define ADC_TIMER_TOP           ((F_CPU/(2*ADC_TIMER_PRESCALER))/(ADC_TIMER_FREQUENCY) -1)

typedef enum adc_channels{ 
    ADC0, ADC1 ,ADC2, ADC3, ADC4, ADC5
} adc_channels_t;                           //*< the adc_channel type 

#define ADC_LAST_CHANNEL ADC0

typedef struct{
    uint32_t sum;
    uint16_t avg;
} adc_channel_t;

typedef struct adc{
    adc_channel_t channel[ADC_LAST_CHANNEL+1];
    adc_channels_t select;
    uint16_t samples;
    uint8_t ready;
} adc_t;

volatile adc_t adc;

uint8_t adc_select_channel(adc_channels_t __ch);
void adc_init(void);

#endif /* ifndef _ADC_H_ */
