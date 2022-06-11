# Parser Generator

Parser Generator is a Java program for generating CLR parser tables.

## Your Task

This directory is for assignment 1. Run the program to generate the CFG specified in grammar.txt. Look at grammar.txt and get to know how the formatting works. You can also investigate the source code of the parser generator to see how it works. You will need the generated parse table for assignment 2.

## How to run

Have the latest version of the Java runtime environment installed.

```
java -jar ParserGenerator [path to grammar file]
```

## Grammar file

Grammar files specify the context-free grammar to generate a CLR parser table for. All productions are in the form A -> B where A is a single nonterminal and B is one or more terminals and nonterminals separated by spaces. Epsilon can be specified as the string epsilon but should be avoided. The last line of the grammar file contains a label "Terminals:" with all terminals in the language listed separated by spaces. See the grammar.txt file in ParserGenerator for 
an example grammar file format.

## Compiling

You will need the latest Java JDK along with Apache Maven. Compiling the program is as simple as executing the following command in ParserGenerator.

```
mvn package
```

Note: The binary is provided in ParserGenerator/, you do not need to compile this program, but must have the latest JDK installed.