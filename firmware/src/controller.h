/**
 * @file controller.h
 *
 * @brief The boat controller module
 *
 */

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <stddef.h>
#include <inttypes.h>
#include "conf.h"
#include "io.h"

#define INITIAL_TURBO_VALUE 100
typedef uint8_t controller_power_channel_t;

typedef struct{
    controller_power_channel_t normal;
    controller_power_channel_t turbo;
} controller_power_channels_t;

typedef enum{
    controller_power_channel_normal_name,
    controller_power_channel_turbo_name,
} controller_power_channel_name_t;

void controller_init(void);
void controller_power_channel_change(controller_power_channel_t *channel);
void controller_power_channel_increase(controller_power_channel_t *channel);
void controller_power_channel_decrease(controller_power_channel_t *channel);

uint8_t controller_power_channel_active_value(void);
uint8_t controller_power_channel_normal_value(void);
uint8_t controller_power_channel_turbo_value(void);
controller_power_channel_name_t controller_power_channel_active_channel_name(void);

#endif /* ifndef CONTROLLER_H */
