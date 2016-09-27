#include <stdio.h>

int mystrncmp(char *, char *, int);

void main(void) {
    char *s = "abcdef";
    char *t = "abc";

    printf("%d\n", mystrncmp(s,t,4));
}

int mystrncmp(char *s, char *t, int n) {
    
    for (; *s == *t && n > 0; n--, s++, t++)
        ;
    if (n == 0)
        return 1;
    return *s - *t;
}
