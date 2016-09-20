#include <stdio.h>
#include <limits.h>
#include <float.h>

void main(void) {
    printf("min char: %d\n", CHAR_MIN);
    printf("max char: %d\n", CHAR_MAX);
    printf("min int: %d\n", INT_MIN);
    printf("max int: %d\n", INT_MAX);
    printf("min long: %ld\n", LONG_MIN);
    printf("max long: %ld\n", LONG_MAX);
    printf("signed char min: %d\n", SCHAR_MIN);
    printf("signed char max: %d\n", SCHAR_MAX);
    printf("short min: %d\n", SHRT_MIN);
    printf("short max: %d\n", SHRT_MAX);
    printf("unsigned char max: %d\n", UCHAR_MAX);
    printf("unsigned int max: %ud\n", UINT_MAX);
    printf("unsigned long max: %lu\n", ULONG_MAX);
    printf("unsigned short max: %du\n", USHRT_MAX);

    printf("float radix of exponent: %d\n", FLT_RADIX);
    printf("float rounding mode: %d\n", FLT_ROUNDS);
    printf("float digits: %d\n", FLT_DIG);
    printf("float epsilon: %f\n", FLT_EPSILON);
    printf("float max: %f\n", FLT_MAX);
    printf("float min: %f\n", FLT_MIN);
    printf("float max exp: %d\n", FLT_MAX_EXP);
    printf("float min exp: %d\n", FLT_MIN_EXP);
    printf("double dig: %d\n", DBL_DIG);
    printf("double epsilon: %f\n", DBL_EPSILON);
    printf("double max: %f\n", DBL_MAX);
    printf("double min: %f\n", DBL_MIN);
    printf("double max exp: %d\n", DBL_MAX_EXP);
    printf("double min exp: %d\n", DBL_MIN_EXP);
}
