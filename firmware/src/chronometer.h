/**
 * @file chronometer.h
 *
 * @defgroup CHRONOMETER Chronometer Module
 *
 * @brief A chronometer for the pilot:
 *      - count leap times 
 *      - 
 *
 */
#ifndef CHRONOMETER_H
#define CHRONOMETER_H

#include "conf.h"
#include "usart.h"
#include "dbg_vrb.h"

volatile uint32_t chronometer_counter;
#define NUMBER_OF_CHRONOMETERS  3

// TODO: implement 'paused' status
typedef enum{
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
        chronometer_status_t status : 1;
        chronometer_mode_t mode     : 1;
        chronometer_stop_t stop     : 2;
} chronometer_config_t;

// TODO: (maybe) implement callback?
// TODO: (maybe) implement name?
typedef struct{
    chronometer_config_t config;
    uint32_t start;
    uint32_t delta;
    uint32_t finish;
} chronometer_t;

static chronometer_t __chronometers[NUMBER_OF_CHRONOMETERS];

typedef struct{
    chronometer_t *uptime;
    chronometer_t *current_leap;
    chronometer_t *last_leap;
} chronometers_t;
volatile chronometers_t chronometers;

void chronometer_init(void);
void chronometer_print(chronometer_t *chronometer);
void chronometer_reset(chronometer_t *chronometer);
void chronometer_start(chronometer_t *chronometer);
void chronometer_finish(chronometer_t *chronometer);
void chronometer_update(chronometer_t *chronometer);
chronometer_t* chronometer_new(chronometer_config_t config);


#endif /* ifndef CHRONOMETER_H */
