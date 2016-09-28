#include <stdio.h>
#include <string.h>
#define MAXLINE 1000

int getline2(char s[], int lim);
int strindex(char s[], char t[]);
int strindexright(char s[], char t[]);

int main(int argc, char *argv[]) {
    long lineno = 0;
    int c, found = 0, except = 0, number=0;
    char s[MAXLINE];
    
    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c) {
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }

    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
        while (getline2(s, MAXLINE) > 0) {
            lineno++;
            if ((strindex(s, *argv) >= 0) != except) {
                if (number)
                    printf("%ld ", lineno);
                printf("%s", s);
                found++;
                printf("%d\n", strindexright(s, argv[0]));
            }
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
