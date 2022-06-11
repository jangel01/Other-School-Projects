#include <iostream>
using namespace std;

int gcd(int a, int b);
void reverseString(string &string1, int stringEnd);
int checkIfPalindrome(string &string2, int position, int stringEnd);

int main()
{
    int num1, num2;
    cout << "Enter two integers:" << endl;
    cin >> num1;
    cin >> num2;
    cout << "The greatest common divisor of " << num1 << " and " << num2 << " is " << gcd(num1, num2) << endl;
    cout << endl;

    string string1;
    cout << "Enter a string you want to reverse: " << endl;
    cin >> string1;
    cout << "In reversed, the string becomes:  " << endl;
    reverseString(string1, (string1.size() - 1));
    cout << endl;
  
    string string2;
    cout << "Enter string to see if it's a palindrome: " << endl;
    cin >> string2;
    if (checkIfPalindrome(string2, 0, (string2.size() - 1)) == 1) {
        cout << "string is a palindrome" << endl;
    }
    else {
        cout << "string is not a palindrome" << endl;
    }

    system("PAUSE");
    return 0;
}

int gcd (int a, int b) {
    int q = a / b;
    int r = a % b;
    if (r == 0) {
        return b;
    }
    else {
        a = b;
        b = r;
        gcd(a, b);
    }
}

void reverseString(string& string1, int stringEnd) {
    if (stringEnd >= 0) {
        cout << string1[stringEnd];
        reverseString(string1, stringEnd - 1);
    }
    else {
        cout << endl;
    }
}

int checkIfPalindrome(string &string2, int position, int stringEnd) {
    if (position == stringEnd) {
        return 1;
    }

    if (string2[position] == string2[stringEnd]) {
        checkIfPalindrome(string2, position + 1, stringEnd - 1);
    } else {
        return 2;
    }
}
