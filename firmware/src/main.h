/**
 * @file main.h
 *
 * @defgroup MAIN Main Module
 *
 * @brief Headers for main.c
 *
 */
#ifndef MAIN_H
#define MAIN_H

#ifndef F_CPU
#define F_CPU 16000000UL    ///< Frequency of CPU
#endif /* ifndef F_CPU */

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// MODULOS DO SISTEMA
#include "conf.h"
#include "dbg_vrb.h"

#ifdef USART_ON
#include "usart.h"
#pragma message "USART: ON!"
#else
#pragma message "USART: OFF!"
#endif /*ifdef USART_ON*/

#ifdef IO_ON
#include "io.h"
#pragma message "IO: ON!"
#else
#pragma message "IO: OFF!"
#endif /*ifdef IO_ON*/

#ifdef INPUT_ON
#include "input.h"
#pragma message "INPUT: ON!"
#else
#pragma message "INPUT: OFF!"
#endif /*ifdef INPUT_ON*/

#ifdef UI_ON
#include "ui.h"
#pragma message "UI: ON!"
#else
#pragma message "UI: OFF!"
#endif /*ifdef UI_ON*/

#ifdef CAN_ON
#include "can.h"
#include "can_filters.h"
#pragma message "CAN: ON!"
#else
#pragma message "CAN: OFF!"
#endif /*ifdef CAN_ON*/

#ifdef ADC_ON
#include "adc.h"
#pragma message "ADC: ON!"
#else
#pragma message "ADC: OFF!"
#endif  /*ifdef ADC_ON*/

#ifdef MACHINE_ON
#include "machine.h"
#pragma message "MACHINE: ON!"
#else
#pragma message "MACHINE: OFF!"
#endif /*ifdef MACHINE_ON*/

#ifdef CHRONOMETER_ON
#include "chronometer.h"
#pragma message "CHRONOMETER: ON!"
#else
#pragma message "CHRONOMETER: OFF!"
#endif /*ifdef CHRONOMETER_ON*/

#ifdef CONTROLLER_ON
#include "controller.h"
#pragma message "CONTROLLER: ON!"
#else
#pragma message "CONTROLLER: OFF!"
#endif  /*ifdef CONTROLLER_ON*/

#ifdef LED_ON
#pragma message "LED: ON!"
#else
#pragma message "LED: OFF!"
#endif /*ifdef LED_ON*/

#ifdef WATCHDOG_ON
#include "watchdog.h"
#pragma message "WATCHDOG: ON!"
#else
#pragma message "WATCHDOG: OFF!"
#endif /*ifdef WATCHDOG_ON*/

#ifdef SLEEP_ON
#include "sleep.h"
#pragma message "SLEEP: ON!"
#else
#pragma message "SLEEP: OFF!"
#endif /*ifdef SLEEP_ON*/

#endif /* ifndef MAIN_H */
