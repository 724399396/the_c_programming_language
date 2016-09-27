#include <stdio.h>
#include <limits.h>


void atoi(long n, char s[]);
void atoip(long n, char *s);
void reverse(char s[]);

void main(void) {
    char s[200];
    
    atoi(INT_MIN, s);
    printf("%s\n", s); 
}

void atoi(long n, char s[]) {
    int sign,i;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ( (n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void atoip(long n, char *s) {
    int sign,i;
    
    if ((sign = n) < 0)
        n = -n;
    do {
        *s++ = n % 10 + '0'
    } while ((n /= 10) > 0);
    if (sign < 0)
        *s++ = '-';
    *s = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int i, j, tmp;
    
    for(i = 0; s[i] != '\0'; i++)
        ;
    i--;

    while(s[i] == '\n')
        i--;

    for(j = 0; j <= i/2; i--, j++) {
        tmp = s[j];
        s[j] = s[i];
        s[i] = tmp;
    }
        
}
