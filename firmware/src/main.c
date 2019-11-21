// coding: utf-8

#include "main.h"

int main(void)
{
    _delay_ms(1000);

    #ifdef USART_ON
        usart_init(MYUBRR,0,1);                         // inicializa a usart
        VERBOSE_MSG_INIT(usart_send_string("\n\n\nUSART... OK!\n"));
    #endif

    // reset as input pull-up against noise
    clr_bit(DDRC, PC6);
    set_bit(PORTC, PC6);
	
	for(;;){
        usart_send_string("Hello World!\n");
        _delay_ms(100);
	}
}


/**
 * @brief se em debug, fica chaveando os pinos de debugs até o reset do watchdog
 */
ISR(BADISR_vect)
{
    for(;;){
        VERBOSE_MSG_ERROR(usart_send_string("\nFATAL ERROR: BAD ISR."));
        #ifdef WATCHDOG_ON
            VERBOSE_MSG_ERROR(usart_send_string("WAITING FOR WATCHDOG TO RESET...\n"));
        #endif
        #ifdef DEBUG_ON
            DEBUG0;
            DEBUG1;
            _delay_ms(100);
        #endif
    }
}

