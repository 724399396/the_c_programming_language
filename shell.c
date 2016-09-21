#include <stdio.h>

void shellsort(int s[], int n);

void main(void) {
    int s[10], i;
    
    for (i=0; i < 10; i++)
        s[i] = 10-i;

    shellsort(s, 10);
    for (i=0; i < 10; i++)
        printf("%d\n", s[i]);
}

void shellsort(int s[], int n) {
    int gap, i, j;

    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for(j = i-gap; j >= 0 && s[j+gap] < s[j]; j -= gap) {
                int tmp = s[j];
                s[j] = s[j+gap];
                s[j+gap] = tmp;
            }
}
