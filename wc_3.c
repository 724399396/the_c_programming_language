#include <stdio.h>

void main(void) {
    long blank, tab, newline;
    int c;

    blank = tab = newline = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ')
            blank++;
        if (c == '\t')
            tab++;
        if (c == '\n')
            newline++;
    }

    printf("blanks: %ld, tabs: %ld, newlines: %ld\n", blank, tab, newline);
}
