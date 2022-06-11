# Laboratory 5

## Laboratory Objectives
1. Explore and use various tools such as: GitHub, VirtualBox, Tuffix, Linux Terminal, and Atom.
1. Write a Python program using:
     1. modules
     2. packages
     3. functions using keyword arguments
1. Run and test a Python program.

## Getting Started
1. Open the Terminal program in Tuffix.
1. Change the present working directory to the `Documents` directory by typing the following command at the command prompt:

    ```
    cd Documents
    ```

1. Make a copy of this Github repository on your computer using the `git` and `clone` commands that you will input to the terminal. The commands take a URL as a parameter to specify where it can get a copy of the repository. You can find the URL by clicking on the green *Clone or download* button at the top right part of this page. Copy the URL and replace the example text shown below. Note that `username` should be replaced with your own Github username. When you hit <kbd>Enter</kbd> it will ask you to provide your Github username and token. Once done, you will have a copy of the repository on your computer.
    ```
    git clone https://github.com/CSUF-CPSC223P-STMAY-2021F/lab05-username.git
    ```
1. Navigate into the new directory using the command line. Note that `username` should be replaced with your own Github username.  As a shortcut, you can type the first few letters of the folder name and press <kbd>Tab</kbd> so that it auto completes the folder name for you.

     ```
     cd lab05-username
     ```
     
## Program Instructions
1. Write a Python package with sub-packages, modules, and functions using keyword arguments.  Use the following directory outline and module names (your first starting point should be a directory called `mathematics` within your `lab05-username` directory):
     ```
	mathematics/
		__init__.py
		whoami.py
		numbers/
			__init__.py
			whoami.py
			series.py
			simple.py
		geometry/
			__init__.py
			whoami.py
			rectangle.py
			circle.py
			cube.py
     ```

1. Create a `mathematics` package.
     1. Initialize the `__all__` variable to the `whoami` module.
     1. Create a `whoami` module.
          1. Create a function named `getname` which returns the `__name__` variable.
     1. Create a `numbers` sub-package.
          1. Initialize the `__all__` variable to the `whoami` and `series` modules.
          1. Create a `whoami` module.
               1. Create a function named `getname` which returns the `__name__` variable.
          1. Create a `series` module.
               1. Create a function named `sum` which receives a keyword parameter `list` and returns the sum of all the values in the list.
               1. Create a function named `average` which receives a keyword parameter `list` and returns the average of all the values in the list.
          1. Create a `simple` module.
               1. Create a function named `addition` which receives the keyword parameters `left` and `right` and returns left plus right.
               1. Create a function named `subtraction` which receives the keyword parameters `left` and `right` and returns left minus right.
               1. Create a function named `multiplication` which receives the keyword parameters `left` and `right` and returns left multiplied by right.
               1. Create a function named `divison` which receives the keyword parameters `left` and `right` and returns left divided by right.
     1. Create a `geometry` sub-package.
          1. Initialize the `__all__` variable to the `whoami`, `circle`, and `cube` modules.
          1. Create a `whoami` module.
               1. Create a function named `getname` which returns the `__name__` variable.
          1. Create a `rectangle` module.
               1. Create a function named `perimeter` which receives a keyword parameters `length` and `width` and returns (2l + 2h).
               1. Create a function named `area` which receives a keyword parameters `length` and `width` and returns (l * h).
          1. Create a `circle` module.
               1. Create a function named `circumference` which receives the keyword parameter `radius` and returns (2 * pi * r).
               1. Create a function named `area` which receives the keyword parameter `radius` and returns (pi * r * r).
          1. Create a `cube` module.
               1. Create a function named `surface_area` which receives the keyword parameter `side` and returns (2 * s * 6).
               1. Create a function named `volume` which receives the keyword parameter `side` and returns (s * s * s).
5. Run the program using the command below and repeat the steps above until you are satisfied your program output meets the above requirements.

    ```
    python3 -m main
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

When you completed the final Github push, go back into github.com through the browser interface and ensure all your files have been correctly updated.  Your files should be exactly outline using the directory structure in step 1.
    
## Grading
1. All points add up to a total of 100 points possible as detailed below.  Partial credit will be given where applicable.

| Points | Description |
| --- | --- |
|50|initial git clone of this repository to your Tuffix machine|
|30|all files submitted in accordance with step 1 and meet the program requirements|
|10|unit testing test.txt file results submitted|
|10|unit testing passes each test|
