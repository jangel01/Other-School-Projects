# Laboratory 4

## Laboratory Objectives
1. Explore and use various tools such as: GitHub, VirtualBox, Tuffix, Linux Terminal, and Atom.
1. Write a Python program using:
     1. lists
     2. loops
     3. conditional statements
     4. input/output
     5. modules
     6. functions using positional and keyword arguments
     7. dictionaries
1. Run and test a Python program.

## Getting Started
1. Open the Terminal program in Tuffix.
1. Change the present working directory to the `Documents` directory by typing the following command at the command prompt:

    ```
    cd Documents
    ```

1. Make a copy of this Github repository on your computer using the `git` and `clone` commands that you will input to the terminal. The commands take a URL as a parameter to specify where it can get a copy of the repository. You can find the URL by clicking on the green *Clone or download* button at the top right part of this page. Copy the URL and replace the example text shown below. Note that `username` should be replaced with your own Github username. When you hit <kbd>Enter</kbd> it will ask you to provide your Github username and token. Once done, you will have a copy of the repository on your computer.
    ```
    git clone https://github.com/CSUF-CPSC223P-STMAY-2021F/lab04-username.git
    ```
1. Navigate into the new directory using the command line. Note that `username` should be replaced with your own Github username.  As a shortcut, you can type the first few letters of the folder name and press <kbd>Tab</kbd> so that it auto completes the folder name for you.

     ```
     cd lab04-username
     ```
     
## Program Instructions
1. Write a Python program that performs as a Tuffy Titan Contact List which contains a list of contacts that can be modified or deleted.

