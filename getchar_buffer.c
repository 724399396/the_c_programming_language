#include <unistd.h>
#include <stdio.h>

int getchar(void) {
    static char buf[BUFSIZ];
    static char *bufp = buf;
    static int n = 0;

    if (n == 0) {
        n = read(0, buf, BUFSIZ);
        bufp = buf;
    }
    return (--n >= 0) ? (unsigned char) *bufp++ : EOF;
}

int main(void) {
    printf("%c\n", getchar());
}

