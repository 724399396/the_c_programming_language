#include <stdio.h>
void expand(char s1[], char s2[]);

void main(void) {
    char s2[100];

    expand("a-z", s2);
    printf("%s\n", s2);
}

void expand(char s1[], char s2[]) {
    int low, high, i, j;
    
    i = 0;
    j = 0;
    while (s1[i] == '-')
        i++;
    low = s1[i];
    i++;
    while(s1[i] != '\0') {

        while(s1[i] == '-')
            i++;
        high = s1[i];
        
        i++;
        char c;
        for(c = low; c <= high; c++)
            s2[j++] = c;
        low = high;
        
    }
    s2[j] = '\0';
}
