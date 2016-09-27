#include <stdio.h>

void mystrncat(char *s, char *t, int n);

void main(void) {
    char s[10] = "abc";
    char t[] = "def";
    mystrncat(s, t, 1);
    printf("%s\n", s);
}

void mystrncat(char *s, char *t, int n) {    

    for (; *s != '\0'; s++)
        ;
    for (; n > 0 && *t != '\0'; t++, n--)
        *s++ = *t;

    *s = '\0';
}
