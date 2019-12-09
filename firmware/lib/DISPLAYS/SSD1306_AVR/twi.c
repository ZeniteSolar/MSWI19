#include "twi.h"

void TWI_Init(void)
{
	TWBR0 = (((F_CPU)/(F_SCL)-16) >> 1);
	TWSR0 = 0;
}

void TWI_Start(void){
	TWCR0 = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while (!(TWCR0 & (1<<TWINT))){};
}

void TWI_Stop(void){
	TWCR0 = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void TWI_SendByte(uint8_t data){
	TWDR0 = data;
	TWCR0 = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR0 & (1<<TWINT))){};
}

void TWI_SendAddress(uint8_t addr) {
	TWDR0 = (addr<<1)|0;
	TWCR0 = (1<<TWINT)|(1<<TWEN);
	while (!(TWCR0 & (1<<TWINT))){};
}
