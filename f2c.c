#include <stdio.h>

void main(void) {
    float f, c;
    float lower, upper, step;
    printf("%3s %7s\n", "fahr", "celsius");

    lower = 0;
    upper = 300;
    step = 20;

    f = lower;
    while (f <= upper) {
        c = (5.0/9.0) * (f-32);
        printf("%4.0f %7.1f\n", f, c);
        f += step;
    }
}
