#include <ctype.h>
#include <stdio.h>
#define NUMBER '0'
#define BUFSIZE 100

int getch();
void ungetch(int);
void ungets(char s[]);

int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
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
        ungetch(c);
    return NUMBER;
}


char buf[BUFSIZE];
int bufp = 0;

int getch() {
  if (bufp > 0)
      return buf[--bufp];
  else
      return getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE)
      printf("ungetch: too many characters\n");
  else
      buf[bufp++] = c;
}

void ungets(char s[]) {
  int i;

  for (i = 0; s[i] != '\0'; i++)
      ungetch(s[i]);
}
