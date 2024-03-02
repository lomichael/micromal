/*
Functions for packing and unpacking bits in bytes.

- Basic bit manipulation functions for setting, clearing, toggling and testing bits.
- Bit manipulation techniques like bit rotation, bit counting manipulation of multiple bits at once for performance.
- SIMD optimizations for bit manipulation on modern processors.
*/

#ifndef BITOPS_H
#define BITOPS_H

#include <stdint.h>

void set_bit(uint8_t *byte, uint8_t bit);
void clear_bit(uint8_t *byte, uint8_t bit);
void toggle_bit(uint8_t *byte, uint8_t bit);
int get_bit(const uint8_t *byte, uint8_t bit);

unsigned int rotate_left(unsigned int value, unsigned int shift);
unsigned int rotate_right(unsigned int value, unsigned int shift);
unsigned int count_bits_set(unsigned int value);
void apply_mask_and_shift(unsigned int *byte, unsigned int mask, unsigned int shift);

#endif // BITOPS_H