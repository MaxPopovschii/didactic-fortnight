#include "bitset.h"

void bitset_init(BitSet *bs) {
    for (size_t i = 0; i < sizeof(bs->bits); i++)
        bs->bits[i] = 0;
}

void bitset_set(BitSet *bs, size_t pos) {
    bs->bits[pos / 8] |= (1 << (pos % 8));
}

void bitset_clear(BitSet *bs, size_t pos) {
    bs->bits[pos / 8] &= ~(1 << (pos % 8));
}

int bitset_test(const BitSet *bs, size_t pos) {
    return (bs->bits[pos / 8] & (1 << (pos % 8))) != 0;
}
