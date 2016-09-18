#include <stdio.h>

void main(void) {
    float f, c;
    float lower, upper, step;
    printf("%7s %8s\n", "celsius", "fahr");

    lower = 0;
    upper = 300;
    step = 20;

    c = lower;
    while (c <= upper) {
        f = (9.0/5.0) * c + 32;
        printf("%7.0f %8.1f\n", c, f);
        c += step;
    }
}
