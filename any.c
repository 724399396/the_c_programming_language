#include <stdio.h>
#define MAXLENGTH 1000
#define SAME 1
#define NOT_SAME 0

int any(char s1[], char s2[]);
int getline2(char s[], int lim);

void main(void) {
    int len;
    char line[MAXLENGTH];
    
    while((len = getline2(line, MAXLENGTH)) != 0) {
        printf("%d\n", any(line, "ab"));
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

int any(char s1[], char s2[]) {
    int i, j, k, state;

    for (i=0; s1[i] != '\0'; i++) {
        state = SAME;
        for (j=0, k=i; s2[j] != '\0' && s1[k] != '\0'; k++, j++) {
            if (s1[k] != s2[j])
                state = NOT_SAME;
        }
        if (state == SAME && s2[j] == '\0')
            return i;
    }
    return -1;
}
