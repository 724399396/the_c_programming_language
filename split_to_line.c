#include <stdio.h>
#define IN 0
#define OUT 1

void main(void) {
    int c,state;
    state = OUT;

    while((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            if (state == IN)
                putchar('\n');
            state = OUT;
        } else {
            state = IN;
            putchar(c);
        }
    }
}
