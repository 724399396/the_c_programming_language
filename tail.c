#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINE 1000

char *alloc(int n);
int getline2(char [], int);

int main(int argc, char *argv[]) {
    int n = 10, i, j;

    if (argc != 2)
        printf("Usage: tail -n\n");
    else {
        while (--argc > 0 && (*++argv)[0] == '-')
            n = atoi(++(*argv));
    
        char *lines[n], line[MAXLINE], *p;
    
        i = 0;
        while(getline2(line, MAXLINE) > 0) {
            p = alloc(MAXLINE);
            strcpy(p, line);
            
            i++;
            if (i > n) {
                for (j = 0; j < n-1; j++)
                    lines[j] = lines[j+1];
                lines[n-1] = p;
                i = 0;
            } else {
                lines[i-1] = p;
            }
        }
        for (j = 0; j < n; j++)
            printf("%s", lines[j]);
    }
}
