#include <stdio.h>
#define MAXLENGTH 1000
#define CONTAIN 1
#define NOT_CONTAIN 0

void squeeze(char s1[], char s2[]);
int getline2(char s[], int lim);

void main(void) {
    int len;
    char line[MAXLENGTH];
    
    while((len = getline2(line, MAXLENGTH)) != 0) {
        squeeze(line, "ab");
        printf("%s\n", line);
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

void squeeze(char s1[], char s2[]) {
    int i, j, k, state;

    k = 0;
    for (i=0; s1[i] != '\0'; i++) {
        state = NOT_CONTAIN;
        for (j=0; s2[j] != '\0'; j++) {
            if (s1[i] == s2[j])
                state = CONTAIN;
        }
        if (state == NOT_CONTAIN)
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
}
