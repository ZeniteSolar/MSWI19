#include "usart.h"

/**
 * @brief sends a char through serial
 * @param data will be sent trough serial
 */
inline void usart_send_char(char data)
{
    while(!(UCSR0A & (1<<UDRE0)));
    UDR0 = data;
}

/**
 * @brief gets data from serial. But BEWARE - it freezes until receive something
 */
inline char usart_receive_char(void)
{
    while(!(UCSR0A & (1<<RXC0)));
    return UDR0;
}

/**
 * @brief sends a char array roght serial.
 * The strings are limited in 255 chars and MUST terminate with '\0'.
 */
inline void usart_send_string(const char *s)
{
    uint8_t i = 0;  
    while(s[i] != '\0') usart_send_char(s[i++]);
}

/**
* @brief sends a number in ascii trough serial.
* The number could be represent with left-filled with a defined FILL char in 
* a defined BASE. Note that the LEN is 6 because 2^16 have its maximum ascii
* size represented with 5 chars + '\0' in the end.
*/
inline void usart_send_uint8(uint8_t num)
{
    #define LEN      4              // length of the string w/ null terminator
    #define BASE    10              // string as a decimal base
    #define FILL    '0'             // character to fill non-used algarisms.
    
    uint8_t i = LEN -1;             // index for each char of the string
    char str[LEN] = {FILL};         // ascii zero filled array
    str[i] = '\0';                  // adds string null terminator
    while(i--){
        str[i] = FILL + (num % BASE);// gets each algarism}
        num /= BASE;                // prepare the next
    }
    usart_send_string(str);       // sends the string
    
    #undef LEN
    #undef BASE
    #undef FILL
}

/**
 * @brief sends a number in ascii trough serial.
 * The number could be represent with left-filled with a defined FILL char in 
 * a defined BASE. Note that the LEN is 6 because 2^16 have its maximum ascii
 * size represented with 5 chars + '\0' in the end.
 */
inline void usart_send_uint16(uint16_t num)
{
    #define LEN      6              // length of the string w/ null terminator
    #define BASE    10              // string as a decimal base
    #define FILL    '0'             // character to fill non-used algarisms.
    
    uint8_t i = LEN -1;             // index for each char of the string
    char str[LEN] = {FILL};         // ascii zero filled array
    str[i] = '\0';                  // adds string null terminator
    while(i--){
        str[i] = FILL + (num % BASE);// gets each algarism}
        num /= BASE;                // prepare the next
    }
    usart_send_string(str);       // sends the string
    
    #undef LEN
    #undef BASE
    #undef FILL
}

/**
 * @brief sends a number in ascii trough serial.
 * The number could be represent with left-filled with a defined FILL char in 
 * a defined BASE. Note that the LEN is 11 because 2^32 have its maximum ascii
 * size represented with 10 chars + '\0' in the end.
 */
inline void usart_send_uint32(uint32_t num)
{
    #define LEN     11              // length of the string w/ null terminator
    #define BASE    10              // string as a decimal base
    #define FILL    '0'             // character to fill non-used algarisms.
    
    uint8_t i = LEN -1;             // index for each char of the string
    char str[LEN] = {FILL};         // ascii zero filled array
    str[i] = '\0';                  // adds string null terminator
    while(i--){
        str[i] = FILL + (num % BASE);// gets each algarism}
        num /= BASE;                // prepare the next
    }
    usart_send_string(str);       // sends the string
    
    #undef LEN
    #undef BASE
    #undef FILL
}
 
/**
 * @brief sends a buffer through serial. Max lenght is 255.
 */
inline void usart_send_buffer(uint8_t *b, uint8_t lenght)
{
    uint8_t i = 0;
    while(i < lenght) usart_send_char(b[i++]);
}

/**
 * @brief starts the usart.
 * @param ubrr is the baudrate
 * @param rx enables the receive
 * @param tx enables the transmit
 * it is recommended to use the following defines:
 * @code
 *      #define USART_BAUD 9600
 *      #define MYUBRR F_CPU/16/USART_BAUD-1
 *      usart_init(MYUBRR,1,1);
 * @endcode
 */
inline void usart_init(uint16_t ubrr, uint8_t rx, uint8_t tx)
{
    // set BAUDRATE
    UBRR0H = (uint8_t)(ubrr >>8);
    UBRR0L = (uint8_t)ubrr;
    
    // Enable RX and TX
    UCSR0B = ((rx&1)<<RXEN0) | ((tx&1)<<TXEN0);
}

