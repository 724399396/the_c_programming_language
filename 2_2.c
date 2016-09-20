#include <stdio.h>
#define MAXLENGTH 1000

int getline2(char s[], int lim);

void main(void) {
    int len;
    char line[MAXLENGTH];
    
    while((len = getline2(line, MAXLENGTH)) != 0) {
        printf("%s", line);        
   }
}

int getline2(char s[], int lim) {
    int i, c;

    i = 0;
    while (i < lim -1) {
        if ((c = getchar()) != EOF) {
            if (c != '\n') {
                s[i++] = c;
            } else {
                break;
            }            
        } else {
            break;
        }
    }
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}
