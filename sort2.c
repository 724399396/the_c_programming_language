#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void myqsort(void *lineptr[], int left, int right, int (*)(void *, void *));

int numcmp(const char *v, const char *t);
int mystrcmp(const char *v, const char *t);

int reverse = 0;
int fold = 0;
int directory = 0;

int main(int argc, char *argv[]) {
    int nlines, number = 0, c;

    while (--argc > 0 && (*++argv)[0] == '-')        
        while(c = *++argv[0])
            switch(c) {
            case 'n':
                number = 1;
                break;
            case 'r':
                reverse = 1;
                break;
            case 'f':
                fold = 1;
                break;
            case 'd':
                directory = 1;
                break;
            defualt:
                printf("find: illegal option:%c\n", c);
                argc = 0;
                break;
            }
    
    if (argc != 0)
        printf("Usage: -n -r\n");
    else if (directory && fold)
        printf("-f -d can't appeare at same time\n");
    else {
        if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
            myqsort((void **)lineptr, 0, nlines-1, 
                    (int (*)(void *, void *))(number ? numcmp : (fold ? mystrcmp : strcasecmp)));
            writelines(lineptr, nlines);
            return 0;
        } else {
            printf("error: input too big to sort\n");
            return 1;
        }
    }
}

#define MAXLINE 1000
int getline2(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;

    char *p, line[MAXLINE];

    nlines = 0;
    while ((len = getline2(line, MAXLINE)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    while(nlines-- > 0)
        printf("%s\n", *lineptr++);
}

void myqsort(void *lineptr[], int left, int right, int (*comp)(void *, void *)) {
    int i, last;
    void swap(void *v[], int i, int j);

    if (left >= right)
        return;
    
    swap(lineptr, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (!reverse && ((*comp)(lineptr[i], lineptr[left]) < 0))
            swap(lineptr, ++last, i);
        else if (reverse && ((*comp)(lineptr[i], lineptr[left])) > 0)
            swap(lineptr, ++last, i);
    swap(lineptr, left, last);
    myqsort(lineptr, left, last -1, comp);
    myqsort(lineptr, last+1, right, comp);
}

void swap(void *v[], int i, int j) {
    void *tmp;

    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}

int numcmp(const char *a, const char *b) {
    int v1 = atoi(a);
    int v2 = atoi(b);
    
    if (v1 < v2)
        return -1;
    if (v1 > v2)
        return 1;
    return 0;
}

int mystrcmp(const char *a, const char *b) {
    if (directory) {
        while (!isdigit(*a) || !isalpha(*a) || !isspace(*a))
            a++;
        while (!isdigit(*b) || !isalpha(*b) || !isspace(*b))
            b++;
        while (*a == *b) {
            if (*a == '\0')
                return 0;
            a++;
            b++;
            while (!isdigit(*a) || !isalpha(*a) || !isspace(*a))
                a++;
            while (!isdigit(*b) || !isalpha(*b) || !isspace(*b))
                b++;            
        }
        return *a - *b;
    } else {
        return strcmp(a,b);
    }
}
