/**
 * @file machine.h
 *
 * @defgroup MACHINE State Machine Module
 *
 * @brief Implements the main state machine of the system.
 *
 */

#ifndef MACHINE_H
#define MACHINE_H

#include <avr/io.h>
#include <avr/wdt.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "conf.h"

// Equations for mode 2 (CTC with TOP OCR2A)
// Note the resolution. For example.. at 150hz, ICR1 = PWM_TOP = 159, so it
#define MACHINE_TIMER_TOP ((F_CPU/(MACHINE_TIMER_PRESCALER))/(MACHINE_TIMER_FREQUENCY) -1)

#ifdef ADC_ON
#include "adc.h"
#endif // ADC_ON
#ifdef USART_ON
#include "usart.h"
#endif //USART_ON
#include "dbg_vrb.h"
#ifdef CAN_ON
#include "can.h"
#include "can_app.h"
extern const uint8_t can_filter[];
#endif // CAN_ON
#ifdef UI_ON
#include "ui.h"
#endif // UI_ON
#ifdef IO_ON
#include "io.h"
#endif //IO_ON
#ifdef CHRONOMETER_ON
#include "chronometer.h"
#endif //CHRONOMETER_ON
#ifdef INPUT_ON
#include "input.h"
#endif
#ifdef CONTROLLER_ON
#include "controller.h"
#endif

typedef enum state_machine{
    STATE_INITIALIZING,
    STATE_IDLE,
    STATE_RUNNING,
    STATE_ERROR,
    STATE_RESET,
} state_machine_t;

typedef union system_flags{
    struct{
        uint8_t     none          :1;
    };
    uint8_t   all;
} system_flags_t;

typedef union error_flags{
    struct{
        uint8_t no_communication_with_mcs :1;
        uint8_t no_message_from_MSC19_1   :1;
        uint8_t no_message_from_MSC19_2   :1;
        uint8_t no_message_from_MSC19_3   :1;
        uint8_t no_message_from_MSC19_4   :1;
        uint8_t no_message_from_MSC19_5   :1;
        uint8_t no_message_from_MT19      :1;
    };
    uint8_t   all;
}error_flags_t;

// debug functions
void print_configurations(void);
void print_system_flags(void);
void print_error_flags(void);

// machine tasks
void task_initializing(void);
void task_idle(void);
void task_running(void);
void task_error(void);
void task_reset(void);

// the machine itself
void set_machine_initial_state(void);
void machine_init(void);
void machine_run(void);
void set_state_error(void);
void set_state_initializing(void);
void set_state_idle(void);
void set_state_cap_charging(void);
void set_state_running(void);
void set_state_reset(void);

void ui_boat_info(void);

// machine variables
extern  volatile state_machine_t state_machine;
extern  volatile system_flags_t system_flags;
extern  volatile error_flags_t error_flags;

extern  volatile uint8_t machine_clk;
extern  volatile uint8_t machine_clk_divider;
extern  volatile uint8_t total_errors;           // Contagem de ERROS

// other variables
extern  volatile uint8_t led_clk_div;
extern  volatile uint8_t ui_clk_div;
extern  volatile uint8_t ui_clk_div_2;
extern  volatile uint16_t ui_timeout_clk_div;

// ISRs
ISR(TIMER2_COMPA_vect);

#endif /* ifndef MACHINE_H */
