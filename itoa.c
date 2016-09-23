#include <stdio.h>
#include <string.h>

void itoa(int n, char s[], int len);
int itoc(int i);
void reverse(char s[]);
int itoa2(int n, char s[]);

void main(void) {
    char s[200] ,s2[200];

    itoa(238767, s, 16);
    printf("%s\n", s);
    itoa2(238767, s2);
    printf("%s\n", s2);
}

void itoa(int n, char s[], int len) {
    int sign, i;

    i = 0;
    if ((sign = n) < 0)
        n = -n;
    do {
        s[i++] = itoc(n % 10);
    } while ((n /= 10) != 0);
    
    if (sign < 0)
        s[i++] = '-';
    for(; i < len; i++)
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

int itoa2(int n, char s[]) {
    int j = 0;

    if (n < 0) {
        s[j++] = '-';
        n = -n;
    }        

    if (n/10)
        j = itoa2(n/10, s);
    s[j++] = n % 10 + '0';
    return j;
}

int itoc(int i) {
    if (i >= 0 && i <= 9)
        return '0' + i;
    if (i >= 10 && i <= 35)
        return 'a' + (i - 10);
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
