#include <stdio.h>

double precision();

double precision() {
  double num;

  printf("%s", "Please enter the precision number and press enter: ");
  scanf("%lf", &num);

  printf("%s, %lf, %s", "You entered", num, "which will be returned to the caller funcion. \n");

  return num;
}
