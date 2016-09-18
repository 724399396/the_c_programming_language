#include <stdio.h>
#define LOWER 0
#define UPPER 300
#define STEP 20

void main(void) {
    int f;
    for(f = UPPER; f >= LOWER; f -= STEP)
        printf("%3d %6.1f\n", f, (5.0/9.0)*(f-32));
}
