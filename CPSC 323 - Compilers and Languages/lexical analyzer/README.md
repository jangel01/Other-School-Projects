# How to run program
Make sure you have all the following files:

	scanning_table.csv
	
	reserved_table.csv
	
	token_table.csv
	
	lexer.py
	
	main.py
And one of the folowing source code files:

	test1.txt (defualt)
	
	test2.txt 
	
	or
	
	your own test file
	
This program was ran on Pycharm, but should work for other IDEs as well. If necessary, change any file paths when prompted by the program. 

If all paths lead to exisiting files and the tables are in csv format, the program should then repeatedly prompt the user on requesting tokens from the source code file until it is exhausted. 

# Test 1 expected output
Source code:
```
int main() {
    // comment
    printf("Hello world\n");
    char a = '\n';
    char c = 'x';
    float w;
	int x, y, z;
	w = 7.12e11;
	x = 334;
	x++;
	y = 5;
	z = x + y;
	/*
	    Multi-line
	    comment
	*/
	return 0;
}
```
Output:
```
Would you like to modify any file paths?

        1. Yes
        2. No

>> 2
Press enter to request tokens. Enter any other key to stop requesting.

Token:      keyword   Lexeme: int

Token:   identifier   Lexeme: main

Token:    leftParen   Lexeme: (

Token:   rightParen   Lexeme: )

Token:    leftBrace   Lexeme: {

Token:   identifier   Lexeme: printf

Token:    leftParen   Lexeme: (

Token:       string   Lexeme: "Hello world\n"

Token:   rightParen   Lexeme: )

Token:    semicolon   Lexeme: ;

Token:      keyword   Lexeme: char

Token:   identifier   Lexeme: a

Token:     assignOp   Lexeme: =

Token:         char   Lexeme: '\n'

Token:    semicolon   Lexeme: ;

Token:      keyword   Lexeme: char

Token:   identifier   Lexeme: c

Token:     assignOp   Lexeme: =

Token:         char   Lexeme: 'x'

Token:    semicolon   Lexeme: ;

Token:      keyword   Lexeme: float

Token:   identifier   Lexeme: w

Token:    semicolon   Lexeme: ;

Token:      keyword   Lexeme: int

Token:   identifier   Lexeme: x

Token:        comma   Lexeme: ,

Token:   identifier   Lexeme: y

Token:        comma   Lexeme: ,

Token:   identifier   Lexeme: z

Token:    semicolon   Lexeme: ;

Token:   identifier   Lexeme: w

Token:     assignOp   Lexeme: =

Token: FloatLiteral   Lexeme: 7.12e11

Token:    semicolon   Lexeme: ;

Token:   identifier   Lexeme: x

Token:     assignOp   Lexeme: =

Token:   IntLiteral   Lexeme: 334

Token:    semicolon   Lexeme: ;

Token:   identifier   Lexeme: x

Token:       incrOp   Lexeme: ++

Token:    semicolon   Lexeme: ;

Token:   identifier   Lexeme: y

Token:     assignOp   Lexeme: =

Token:   IntLiteral   Lexeme: 5

Token:    semicolon   Lexeme: ;

Token:   identifier   Lexeme: z

Token:     assignOp   Lexeme: =

Token:   identifier   Lexeme: x

Token:        addOp   Lexeme: +

Token:   identifier   Lexeme: y

Token:    semicolon   Lexeme: ;

Token:      keyword   Lexeme: return

Token:   IntLiteral   Lexeme: 0

Token:    semicolon   Lexeme: ;

Token:   rightBrace   Lexeme: }
Reached end of token stream. Ending program.

Process finished with exit code 0
```

# Test 2 expected outpout
Source code:
```
int main(int argc) {
	int x, y, z;
	x = 0;
	y = 1;
	z = sum(x, y);
	z += mult (x, y);
	return z;
}

int sum(int a, int b) {
	return a + b;
}

int mult(int a, int b) {
	return a * b;
}
```
Output:
```
Would you like to modify any file paths?

        1. Yes
        2. No

>> 1
Which file path would you lime to modify?

        1. Scanning file
        2. Token file
        3. Reserved file
        4. Source code file
        5. Exit
        
>> 4
Input source code file path: test2.txt
Which file path would you lime to modify?

        1. Scanning file
        2. Token file
        3. Reserved file
        4. Source code file
        5. Exit
        
>> 5
Press enter to request tokens. Enter any other key to stop requesting.

Token:      keyword   Lexeme: int

Token:   identifier   Lexeme: main

Token:    leftParen   Lexeme: (

Token:      keyword   Lexeme: int

Token:   identifier   Lexeme: argc

Token:   rightParen   Lexeme: )

Token:    leftBrace   Lexeme: {

Token:      keyword   Lexeme: int

Token:   identifier   Lexeme: x

Token:        comma   Lexeme: ,

Token:   identifier   Lexeme: y

Token:        comma   Lexeme: ,

Token:   identifier   Lexeme: z

Token:    semicolon   Lexeme: ;

Token:   identifier   Lexeme: x

Token:     assignOp   Lexeme: =

Token:   IntLiteral   Lexeme: 0

Token:    semicolon   Lexeme: ;

Token:   identifier   Lexeme: y

Token:     assignOp   Lexeme: =

Token:   IntLiteral   Lexeme: 1

Token:    semicolon   Lexeme: ;

Token:   identifier   Lexeme: z

Token:     assignOp   Lexeme: =

Token:   identifier   Lexeme: sum

Token:    leftParen   Lexeme: (

Token:   identifier   Lexeme: x

Token:        comma   Lexeme: ,

Token:   identifier   Lexeme: y

Token:   rightParen   Lexeme: )

Token:    semicolon   Lexeme: ;

Token:   identifier   Lexeme: z

Token:     assignOp   Lexeme: +=

Token:   identifier   Lexeme: mult

Token:    leftParen   Lexeme: (

Token:   identifier   Lexeme: x

Token:        comma   Lexeme: ,

Token:   identifier   Lexeme: y

Token:   rightParen   Lexeme: )

Token:    semicolon   Lexeme: ;

Token:      keyword   Lexeme: return

Token:   identifier   Lexeme: z

Token:    semicolon   Lexeme: ;

Token:   rightBrace   Lexeme: }

Token:      keyword   Lexeme: int

Token:   identifier   Lexeme: sum

Token:    leftParen   Lexeme: (

Token:      keyword   Lexeme: int

Token:   identifier   Lexeme: a

Token:        comma   Lexeme: ,

Token:      keyword   Lexeme: int

Token:   identifier   Lexeme: b

Token:   rightParen   Lexeme: )

Token:    leftBrace   Lexeme: {

Token:      keyword   Lexeme: return

Token:   identifier   Lexeme: a

Token:        addOp   Lexeme: +

Token:   identifier   Lexeme: b

Token:    semicolon   Lexeme: ;

Token:   rightBrace   Lexeme: }

Token:      keyword   Lexeme: int

Token:   identifier   Lexeme: mult

Token:    leftParen   Lexeme: (

Token:      keyword   Lexeme: int

Token:   identifier   Lexeme: a

Token:        comma   Lexeme: ,

Token:      keyword   Lexeme: int

Token:   identifier   Lexeme: b

Token:   rightParen   Lexeme: )

Token:    leftBrace   Lexeme: {

Token:      keyword   Lexeme: return

Token:   identifier   Lexeme: a

Token:       multOp   Lexeme: *

Token:   identifier   Lexeme: b

Token:    semicolon   Lexeme: ;

Token:   rightBrace   Lexeme: }
Reached end of token stream. Ending program.

Process finished with exit code 0
```
