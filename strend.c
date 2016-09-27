#include <stdio.h>

int mystrend(char *s, char *t);

void main(void) {
    char s[10] = "abcdef";
    char t[] = "def";
    printf("%d\n", mystrend(s, t));
   
}

int mystrend(char *s, char *t) {
    int i, j;
    
    for (i = 0; s[i] != '\0'; i++)
        ;
    for (j = 0; t[j] != '\0'; j++)
        ;

    for (; j >= 0 && s[i] == t[j]; j--, i--)
        ;

    if (j == -1)
        return 1;
    return -1;
}
