#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"

int main(int argc, char *argv[]) {
    int c;
    if (argc < 2)
        printf("Usage: polish expression\n");
    else {
        while (--argc > 0) {            
            c = (*++argv)[0];
            switch(c) {
            case '+':
                push(pop()+pop());
                break;
            case '*':
                push(pop()*pop());
                break;
            default:
                push(atof(*argv));
                break;
            }
        }
        printf("res: %f\n", pop());
    }
}
