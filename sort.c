#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void myqsort(char *lineptr[], int left, int right);

int main() {
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        myqsort(lineptr, 0, nlines-1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
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

void myqsort(char *lineptr[], int left, int right) {
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    
    swap(lineptr, left, (left+right)/2);
    last = left;
    for (i = left+1; i <= right; i++)
        if (strcmp(lineptr[i], lineptr[left]) < 0)
            swap(lineptr, ++last, i);
    swap(lineptr, left, last);
    myqsort(lineptr, left, last -1);
    myqsort(lineptr, last+1, right);
}

void swap(char *v[], int i, int j) {
    char *tmp;

    tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}
