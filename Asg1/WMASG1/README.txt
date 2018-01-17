////////////////////////////////////////////////
					Read Me			Robert James
////////////////////////////////////////////////

1. oc.cpp: Main file which is a modified version of Wesley Mackey's cppstrtok.cpp. Its main function is to read in from a command line "oc [-ly] [-@ flag ...] [-D string] program.oc" where oc is the programs name -ly flex flags and -@ flag and -D string are the Debug options. After receiving the program.oc the program will create a hash table called program.str or if there is an error program.err

2.auxlib.c/h: supporting function for the main program created by Wesley Mackey and includes the debugging macros as well as other auxiliary functions

3.stringset.c/h: supporting function for the main program created by Wesley Mackey creates an hash set from and undordered set and writes it to an output file.

