#include "controller.h"

static controller_power_channels_t controller_power_channels;
static uint8_t * active_power_channel;

void controller_init(void)
{
    controller_power_channels.normal = 0;
    controller_power_channels.turbo = INITIAL_TURBO_VALUE;
    active_power_channel = &(controller_power_channels.normal);
}

void controller_power_channel_change(controller_power_channel_t *channel)
{
    if(channel == NULL){
        if(active_power_channel == &(controller_power_channels.normal)){
            active_power_channel = &(controller_power_channels.turbo);
        }else{
            active_power_channel = &(controller_power_channels.normal);
        }
    }else{
        active_power_channel = channel;
    }
#ifdef BUZZER_ON
    buzzer_beep(buzzer_beep1);
#endif
}

void controller_power_channel_increase(controller_power_channel_t *channel)
{
    if(channel == NULL){
        if((*active_power_channel) != 100){
            (*active_power_channel)++;
#ifdef BUZZER_ON
            buzzer_beep(buzzer_beep1);
#endif
        }
    }else{
        if((*channel) != 100){
            (*channel)++;
#ifdef BUZZER_ON
            buzzer_beep(buzzer_beep1);
#endif
        }
    }
}

void controller_power_channel_decrease(controller_power_channel_t *channel)
{
    if(channel == NULL){
        if((*active_power_channel) != 0){
            (*active_power_channel)--;
#ifdef BUZZER_ON
            buzzer_beep(buzzer_beep1);
#endif
        }
    }else{
        if((*channel) != 0){
            (*channel)--;
#ifdef BUZZER_ON
            buzzer_beep(buzzer_beep1);
#endif
        }
    }
}

uint8_t controller_power_channel_active_value(void)
{
    return (*active_power_channel);
}

uint8_t controller_power_channel_normal_value(void)
{
    return controller_power_channels.normal;
}

uint8_t controller_power_channel_turbo_value(void)
{
    return controller_power_channels.turbo;
}

controller_power_channel_name_t controller_power_channel_active_channel_name(void)
{
    if(active_power_channel == &(controller_power_channels.normal)){
        return controller_power_channel_normal_name;
    }else{
        return controller_power_channel_turbo_name;
    }
}
