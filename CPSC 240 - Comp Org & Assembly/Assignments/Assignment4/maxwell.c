#include <stdio.h>

extern double hi();

int main() {
  char myname[] = "Jason";
  double result = 0.0;
  printf("%s", "Welcome to Power Unlimited programmed by Jason Angel. \n");
  result = hi();
  if (result == -1.0) {
    printf("%s, %.1lf, %s", "The main function received this number", result, "and will keep it. \n");
  } else {
    printf("%s, %.5lf, %s", "The main function received this number", result, "and will keep it. \n");
  }
  printf("%s", "Next zero will be returned to the OS. Bye. \n");
  return 0;
}
