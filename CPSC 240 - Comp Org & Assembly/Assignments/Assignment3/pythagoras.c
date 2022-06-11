#include <stdio.h>

extern double triangle();

int main(int argc, char * argv[]) {
  double number = 0.0;
  printf("%s", "Welcome to the Right Triangles Program created by Jason Angel. \n");
  printf("%s", "If errors are discovered please report them to Jason Angel at jasonangel@csu.fullerton.edu for a quick fix."
    "At Columbia Software the customer comes first. \n");
  number = triangle();
  printf("%s, %1.18lf, %s", "The main function received this number", number, " and plans to keep it. \n");
  printf("%s", "An integer zero will be returned to the operating system. Bye. \n");
  return 0;
}
