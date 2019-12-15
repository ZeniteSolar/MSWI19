/**
 * @file chronometer.h
 *
 * @defgroup CHRONOMETER Chronometer Module
 *
 * @brief A chronometer for the pilot:
 *      - count lap times 
 *      - 
 *
 */

#ifndef CHRONOMETER_H
#define CHRONOMETER_H

#include "conf.h"
#include "usart.h"
#include "dbg_vrb.h"
#include "io.h"

volatile uint32_t chronometer_counter;
#define TIME_STRING_LEN 13

typedef enum{
    chronometer_status_paused,
    chronometer_status_finished, 
    chronometer_status_running
} chronometer_status_t;

typedef enum{
    chronometer_mode_progressive, // delta is the elapsed time
    chronometer_mode_regressive   // delta is the remaining time
} chronometer_mode_t;

typedef enum{
    chronometer_stop_auto,
    chronometer_stop_manual,
    chronometer_stop_never
} chronometer_stop_t;
    
typedef struct{
        chronometer_status_t status : 2;
        chronometer_mode_t mode     : 1;
        chronometer_stop_t stop     : 2;
} chronometer_config_t;

typedef union{
    struct{
        struct{
            uint16_t millis : 10;
            uint16_t hours : 6;
        };
        struct{
            uint8_t minutes;
            uint8_t seconds;
        };
    };
    uint32_t all;
} time_t;
 

// TODO: (maybe) implement callback?
// TODO: (maybe) implement name?
typedef struct{
    chronometer_config_t config;
    uint32_t start;
    uint32_t delta;
    uint32_t finish;
} chronometer_t;

typedef struct{
    chronometer_t *uptime;
    chronometer_t *current_lap;
    chronometer_t *last_lap;
} chronometers_t;
chronometers_t chronometers;

typedef struct{
    uint8_t laps_counter;
    uint8_t lap_best;
    uint8_t lap_last;
} _foo;

void chronometer_difference(chronometer_t *a, chronometer_t *b, chronometer_t *result);
void chronometer_callback_test(chronometer_t *chronometer);
void chronometer_millis_to_time_string(uint32_t millis, char *str);
void chronometer_millis_to_time(uint32_t millis, time_t * time);
void chronometer_init(void);
void chronometer_print_time(chronometer_t *chronometer);
void chronometer_print(chronometer_t *chronometer);
void chronometer_reset_delta(chronometer_t *chronometer);
void chronometer_reset_all(chronometer_t *chronometer);
void chronometer_start(chronometer_t *chronometer);
void chronometer_pause(chronometer_t *chronometer);
void chronometer_finish(chronometer_t *chronometer);
void chronometer_update(chronometer_t *chronometer);
chronometer_t* chronometer_new(chronometer_config_t config);


#endif /* ifndef CHRONOMETER_H */
