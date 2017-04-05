#	Group 29: Team 2
#	2012A7PS084P: Srishti Dhamija
#	2012C6PS736P: Astha Gupta	

#this is a make file for parser and lexer 

main: driver.o parser.o parseFunctions.o lex.o list.o stack.o tree.o lookup.o AST.o symbolTable_new.o typecheck.o semantic.o
	gcc -g -o compiler driver.o parser.o parseFunctions.o lex.o list.o stack.o tree.o lookup.o AST.o symbolTable_new.o typecheck.o semantic.o -lm

parser.o: parser.c
	gcc -c parser.c

parseFunctions.o: parseFunctions.c
	gcc -c parseFunctions.c

symbolTable_new.o: symbolTable_new.c
	gcc -c symbolTable_new.c

driver.o: driver.c
	gcc -c driver.c

lex.o: lex.c
	gcc -c lex.c

list.o: list.c
	gcc -c list.c

lookup.o: lookup.c
	gcc -c lookup.c

stack.o: stack.c
	gcc -c stack.c

tree.o: tree.c
	gcc -c tree.c

AST.o: AST.c
	gcc -c AST.c

typecheck.o: typecheck.c
	gcc -c typecheck.c

semantic.o: semantic.c
	gcc -c semantic.c
default: 
	gcc parserDSPointer.o lex.o stack.o tree.o
