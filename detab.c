#include <stdio.h>
#define n 4

void main(void) {
    int c, i;

    while ((c = getchar()) != EOF)
        if (c == '\t')
            for(i = 0; i < n; i++)
                putchar(' ');
        else
            putchar(c);
    
}
