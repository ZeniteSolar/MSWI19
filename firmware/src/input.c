
#include "input.h"

static void (*callback_functions[10])(void *);
static void (*callback_arguments[10]);
static void callback_caller(input_names_t input);
static const uint8_t input_cooldown_time = 25;
static const uint8_t input_cooldown_time_first = 50;
static inline void input_update_sw0(void);
static inline void input_update_sw1(void);
static inline void input_update_sw2(void);
static inline void input_update_sw3(void);
static inline void input_update_sw4(void);
static inline void input_update_sw5(void);
static inline void input_update_sw6(void);
static inline void input_update_sw7(void);
static inline void input_update_sw8(void);
static inline void input_update_sw9(void);
static switches_t switches_old;

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
        if(callback_functions[input]){
            callback_functions[input](callback_arguments[input]);
        }
    }
}

void inputs_update(void)
{
    switches_old.all = switches_old.all;
    switches_read();

    VERBOSE_MSG_INPUT(usart_send_string("\r["));
    VERBOSE_MSG_INPUT(usart_send_uint8(input_cooldown));
    VERBOSE_MSG_INPUT(usart_send_string("]\t"));

    input_update_sw0();
    input_update_sw1();
    input_update_sw2();
    input_update_sw3();
    input_update_sw4();
    input_update_sw5();
    input_update_sw6();
    input_update_sw7();
    input_update_sw8();
    input_update_sw9();

    switches_old.all = switches.all;
}

static inline void input_update_sw0(void)
{
    static uint8_t input_cooldown = 0;
    if(input_cooldown) input_cooldown--;
    else{
        if(switches.sw0 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw0 pressed]\n"));
            callback_caller(sw0);
            if(switches.sw0 == switches_old.sw0){
                input_cooldown = input_cooldown_time;
            }else{
                input_cooldown = input_cooldown_time_first;
            }
        }
    }
    if(switches.sw0 == switch_released){
        if(switches_old.sw0 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw0 released]\n"));
            input_cooldown = 0;
        }
    } 
}

static inline void input_update_sw1(void)
{
    static uint8_t input_cooldown = 0;
    if(input_cooldown) input_cooldown--;
    else{
        if(switches.sw1 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw1 pressed]\n"));
            callback_caller(sw1);
            if(switches.sw1 == switches_old.sw1){
                input_cooldown = input_cooldown_time;
            }else{
                input_cooldown = input_cooldown_time_first;
            }
        }
    }
    if(switches.sw1 == switch_released){
        if(switches_old.sw1 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw1 released]\n"));
            input_cooldown = 0;
        }
    } 
}

static inline void input_update_sw2(void)
{
    static uint8_t input_cooldown = 0;
    if(input_cooldown) input_cooldown--;
    else{
        if(switches.sw2 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw2 pressed]\n"));
            callback_caller(sw2);
            if(switches.sw2 == switches_old.sw2){
                input_cooldown = input_cooldown_time;
            }else{
                input_cooldown = input_cooldown_time_first;
            }
        }
    }
    if(switches.sw2 == switch_released){
        if(switches_old.sw2 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw2 released]\n"));
            input_cooldown = 0;
        }
    } 
}

static inline void input_update_sw3(void)
{
    static uint8_t input_cooldown = 0;
    if(input_cooldown) input_cooldown--;
    else{
        if(switches.sw3 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw3 pressed]\n"));
            callback_caller(sw3);
            if(switches.sw3 == switches_old.sw3){
                input_cooldown = input_cooldown_time;
            }else{
                input_cooldown = input_cooldown_time_first;
            }
        }
    }
    if(switches.sw3 == switch_released){
        if(switches_old.sw3 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw3 released]\n"));
            input_cooldown = 0;
        }
    } 
}

static inline void input_update_sw4(void)
{
    static uint8_t input_cooldown = 0;
    if(input_cooldown) input_cooldown--;
    else{
        if(switches.sw4 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw4 pressed]\n"));
            callback_caller(sw4);
            if(switches.sw4 == switches_old.sw4){
                input_cooldown = input_cooldown_time;
            }else{
                input_cooldown = input_cooldown_time_first;
            }
        }
    }
    if(switches.sw4 == switch_released){
        if(switches_old.sw4 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw4 released]\n"));
            input_cooldown = 0;
        }
    } 
}

static inline void input_update_sw5(void)
{
    static uint8_t input_cooldown = 0;
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
}

static inline void input_update_sw6(void)
{
    static uint8_t input_cooldown = 0;
    if(input_cooldown) input_cooldown--;
    else{
        if(switches.sw6 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw6 pressed]\n"));
            callback_caller(sw6);
            if(switches.sw6 == switches_old.sw6){
                input_cooldown = input_cooldown_time;
            }else{
                input_cooldown = input_cooldown_time_first;
            }
        }
    }
    if(switches.sw6 == switch_released){
        if(switches_old.sw6 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw6 released]\n"));
            input_cooldown = 0;
        }
    } 
}

static inline void input_update_sw7(void)
{
    static uint8_t input_cooldown = 0;
    if(input_cooldown) input_cooldown--;
    else{
        if(switches.sw7 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw7 pressed]\n"));
            callback_caller(sw7);
            if(switches.sw7 == switches_old.sw7){
                input_cooldown = input_cooldown_time;
            }else{
                input_cooldown = input_cooldown_time_first;
            }
        }
    }
    if(switches.sw7 == switch_released){
        if(switches_old.sw7 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw7 released]\n"));
            input_cooldown = 0;
        }
    } 
}
                                
static inline void input_update_sw8(void)
{
    static uint8_t input_cooldown = 0;
    if(input_cooldown) input_cooldown--;
    else{
        if(switches.sw8 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw8 pressed]\n"));
            callback_caller(sw8);
            if(switches.sw8 == switches_old.sw8){
                input_cooldown = input_cooldown_time;
            }else{
                input_cooldown = input_cooldown_time_first;
            }
        }
    }
    if(switches.sw8 == switch_released){
        if(switches_old.sw8 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw8 released]\n"));
            input_cooldown = 0;
        }
    } 
}
static inline void input_update_sw9(void)
{
    static uint8_t input_cooldown = 0;
    if(input_cooldown) input_cooldown--;
    else{
        if(switches.sw9 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw9 pressed]\n"));
            callback_caller(sw9);
            if(switches.sw9 == switches_old.sw9){
                input_cooldown = input_cooldown_time;
            }else{
                input_cooldown = input_cooldown_time_first;
            }
        }
    }
    if(switches.sw9 == switch_released){
        if(switches_old.sw9 == switch_pressed){
            VERBOSE_MSG_INPUT(usart_send_string("[sw9 released]\n"));
            input_cooldown = 0;
        }
    } 
}
