#include "ui.h"

/**
 * @brief inicializa o UI
 */
void ui_init(void)
{
    display_init();
    test_display();

    ui_clear();
    ui_draw_layout();
    ui_update();
}

void ui_clear(void)
{
    display_clear();
}

void ui_update(void)
{
    display_update();
}

void ui_draw_layout(void)
{
    display_layout();
}

void ui_update_battery_voltage_main(uint16_t num)
{
    float val = num / 1000.f;
    display_send_float(val, col2, line2);
}

void ui_update_battery_voltage_auxiliary(uint16_t num)
{
    float val = num / 1000.f;
    display_send_float(val, col2, line3);
}

void ui_update_battery_voltage_extra(uint16_t num)
{
    float val = num / 1000.f;
    display_send_float(val, col2, line4);
}

void ui_update_battery_current_input(uint16_t num)
{
    float val = num / 100.f;
    display_send_float(val, col4, line2);
}

void ui_update_battery_current_output(uint16_t num)
{
    float val = num / 100.f;
    display_send_float(val, col4, line3);
}

void ui_update_boat_rpm(uint16_t num)
{
    display_send_uint16(num, col4, line4);
}

void ui_update_no_communication_with_tachometer()
{
    display_send_string(" N.C.", col4, line4);
}

void ui_update_no_communication_with_battery_main()
{
    display_send_string(" N.C.", col2, line2);
}

void ui_update_no_communication_with_battery_auxiliary()
{
    display_send_string(" N.C.", col2, line3);
}

void ui_update_no_communication_with_battery_extra()
{
    display_send_string(" N.C.", col2, line4);
}

void ui_update_no_communication_with_current_input()
{
    display_send_string(" N.C.", col4, line2);
}

void ui_update_no_communication_with_current_output()
{
    display_send_string(" N.C.", col4, line3);
}

void ui_boat_charging(void)
{
    display_clear();
    display_send_string_big_font("  CAP ", col1, line3-2);
    display_send_string_big_font("CHARGING", col1, line4+4);
    display_update();
}

void ui_boat_on(void)
{
    display_clear();
    display_send_string_big_font(" BOAT", col2, line3-2);
    display_send_string_big_font("  ON!", col2, line4+5);
    display_update();
    _delay_ms(500);
    LCD_Fill(1);
    display_update();
    display_layout();
    display_update();
}

void ui_boat_off(void)
{
    display_clear();
    display_send_string_big_font(" BOAT", col2, line3-2);
    display_send_string_big_font(" OFF!", col2, line4+5);
    display_update();
    _delay_ms(500);
}

void ui_boat_charge_failed(void)
{
    display_clear();
    display_send_string_big_font(" CHARGE", col1, line3-2);
    display_send_string_big_font(" FAILED", col1, line4+5);
    display_update();
}

void ui_no_communication_with_mic(void)
{
    display_clear();
    display_send_string_big_font(" MIC", col2, line3-2);
    display_send_string_big_font("DISCON.", col1, line4+5);
    display_update();
    _delay_ms(250);
}

void ui_no_communication_with_mcs(void)
{
    display_clear();
    display_send_string_big_font(" MCS", col2, line3-2);
    display_send_string_big_font("DISCON.", col1, line4+5);
    display_update();
    _delay_ms(500);
}
