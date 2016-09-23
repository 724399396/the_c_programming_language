#include <stdio.h>
#include "calc.h"
#define BUFSIZE 100

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
