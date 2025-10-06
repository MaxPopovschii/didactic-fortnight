#ifndef BITSET_H
#define BITSET_H

#include <stddef.h>
#define BITSET_SIZE 128

typedef struct {
    unsigned char bits[BITSET_SIZE / 8];
} BitSet;

void bitset_init(BitSet *bs);
void bitset_set(BitSet *bs, size_t pos);
void bitset_clear(BitSet *bs, size_t pos);
int  bitset_test(const BitSet *bs, size_t pos);

#endif // BITSET_H
