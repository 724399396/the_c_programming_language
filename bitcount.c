#include <stdio.h>

int bitcount(unsigned x);

void main(void) {
    printf("%d\n", bitcount(239));
}

int bitcount(unsigned x) {
    int i;

    for(i = 0; x != 0; x &= (x-1), i++)
        ;
    return i;
}
