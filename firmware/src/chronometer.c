#include "chronometer.h"

#define NUMBER_OF_CHRONOMETERS  3
static chronometer_t __chronometers[NUMBER_OF_CHRONOMETERS];

void chronometer_callback_test(chronometer_t *chronometer)
{
    usart_send_char('\r');
    usart_send_uint8(*(uint8_t *)chronometer);
    usart_send_char(',');
    usart_send_uint32(chronometer->start);
    usart_send_char(',');
    usart_send_uint32(chronometer->delta);
    usart_send_char(',');
    usart_send_uint32(chronometer->finish);
}

void chronometer_print(chronometer_t *chronometer)
{
    usart_send_string("chronometer: ");
    usart_send_uint32(chronometer->start);
    usart_send_string(", ");
    usart_send_uint32(chronometer->delta);
    usart_send_string(", ");
    usart_send_uint32(chronometer->finish);
    usart_send_string("\n\r");
}

void chronometer_reset_all(chronometer_t *chronometer)
{
    VERBOSE_MSG_CHRONOMETER(usart_send_string("chronometer reset all!\n\r"));
    chronometer->start = chronometer->delta = chronometer->finish = 0;
}

void chronometer_reset_delta(chronometer_t *chronometer)
{
    VERBOSE_MSG_CHRONOMETER(usart_send_string("chronometer reset delta!\n\r"));
    chronometer->delta = 0;
}

void chronometer_start(chronometer_t *chronometer)
{
    VERBOSE_MSG_CHRONOMETER(usart_send_string("chronometer start!\n\r"));
    chronometer->config.status = chronometer_status_running;
    chronometer->start = chronometer_counter;
    if(chronometer->config.mode == chronometer_mode_progressive){
        chronometer->delta = chronometer->start;
    }else{
        chronometer->delta = chronometer->finish;
    }
}

void chronometer_pause(chronometer_t *chronometer)
{
    VERBOSE_MSG_CHRONOMETER(usart_send_string("chronometer start!\n\r"));
    chronometer->config.status = chronometer_status_paused;
}

void chronometer_finish(chronometer_t *chronometer)
{
    VERBOSE_MSG_CHRONOMETER(usart_send_string("chronometer finish!\n\r"));
    chronometer->finish = chronometer_counter;
    chronometer->config.status = chronometer_status_finished;
}

// TODO: implement and test all configs
void chronometer_update(chronometer_t *chronometer)
{
    if(chronometer->config.status == chronometer_status_running){
        chronometer->delta = chronometer_counter -chronometer->start;
        if(chronometer->config.mode == chronometer_mode_progressive){
            if(chronometer->config.stop == chronometer_stop_auto){
                if(chronometer->delta >= chronometer->finish){
                    chronometer_finish(chronometer);
                }
            }
        }else{
            if(chronometer->config.stop == chronometer_stop_auto){
                if(chronometer->delta == 0){
                    chronometer_finish(chronometer);
                }
            }
        }
    }
}

chronometer_t* chronometer_new(chronometer_config_t config)
{
    static uint8_t chronometer_number = 0;
    if(chronometer_number++ == NUMBER_OF_CHRONOMETERS-1){
        chronometer_number = 0;      
    }

    VERBOSE_MSG_CHRONOMETER(usart_send_string("new chronometer: "));
    VERBOSE_MSG_CHRONOMETER(usart_send_uint8(chronometer_number));
    VERBOSE_MSG_CHRONOMETER(usart_send_string("\n\r"));

    chronometer_t *chronometer = &__chronometers[chronometer_number];
    chronometer->config = config;

    chronometer_reset_all(chronometer);

    return chronometer;
}

void chronometer_init(void)
{
    chronometer_config_t config = {
        .mode = chronometer_mode_progressive,
        .stop = chronometer_stop_never,
    };
    chronometers.uptime = chronometer_new(config);

    chronometer_start(chronometers.uptime);
}

