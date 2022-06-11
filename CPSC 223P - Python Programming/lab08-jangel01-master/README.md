# Laboratory 8

## Laboratory Objectives
1. Explore and use various tools such as: GitHub, VirtualBox, Tuffix, Linux Terminal, and Atom.
1. Write a Python program using:
     1. classes
     2. inheritance
1. Run and test a Python program.

## Getting Started
1. Open the Terminal program in Tuffix.
1. Change the present working directory to the `Documents` directory by typing the following command at the command prompt:

    ```
    cd Documents
    ```

1. Make a copy of this Github repository on your computer using the `git` and `clone` commands that you will input to the terminal. The commands take a URL as a parameter to specify where it can get a copy of the repository. You can find the URL by clicking on the green *Clone or download* button at the top right part of this page. Copy the URL and replace the example text shown below. Note that `username` should be replaced with your own Github username. When you hit <kbd>Enter</kbd> it will ask you to provide your Github username and token. Once done, you will have a copy of the repository on your computer.
    ```
    git clone https://github.com/CSUF-CPSC223P-STMAY-2021F/lab08-username.git
    ```
1. Navigate into the new directory using the command line. Note that `username` should be replaced with your own Github username.  As a shortcut, you can type the first few letters of the folder name and press <kbd>Tab</kbd> so that it auto completes the folder name for you.

     ```
     cd lab08-username
     ```
     
## Program Instructions
1. Write a Python program that performs as a Tuffy Titan Student/Faculty List which contains a list of students and a list of faculty.
1. Create a `people` module to meet the following requirements:
     1. Create a file named `people.py`.
          1. Define a class named `Person`.  
               1. Define a member function named `__init__` to meet the following requirements:
                    1. Take a self object as a positional parameter.
                    1. Take a first name string as a positional parameter.
                    1. Take a last name string as a positional parameter.
                    1. Set a member variable `firstname` equal to the first name parameter.
                    1. Set a member variable `lastname` equal to the last name parameter.
          1. Define a class named `Faculty` that inherits from `Person`  
               1. Define a member function named `__init__` to meet the following requirements:
                    1. Take a self object as a positional parameter.
                    1. Take a first name as a positional parameter.
                    1. Take a last name as a positional parameter.
                    1. Take a department as a positional parameter.
                    1. Call the `Person` `__init__` member function passing the first and last name.
                    1. Set a member variable `department` equal to the department parameter.
          1. Define a class named `Student` that inherits from `Person`  
               1. Define a member function named `__init__` to meet the following requirements:
                    1. Take a self object as a positional parameter.
                    1. Take a first name string as a positional parameter.
                    1. Take a last name string as a positional parameter.
                    1. Call the `Person` `__init__` member function passing the first and last name.
               1. Define a member function named `set_class` to meet the following requirements:
                    1. Take a self object as a positional parameter.
                    1. Take a class year string as a positional parameter.
                    1. Set a member variable `classyear` equal to the class year parameter.
               1. Define a member function named `set_major` to meet the following requirements:
                    1. Take a self object as a positional parameter.
                    1. Take a major string as a positional parameter.
                    1. Set a member variable `major` equal to the major parameter.
               1. Define a member function named `set_advisor` to meet the following requirements:
                    1. Take a self object as a positional parameter.
                    1. Take a `Faculty` object as a positional parameter.
                    1. Set a member variable `advisor` equal to the faculty parameter.
1. Create a `main` driver program to meet the following requirements:
     1. Create a file named `main.py`.
     1. Import the `Faculty` and `Student` classes from the `people` module.
     2. Declare a variable to hold a list of faculty.
     3. Declare a variable to hold a list of students.
     6. Implement a menu within a loop with following choices:
          1. Add faculty
          2. Print faculty
          3. Add student
          4. Print student
          9. Exit the program
     7. Prompt the user for the menu choice.
     8. The Add faculty function should prompt the user for the first name, last name, and department, then instantiate a `Faculty` object and append the object to the faculty list.
     8. The Add student function should prompt the user for the first name, last name, class year, major, and the record number of the faculty advisor, then instantiate a `Student` object and append the object to the student list.
1. Run the program using the command below and repeat the steps above until you are satisfied your program output meets the above requirements.

    ```
    python3 -m main
    ```


