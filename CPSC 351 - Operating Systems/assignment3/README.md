# Assignment 3 - Synchronization

Homework is to be completed individually.  When you are done, please upload your .cpp file to Gradescope.  Be sure to name it appropriately.  For example, cs351_assignment3_john_oates.cpp.

Assignment 3: Write a C or C++ program to demonstrate thread synchronization.  Your main function should first create a file called synch.txt.  Then it will create two separate threads, Thread-A and Thread-B.  Both threads will open synch.txt and write to it. Thread-A will write the numbers 1 - 26 twenty times in nested for loops then exit. In other words, print 1 - 26 over and over again on separate lines for at least 20 times. Thread-B will write the letters A - Z twenty times in nested for loops then exit.  You must use a mutex lock to control synchronization between the two threads.  When the program is complete, the synch.txt file should look like this:

 

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26

1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26

..... 20x

A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

A B C D E F G H I J K L M N O P Q R S T U V W X Y Z

... 20x

When you are satisfied that the program works as expected, remove the mutex locks and see what the file looks like after running the program (just for fun
