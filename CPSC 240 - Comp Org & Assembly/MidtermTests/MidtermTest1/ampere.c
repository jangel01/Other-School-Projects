//Name: Jason Angel
//Section; CPSC 240-03
//Email: jasonangel@csu.fullerton.edu
//Program name: Electricity


#include <stdio.h>

extern char *electricity();

int main(int argc, char * argv[]) {
  char *name;
  printf("%s", "Welcome to the High Voltage Software System by Jason Angel \n");
  name = electricity();
  printf("%s, %s, %s", "Goodbye ", name, ". Have a nice research party. \n");
  printf("%s", "Zero is returned to the operating system. \n");

  return 0;
}