1. Typical input and output for the program:
     ```
           *** TUFFY TITAN STUDENT/FACULTY MAIN MENU

     1. Add faculty
     2. Print faculty
     3. Add student
     4. Print student
     9. Exit the program

     Enter menu choice: 2

     ======================= FACLUTY =======================
     Record  Name                  Department
     ======  ====================  =========================
     0       Susan Barua           Computer Science         
     1       Hosssen Moini         Mechanical Engineering   
     2       Huda Munjy            Civil Engineering        
     3       Mostafa Shiva         Electrical Engineering   

           *** TUFFY TITAN STUDENT/FACULTY MAIN MENU

     1. Add faculty
     2. Print faculty
     3. Add student
     4. Print student
     9. Exit the program

     Enter menu choice: 4

     ===================================== STUDENTS ======================================
     Name                  Class      Major                      Advisor
     ====================  ========   =========================  =========================
     Erica Perine          Freshman   Civil Engineering          Huda Munjy          
     Jonathan Rosso        Senior     Computer Science           Susan Barua         
     Samuel Carter         Sophomore  Environmental Engineering  Huda Munjy          
     Stephanie Dalaba      Senior     Electrical Engineering     Mostafa Shiva       
     Chuck Pirards         Junior     Mechanical Engineering     Hosssen Moini       

           *** TUFFY TITAN STUDENT/FACULTY MAIN MENU

     1. Add faculty
     2. Print faculty
     3. Add student
     4. Print student
     9. Exit the program

     Enter menu choice: 1

     Enter first name: George
     Enter last name: Kiran
     Enter department: Computer Engineering

           *** TUFFY TITAN STUDENT/FACULTY MAIN MENU

     1. Add faculty
     2. Print faculty
     3. Add student
     4. Print student
     9. Exit the program

     Enter menu choice: 2

     ======================= FACLUTY =======================
     Record  Name                  Department
     ======  ====================  =========================
     0       Susan Barua           Computer Science         
     1       Hosssen Moini         Mechanical Engineering   
     2       Huda Munjy            Civil Engineering        
     3       Mostafa Shiva         Electrical Engineering   
     4       George Kiran          Computer Engineering     

           *** TUFFY TITAN STUDENT/FACULTY MAIN MENU

     1. Add faculty
     2. Print faculty
     3. Add student
     4. Print student
     9. Exit the program

     Enter menu choice: 3

     Enter first name: Becky
     Enter last name: Hanna
     Enter class year: Senior
     Enter major: Computer Science
     Enter faculty advisor: 4

           *** TUFFY TITAN STUDENT/FACULTY MAIN MENU

     1. Add faculty
     2. Print faculty
     3. Add student
     4. Print student
     9. Exit the program

     Enter menu choice: 4

     ===================================== STUDENTS ======================================
     Name                  Class      Major                      Advisor
     ====================  =========  =========================  =========================
     Erica Perine          Freshman   Civil Engineering          Huda Munjy          
     Jonathan Rosso        Senior     Computer Science           Susan Barua         
     Samuel Carter         Sophomore  Environmental Engineering  Huda Munjy          
     Stephanie Dalaba      Senior     Electrical Engineering     Mostafa Shiva       
     Chuck Pirards         Junior     Mechanical Engineering     Hosssen Moini       
     Becky Hanna           Senior     Computer Science           George Kiran        

           *** TUFFY TITAN STUDENT/FACULTY MAIN MENU

     1. Add faculty
     2. Print faculty
     3. Add student
     4. Print student
     9. Exit the program

     Enter menu choice: 9
     ```

1. Run the unit testing program to ensure that your program runs as expected.

    ```
    ./test.sh
    ```
       
    The unit testing will output the results of a series of tests using specific input and expected output.  Any error will provide information on where the expected output is different from the actual output.  You will need to edit your source code to fix the error and run `./test.sh` repeatedly until it passes all the test.

## Submission
Periodically throughout the exercise, and when you have completed the exercise, **submit the complete repository to Github**.

   <pre>git add .<br>git commit -m "<i>your comment</i>"<br>git push</pre>

In case it asks you  to configure global variables for an email and name, just copy the commands it provides then replace the dummy text with your email and Github token.

   <pre>git config --global user.email "<i>tuffy@csu.fullerton.edu</i>"<br>git config --global user.name "<i>Tuffy Titan</i>"<br>git commit -m "<i>your comment</i>"<br>git push</pre>

When you completed the final Github push, go back into github.com through the browser interface and ensure all your files have been correctly updated.  You should have the following files:
```
main.py
people.py
test.txt
```
    
## Grading
1. All points add up to a total of 100 points possible as detailed below.  Partial credit will be given where applicable.

| Points | Description |
| --- | --- |
|50|initial git clone of this repository to your Tuffix machine|
|15|main.py file submitted contains the main driver program and meets the program requirements|
|15|people.py file submitted contains the people module and meets the program requirements|
|10|unit testing test.txt file results submitted|
|10|unit testing passes each test|
