#include <stdio.h>

int atoi(char s[]);
int lower(int c);
int htoi(char s[]);

void main(void) {
    printf("%d %d\n", 0x3fa2, htoi("0x3fa2"));
}

int atoi(char s[]) {
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
        n = 10 * n + (s[i] - '0');
    return n;
}

int lower(int c) {
    return (c >= 'A' && c <= 'Z') ? c - 'A' + 'a' : c;
}

int htoi(char s[]) {
    int i, n;
    
    i = 0;
    if (s[0] == '0')
        if (s[1] == 'x' || s[1] == 'X')
            i = 2;

    for (n = 0; (s[i] >= '0' && s[i] <= '9') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'); i++) {
        if (s[i] >= '0' && s[i] <= '9')
            n = n * 16 + (s[i] - '0');
        else if (s[i] >= 'a' && s[i] <= 'z')
            n = n * 16 + (s[i] - 'a' + 10);
        else
            n = n * 16 + (s[i] - 'A' + 10);
    }
    
    return n;
}
