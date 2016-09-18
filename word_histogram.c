#include <stdio.h>

void main(void) {
    int c, length, i;
    i = length = 0;

    while ((c = getchar()) != EOF) {
        length++;
    }

    for(i = 0; i < length; i++)
        putchar('>');
    putchar('\n');

    for(i = 0; i < length; i++)
        printf("#\n");
}
