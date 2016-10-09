#include "syscalls.h"

int main(int argc, char *argv[]) {
    int f, n;
    char buf[BUFSIZE];
    
    while (--argc > 0) {
        if ((f = open(*++argv, O_RDONLY, 0)) == -1)
            error("cat: can't open %s", *argv);
        while ((n = read(f, buf, BUFSIZE)) > 0)
            if (write(0, buf, BUFSIZE) != n)
                error("cat: write error to console");
        close(f);
    }
}
