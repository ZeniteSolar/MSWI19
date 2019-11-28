/**
 * @file log2.h
 *
 * @defgroup LOG2 Log2
 *
 * @brief computing log2 is quite simple in microcontrollers but sometime we
 * just miss it.
 *
 */

#ifndef _LOG2_H_
#define _LOG2_H_

/**
 * @brief computes the log2 from the number n as r = log2(n)
 *          The benefit from using a macro implementation is that it is 
 *          independet from the sizeof(n). And also it is always inline.
 * @param[in] n is the input for log2(n)
 * @param[out] r is the output from log2(n)
 */
#define log2(r,n)   while((n)>>=1)(r)++;
// to implement as a C function:
/*inline uint8_t log2(uint8_t n)
{            
    uint8_t r = 0;
    while (n >>= 1) r++;
    return r;
}*/

#endif
