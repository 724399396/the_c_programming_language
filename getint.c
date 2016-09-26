#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);
int getint(int *pn);

void main(void) {
    int n, c;
    getint(&n);

    while((c = getch()) != EOF)
        putchar(c);
}

int getint(int *pn) {
    int sign, c, sc;

    sc = 0;
    while (isspace((c = getch())))
        ;
    
     if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
         ungetch(c);
         return 0;
     }

     sign = c == '-' ? -1 : 1;
     if (c == '+' || c == '-') {
         sc = c;
         c = getch();
     }
     for (*pn = 0; isdigit(c); c = getch() )
         *pn = *pn * 10 + (c - '0');
     *pn = *pn * sign;
     if (!(*pn) && sc)
         ungetch(sc);
     if (c != EOF)
         ungetch(c);
     return c;
}

