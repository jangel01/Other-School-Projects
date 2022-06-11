# Name: Jason Angel
# Date: 10/28/21
# Purpose: Create list of faculty and students using subclasses

from people import *

faculty = []
students = []
choice = 0

while (choice != 6):
    print(""" *** TUFFY TITAN STUDENT/FACULTY MAIN MENU
    1. Add Faculty
    2. Print Faculty
    3. Add Student
    4. Print Student
    9. Exit the program""")

    choice = int(input("Enter menu choice: "))

    if choice == 1:
        firstname = input("Enter first name: ")
        lastname = input("Enter last name: ")
        department =  input("Enter department ")

        newfaculty = Faculty(firstname, lastname, department)
        faculty.append(newfaculty)
    elif choice == 2:
        for record in range(len(faculty)):
            fullname = faculty[record].firstname + " " + faculty[record].lastname
            print(f' {str(record):5} {fullname:25} {faculty[record].department}')
    elif choice == 3:
        firstname = input("Enter first name: ")
        lastname = input("Enter last name: ")
        classyear = input("Enter class year: ")
        major = input("Enter major: ")
        facultyadvisor = int(input("Enter faculty advisor: "))

        newstudent = Student(firstname, lastname)
        newstudent.set_class(classyear)
        newstudent.set_major(major)

        for record in range(len(faculty)):
            if facultyadvisor == record:
                newstudent.set_advisor(faculty[record])
                break

        students.append(newstudent)
    elif choice == 4:
        for student in range(len(students)):
            studentname = students[student].firstname + " " + students[student].lastname
            facultyname = students[student].advisor.firstname + " " + students[student].advisor.lastname
            print(f' {studentname:25} {students[student].classyear:15} {students[student].major:25}'
            f'{facultyname}')
