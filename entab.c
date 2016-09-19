#include <stdio.h>
#define n 8

void main(void) {
    int c, i;

    i = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            i++;
            if (i == n) {
                i = 0;
                putchar('\t');
            }
        }
        else {
            if (i != 0) {
                for(; i > 0; i--)
                    putchar(' ');
            }
            putchar(c);
        }
    }
}
