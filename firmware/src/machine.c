#include "machine.h"

/**
 * @brief
 */
void machine_init(void)
{
	//clr_bit(PRR0, PRTIM2);                          // Activates clock

    // MODE 2 -> CTC with TOP on OCR1
    TCCR2A  =    (1 << WGM21) | (0 << WGM20)        // mode 2
              | (0 << COM2B1) | (0 << COM2B0)       // do nothing
              | (0 << COM2A1) | (0 << COM2A0);      // do nothing

    TCCR2B =
#if MACHINE_TIMER_PRESCALER ==     1
                (0 << CS22) | (0 << CS21) | (1 << CS20) // Prescaler N=1
#elif MACHINE_TIMER_PRESCALER ==   8
                (0 << CS22) | (1 << CS21) | (0 << CS20) // Prescaler N=8
#elif MACHINE_TIMER_PRESCALER ==   32
                (0 << CS22) | (1 << CS21) | (1 << CS20) // Prescaler N=32
#elif MACHINE_TIMER_PRESCALER ==   64
                (1 << CS22) | (0 << CS21) | (0 << CS20) // Prescaler N=64
#elif MACHINE_TIMER_PRESCALER ==   128
                (1 << CS22) | (0 << CS21) | (1 << CS20) // Prescaler N=128
#elif MACHINE_TIMER_PRESCALER ==   256
                (1 << CS22) | (1 << CS21) | (0 << CS20) // Prescaler N=256
#elif MACHINE_TIMER_PRESCALER ==   1024
                (1 << CS22) | (1 << CS21) | (1 << CS20) // Prescaler N=1024
#else
                0
#endif
                | (0 << WGM22);      // mode 2

    OCR2A = MACHINE_TIMER_TOP;                       // OCR2A = TOP = fcpu/(N*2*f) -1

    TIMSK2 |=   (1 << OCIE2A);                      // Activates interruption

    set_machine_initial_state();
    set_state_initializing();
}

/**
 * @brief set machine initial state
 */
inline void set_machine_initial_state(void)
{
    error_flags.all = 0;
    machine_clk = machine_clk_divider = led_clk_div = 0;
    system_flags.charge_failed = 0;
    system_flags.cap_charging  = 0;
    system_flags.boat_on       = 0;
}

/**
 * @brief set error state
 */
inline void set_state_error(void)
{
    VERBOSE_MSG_MACHINE(usart_send_string("\n>>>STATE ERROR\n"));
    state_machine = STATE_ERROR;
}

/**
* @brief set initializing state
*/
inline void set_state_initializing(void)
{
    VERBOSE_MSG_MACHINE(usart_send_string("\n>>>INITIALIZING STATE\n"));
    state_machine = STATE_INITIALIZING;
}

/**
* @brief set idle state
*/
inline void set_state_idle(void)
{
    VERBOSE_MSG_MACHINE(usart_send_string("\n>>>IDLE STATE\n"));
    state_machine = STATE_IDLE;
}

inline void set_state_cap_charging(void)
{
    VERBOSE_MSG_MACHINE(usart_send_string("\n>>>CAP CHARGING STATE\n"));
    state_machine = STATE_CAP_CHARGING;
}

/**
* @brief set running state
*/
inline void set_state_running(void)
{
    VERBOSE_MSG_MACHINE(usart_send_string("\n>>>RUNNING STATE\n"));
    state_machine = STATE_RUNNING;
}

/**
 * @brief set reset state
 */
inline void set_state_reset(void)
{
    VERBOSE_MSG_MACHINE(usart_send_string("\n>>>RESET STATE\n"));
    state_machine = STATE_RESET;
}

/**
 * @breif prints the configurations and definitions
 */
