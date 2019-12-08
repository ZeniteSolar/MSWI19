/**
 * @file input.h
 *
 * @defgroup INPUT Input Module
 *
 * @desc
 *
 */
#ifndef INPUT_H
#define INPUT_H

#include "io.h"

typedef enum {
    sw0, sw1, sw2, sw3, sw4, sw5, sw6, sw7, sw8, sw9, input_length,
} input_names_t;

void inputs_update(void);
void input_assign_callback(input_names_t input, void *function, void *argument);

#endif /* ifndef INPUT_H */
