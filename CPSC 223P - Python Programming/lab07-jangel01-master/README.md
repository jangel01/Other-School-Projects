# Laboratory 7

## Laboratory Objectives
1. Explore and use various tools such as: GitHub, VirtualBox, Tuffix, Linux Terminal, and Atom.
1. Write a Python program using:
     1. modules
     2. dictionaries
     3. file input/output
     4. classes
1. Run and test a Python program.

## Getting Started
1. Open the Terminal program in Tuffix.
1. Change the present working directory to the `Documents` directory by typing the following command at the command prompt:

    ```
    cd Documents
    ```

1. Make a copy of this Github repository on your computer using the `git` and `clone` commands that you will input to the terminal. The commands take a URL as a parameter to specify where it can get a copy of the repository. You can find the URL by clicking on the green *Clone or download* button at the top right part of this page. Copy the URL and replace the example text shown below. Note that `username` should be replaced with your own Github username. When you hit <kbd>Enter</kbd> it will ask you to provide your Github username and token. Once done, you will have a copy of the repository on your computer.
    ```
    git clone https://github.com/CSUF-CPSC223P-STMAY-2021F/lab07-username.git
    ```
1. Navigate into the new directory using the command line. Note that `username` should be replaced with your own Github username.  As a shortcut, you can type the first few letters of the folder name and press <kbd>Tab</kbd> so that it auto completes the folder name for you.

     ```
     cd lab07-username
     ```
     
## Program Instructions
1. Write a Python program that performs as a Tuffy Titan Contact List which contains a dictionary of contacts that is stored on the hard drive and that can have contacts added, modified, or deleted.
1. Create a `contacts` module to meet the following requirements:
     1. Create a file named `contacts.py`.
          1. Define a class named `Contacts`.  
               1. Define a member function named `__init__` to meet the following requirements:
                    1. Take a `self` as a positional parameter.
                    2. Take a `filename` as a keyword parameter.
                    3. Set a member variable equal to the filename.
                    4. Set a member varialbe equal to an empty data dictionary.
                    5. Open the filename and load the JSON decoded contents to the empty data dictionary.
                    6. Cleanly manage the `FileNotFoundError` if the filename does not exist.
               1. Define a member function named `add_contact` to meet the following requirements:
                    1. Take a `self` as a positional parameter.
                    1. Take a `id` as a keyword parameter.
                    1. Take a `first_name` as a keyword parameter.
                    1. Take a `last_name` as a keyword parameter.
                    2. If the id exists in the data dictionary, return the string `error`.
                    3. Set the id:[first_name, last_name] key:value pair to the data dictionary.
                    4. Sort the data dictionary in ascending order by last name, and then by first name, ignoring case.
                    5. Write the contents of the data dictionary to the filename that was set to the member variable.
                    6. Return the key:value pair that was added.
               1. Define a member function named `modify_contact` to meet the following requirements:
                    1. Take a `self` as a positional parameter.
                    1. Take a `id` as a keyword parameter.
                    1. Take a `first_name` as a keyword parameter.
                    1. Take a `last_name` as a keyword parameter.
                    1. If the id does not exists in the dictionary, return the string `error`.
                    1. Set the id:[first_name, last_name'] key:value pair to the contact dictionary.
                    4. Sort the data dictionary in ascending order by last name, and then by first name, ignoring case.
                    5. Write the contents of the data dictionary to the filename that was set to the member variable.
                    6. Return the key:value pair that was modified.
               1. Define a member function named `delete_contact` to meet the following requirements:
                    1. Take a `self` as a positional parameter.
                    1. Take a `id` as a keyword parameter.
                    2. If the id does not exists in the dictionary, return the string `error`.
                    3. Remove the key:value pair with the key equal to id.
                    5. Write the contents of the data dictionary to the filename that was set to the member variable.
                    3. Return the key:value pair with the key equal to id.
1. Create a `main` driver program to meet the following requirements:
     1. Create a file named `main.py`.
     1. Import the `contacts` module.
     2. Instantiate a `Contacts` object with any default filename. 
     3. Implement a menu within a loop with following choices:
          1. Add contact
          1. Modify contact
          1. Delete contact
          1. Print contact list
          1. Set contact filename
          1. Exit the program
     4. Prompt the user for the menu choice.
     5. Prompt the user for the information needed for the appropriate `Contacts` member function and call the function.
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
     5. Set contact filename
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
     5. Set contact filename
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
     5. Set contact filename
     6. Exit the program

     Enter menu choice: 4

     ==================== CONTACT LIST ====================
     Last Name             First Name            Phone
     ====================  ====================  ==========
     Gates                 Bill                  5625553333  
     Jobs                  Steve                 7145551212  

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Set contact filename
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
     5. Set contact filename
     6. Exit the program

     Enter menu choice: 4

     ==================== CONTACT LIST ====================
     Last Name             First Name            Phone
     ====================  ====================  ==========
     Gates                 Bill                  5625553333  
     Jobs                  Alpha                 7145551111  
     Jobs                  Steve                 7145551212  

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Set contact filename
     6. Exit the program

     Enter menu choice: 1

     Enter phone number: 7145551111
     Enter first name: Richard
     Enter last name: Stallman
     Phone number already exists.

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Set contact filename
     6. Exit the program

     Enter menu choice: 2

     Enter phone number: 7145551111
     Enter first name: Richard
     Enter last name: Stallman
     Modified: Richard Stallman.

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Set contact filename
     6. Exit the program

     Enter menu choice: 4

     ==================== CONTACT LIST ====================
     Last Name             First Name            Phone
     ====================  ====================  ==========
     Gates                 Bill                  5625553333  
     Jobs                  Steve                 7145551212  
     Stallman              Richard               7145551111  

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Set contact filename
     6. Exit the program

     Enter menu choice: 3

     Enter phone number: 5625553333
     Deleted: Bill Gates.

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Set contact filename
     6. Exit the program

     Enter menu choice: 4

     ==================== CONTACT LIST ====================
     Last Name             First Name            Phone
     ====================  ====================  ==========
     Jobs                  Steve                 7145551212  
     Stallman              Richard               7145551111  

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Set contact filename
     6. Exit the program

     Enter menu choice: 3

     Enter phone number: 7145559999
     Invalid phone number.

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Set contact filename
     6. Exit the program

     Enter menu choice: 4

     ==================== CONTACT LIST ====================
     Last Name             First Name            Phone
     ====================  ====================  ==========
     Jobs                  Steve                 7145551212  
     Stallman              Richard               7145551111  

           *** TUFFY TITAN CONTACT MAIN MENU

     1. Add contact
     2. Modify contact
     3. Delete contact
     4. Print contact list
     5. Set contact filename
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
