[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=7858737&assignment_repo_type=AssignmentRepo)
# CPSC 323 Parsing Project

This is our project.

## Team members and emails

Jason Angel jasonangel@csu.fullerton.edu

## How to compile and execute
For assignment 2, make sure you are in  default-grammar-parser repository and run the program:
```
python3 main.py code.txt 
```

## Inputs and outputs
Input:
```
a  = b + c + d
```

Output:
```
1. E0 | id = id + id + id $ | Shift
2. E0id3 | = id + id + id $ | Reduce
3. E0E2 | = id + id + id $ | Shift
4. E0E2=5 | id + id + id $ | Shift
5. E0E2=5id8 | + id + id $ | Reduce
6. E0E2=5E7 | + id + id $ | Shift
7. E0E2=5E7+9 | id + id $ | Shift
8. E0E2=5E7+9id10 | + id $ | Reduce
9. E0E2=5E7 | + id $ | Shift
10. E0E2=5E7+9 | id $ | Shift
11. E0E2=5E7+9id10 | $ | Reduce
12. E0E2=5E7 | $ | Reduce
13. E0S1 | $ | ACCT
```
