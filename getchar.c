#include <unistd.h>
#include <stdio.h>

int getchar(void) {
    char c;
    
    return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}


int main(void) {
    printf("%c\n", getchar());
}
