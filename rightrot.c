#include <stdio.h>

unsigned int rightrot(unsigned int x, int n);
int right(int x, int y);

void main(void) {
    printf("%d %d\n", 45, rightrot(87, 4));
}

unsigned int rightrot(unsigned int x, int n) {
    int i, mask1, mask2, y;

    y=x;
    for (i = 0; i < n; i++) {
        mask1 = (1 << i);
        mask2 = (1 << n-i-1);
        y = (~mask2 & y) | right((x & mask1), n-1-i*2);
        printf("%d %d %d\n", mask1, mask2, y);
    }
    return y;
}

int right(int x, int y) {
    if (y >= 0)
        return x << y;
    else
        return x >> -y;
}
