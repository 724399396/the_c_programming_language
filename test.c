#include <stdio.h>

void main(void) {
    char* c = "abc";
    int a = 10;

    printf("%ld %ld %ld\n", (int)c, &c, *c);
    printf("%ld %ld\n", (int)a, &a);
}
