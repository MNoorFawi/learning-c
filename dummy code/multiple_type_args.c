#include <stdio.h>
#include <string.h>

int add_int(int a, int b) {
  return a + b;
}

float add_float(float a, float b) {
  return a + b;
}

char * add_char(char * a, char * b) {
  strcat(a, b);
  return a;
}

#define add_func(x, y)\
_Generic((x), \
    int: add_int, float: add_float, char *: add_char, \
    default: add_int)\
  (x, y)

int main() {
    int a = 1, b = 2;
    printf("%d\n", add_func(a, b));
  
    float c = 1.2, d = 2.3;
    printf("%f\n", add_func(c, d));
  
    char x[] = "Hello";
    char y[] = "World";
    char * z = add_func(x, y);
    printf("%s\n", z);
  
  return 0;
}
