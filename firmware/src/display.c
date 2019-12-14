#include "display.h"

/**
 * @brief starts the display.
 */
void display_init(void)
{
	lcd_init(LCD_DISP_ON);
    lcd_set_contrast(0xFF);
}

inline void display_clear(void)
{
    lcd_clrscr();
}

/**
 * @brief test the display
 */
void display_test(void)
{
    uint8_t i,j;
    lcd_clrscr();
    for(i = 0; i<8; i++) 
    for(j = 0; j<21;){
        lcd_gotoxy(j,i);
        lcd_puts(" ");
        lcd_gotoxy(++j,i);
        lcd_puts("ZENITE");
    }

    display_send_string("Zenite", 4, 1, font_big);
    _delay_ms(250);
    
    display_send_string("Solar", 5, 3, font_big);
    _delay_ms(250);

    display_send_string("2020", 6, 5, font_big);
    _delay_ms(500);
}

/**
 * @brief sends a char array
 * The strings are limited in 255 chars and MUST terminate with '\0'.
 */
void display_send_string(char *s, uint8_t x, uint8_t y, display_font_size_t size)
{
    lcd_charMode(size);
    lcd_gotoxy(x,y);
    lcd_puts(s);
}

/**
* @brief sends a number in ascii.
* The number could be represent with left-filled with a defined FILL char in
* a defined BASE. Note that the LEN is 6 because 2^16 have its maximum ascii
* size represented with 5 chars + '\0' in the end.
*/
void display_send_uint8(uint8_t num, uint8_t x, uint8_t y, display_font_size_t size)
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
    display_send_string(str, x, y, size);       // sends the string

    #undef LEN
    #undef BASE
    #undef FILL
}

void display_send_int8(int8_t num, uint8_t x, uint8_t y, display_font_size_t size)
{
    #define LEN     4              // length of the string w/ null terminator
    #define BASE    10              // string as a decimal base
    #define FILL    '0'             // character to fill non-used algarisms.

    uint8_t i = LEN -1;             // index for each char of the string
    char str[LEN] = {FILL};         // ascii zero filled array

    if(num < 0){
        str[0] = '-';
        num = -num;
    }else{
        str[0] = '+';
    }

    str[i] = '\0';                  // adds string null terminator
    while(i--){
        str[i] = FILL + (num % BASE);// gets each algarism}
        num /= BASE;                // prepare the next
    }
    display_send_string(str, x, y, size);         // sends the string

    #undef LEN
    #undef BASE
    #undef FILL
}

/**
 * @brief sends a number in ascii.
 * The number could be represent with left-filled with a defined FILL char in
 * a defined BASE. Note that the LEN is 6 because 2^16 have its maximum ascii
 * size represented with 5 chars + '\0' in the end.
 */
void display_send_uint16(uint16_t num, uint8_t x, uint8_t y, display_font_size_t size)
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
    display_send_string(str, x, y, size);       // sends the string

    #undef LEN
    #undef BASE
    #undef FILL
}

void display_send_int16(int16_t num, uint8_t x, uint8_t y, display_font_size_t size)
{
    #define LEN     7              // length of the string w/ null terminator
    #define BASE    10              // string as a decimal base
    #define FILL    '0'             // character to fill non-used algarisms.

    uint8_t i = LEN -1;             // index for each char of the string
    char str[LEN] = {FILL};         // ascii zero filled array

    if(num < 0){
        str[0] = '-';
        num = -num;
    }else{
        str[0] = '+';
    }

    str[i] = '\0';                  // adds string null terminator
    while(i--){
        str[i] = FILL + (num % BASE);// gets each algarism}
        num /= BASE;                // prepare the next
    }
    display_send_string(str, x, y, size);         // sends the string

    #undef LEN
    #undef BASE
    #undef FILL
}

/**
 * @brief sends a number in ascii.
 * The number could be represent with left-filled with a defined FILL char in
 * a defined BASE. Note that the LEN is 11 because 2^32 have its maximum ascii
 * size represented with 10 chars + '\0' in the end.
 */
void display_send_uint32(uint32_t num, uint8_t x, uint8_t y, display_font_size_t size)
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
    display_send_string(str, x, y, size);       // sends the string

    #undef LEN
    #undef BASE
    #undef FILL
}

void display_send_int32(int32_t num, uint8_t x, uint8_t y, display_font_size_t size)
{
    #define LEN     12              // length of the string w/ null terminator
    #define BASE    10              // string as a decimal base
    #define FILL    '0'             // character to fill non-used algarisms.

    uint8_t i = LEN -1;             // index for each char of the string
    char str[LEN] = {FILL};         // ascii zero filled array
    char sign = ' ';

    if(num < 0){
        sign = '-';
        num = -num;
    }

    str[i] = '\0';                  // adds string null terminator
    while(i--){
        str[i] = FILL + (num % BASE);// gets each algarism}
        num /= BASE;                // prepare the next
    }

    str[0] = sign;

    display_send_string(str, x, y, size);         // sends the string

    #undef LEN
    #undef BASE
    #undef FILL
}

/**
 * @brief sends a float number in ascii trough serial.
 */
inline void display_send_float(float num, uint8_t x, uint8_t y, display_font_size_t size)
{
    #define LEN     7               // length of the string w/ sign, dot ('.') and null terminator
    #define PREC    3               // precision: digits before dot. 

    char str[LEN];

    dtostrf(num, LEN, PREC, str);   // uses the avr-lib function (for doubles)

    display_send_string(str, x, y, size); // sends the string
}


