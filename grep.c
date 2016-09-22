#include <stdio.h>
#define MAXLINE 1000

int getline2(char s[], int lim);
int strindex(char s[], char t[]);
int strindexright(char s[], char t[]);

char pattern[] = "ould";

int main() {
    int found = 0;
    char s[MAXLINE];
    
    while (getline2(s, MAXLINE) > 0) {
        if (strindex(s, pattern) > 0) {
            printf("%s", s);
            found++;
        }
        printf("%d\n", strindexright(s, pattern));
    }
    return found;
}

int getline2(char s[], int lim) {
    int c, i;
    
    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;

    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;    
}

int strindex(char s[], char t[]) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) {
        for (k = 0, j = i; t[k] != '\0' && t[k] == s[j]; k++, j++)
            ;
        if (t[k] == '\0')
            return i;
    }
    return -1;
}

int strindexright(char s[], char t[]) {
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++) 
        ;

    for (; i >= 0; i--) {
        for (k = 0, j = i; t[k] != '\0' && t[k] == s[j]; k++, j++)
            ;
        if (t[k] == '\0')
            return i;
    }
    return -1;
}
