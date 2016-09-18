#include <stdio.h>

void main(void) {
    int c;
    int pre = EOF;

    while((c = getchar()) != EOF) {
        if (!(pre == ' ' && c == ' ')) {
             putchar(c);
        }
        pre = c;
    }
}
