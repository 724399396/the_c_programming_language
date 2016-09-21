#include <stdio.h>
#include <string.h>

void itob(int n, char s[], int b);
int itoc(int i);
void reverse(char s[]);

void main(void) {
    char s[200];

    itob(238767, s, 16);
    printf("%s\n", s);
}

void itob(int n, char s[], int b) {
    int sign, i;

    i = 0;
    if ((sign = n) < 0)
        n = -n;
    do {
        s[i++] = itoc(n % b);
    } while ((n /= b) != 0);
    
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
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
