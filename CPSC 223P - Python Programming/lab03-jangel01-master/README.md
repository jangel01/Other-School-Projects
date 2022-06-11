# Laboratory 3

## Laboratory Objectives
1. Explore and use various tools such as: GitHub, VirtualBox, Tuffix, Linux Terminal, and Atom.
1. Write a Python program using:
     1. lists
     2. loops
     3. conditional statements
     4. input/output
     5. modules
     6. functions using positional and keyword arguments
1. Run and test a Python program.

## Getting Started
1. Open the Terminal program in Tuffix.
1. Change the present working directory to the `Documents` directory by typing the following command at the command prompt:

    ```
    cd Documents
    ```

1. Make a copy of this Github repository on your computer using the `git` and `clone` commands that you will input to the terminal. The commands take a URL as a parameter to specify where it can get a copy of the repository. You can find the URL by clicking on the green *Clone or download* button at the top right part of this page. Copy the URL and replace the example text shown below. Note that `username` should be replaced with your own Github username. When you hit <kbd>Enter</kbd> it will ask you to provide your Github username and token. Once done, you will have a copy of the repository on your computer.
    ```
    git clone https://github.com/CSUF-CPSC223P-STMAY-2021F/lab03-username.git
    ```
1. Navigate into the new directory using the command line. Note that `username` should be replaced with your own Github username.  As a shortcut, you can type the first few letters of the folder name and press <kbd>Tab</kbd> so that it auto completes the folder name for you.

     ```
     cd lab03-username
     ```
     
## Program Instructions
1. Write a Python program that performs as a Tuffy Titan Contact List which contains a list of contacts that can be modified or deleted.

1. Create a `contacts` module to meet the following requirements:
     1. Create a file named `contacts.py`.
     1. Add a comment at the top of the file which indicates your name, date and the purpose of the file.
     1. Note: All contact lists within this module should assume the list is of the form: `[["first name","last name"],["first name","last name"],...]`
     1. Note: All functions should implement a docstring with a simple sentence that describes the function.
     1. Define a function named `add_contact` to meet the following requirements:
          1. Take a contact list as a positional parameter.
          1. Take a `first_name` as a keyword parameter.
          1. Take a `last_name` as a keyword parameter.
          1. Append the first_name/last_name contact to the contact list.
     1. Define a function named `modify_contact` to meet the following requirements:
          1. Take a contact list as a positional parameter.
          1. Take a `first_name` as a keyword parameter.
          1. Take a `last_name` as a keyword parameter.
          1. Take a `index` as a keyword parameter.
          1. If the index it is within the range of the contact list, modify the appropriate index of the contact list with the first_name/last_name contact, and return a True.
          1. If the index it is not within the range of the contact list, return a False without modifying the contact list.
     1. Define a function named `delete_contact` to meet the following requirements:
          1. Take a contact list as a positional parameter.
          1. Take a `index` as a keyword parameter.
          1. If the index it is within the range of the contact list, delete the contact at the index value, and return a True.
          1. If the index it is not within the range of the contact list, return a False without modifying the contact list.
     1. Define a function named `sort_contacts` to meet the following requirements:
          1. Take a contact list as a positional parameter.
          1. Take a `column` as a keyword parameter.
          1. If the column is 0, sort the contact list by the first name.
          1. If the column is 1, sort the contact list by the last name.
1. Create a `main` driver program to meet the following requirements:
     1. Create a file named `main.py`.
     1. Add a comment at the top of the file which indicates your name, date and the purpose of the file.
     1. Import the `contacts` module.
     2. Define a variable to use for the contact list. 
     3. Implement a menu within a loop with following choices:
          1. Print list
          2. Add contact
          3. Modify contact
          4. Delete contact
          5. Sort list by first name
          6. Sort list by last name
          7. Exit the program
     4. Prompt the user for the menu choice.
     5. Prompt the user for the information needed for the appropriate `contacts` function and call the function.
     6. Print out appropriate errors with function return values of False.
1. Run the program using the command below and repeat the steps above until you are satisfied your program output meets the above requirements.

    ```
    python3 -m main
    ```


