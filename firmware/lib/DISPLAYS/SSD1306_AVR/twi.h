#ifndef TWI_H_
#define TWI_H_

#ifdef __cplusplus
extern C {
#endif // __cplusplus

#include <avr/io.h>
#include <ctype.h>

#define F_SCL 100000

void TWI_Init(void);
void TWI_Start(void);
void TWI_Stop(void);
void TWI_SendByte(uint8_t data);
void TWI_SendAddress(uint8_t addr);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // TWI_H_
