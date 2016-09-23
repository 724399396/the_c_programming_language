#include <ctype.h>
#include <stdio.h>
#include "calc.h"

int getop(char s[]) {
    int i, c;
    static int lc = EOF;

    if (lc != EOF && lc != ' ' && lc != '\t'
        && !isdigit(c) && lc != '.') {
        c = lc;
        lc = EOF;
        s[1] = '\0';
        return c;
    }

    if (lc == EOF || lc == ' ' || c == '\t')
        while ((s[0] = c = getch()) == ' ' || c == '\t')
            ;
    else
        s[0] = c = lc;
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        lc = c;
    return NUMBER;
}
