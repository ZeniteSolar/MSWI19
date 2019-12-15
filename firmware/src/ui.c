#include "ui.h"

static screen_t ui_screen;

void ui_init(void)
{
    ui_screen = screen_main;
    display_init(); 
    display_test();
    display_clear();
}

void ui_update(void){
    switch(ui_screen){
        default:
        case screen_main:
            ui_screen_main();
            break;
        case screen_laps:
            ui_screen_laps();
            break;
    }
}

void ui_screen_change(screen_t * screen)
{
    display_clear();
    if(screen == NULL){
        if(++ui_screen== screen_last) ui_screen = screen_main;
    }else{
        if(*screen < screen_last) ui_screen = *screen;
    }
#ifdef BUZZER_ON
    buzzer_beep(buzzer_beep2);
#endif
}

void ui_screen_main(void)
{
    char time_str[TIME_STRING_LEN];

    // total time
    chronometer_millis_to_time_string(chronometers.uptime->delta, time_str);
    display_send_string(time_str, 0, 0, font_big);

    // power settings
    static char channel_name_normal[] = "BASIC";
    static char channel_name_turbo[] = "TURBO";
    controller_power_channel_t active_power_channel = controller_power_channel_active_channel_name();
    if(active_power_channel == controller_power_channel_normal_name){
        display_send_string(channel_name_normal, 0, 3, font_big);
        display_send_uint8(controller_power_channel_normal_value(), 14, 3, font_big);
        
        display_send_string(channel_name_turbo, 0, 6, font_small);
        display_send_uint8(controller_power_channel_turbo_value(), 14, 6, font_small);
    }else{
        display_send_string(channel_name_turbo, 0, 3, font_big);
        display_send_uint8(controller_power_channel_turbo_value(), 14, 3, font_big);
        
        display_send_string(channel_name_normal, 0, 6, font_small);
        display_send_uint8(controller_power_channel_normal_value(), 14, 6, font_small);
    }

}

void ui_screen_laps(void)
{
    char time_str[TIME_STRING_LEN];

    // LAP
    display_send_string("LAP)", 2, 0, font_small);
    display_send_uint8(2, 7, 0, font_small);

    // total
    display_send_string("TOTAL)", 0, 1, font_small);
    chronometer_millis_to_time_string(chronometers.uptime->delta, time_str);
    display_send_string(time_str, 7, 1, font_small);

    // best lap
    display_send_string("L.10)", 0, 3, font_small);
    chronometer_millis_to_time_string(chronometers.uptime->delta, time_str);
    display_send_string(time_str, 7, 3, font_small);

    // last lap
    display_send_string("L.09)", 0, 5, font_small);
    chronometer_millis_to_time_string(chronometers.uptime->delta, time_str);
    display_send_string(time_str, 7, 5, font_small);

}
