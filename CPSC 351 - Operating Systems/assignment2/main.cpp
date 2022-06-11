/* Name:  Jason Angel
*  Email : jasonangel@csu.fullerton.edu
*  Assignment 2
* 
* Note you may have to input _CRT_SECURE_NO_WARNINGS into preprocessor definitions 
* to ignore a warning strtok() may cause
*/

#include <iostream>                 
#include <windows.h>                // CreateThread() 
#include <vector>                   // std::vector
#include <string> 
#include <cstring>                  // strtok()

using namespace std;

// Print command list
void printPrompt();

// Function to pass to CreateThread(). Function passes the inputted command to system().
DWORD WINAPI cmd(LPVOID lp);

int main() {
    cout << "Welcome to myShell\n\n";

    while (1) {
        DWORD ThreadId;
        HANDLE ThreadHandle;
        vector<char*> argument;
        char userInput[100];

        printPrompt();

        // Fetch user input until end of line is reached
        gets_s(userInput);

        // token is used as a delimiter. It is used to distinguish arguments from userInput
        char* token = strtok(userInput, " ");
        while (token) {
            argument.push_back(token);
            token = strtok(NULL, " ");
        }

        if (argument.size() == 0) {
            cout << "Please enter an argument." << endl;
            continue;
        }
        else if (argument.size() > 4) {                   // Accept up to 4 arguments.
            cout << "Too many arguments." << endl;
            continue;
        }

        if (string(argument[0]) == "dir" ||
            string(argument[0]) == "help" ||
            string(argument[0]) == "vol" ||
            string(argument[0]) == "path" ||
            string(argument[0]) == "tasklist" ||
            string(argument[0]) == "notepad" ||
            string(argument[0]) == "echo" ||
            string(argument[0]) == "color" ||
            string(argument[0]) == "ping") {

            ThreadHandle = CreateThread(
                NULL,
                0,
                cmd,
                &argument,
                0,
                &ThreadId);

            if (ThreadHandle != NULL) {
                WaitForSingleObject(ThreadHandle, INFINITE);
            }

            CloseHandle(ThreadHandle);
        }
        else if (string(argument[0]) == "exit" || string(argument[0]) == "quit") {
            cout << "Thanks for using myShell!" << endl;
            break;
        }
        else {
            cout << "Invalid command" << endl;
        }
    }


    return 0;
}

void printPrompt() {
    cout << "=====Enter a command from below along with any appropaite arguments===== \n";
    cout << "dir \n";
    cout << "help \n";
    cout << "vol \n";
    cout << "path \n";
    cout << "tasklist \n";
    cout << "notepad \n";
    cout << "echo \n";
    cout << "color \n";
    cout << "ping \n\n";

    cout << "To exit myShell, type 'quit' or 'exit' \n\n";
    cout << ">> ";
}

DWORD WINAPI cmd(LPVOID lp) {
    // lp needs to be casted back into a vecotr.
    vector<char*> argument = *(vector<char*>*) lp;

    string cmd = string(argument[0]);

    // See whether there are additonal arguments and add them to cmd string.
    for (auto i = argument.begin() + 1; i != argument.end(); ++i) {
        cmd += " " + string(*i);
    }

    system(cmd.c_str());

    return 0;
}
