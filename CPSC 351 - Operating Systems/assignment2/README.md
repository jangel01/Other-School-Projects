# Assignment 2 - Command Line Interpreter

Homework is to be completed individually. You will turn in two files

    Source code file (written in c or c++) named: cs351_assignment2_firstName_lastName.cpp. 
    Executable filenamed: cs351_assignment2_firstName_lastName.exe.

Be sure to include your name at the top of each source file submitted. For example:
// ConsoleApplication1.cpp : Simple Command Line Interpreter.
// Copyright (c) John Oates 8/26/2016
//

Interactive Shell:
Write a C/C++ program to implement an interactive shell in which users can execute commands. Call this program myShell. Create an infinite loop (while(1)) that repeatedly prompts the user to enter a command (see example output and input below). Before executing the command entered by the user, the command must be compared against the list of supported commands shown here:

dir
help
vol
path
tasklist
notepad
echo
color
ping

Since some commands require more than one argument (e.g. echo, color, ping), you will need to parse the user input into its arguments. Consider using the strtok() function.

For example:

COMMAND TYPED BY THE USER:
ping 192.168.1.1

ARGUMENT 0: "ping"
ARGUMENT 1: "192.168.1.1"

If the command in argument[0] is in the list above, your program must execute the command in a child thread via CreateThread(). In other words, create a child thread that executes the command.  You do not need to actually write code to execute each command.  Simply pass the command into the system call, system() and let the operating system handle the processing for you.  The parent thread waits for the child to terminate. If the user types exit or quit, your shell should simply terminate. Sample output and input are shown below:

Welcome to myShell

==> dir

Volume in drive C is Windows
Volume Serial Number is 301D-8616

Directory of c:\Projects\ConsoleApplication1\ConsoleApplication1

08/27/2016 08:59 AM     <DIR>             .
08/27/2016 08:59 AM     <DIR>               ..
08/27/2016 08:59 AM                    1,686 ConsoleApplication1.cpp
08/25/2016 05:42 PM                    8,060 ConsoleApplication1.vcxproj
08/25/2016 05:42 PM                    1,346 ConsoleApplication1.vcxproj.filters
08/27/2016 09:00 AM     <DIR>              Debug
08/25/2016 05:42 PM                    1,799 ReadMe.txt
08/25/2016 05:42 PM                       306 stdafx.cpp
08/25/2016 05:42 PM                       320 stdafx.h
08/25/2016 05:42 PM                       314 targetver.h
                     7 File(s) 13,831 bytes
                     3 Dir(s) 526,080,049,152 bytes free

==> ping 192.168.1.1

Pinging 192.168.1.1 with 32 bytes of data:
Reply from 192.168.1.1: bytes=32 time=2ms TTL=64
Reply from 192.168.1.1: bytes=32 time=1ms TTL=64
Reply from 192.168.1.1: bytes=32 time=3ms TTL=64
Reply from 192.168.1.1: bytes=32 time=4ms TTL=64

Ping statistics for 192.168.1.1:
    Packets: Sent = 4, Received = 4, Lost = 0 (0% loss),
Approximate round trip times in milli-seconds:
    Minimum = 1ms, Maximum = 4ms, Average = 2ms

==> exit

Thanks for using myShell!

Assumptions: Assume arguments within myShell do not contain spaces. In other words, don't worry about parsing out quoted strings in your argument list (e.g.cat a.txt "some file.txt"). You may assume that no more than four arguments will be used on the command line (i.e. similar to argv[0], argv[1], argv[2], and argv[3])
