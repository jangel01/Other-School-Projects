// Jason ANgel
// CPSC 240-03
// jasonangel@csu.fullerton.edu
// Harmonic Sum

#include <iostream>

using namespace std;

extern "C" double harmonic();

int main () {
  cout << "Welcome to Harmonic Sum by Jason Angel." << endl;
  double result = harmonic();

  cout << "The main program received this number " << result << " and will keep it." << endl;
  cout << "I hope you enjoyed this summation program. A zero will be returned to the operating system. Bye." << endl;
  return 0;
}
