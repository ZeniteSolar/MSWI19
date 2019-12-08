
#include "input.h"

static void (*callback_functions[10])(void *);
static void (*callback_arguments[10]);
static void callback_caller(input_names_t input);
static uint8_t input_cooldown = 0;
static const uint8_t input_cooldown_time = 25;
static const uint8_t input_cooldown_time_first = 50;

void input_assign_callback(input_names_t input, void *function, void *argument)
{
    if(input < input_length) if(function){
        callback_functions[input] = function;
        callback_arguments[input] = argument;
    }
}

static void callback_caller(input_names_t input)
{
    if(input < input_length){
        callback_functions[input](callback_arguments[input]);
    }
}

void inputs_update(void)
{
    switches_t switches_old = {.all = switches.all};
    switches_read();

    VERBOSE_MSG_INPUT(usart_send_string("\r["));
    VERBOSE_MSG_INPUT(usart_send_uint8(input_cooldown));
    VERBOSE_MSG_INPUT(usart_send_string("]\t"));

    if(input_cooldown) input_cooldown--;
    else{
        if(switches.sw5 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw5 pressed]\n"));
            callback_caller(sw5);
            if(switches.sw5 == switches_old.sw5){
                input_cooldown = input_cooldown_time;
            }else{
                input_cooldown = input_cooldown_time_first;
            }
        }
    }
    if(switches.sw5 == switch_released){
        if(switches_old.sw5 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw5 released]\n"));
            input_cooldown = 0;
        }
    }

    switches_old.all = switches.all;
}
