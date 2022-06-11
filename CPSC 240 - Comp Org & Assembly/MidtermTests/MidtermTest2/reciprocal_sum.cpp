// Jason ANgel
// CPSC 240-03
// jasonangel@csu.fullerton.edu
// Harmonic Sum

#include <iostream>

using namespace std;

extern "C" double reciprocal_sum(double sum);

double reciprocal_sum(double sum) {
  sum = 1 / sum;
  cout << "The reciprocal of the sum is " << sum << " Have a nice day." << endl;
  return sum;
}
