/*
    Name: Jason Angel
    Section: 5 
    Lab One

    This program outputs exam grades for three students, then averages their individual scores
    based on the input of the user.

    User can update any score if they wish to do so and the output will change accordingly.

*/

#include <iostream>

using namespace std;

void student_avg(int, int, int);

int main()
{
    int gradebook[3][3];
    int student1_sum, student2_sum, student3_sum;
    int student1_avg, student2_avg, student3_avg;

    // for loop asks for user input and sums up each student's exam score
    for (int student = 0; student < 3; student++) {
        int sum = 0;

        for (int exam = 0; exam < 3; exam++) {
            cout << "Enter Student " << student + 1 << "'s  Exam " << exam + 1 << " score." << endl;
            cin >> gradebook[student][exam];
            sum += gradebook[student][exam];
        }

        switch (student) {
        case 0:
            student1_sum = sum;
            break;
        case 1:
            student2_sum = sum;
            break;
        default:
            student3_sum = sum;
        }
    }

    // calculate student average exam score
    student1_avg = student1_sum / 3;
    student2_avg = student2_sum / 3;
    student3_avg = student3_sum / 3;

    cout << endl;

    // for loop outputs scores of students
    for (int student = 0; student < 3; student++) {
        for (int exam = 0; exam < 3; exam++) {
            cout << "Student " << student + 1 << "'s Exam " << exam + 1 << " score is: "
                << gradebook[student][exam] << endl;
        }
        cout << endl;
    }
    
    // output student averages
    
    student_avg(student1_avg, student2_avg, student3_avg);

    cout << endl;

    // do while loop serves to update any score if necessary

    bool update = false;
    do {
        char answer;
        cout << "Would you like to update an exam score Y/N?" << endl;
        cin >> answer;
        if (answer == 'Y') {
            update = true;
            int student_number;
            int exam_number;

            cout << "Enter a student's number 1-3: ";
            cin >> student_number;
            cout << "Enter an exam number 1-3: ";
            cin >> exam_number;

            cout << "Enter a new value for Student " << student_number << " Exam "
                << exam_number << ": ";
            cin >> gradebook[student_number - 1][exam_number - 1];

            cout << "Student " << student_number << " 's Exam " << exam_number << " score is: "
                << gradebook[student_number - 1][exam_number - 1];

            cout << endl;
        }
        else {
            update = false;
        }
    } while (update == true);

    cout << endl;    

    // the rest of the program updates student averages (if there were any changes)
    // and outputs averages again.
    for (int student = 0; student < 3; student++) {
        int sum = 0;
        for (int exam = 0; exam < 3; exam++) {
            sum += gradebook[student][exam];
        }

        switch (student) {
        case 0:
            student1_sum = sum;
            break;
        case 1: 
            student2_sum = sum;
            break;
        default:
            student3_sum = sum;
        }
    }

    student1_avg = student1_sum / 3;
    student2_avg = student2_sum / 3;
    student3_avg = student3_sum / 3;

    student_avg(student1_avg, student2_avg, student3_avg);

    system("PAUSE");
    return 0;
}

void student_avg(int student1_avg, int student2_avg, int student3_avg) {
    cout << "The averrage score for Student 1 is: " << student1_avg << endl;
    cout << "The averrage score for Student 2 is: " << student2_avg << endl;
    cout << "The averrage score for Student 3 is: " << student3_avg << endl;
}


