#include <stdio.h>
#define MAXLENGTH 1000

int getline2(char s[], int lim);
int trim_trailing(char s[]);

void main(void) {
    int len;
    char line[MAXLENGTH];
    
    while((len = getline2(line, MAXLENGTH)) != 0) {
        len = trim_trailing(line);
        if (len > 0) {
            printf("%s", line);
        }
   }
}

int getline2(char s[], int lim) {
    int i, c;

    for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int trim_trailing(char s[]) {
    int i;
    
    for(i = 0; s[i] != '\0'; i++)
        ;
    
    for(i--; s[i] == '\t' || s[i] == '\n' || s[i] == ' '; i--)
        s[i] = '\0';

    return i+1;
}
