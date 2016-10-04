#include <stdarg.h>
#include <stdio.h>

void minscanf(char *fmt, ...) {
    char *p;
    va_list ap;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            continue;
        }
        switch (*++p) {
        case 'd':
            scanf("%d", va_arg(ap, void *));
            break;
        case 'f':
            scanf("%f", va_arg(ap, void *));
            break;
        case 's':
            scanf("%s", va_arg(ap, void *));
            break;
        }
    }
    va_end(ap);
}

void main(void) {
    int i;
    float f;
    char s[10];
    minscanf("%d %f %s", &i, &f, s);
    printf("%d %f %s\n", i, f, s);
}
