#include <stdio.h>
#define IN 0
#define OUT 1

void main(void) {
    int c, nl, nw, nc, state;

    nl = nw = nc = 0;
    state = OUT;
    while ((c = getchar()) != EOF) {
        nc++;
        if (c == '\n')
            nl++;
        if (c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if (state == OUT) {
            state = IN;
            nw++;
        }           
    }

    printf("%d %d %d\n", nl, nw, nc);
}
