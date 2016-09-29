#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100

#define NKEYS (sizeof keytab / sizeof (keytab[0]))

struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    /* ... */
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0
};

int getword(char *, int);
int binsearch(char *, struct key *, int);

int main(void) {
    int c;
    char word[MAXWORD];
    
    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((c = binsearch(word, keytab, NKEYS) >= 0))
                keytab[c].count++;
            
    for (c = 0; c < NKEYS; c++)
        if (keytab[c].count > 0)          
            printf("%4d %s\n", keytab[c].count, keytab[c].word);

    return 0;            
}

int binsearch(char *c, struct key *keytab, int n) {
    int low, high, mid;
    int cond;
    
    low = 0;
    high = n-1;
    while (low <= high) {
        mid = (low+high)/2;
        if ((cond = strcmp(c, keytab[mid].word)) < 0)
            high = mid -1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
