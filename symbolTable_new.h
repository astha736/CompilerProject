#include <stdio.h>
#include "list.h"

#ifndef _SYMBOLTABLE_NEW_H
#define _SYMBOLTABLE_NEW_H

#define MAX_PARAMS 10

typedef struct symbolTableEntry {
	char value[25];			// Identifier
	int enumval;			// Type
	int declaration;		// Line no (Declaration)
	double scope;			// Scope
	int lowerbound;			// Lower bound (if array type)
	int upperbound;			// Upper bound (if array type)
	int argc;			// Argument count (if function signature)
	int returntype;			// Return type (if function signature)
	int param_types[MAX_PARAMS];	// Argument types (if function signature)	
	int refcount;			// No. of references
	int referenced[25];		// Line nos (Referenced)
	struct symbolTableEntry *next;
} symbolTableEntry;

typedef struct symbolTable {
    int size;       
    symbolTableEntry **table; 
} symbolTable;

symbolTable* create_symbol_table(int size);

unsigned int hash_entry(symbolTable *symTable, char str[]);

symbolTableEntry* lookup_current_scope(symbolTable *symTable, char value[], double currscope);

symbolTableEntry* lookup_enclosing_scope(symbolTable *symTable, char value[], double currscope);

symbolTableEntry* lookup(symbolTable *symTable, char value[]);

symbolTable* insert_entry(symbolTable *symTable, symbolTableEntry *entry); 

void print_symbol_table(symbolTable *symTable, FILE *fp);

symbolTableEntry* create_entry(symbolTableEntry *entry);

symbolTable* populate_symbol_table(list* tokenStream, symbolTable *symTable);

void print_symbol_table_entry(symbolTableEntry *entry);

#endif