1. Typical input and output for the program:
     ```
           *** TUFFY TITAN CONTACT MAIN MENU

     1. Print list
     2. Add contact
     3. Modify contact
     4. Delete contact
     5. Sort list by first name
     6. Sort list by last name
     7. Exit the program

     Enter menu choice: 2

     Enter first name: Richard
     Enter last name: Stallman

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Print list
     2. Add contact
     3. Modify contact
     4. Delete contact
     5. Sort list by first name
     6. Sort list by last name
     7. Exit the program

     Enter menu choice: 2

     Enter first name: Bill
     Enter last name: Gates

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Print list
     2. Add contact
     3. Modify contact
     4. Delete contact
     5. Sort list by first name
     6. Sort list by last name
     7. Exit the program

     Enter menu choice: 2

     Enter first name: Steve
     Enter last name: Jobs

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Print list
     2. Add contact
     3. Modify contact
     4. Delete contact
     5. Sort list by first name
     6. Sort list by last name
     7. Exit the program

     Enter menu choice: 1

     ================== CONTACT LIST ==================
     Index   First Name            Last Name
     ======  ====================  ====================
     0       Richard               Stallman              
     1       Bill                  Gates                 
     2       Steve                 Jobs                  

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Print list
     2. Add contact
     3. Modify contact
     4. Delete contact
     5. Sort list by first name
     6. Sort list by last name
     7. Exit the program

     Enter menu choice: 3

     Enter the index number: 2
     Enter first name: Tim
     Enter last name: Cook

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Print list
     2. Add contact
     3. Modify contact
     4. Delete contact
     5. Sort list by first name
     6. Sort list by last name
     7. Exit the program

     Enter menu choice: 1

     ================== CONTACT LIST ==================
     Index   First Name            Last Name
     ======  ====================  ====================
     0       Richard               Stallman              
     1       Bill                  Gates                 
     2       Tim                   Cook                  

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Print list
     2. Add contact
     3. Modify contact
     4. Delete contact
     5. Sort list by first name
     6. Sort list by last name
     7. Exit the program

     Enter menu choice: 3

     Enter the index number: 5
     Enter first name: Mickey
     Enter last name: Mouse
     Invalid index number.

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Print list
     2. Add contact
     3. Modify contact
     4. Delete contact
     5. Sort list by first name
     6. Sort list by last name
     7. Exit the program

     Enter menu choice: 6

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Print list
     2. Add contact
     3. Modify contact
     4. Delete contact
     5. Sort list by first name
     6. Sort list by last name
     7. Exit the program

     Enter menu choice: 1

     ================== CONTACT LIST ==================
     Index   First Name            Last Name
     ======  ====================  ====================
     0       Tim                   Cook                  
     1       Bill                  Gates                 
     2       Richard               Stallman              

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Print list
     2. Add contact
     3. Modify contact
     4. Delete contact
     5. Sort list by first name
     6. Sort list by last name
     7. Exit the program

     Enter menu choice: 5

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Print list
     2. Add contact
     3. Modify contact
     4. Delete contact
     5. Sort list by first name
     6. Sort list by last name
     7. Exit the program

     Enter menu choice: 1

     ================== CONTACT LIST ==================
     Index   First Name            Last Name
     ======  ====================  ====================
     0       Bill                  Gates                 
     1       Richard               Stallman              
     2       Tim                   Cook                  

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Print list
     2. Add contact
     3. Modify contact
     4. Delete contact
     5. Sort list by first name
     6. Sort list by last name
     7. Exit the program

     Enter menu choice: 4

     Enter the index number: 1

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Print list
     2. Add contact
     3. Modify contact
     4. Delete contact
     5. Sort list by first name
     6. Sort list by last name
     7. Exit the program

     Enter menu choice: 1

     ================== CONTACT LIST ==================
     Index   First Name            Last Name
     ======  ====================  ====================
     0       Bill                  Gates                 
     1       Tim                   Cook                  

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Print list
     2. Add contact
     3. Modify contact
     4. Delete contact
     5. Sort list by first name
     6. Sort list by last name
     7. Exit the program

     Enter menu choice: 4

     Enter the index number: 5
     Invalid index number.

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Print list
     2. Add contact
     3. Modify contact
     4. Delete contact
     5. Sort list by first name
     6. Sort list by last name
     7. Exit the program

     Enter menu choice: 7
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
contacts.py
test.txt
```
    
## Grading
1. All points add up to a total of 100 points possible as detailed below.  Partial credit will be given where applicable.

| Points | Description |
| --- | --- |
|50|initial git clone of this repository to your Tuffix machine|
|15|main.py file submitted contains the main driver program and meets the program requirements|
|15|contacts.py file submitted contains the contacts module and meets the program requirements|
|10|unit testing test.txt file results submitted|
|10|unit testing passes each test|
