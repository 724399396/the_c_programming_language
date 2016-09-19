#include <stdio.h>
#define MAXLENGTH 1000

int getline2(char s[], int lim);
void reverse(char s[]);

void main(void) {
    int len;
    char line[MAXLENGTH];
    
    while((len = getline2(line, MAXLENGTH)) != 0) {
        reverse(line);
        printf("%s", line);        
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
