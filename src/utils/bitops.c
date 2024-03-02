/*
Functions for packing and unpacking bits in bytes.

- Basic bit manipulation functions for setting, clearing, toggling and testing bits.
- Bit manipulation techniques like bit rotation, bit counting manipulation of multiple bits at once for performance.
- SIMD optimizations for bit manipulation on modern processors.
*/

#include <limits.h>
#include "bitops.h"

// ----- BELOW THIS LINE: GOOD TO GO -----

void set_bit(uint8_t *byte, uint8_t bit)
{
    *byte |= (1U << bit);
}

void clear_bit(uint8_t *byte, uint8_t bit)
{
    *byte &= ~(1U << bit);
}

void toggle_bit(uint8_t *byte, uint8_t bit)
{
    *byte ^= (1U << bit);
}

int get_bit(const uint8_t byte, uint8_t bit)
{
    return (byte >> bit) & 1U;
}

unsigned int rotate_left(unsigned int value, unsigned int shift)
{
    const unsigned int mask = (CHAR_BIT * sizeof(value) - 1);
    shift &= mask;
    return (value << shift) | (value >> ((-shift) & mask));
}

unsigned int rotate_right(unsigned int value, unsigned int shift)
{
    const unsigned int mask = (CHAR_BIT * sizeof(value) - 1);
    shift &= mask;
    return (value >> shift) | (value << ((-shift) & mask));
}

unsigned int count_bits_set(unsigned int value)
{
    unsigned int count = 0;
    for (count = 0; value; count++)
    {
        value &= value - 1;
    }
    return count;
}
// ----- ABOVE THIS LINE: GOOD TO GO -----