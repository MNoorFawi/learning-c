#include <stdio.h>
#define ADD(...) addition((func_args) {__VA_ARGS__})

typedef struct {
  int a;
  double b;
}
func_args;

double add(int a, double b) {
  double x = a + b;
  printf(" sum=%.2f\n\n", x);
  return x;
}

double addition(func_args input ) {
  int a_out = input .a ? input .a : 5;
  double b_out = input .b ? input .b : 2.5;
  printf("i=%d x=%.2f\n", a_out, b_out);
  return add(a_out, b_out);
}

int main() {
  ADD(4, 5); //a=4, b=5
  ADD(.a = 2, 2.3); //a=2, b=2.3
  ADD(3); //a=3, b=2.5
  ADD(.b = 1.2); //a=5, b=1.2
  return 0;
}