1. Create a `contacts` module to meet the following requirements:
     1. Create a file named `contacts.py`.
     1. Add a comment at the top of the file which indicates your name, date and the purpose of the file.
     1. Note: All contact dictionaries within this module should assume a dictionary of the form: `{id: ['first', 'last'], id: ['first', 'last'], id: ['first', 'last']...}`
     1. Note: All functions should implement a docstring with a simple sentence that describes the function.
     1. Define a function named `add_contact` to meet the following requirements:
          1. Take a contact dictionary as a positional parameter.
          1. Take a `id` as a keyword parameter.
          1. Take a `first_name` as a keyword parameter.
          1. Take a `last_name` as a keyword parameter.
          2. If the id exists in the dictionary, return the string `error`.
          3. Append the id:[first_name, last_name'] key:value pair to the contact dictionary.
          4. Return the key:value pair that was added.
     1. Define a function named `modify_contact` to meet the following requirements:
          1. Take a contact dictionary as a positional parameter.
          1. Take a `id` as a keyword parameter.
          1. Take a `first_name` as a keyword parameter.
          1. Take a `last_name` as a keyword parameter.
          1. If the id does not exists in the dictionary, return the string `error`.
          1. Append the id:[first_name, last_name'] key:value pair to the contact dictionary.
          1. Return the key:value pair that was added.
     1. Define a function named `delete_contact` to meet the following requirements:
          1. Take a contact dictionary as a positional parameter.
          1. Take a `id` as a keyword parameter.
          2. If the id does not exists in the dictionary, return the string `error`.
          3. Remove the key:value pair with the key equal to id.
          3. Return the key:value pair with the key equal to id.
     1. Define a function named `sort_contacts` to meet the following requirements:
          1. Take a contact dictionary as a positional parameter.
          2. Sort the dictionary in ascending order by last name, and then by first name, ignoring case.
          3. Return the sorted dictionary. 
     1. Define a function named `find_contact` to meet the following requirements:
          1. Take a contact dictionary as a positional parameter.
          1. Take a `find` as a keyword parameter.
          2. Create an empty dictionary.
          3. If find is a numeric value and contained as a key in the dictionary, add the key:value pair to the created dictionary.
          4. Loop through all the key:value pairs and if the find substring is contained in either the first name or last name, add the key:value pair to the created dictionary.
          5. Sort the created dictionary in ascending order by last name, and then by first name, ignoring case.
          6. Return the created dictionary. 
1. Create a `main` driver program to meet the following requirements:
     1. Create a file named `main.py`.
     1. Add a comment at the top of the file which indicates your name, date and the purpose of the file.
     1. Import the `contacts` module.
     2. Define a variable to use for the contact dictionary. 
     3. Implement a menu within a loop with following choices:
          1. Add contact
          1. Modify contact
          1. Delete contact
          1. Print contact list
          1. Find contact
          1. Exit the program
     4. Prompt the user for the menu choice.
     5. Prompt the user for the information needed for the appropriate `contacts` function and call the function.
     6. Print out appropriate errors with function return values of `error`.
1. Run the program using the command below and repeat the steps above until you are satisfied your program output meets the above requirements.

    ```
    python3 -m main
    ```


1. Typical input and output for the program:
     ```
           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Find contact
     6. Exit the program

     Enter menu choice: 1

     Enter phone number: 7145551212
     Enter first name: Steve 
     Enter last name: Jobs
     Added: Steve Jobs.

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Find contact
     6. Exit the program

     Enter menu choice: 4

     ==================== CONTACT LIST ====================
     Last Name             First Name            Phone
     ====================  ====================  ==========
     Jobs                  Steve                 7145551212  

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Find contact
     6. Exit the program

     Enter menu choice: 1

     Enter phone number: 7145551212
     Enter first name: Bill 
     Enter last name: Gates
     Phone number already exists.

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Find contact
     6. Exit the program

     Enter menu choice: 2

     Enter phone number: 7145551212
     Enter first name: Bill
     Enter last name: Gates
     Modified: Bill Gates.

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Find contact
     6. Exit the program

     Enter menu choice: 4

     ==================== CONTACT LIST ====================
     Last Name             First Name            Phone
     ====================  ====================  ==========
     Gates                 Bill                  7145551212  

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Find contact
     6. Exit the program

     Enter menu choice: 2

     Enter phone number: 5551212
     Enter first name: Richard 
     Enter last name: Stallman
     Phone number does not exist.

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Find contact
     6. Exit the program

     Enter menu choice: 3

     Enter phone number: 5551212
     Invalid phone number.

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Find contact
     6. Exit the program

     Enter menu choice: 3

     Enter phone number: 7145551212
     Deleted: Bill Gates.

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Find contact
     6. Exit the program

     Enter menu choice: 4

     ==================== CONTACT LIST ====================
     Last Name             First Name            Phone
     ====================  ====================  ==========

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Find contact
     6. Exit the program

     Enter menu choice: 1

     Enter phone number: 7145551111
     Enter first name: Alpha
     Enter last name: Jobs
     Added: Alpha Jobs.

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Find contact
     6. Exit the program

     Enter menu choice: 1

     Enter phone number: 7145552222
     Enter first name: Steve
     Enter last name: Jobs
     Added: Steve Jobs.

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Find contact
     6. Exit the program

     Enter menu choice: 1

     Enter phone number: 5625553333
     Enter first name: Bill
     Enter last name: Gates
     Added: Bill Gates.

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Find contact
     6. Exit the program

     Enter menu choice: 4

     ==================== CONTACT LIST ====================
     Last Name             First Name            Phone
     ====================  ====================  ==========
     Gates                 Bill                  5625553333  
     Jobs                  Alpha                 7145551111  
     Jobs                  Steve                 7145552222  

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Find contact
     6. Exit the program

     Enter menu choice: 5

     Enter search string: jobs
     ================== FOUND CONTACT(S) ==================
     Last Name             First Name            Phone
     ====================  ====================  ==========
     Jobs                  Alpha                 7145551111  
     Jobs                  Steve                 7145552222  

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Find contact
     6. Exit the program

     Enter menu choice: 5

     Enter search string: 5625553333
     ================== FOUND CONTACT(S) ==================
     Last Name             First Name            Phone
     ====================  ====================  ==========
     Gates                 Bill                  5625553333  

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Find contact
     6. Exit the program

     Enter menu choice: 6
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
