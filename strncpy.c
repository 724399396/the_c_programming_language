#include <stdio.h>

void mystrncpy(char *, char *, int);

void main(void) {
    char s[10];
    char *t = "abcdef";

    mystrncpy(s, t, 5);
    printf("%s\n", s);
}

void mystrncpy(char *s, char *t, int n) {
    int i;
    for (i = 0; i < n && t[i] != '\0'; i++)
        s[i] = t[i];
    s[i] = '\0';
}
