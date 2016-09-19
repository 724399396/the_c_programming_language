#include <stdio.h>
#define IN_COMMENT 0
#define OUT_COMMENT 1
#define IN_STRING 2
#define SHORT_COMMENT 3
#define MAX_LENGTH 1000

int state;

int getline2(char s[], int lim);
int removeComment(char from[], char to[]);

void main(void) {
    int len;
    extern int state;
    char line[MAX_LENGTH], after[MAX_LENGTH];

    state = OUT_COMMENT;
    while ((len = getline2(line, MAX_LENGTH)) != 0)
        if (removeComment(line, after) > 0)
            printf("%s", after);
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

int removeComment(char from[], char to[]) {
    int i, j;
    extern int state;

    for(i = 0, j = 0; from[i] != '\0'; i++) {
        if (state == OUT_COMMENT) {
            if (from[i] == '/' && from[i+1] == '/') {
                state = SHORT_COMMENT;
                i++;
            } else if (from[i] == '/' && from[i+1] == '*') {
                state = IN_COMMENT;
                i++;
            } else if (from[i] == '"') {
                to[j++] = from[i];
                state = IN_STRING;
            } else
                to[j++] = from[i];
        } else if (state == IN_COMMENT) {
            if (from[i] == '*' && from[i+1] == '/') {
                state = OUT_COMMENT;
                i++;
            }
        } else if (state == IN_STRING) {
            if (from[i] == '"') {             
                state = IN_STRING;
            }
            to[j++] = from[i];
        } else if (state == SHORT_COMMENT) {
            if (from[i+1] == '\0')
                state = OUT_COMMENT;
        }
    }

   to[j] = '\0';
   return j;
}

