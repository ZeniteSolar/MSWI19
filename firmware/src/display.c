#include "display.h"

/**
 * @brief starts the display.
 */
void display_init(void)
{
    SSD1306_Init();
}

void display_clear(void)
{
    LCD_Fill(0);
}

void display_update(void)
{
    LCD_UpdateScreen();
}

#define line1   8
#define line2   25
#define line3   40
#define line4   55
#define col1    0
#define col2    18
#define col3    65
#define col4    83

void display_layout(void)
{
    LCD_Line(0, 13, LCD_WIDTH, 13, 1);
    LCD_Line(LCD_WIDTH/2, 0, LCD_WIDTH/2, LCD_HEIGHT, 1);

    display_send_string("BAT.", col2, line1);
    display_send_string("M", col1, line2);
    display_send_string("A", col1, line3);
    display_send_string("E", col1, line4);

    display_send_string("CURR.", col4, line1);
    display_send_string(">", col3, line2);
    display_send_string("<", col3, line3);
    display_send_string("T", col3, line4);

    /*
    display_send_uint16(43218, col2, line2);
    display_send_uint16(12657, col2, line3);
    display_send_uint16(13014, col2, line4);

    display_send_uint16(9872, col4, line2);
    display_send_uint16(10421, col4, line3);
    */
}

/**
 * @brief test the display
 */
void test_display(void)
{
    LCD_Fill(1);
    display_update();
    _delay_ms(250);

    display_clear();
    LCD_Font(15, 27, "Zenite", normal_font, 2, 1);
    LCD_Font(45, 42, "Solar", normal_font, 2, 1);
    LCD_Font(75, 57, "2019", normal_font, 2, 1);
    display_update();
    _delay_ms(250);

    LCD_ToggleInvert();
    display_update();
    _delay_ms(250);

    LCD_ToggleInvert();

}

/**
 * @brief sends a char array
 * The strings are limited in 255 chars and MUST terminate with '\0'.
 */
void display_send_string(char *s, uint8_t x, uint8_t y)
{
    LCD_Font(x, y, s, normal_font, 2, 1);
}

void display_send_string_big_font(char *s, uint8_t x, uint8_t y)
{
    LCD_Font(x, y, s, big_font, 2, 1);
}

/**
* @brief sends a number in ascii.
* The number could be represent with left-filled with a defined FILL char in
* a defined BASE. Note that the LEN is 6 because 2^16 have its maximum ascii
* size represented with 5 chars + '\0' in the end.
*/
void display_send_uint8(uint8_t num, uint8_t x, uint8_t y)
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
    display_send_string(str, x, y);       // sends the string

    #undef LEN
    #undef BASE
    #undef FILL
}

void display_send_int8(int8_t num, uint8_t x, uint8_t y)
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
    display_send_string(str, x, y);         // sends the string

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
void display_send_uint16(uint16_t num, uint8_t x, uint8_t y)
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
    display_send_string(str, x, y);       // sends the string

    #undef LEN
    #undef BASE
    #undef FILL
}

void display_send_int16(int16_t num, uint8_t x, uint8_t y)
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
    display_send_string(str, x, y);         // sends the string

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
void display_send_uint32(uint32_t num, uint8_t x, uint8_t y)
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
    display_send_string(str, x, y);       // sends the string

    #undef LEN
    #undef BASE
    #undef FILL
}

void display_send_int32(int32_t num, uint8_t x, uint8_t y)
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

    display_send_string(str, x, y);         // sends the string

    #undef LEN
    #undef BASE
    #undef FILL
}

/**
 * @brief sends a float number in ascii trough serial.
 */
inline void display_send_float(float num, uint8_t x, uint8_t y)
{
    #define LEN     7               // length of the string w/ sign, dot ('.') and null terminator
    #define PREC    3               // precision: digits before dot. 

    char str[LEN];

    dtostrf(num, LEN, PREC, str);   // uses the avr-lib function (for doubles)

    display_send_string(str, x, y); // sends the string
}


