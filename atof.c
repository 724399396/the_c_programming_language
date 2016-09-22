#include <stdio.h>
#include <ctype.h>
#define MAXLENGTH 1000

int main(void) {
    double sum, atof(char s[]);
    int getline2(char s[], int lim);
    char s[MAXLENGTH];

    while (getline2(s, MAXLENGTH) > 0)
        printf("\t%g\n", sum += atof(s));
    
}

int getline2(char s[], int lim) {
    int c, i;
    
    for (i = 0; i < lim -1 && (c = getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;    
}

double atof(char s[]) {
    int i, sign, j, et, es;
    double res, power;
    
    for (i = 0; isspace(s[i]); i++)
        ;
    sign = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;
    for (; isdigit(s[i]); i++)
        res = res * 10.0 + (s[i] - '0');

    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++) {
        res = res * 10.0 + (s[i] - '0');
        power *= 10.0;
    }
    
    if (s[i] == 'e' || s[i] == 'E')
        i++;
    es = s[i] == '-' ? -1 : 1;
    if (s[i] == '-' || s[i] == '+')
        i++;    
    for (et=0; isdigit(s[i]); i++) {
         et = et * 10 + (s[i] - '0');
    }
    if (es == 1) 
        for (j=0; j < et; j++) {
            power /= 10;
        }
    else
        for (j=0; j < et; j++) {
            power *= 10;
        }

    return sign * res / power;
}
