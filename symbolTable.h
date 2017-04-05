/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include <stdio.h>

#ifndef _SYMBOLTABLE_H
#define _SYMBOLTABLE_H

#define MAX_PARAMS 10

typedef struct symbolTableEntry {
	char value[25];
	char type[25];
	int declaration;
	int scope;
	int lowerbound;		
	int upperbound;		
	int argc;	
	char returntype[25];	
	//Store memory location
	//Store params.
	struct symbolTableEntry *next;
} symbolTableEntry;

typedef struct symbolTable {
    int size;       
    symbolTableEntry **table; 
} symbolTable;

symbolTable* create_symbol_table(int size);
unsigned int hash_entry(symbolTable *symTable, char str[]);
symbolTableEntry* lookup_current_scope(symbolTable *symTable, char value[], int currscope);
symbolTableEntry* lookup_enclosing_scope(symbolTable *symTable, char value[], int currscope);
symbolTable* insert_entry(symbolTable *symTable, char value[],char type[], int declaration, int scope, int lowerbound, int upperbound, int argc, char ret[]);
void print_symbol_table(symbolTable *symTable, FILE *fp);
symbolTableEntry* create_entry(symbolTableEntry *entry);

/*
Hash Table of Lists: Operations

To process a use of x:
• look up x in the symbol table
• If it is not there, then issue an "undeclared variable" error

On scope exit:
• Scan all entries in the symbol table, looking at the first item on each list 
• If that item's level number = the current level number, then remove it from its list (and if the list becomes empty, remove the entire symbol-table entry)
• Finally, decrement the current level number */

#endif

