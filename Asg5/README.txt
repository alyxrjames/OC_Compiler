////////////////////////////////////////////////
					Read Me			Robert James
////////////////////////////////////////////////

1. oc.cpp: Main file which is a modified version of Wesley Mackey's cppstrtok.cpp. Its main function is to read in from a command line "oc [-ly] [-@ flag ...] [-D string] program.oc" where oc is the programs name -ly flex flags and -@ flag and -D string are the Debug options. After receiving the program.oc the program will create a hash table called program.str as well as program.tok or if there is an error program.err. Finally the program will generate an AST for the given program file called program.ast

2. auxlib.c/h: supporting functions for the main program created by Wesley Mackey and includes the debugging macros as well as other auxiliary functions.

3. stringset.c/h: supporting functions for the main program created by Wesley Mackey creates an hash set from and undordered set and writes it to an output file.

4. astree.c/h: supporting functions for the program created by Wesley Mackey. Creates a vector representation of an abstract syntax tree and useful manipulation functions.

5. lyutils.c/h: supporting functions for the program created by Wesley Mackey. Utility functions to interface with bison the lexical analyzer or scanner.

6. Makefile: builds the executable "oc" with MAKE created by Wesley Mackey.

7. scanner.l: contains the Lex patterns for the program that are recognized by the compiler. Note* utilizes parts from Wesley Mackey's code in lexer.l.

8. parser.y: Heavily modified version of Wesley Mackeys dummy program with clear grammar definitions utililizing LALR(1)

Note: This is to be regraded for asignment 4

