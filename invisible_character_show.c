#include <stdio.h>
#include <string.h>

int main(int argv, char* args[]) {
    int c;
    FILE* src;
    FILE* des;
    src = fopen(args[1], "r");
    des = fopen(strcat(args[1], ".show"), "w");
    while((c = getc(src)) != EOF) {
        if (c == '\t') {
            putc('\\', des);
            putc('t', des);
            continue;
        }
        if (c == '\b') {
            putc('\\', des);
            putc('b', des);
            continue;
        }
        if (c == '\\') {
            putc('\\', des);
            putc('\\', des);
            continue;
        }
        putc(c, des);
    }
    fclose(src);
    fclose(des);
}
