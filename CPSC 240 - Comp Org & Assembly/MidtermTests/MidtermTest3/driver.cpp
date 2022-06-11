// Jason Angel
// jasonangel@csu.fullerton.edu
// CPSC 240-03
// Final 

#include <iostream>

using namespace std;

extern "C" double force();

int main () {
  cout << "This is final exam by Jason Angel" << endl;

  double result = force();
  cout << "THe main program recieved " << result << " and will just keep it." << endl;
  cout << "Have a nice day" << endl;
  return 0;
}
