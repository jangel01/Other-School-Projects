#include <iostream>

using namespace std;

extern "C" double sum();

int main () {
  cout << "Welcome to this wonderful program written by Jason Angel planning a career in microprocessor architecture" << endl;

  double result = sum();
  cout << "The driver recieved this number " << result << " and has no knowledge about it." << endl;
  cout << "Zero will be returned to the OS as a signal of success" << endl;
  return 0;
}
