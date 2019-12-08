#include "chronometer.h"

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

void chronometer_reset(chronometer_t *chronometer)
{
    VERBOSE_MSG_CHRONOMETER(usart_send_string("chronometer reset!\n\r"));
    chronometer->start = chronometer->delta = chronometer->finish = 0;
}

void chronometer_start(chronometer_t *chronometer)
{
    VERBOSE_MSG_CHRONOMETER(usart_send_string("chronometer start!\n\r"));
    chronometer->config.status = chronometer_status_running;
    chronometer->start = chronometer_counter;
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

        if(chronometer->config.mode == chronometer_mode_progressive){
            chronometer->delta = chronometer_counter - chronometer->start;

            if(chronometer->config.stop == chronometer_stop_auto){
                if(chronometer->delta >= chronometer->finish){
                    chronometer_finish(chronometer);
                }
            }

        }else{
            chronometer->delta = chronometer->finish -chronometer_counter;

            if(chronometer->config.stop == chronometer_stop_auto){
                if(chronometer->delta <= 0){
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