inline void print_configurations(void)
{
    VERBOSE_MSG_MACHINE(usart_send_string("CONFIGURATIONS:\n"));

#ifdef ADC_ON
    VERBOSE_MSG_MACHINE(usart_send_string("\nadc_f: "));
    VERBOSE_MSG_MACHINE(usart_send_uint16( ADC_FREQUENCY ));
    VERBOSE_MSG_MACHINE(usart_send_char(','));
    VERBOSE_MSG_MACHINE(usart_send_uint16( ADC_AVG_SIZE_10 ));
#endif // ADC_ON

    VERBOSE_MSG_MACHINE(usart_send_string("\nmachine_f: "));
    VERBOSE_MSG_MACHINE(usart_send_uint16( MACHINE_FREQUENCY ));

    VERBOSE_MSG_MACHINE(usart_send_char('\n'));
}

/**
* @brief prints the system flags
*/
inline void print_system_flags(void)
{
    //VERBOSE_MSG_MACHINE(usart_send_string(" EN "));
    //VERBOSE_MSG_MACHINE(usart_send_char(48+system_flags.enable));
}

/**
* @brief prints the error flags
*/
inline void print_error_flags(void)
{
    //VERBOSE_MSG_MACHINE(usart_send_string(" errFl: "));
    //VERBOSE_MSG_MACHINE(usart_send_char(48+error_flags.no_canbus));
}

/**
 * @brief Exibe no display um resumo das informações do barco
 */
void ui_boat_info(void)
{
  #ifdef UI_ON
      if(ui_clk_div++ >= UI_CLK_DIVIDER_VALUE){
          ui_clear();
          ui_draw_layout();

  #ifdef UI_FAKE_DATA
      static uint16_t fake_data = 0;
      ui_update_battery_voltage_main(fake_data++);
      ui_update_battery_voltage_auxiliary(fake_data++);
      ui_update_battery_voltage_extra(fake_data++);
      ui_update_battery_current_input(fake_data++);
      ui_update_battery_current_output(fake_data++);
      ui_update_boat_rpm(fake_data++);
  #else
      if(error_flags.no_message_from_MSC19_1)
          ui_update_no_communication_with_battery_main();
      else
          ui_update_battery_voltage_main(battery_voltage.main);

      if(error_flags.no_message_from_MSC19_2)
          ui_update_no_communication_with_battery_auxiliary();
      else
          ui_update_battery_voltage_auxiliary(battery_voltage.aux);
      if(error_flags.no_message_from_MSC19_3)
          ui_update_no_communication_with_battery_extra();
      else
          ui_update_battery_voltage_extra(battery_voltage.extra);

      if(error_flags.no_message_from_MSC19_4)
          ui_update_no_communication_with_current_input();
      else
          ui_update_battery_current_input(battery_current.in);

      if(error_flags.no_message_from_MSC19_5)
          ui_update_no_communication_with_current_output();
      else
          ui_update_battery_current_output(battery_current.out);

      if(error_flags.no_message_from_MT19)
          ui_update_no_communication_with_tachometer();
      else
          ui_update_boat_rpm(control.rpm);

  #endif
          ui_update();
          ui_clk_div = 0;
      }
  #endif // UI_ON
}

/**
 * @brief Checks if the system is OK to run
 */
inline void task_initializing(void)
{
#ifdef LED_ON
    set_led(LED2);
#endif

    set_machine_initial_state();
    VERBOSE_MSG_INIT(usart_send_string("System initialized without errors.\n"));
    set_state_idle();
}

/**
 * @brief waits for commands while checking the system
 */
inline void task_idle(void)
{
#ifdef LED_ON
    if(led_clk_div++ >= 100){
        cpl_led(LED1);
        led_clk_div = 0;
    }
#endif

    if(system_flags.cap_charging)
    {
      #ifdef UI_ON
      ui_boat_charging();
      #endif
      set_state_cap_charging();
    }

    ui_boat_info();
}

void task_cap_charging(void)
{
#ifdef LED_ON
    if(led_clk_div++ >= 10){
        cpl_led(LED1);
        led_clk_div = 0;
    }
#endif

    if(system_flags.boat_on)
    {
      ui_boat_on();
      set_state_running();
    }

    if(!system_flags.cap_charging)
    {
      ui_boat_charge_failed();
      _delay_ms(500);
      ui_boat_off();
      set_state_idle();
    }

    if(ui_timeout_clk_div++ >= UI_TIMEOUT_CLK_DIV_VALUE)
    {
      ui_timeout_clk_div = 0;
      set_state_initializing();
      set_state_idle();
    }

}

