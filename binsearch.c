#include <stdio.h>

int binsearch(int x, int v[], int n);

void main(void) {
    int test[5], i;

    for (i = 0; i < 5; i++)
        test[i] = i;
    
    printf("%d\n", binsearch(1, test, 5));
}

int binsearch(int x, int v[], int n) {
    int low, high, mid;

    low = 0;
    high = n-1;
    mid = (low+high)/2;
    while(low <= high && v[mid] != x) {
        mid = (low+high)/2;
        if (v[mid] <= x)
            low = mid+1;
        else
            high = mid-1;
    }

    return x == v[mid] ? mid : -1;
}

