/**
 * @file ui.h
 *
 * @defgroup UI    UI Module
 *
 * @brief This module implements a simple UI
 *
 */

#ifndef _UI_H_
#define _UI_H_

#include <util/delay.h>
#include <stddef.h>
#include "conf.h"
#include "dbg_vrb.h"
#include "usart.h"
#include "display.h"
#include "chronometer.h"
#include "controller.h"

// NORMALSIZE -> 21x8
// DOUBLESIZE -> 10x4

// TODO: add screen_init
typedef enum {screen_main, screen_laps, screen_last} screen_t;


/**
 *  TELA GERAL
 * .---------------------.
 * :  LAP) 02            : -> Volta 
 * :TOTAL) 02:23:51.876  : -> tempo total
 * :---------------------: 
 * :[ M A X ] :  1 0 0 % : -> limite superior
 * :                     :
 * :[ V E L ] :  0 7 0 % : -> velocidade do motor
 * :                     :
 * '---------------------'
 */
void ui_screen_main(void);

/**
 *  TELA DE VOLTAS -> melhor volta
 * .---------------------.
 * :  LAP) 02            : -> Volta 
 * :TOTAL) 02:23:51.876  : -> tempo total
 * :---------------------: 
 * :L.10)  00:03:19.161  : -> volta atual
 * :L.09)  00:20:42.122  : -> melhor volta
 * :diff) = -00:17:23.039: -> diferença
 * :L.09)  00:20:42.122  : -> última volta
 * :diff) = -00:17:23.039: -> diferença
 * '---------------------'
 */
void ui_screen_laps(void);

/**
 *  TELA DE CRIAÇÃO DE DESPERTADOR
 * .---------------------.
 * :                     :
 * :---------------------:
 * :   [00:00:00.000]    : -> [ ] -> editando um timer:
 * : mode:               : um sublinhado inversao nas cores indicam
 * :                     : o campo que está sendo editado.
 * :                     :
 * '---------------------' Ações: incremento, decremento, próximo, cancelar.
 */
void ui_screen_create_timer(void);

void ui_screen_change(screen_t * screen);
void ui_init(void);
void ui_update(void);


#endif /* ifndef _UI_H_ */
