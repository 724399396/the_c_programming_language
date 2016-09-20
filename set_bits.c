#include <stdio.h>

unsigned int setbits(unsigned int x, int p, int n, int y);

void main(void) {
    printf("%d %d\n", 45, setbits(45, 5, 4, 0));
}

unsigned int setbits(unsigned int x, int p, int n, int y) {
    int mask, set;

    mask = (~(~0 << n)) << (p-n+1);

    if (y)
        set = mask;
    else
        set = 0;

    return ((x & ~mask) | set);
}
