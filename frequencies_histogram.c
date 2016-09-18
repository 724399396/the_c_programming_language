#include <stdio.h>

void main(void) {
    int c, i, nwhite, nother;
    int ndigit[10];
    
    nwhite = nother = 0;
    for(i = 0; i < 10; i++)
        ndigit[i] = 0;

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9')
            ++ndigit[c-'0'];
        else if (c == ' ' || c == '\t' || c == '\n')
            nwhite++;
        else
            nother++;
    }

    int j;
    for(i = 0; i < 10; i++) {
        printf("%c: ", i + '0');      
        for(j = 0; j < ndigit[i]; j++)
            putchar('>');
        putchar('\n');
    }             
    printf("whites: ");
    for(j = 0; j < nwhite; j++)
        putchar('>');
    putchar('\n');

    printf("others: ");
    for(j = 0; j < nother; j++)
        putchar('>');
    putchar('\n');
}
