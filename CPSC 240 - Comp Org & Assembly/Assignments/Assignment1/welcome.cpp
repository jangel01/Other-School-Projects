#include <stdio.h>

extern "C" char * hello_world();

int main(int argc, char* argv[]) {
  printf("%s", "Welcome to this friendly 'Hello' program created by Jason Angel \n");
  char * name;
  name = hello_world();
  printf("%s, %s", "Stay away from viruses", name);
  printf("%s", "Bye. The integer zero will now be returned to the operating system. \n");
  return 0;
}
