/**
 * @file ui.h
 *
 * @defgroup UI    UI Module
 *
 * @brief This module implements a simple UI
 *
 *  _________________
 * |  BAT.  |  CURR. |
 * |_________________|
 * |M 43218 |> 03972 |
 * |A 12657 |< 10421 |
 * |S:13014 |        |
 * |_________________|
 *
 */

#ifndef _UI_H_
#define _UI_H_

#include "conf.h"
#include "dbg_vrb.h"
#include "usart.h"
#include "display.h"
#include <util/delay.h>

void ui_init(void);
void ui_clear(void);
void ui_update(void);
void ui_draw_layout(void);

void ui_update_battery_voltage_main(uint16_t num);
void ui_update_battery_voltage_auxiliary(uint16_t num);
void ui_update_battery_voltage_extra(uint16_t num);
void ui_update_battery_current_input(uint16_t num);
void ui_update_battery_current_output(uint16_t num);
void ui_update_boat_rpm(uint16_t num);
void ui_update_no_communication_with_battery_main(void);
void ui_update_no_communication_with_battery_auxiliary(void);
void ui_update_no_communication_with_battery_extra(void);
void ui_update_no_communication_with_current_input(void);
void ui_update_no_communication_with_current_output(void);
void ui_update_no_communication_with_tachometer(void);

// UI boat messages
void ui_boat_charging(void);
void ui_boat_on(void);
void ui_boat_off(void);
void ui_boat_charge_failed(void);

void ui_no_communication_with_mic(void);
void ui_no_communication_with_mcs(void);

#endif /* ifndef _UI_H_ */