/**
 * @brief running task checks the system and apply the control action to pwm.
 */
inline void task_running(void)
{
#ifdef LED_ON
    if(led_clk_div++ >= 50){
        cpl_led(LED1);
        led_clk_div = 0;
    }
#endif

    if(!system_flags.boat_on)
    {
        #ifdef UI_ON
        ui_boat_off();
        #endif
        set_state_idle();
    }

    ui_boat_info();
}

/**
 * @brief error task checks the system and tries to medicine it.
 */
inline void task_error(void)
{
#ifdef LED_ON
    if(led_clk_div++ >= 5){
        cpl_led(LED2);
        cpl_led(LED1);
        led_clk_div = 0;
    }
#endif
/*
    total_errors++;         // incrementa a contagem de erros

    if(error_flags.no_communication_with_mcs)
    {
        VERBOSE_MSG_ERROR(usart_send_string("\t - No canbus communication with MCS!\n"));
        ui_no_communication_with_mcs()
    }

   if(error_flags.can_app_task)
        VERBOSE_ON_ERROR(usart_send_string("\t - can_app_task failed"));

    if(total_errors < 2){
        VERBOSE_MSG_ERROR(usart_send_string("I will reset the machine state.\n"));
    }
    if(total_errors >= 20){
        VERBOSE_MSG_ERROR(usart_send_string("The watchdog will reset the whole system.\n"));
        set_state_reset();
    }

#ifdef LED_ON
    cpl_led(LED1);
#endif
*/
    set_state_initializing();

}

/**
 * @brief reset error task just freezes the processor and waits for watchdog
 */
inline void task_reset(void)
{
#ifndef WATCHDOG_ON
    //wdt_init();
#endif

    cli();  // disable interrupts

    VERBOSE_MSG_ERROR(usart_send_string("WAITING FOR A RESET!\n"));
    for(;;)
    {
      cpl_led(LED2);
      cpl_led(LED1);
      _delay_ms(100);
    }
}

void print_infos(void)
{
    static uint8_t i = 0;

    switch(i++){
        case 0:
            //print_system_flags();
            break;
        case 1:
            //print_error_flags();
            break;
        case 2:
            //print_control_others();
        default:
            //VERBOSE_MSG_MACHINE(usart_send_char('\n'));
            i = 0;
            break;
    }
}

/**
 * @brief this is the machine state itself.
 */
inline void machine_run(void)
{
    //print_infos();

    if(machine_clk){
        machine_clk = 0;
            switch(state_machine){
                case STATE_INITIALIZING:
                    task_initializing();
                    break;

                case STATE_IDLE:
                    task_idle();
                    #ifdef CAN_ON
                    can_app_task();
                    #endif /* CAN_ON */
                    break;

                case STATE_CAP_CHARGING:
                    task_cap_charging();
                    #ifdef CAN_ON
                    can_app_task();
                    #endif /* CAN_ON */
                    break;

                case STATE_RUNNING:
                    task_running();
                    #ifdef CAN_ON
                    can_app_task();
                    #endif /* CAN_ON */
                    break;

                case STATE_ERROR:
                    task_error();
                    break;

                case STATE_RESET:
                default:
                    task_reset();
                    break;
            }
        }
}

/**
* @brief ISR para ações de controle
*/
ISR(TIMER2_COMPA_vect)
{
    if(machine_clk_divider++ == MACHINE_CLK_DIVIDER_VALUE){
       /* if(machine_clk){
            for(;;){
        //        pwm_reset();
                VERBOSE_MSG_ERROR(if(machine_clk) usart_send_string("\nERROR: CLOCK CONFLICT!!!\n"));
            }
        }*/
        machine_clk = 1;
        machine_clk_divider = 0;
    }
}
