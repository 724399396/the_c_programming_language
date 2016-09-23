#include <stdio.h>
#define MAXLENGTH 1000

int getline2(char s[], int lim);
void reverse(char s[]);
int rec_reverse(char s[], int i);

void main(void) {
    int len;
    char line[MAXLENGTH];
    
    while((len = getline2(line, MAXLENGTH)) != 0) {
        rec_reverse(line, 0);
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

int rec_reverse(char s[], int i) {
    int j;
    char c;

    c = s[i];
    if (s[i] == '\0' || s[i] == '\n') 
        j = -1;
    else  {        
        j = rec_reverse(s, i+1);
        s[j] = c;
    }

    return j+1;
}
