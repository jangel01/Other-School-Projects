#include <stdio.h>

extern double hi();

int main() {
  double result = 0.0;

  printf("%s", "Welcome to Gravitational Experiments by Jason Angel. \n");
  result = hi();

  printf("%s, %lf, %s", "The main function received this number", result, " and will keep it. \n");
  printf("%s", "A 0 will be returned to the OS. Bye \n");
  return 0;
}
