#include <stdio.h>

void mystrcat(char *s, char *t);

void main(void) {
    char s[10] = "abc";
    char t[] = "def";
    mystrcat(s, t);
    printf("%s\n", s);
}

void mystrcat(char *s, char *t) {
    
    for (; *s != '\0'; s++)
        ;
    for (; *t != '\0'; t++)
        *s++ = *t;

    *s = '\0';
}
