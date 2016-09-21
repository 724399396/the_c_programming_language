#include <stdio.h>

void escape(char s[], char t[]);

void main(void) {
    char s[10], t[10];

    s[0] = '\t';
    s[1] = 'a';
    s[2] = '\n';
    s[3] = 'b';
    s[4] = '\0';
    escape(s, t);
    printf("%s\n", s);
    printf("%s\n", t);
}

void escape(char s[], char t[]) {
    int i,j;
    
    for(i=0, j=0; s[i] != '\0'; i++)
        switch(s[i]) {
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case  '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            default:
                t[j++] = s[i];
                break;
        }
    t[j] = '\0';
}
