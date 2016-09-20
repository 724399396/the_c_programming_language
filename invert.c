#include <stdio.h>

unsigned int invert(unsigned int x, int p, int n);

void main(void) {
    printf("%d %d\n", 45, invert(45, 5, 4));
}

unsigned int invert(unsigned int x, int p, int n) {
    int mask, set;

    mask = (~(~0 << n)) << (p-n+1);

    return ((x & ~mask) | (~(x & mask) & mask));
}
