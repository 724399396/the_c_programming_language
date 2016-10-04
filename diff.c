#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLINELENGTH 1000

int main(int argc, char *argv[]) {
    char *prog = argv[0];
    char fl1[MAXLINELENGTH], fl2[MAXLINELENGTH];

    if (argc != 3) {
        printf("Usage : file1 file 2\n");
        exit(1);
    } else {
        FILE *f1 = fopen(argv[1], "r");
        FILE *f2 = fopen(argv[2], "r");
        
        while (NULL != fgets(fl1, MAXLINELENGTH, f1) && NULL != fgets(fl2, MAXLINELENGTH, f2))
            if (strcmp(fl1, fl2)) {
                printf("not equal: %s %s\n", fl1, fl2);
                break;
            }
        
        fclose(f1);
        fclose(f2);
        printf("equal\n");
    }
}
