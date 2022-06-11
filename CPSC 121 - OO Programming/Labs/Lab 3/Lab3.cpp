/*
    Name: Jason Angel
    Section: 5
    Lab: 3

    This program lets you crate your own quiz up to five questions long using functions.
*/
#include <iostream>
#include <string>

using namespace std;

void addQuestion(string[5][2], int);
void blankQuestions(string[5][2]);
void displayQuiz(string[5][2]); 

int main() {
    string arr[5][2];
    char input;
    int question_number = 1;

    cout << "Welcome to Quiz Maker." << endl;
    cout << "Make a quiz up to 5 questions long!" << endl;
    cout << endl;

    do {
        cout << "What would you like to do?" << endl;
        cout << "a. Create question" << endl;
        cout << "b. Quit" << endl;
        cin >> input;
        if (input == 'a') {
            addQuestion(arr, question_number - 1);
            question_number++;
        } 
        else if (input == 'b') {
            blankQuestions(arr);
            break;
        }
        else {
            cout << "Invalid option." << endl;
        }
        cout << endl;
    } while (input != 'b' && question_number <= 5);

    cout << endl;
    cout << "Thank you for using Quizmaker!" << endl;
    cout << endl;

    displayQuiz(arr);

    system("PAUSE");
    return 0;
}

// This function asks for a question and answer and stores the strings in the array.
void addQuestion(string arr[5][2], int question_number) {
    cin.ignore();
    cout << "Please enter your question: ";
    getline(cin, arr[question_number][0]);
    cout << "Please enter the answer: ";
    getline(cin, arr[question_number][1]);
    cout << "Question " << question_number + 1 << " added!" << endl;
}

// Function fills empty array with default text showing max amount of questions wasn't reached. 
// Only happens if user quits.
void blankQuestions(string arr[5][2]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            if (arr[i][0] == "") {
                arr[i][0] = "Blank Question";
            }
            if (arr[i][1] == "") {
                arr[i][1] = "Blank Answer";
            }
        }
    }
}

// prints user generated quiz from the array
void displayQuiz(string arr[5][2]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                cout << "Q" << i + 1<< ": " << arr[i][j] << endl;
            }
            else {
                cout << "A: " << arr[i][j] << endl;
            }
        }
        cout << endl;
    }
}


