/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbolTable.h"

symbolTable* create_symbol_table(int size) {
	symbolTable *new_table;
	if (size<1) return NULL; 

        if ((new_table = malloc(sizeof(symbolTable))) == NULL) {
            return NULL;
        }
        
        if ((new_table->table = malloc(sizeof(symbolTableEntry *) * size)) == NULL) {
            return NULL;
        }

	int i;
        for(i=0; i<size; i++) new_table->table[i] = NULL;
        new_table->size = size;
	
        return new_table;
}

unsigned int hash_entry(symbolTable *symTable, char value[]) {
        unsigned int hashval;
        hashval = 0;
        for(; *value != '\0'; value++) hashval = *value + (hashval << 5) - hashval;
        return hashval % symTable->size;
}

symbolTableEntry* lookup_current_scope(symbolTable *symTable, char value[], int currscope) {
        symbolTableEntry *list;
        unsigned int hashval = hash_entry(symTable, value);

        for(list = symTable->table[hashval]; list != NULL; list = list->next) {
		if ((strcmp(list->value, value) == 0) && (list->scope == currscope)) return list;
        }
        return NULL;
}

symbolTableEntry* lookup_enclosing_scope(symbolTable *symTable, char value[], int currscope) {
        symbolTableEntry *list;
        unsigned int hashval = hash_entry(symTable, value);

        for(list = symTable->table[hashval]; list != NULL; list = list->next) {
		if (strcmp(list->value, value) == 0) return list;
        }
        return NULL;
}

symbolTable* insert_entry(symbolTable *symTable, char value[],char type[], int declaration, int scope, int lowerbound, int upperbound, int argc, char ret[]) { 

        symbolTableEntry *entry = (symbolTableEntry*) malloc(sizeof(symbolTableEntry));
	strcpy(entry->value, value);
	strcpy(entry->type, type);
	strcpy(entry->returntype, ret);
	entry->declaration = declaration;
	entry->scope = scope;
	entry->lowerbound = lowerbound;		
	entry->upperbound = upperbound;		
	entry->argc = argc;
	unsigned int hashval = hash_entry(symTable, entry->value);
       //	printf("1\n");
        if(lookup_current_scope(symTable, entry->value, entry->scope) != NULL) {
	printf("Error: Multiple declaration of %s in scope %d.\n", entry->value, entry->scope);
	return symTable;
	}
		//printf("2\n");
	symbolTableEntry *temp;
	temp = symTable->table[hashval];
	if(temp == NULL) {
	//printf("3\n");
        entry->next = NULL;
        symTable->table[hashval] = entry; }
	else {
	//printf("4\n");
	symTable->table[hashval] = entry;
	entry->next = temp;
	}
	//printf("Success\n");
        return symTable;
}

void print_symbol_table(symbolTable *symTable, FILE *fp) {
	symbolTableEntry *list;
	int i;
	fprintf(fp, "\n  %-10s \t| %-15s \t| %-5s \t| %-3s \t| %-5s \t| %-5s \t| %-3s \t| %-5s", "VALUE", "TYPE", "LINENO", "SCOPE", "LBOUND", "UBOUND", "ARGC", "RET_TYPE");
	for (i=0; i<symTable->size; i++) {
		for(list = symTable->table[i]; list != NULL; list = list->next) {
			fprintf(fp, "\n  %-10s \t| %-15s \t| %-5d \t| %-5d \t| %-5d \t| %-5d \t| %-3d \t| %-5s", list->value, list->type, list->declaration, list->scope, list->lowerbound, list->upperbound, list->argc, list->returntype);
		}
	}

}
