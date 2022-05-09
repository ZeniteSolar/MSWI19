#include "io.h"
#include "conf.h"

switches_t switches;

void leds_init(void)
{
#ifdef IO_ON
    leds_t config = {
        .all = LEDS_DDR,
        .led0 = direction_output,
        .led1 = direction_output,
        .led2 = direction_output,
        .led3 = direction_output,
    };
    
    LEDS_DDR = config.all;

    leds.led0 = led_on;
    leds.led1 = led_on;
    leds.led2 = led_on;
    leds.led3 = led_on;
    
    _delay_ms(100);

    leds.led0 = led_off;
    leds.led1 = led_off;
    leds.led2 = led_off;
    leds.led3 = led_off;
#endif
}

void switches_init(void)
{
#ifdef IO_ON
    switches_direction(direction_input);
#endif
}

void switches_read(void)
{
#ifdef IO_ON
    switches.all = SW_PIN;

#ifdef IO_DEBUG
	if(switches.sw0 == switch_on) usart_send_string("sw0\n\r");
	if(switches.sw1 == switch_on) usart_send_string("sw1\n\r");
	if(switches.sw2 == switch_on) usart_send_string("sw2\n\r");
	if(switches.sw3 == switch_on) usart_send_string("sw3\n\r");
	if(switches.sw4 == switch_on) usart_send_string("sw4\n\r");
	if(switches.sw5 == switch_on) usart_send_string("sw5\n\r");
	if(switches.sw6 == switch_on) usart_send_string("sw6\n\r");
	if(switches.sw7 == switch_on) usart_send_string("sw7\n\r");
	if(switches.sw8 == switch_on) usart_send_string("sw8\n\r");
	if(switches.sw9 == switch_on) usart_send_string("sw9\n\r");
#endif
    
#endif 
}

void switches_direction(direction_t direction)
{
#ifdef IO_ON
    switches_t config = {
        .all = SW_DDR,
        .sw0 = direction,
        .sw1 = direction,
        .sw2 = direction,
        .sw3 = direction,
        .sw4 = direction,
        .sw5 = direction,
        .sw6 = direction,
        .sw7 = direction,
        .sw8 = direction,
        .sw9 = direction,
    };

    DDRC = config.high;
    DDRD = config.low;

    if(direction == direction_input){
        config = (switches_t){
            .all = SW_PORT,
            .sw0 = pullup_enabled,
            .sw1 = pullup_enabled,
            .sw2 = pullup_enabled,
            .sw3 = pullup_enabled,
            .sw4 = pullup_enabled,
            .sw5 = pullup_enabled,
            .sw6 = pullup_enabled,
            .sw7 = pullup_enabled,
            .sw8 = pullup_enabled,
            .sw9 = pullup_enabled,
        };

        PORTC = config.high;
        PORTD = config.low;
    }
#endif 
}

void buzzer_beep(uint16_t ms)
{
#ifdef IO_ON
    buzzer.buzzer0 = buzzer_on;
    _delay_ms(ms);
    buzzer.buzzer0 = buzzer_off;
    _delay_ms(ms);
#endif 
}

void buzzer_init(void)
{
#ifdef IO_ON
    buzzer_t config = {
        .all = BUZZER_DDR,
        .buzzer0 = direction_output,
    };
    BUZZER_DDR = config.all;

    buzzer_beep(buzzer_beep2);
    _delay_ms(buzzer_beep5);

    buzzer_beep(buzzer_beep2);
    _delay_ms(buzzer_beep5);

    buzzer_beep(buzzer_beep2);
    _delay_ms(buzzer_beep5);
    
    buzzer_beep(buzzer_beep2);
    _delay_ms(buzzer_beep5);
#endif 
}

