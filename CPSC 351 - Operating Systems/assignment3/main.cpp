/* Name:  Jason Angel
*  Email : jasonangel@csu.fullerton.edu
*  Assignment 3
*/

#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>

using namespace std;

// Print "1-26" 20 times
void printNum(mutex &m);
// Print "A-Z" 20 times
void printAlpha(mutex &m);

int main()
{
    ofstream{"synch.txt"};
    mutex m;
    thread t1(printNum, ref(m));
    thread t2(printAlpha, ref(m));

    t1.join();
    t2.join();

	return 0;
}

void printNum(mutex &m) {
    m.lock();
    ofstream file("synch.txt", ios_base::app);
    for (int i = 0; i < 20; ++i) {
        for (int j = 0; j < 26; ++j) {
            file << j + 1 << " ";
        }
        file << endl;
    }
    file.close();
    m.unlock();
}

void printAlpha(mutex &m) {
    m.lock();
    ofstream file("synch.txt", ios_base::app);
    for (int i = 0; i < 20; ++i) {
        for (char j = 'A'; j <= 'Z'; ++j) {
            file << j << " ";
        }
        file << endl;
    }
    file.close();
    m.unlock();
}
