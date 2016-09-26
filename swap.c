#include <stdio.h>

#define swap(t,x,y) do {\
  int tmp;\
  tmp = x;\
  x = y;\
  y = tmp;\
} while (0)

void main(void) {
    double x,y;
    
    x = 2.0;
    y = 1.0;
    swap(double, x, y);
    printf("%f %f\n", x, y);
}
