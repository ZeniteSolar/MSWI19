/**
 * @file bit_utils.h
 *
 * @defgroup BIT_UTILS Bit Utils
 *
 * @brief The basic bitwork a little bit easier using this.
 *
 */
#ifndef _BIT_UTILS_H_
#define _BIT_UTILS_H_

// FROM AVR:  http://www.atmel.com/webdoc/avrlibcreferencemanual/ch20s22s02.html
// #define bit_is_set(sfr,bit)              (_SFR_BYTE(sfr) & _BV(bit)) 
// #define bit_is_clear(sfr,bit)            (!(_SFR_BYTE(sfr) & _BV(bit)))
// #define loop_until_bit_is_clear(sfr,bit) do { } while (bit_is_set(sfr, bit))  
// #define loop_until_bit_is_set(sfr,bit)   do { } while (bit_is_clear(sfr, bit)) 
// #define _BV(bit)                         (1 << (bit))

/**
 * @brief Changes the nth bit 'bit' to 1 of an address/variable 'y'.
 */
#define set_bit(y,bit)  (y|=(1<<(bit)))

/**
 * @brief Changes the nth bit 'bit' to 0 of an address/variable 'y'.
 */ 
#define clr_bit(y,bit)  (y&=~(1<<(bit)))

/**
 * @brief Changes the nth bit 'bit' of an address/variable 'y' to its logical complement (from 0 to 1, from 1 to 0).
 */ 
#define cpl_bit(y,bit)  (y^=(1<<(bit)))

/**
 * @brief Returns '1' if the nth bit 'bit' of an address/variable 'y' is '1',
 * 0 otherwise.
 */ 
#define tst_bit(y,bit)  (y&(1<<(bit)))

/**
 * @brief Returns the low byte from a word
 */
#define LOW(y)          (y&0xFF)

/**
 * @brief Returns the high byte from a word
 */
#define HIGH(y)         ((y>>8)&0xFF)

/**
 *  Concatena dois bytes 
 */
#define HIGH_LOW(z, y, x)     (z = (y << 8) | (x));

/**
 *  Detecta borda de subida
 */
#define RISING_EDGE(_new, _old)      (((_new) ^ (_old)) & (_new))

/**
 *  Detecta borda de subida
 */
#define FALLING_EDGE(_new, _old)      (((_new) ^ (_old)) & (_old))


/**
 *  Detecta borda de subida e descida
 */
#define ANY_EDGE(_new, _old)      ((_new) ^ (_old))

#endif /* ifndef _BIT_UTILS_H_*/
