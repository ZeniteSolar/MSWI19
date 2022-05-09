#include "chronometer.h"

volatile uint32_t chronometer_counter;
chronometers_t chronometers;

#define NUMBER_OF_CHRONOMETERS  3
static chronometer_t __chronometers[NUMBER_OF_CHRONOMETERS];

inline void chronometer_millis_to_time_string(uint32_t millis, char* str)
{
    time_t time;
    chronometer_millis_to_time(millis, &time);

    str[0] = '0' + ((time.hours/10) % 10);
    str[1] = '0' + (time.hours % 10);
    str[2] = ':';
    str[3] = '0' + ((time.minutes/10) % 10);
    str[4] = '0' + ((time.minutes) % 10);
    str[5] = ':';
    str[6] = '0' + ((time.seconds/10) % 10);
    str[7] = '0' + ((time.seconds) % 10);
    str[8] = '.';
    str[9] = '0' + ((time.millis/100) % 10);
    str[10] = '0' + ((time.millis/10) % 10);
    str[11] = '0' + ((time.millis) % 10);
    str[12] = '\0';
}

inline void chronometer_millis_to_time(uint32_t millis, time_t *time)
{
    time->hours = millis / 3600000;
    millis -= 3600000 * time->hours;
    
    time->minutes = millis / 60000U;
    millis -= 60000 * time->minutes;

    time->seconds = millis / 1000;
    millis -= 1000 * time->seconds;

    time->millis = millis;
}

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

    chronometer_print_time(chronometer);
}

void chronometer_print_time(chronometer_t *chronometer)
{
    usart_send_string("time: ");
    char str_time[TIME_STRING_LEN];

    chronometer_millis_to_time_string(chronometer->start, str_time);
    usart_send_string(str_time);
    usart_send_char(',');

    chronometer_millis_to_time_string(chronometer->delta, str_time);
    usart_send_string(str_time);
    usart_send_char(',');

    chronometer_millis_to_time_string(chronometer->finish, str_time);
    usart_send_string(str_time);
    usart_send_string("\n\r");
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

    #ifdef BUZZER_ON
    buzzer_beep(buzzer_beep2);
    _delay_ms(buzzer_beep2);
    buzzer_beep(buzzer_beep2);
    #endif
}

void chronometer_reset_delta(chronometer_t *chronometer)
{
    VERBOSE_MSG_CHRONOMETER(usart_send_string("chronometer reset delta!\n\r"));
    chronometer->delta = 0;

    #ifdef BUZZER_ON
    buzzer_beep(buzzer_beep2);
    _delay_ms(buzzer_beep2);
    buzzer_beep(buzzer_beep2);
    #endif
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

    #ifdef BUZZER_ON
    buzzer_beep(buzzer_beep3);
    _delay_ms(buzzer_beep4);
    buzzer_beep(buzzer_beep3);
    _delay_ms(buzzer_beep5);
    buzzer_beep(buzzer_beep3);
    #endif
}

void chronometer_pause(chronometer_t *chronometer)
{
    VERBOSE_MSG_CHRONOMETER(usart_send_string("chronometer start!\n\r"));
    chronometer->config.status = chronometer_status_paused;

    #ifdef BUZZER_ON
    buzzer_beep(buzzer_beep2);
    _delay_ms(buzzer_beep3);
    buzzer_beep(buzzer_beep3);
    #endif
}

void chronometer_finish(chronometer_t *chronometer)
{
    VERBOSE_MSG_CHRONOMETER(usart_send_string("chronometer finish!\n\r"));
    chronometer->finish = chronometer_counter;
    chronometer->config.status = chronometer_status_finished;

    #ifdef BUZZER_ON
    buzzer_beep(buzzer_beep5);
    buzzer_beep(buzzer_beep5);
    buzzer_beep(buzzer_beep5);
    buzzer_beep(buzzer_beep5);
    #endif
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

