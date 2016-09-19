#include <stdio.h>
#define LINE_LENGTH 10
#define TAB_LENGTH 4

void main(void) {
    int c, i;

    i = 0;
    while ((c = getchar()) != EOF) {
        if (i >= LINE_LENGTH) {
            i = 0;
            putchar('\n');
        }
        if (c == '\t')
            i = i+TAB_LENGTH;
        else
            i++;
        putchar(c);
    }
}
