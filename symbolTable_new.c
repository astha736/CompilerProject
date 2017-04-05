#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include "list.h"
#include "type.h"
#include "parseFunctions.h"
#include "symbolTable_new.h"

#define MAX_SCOPE_COUNT 10

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

symbolTableEntry* lookup_current_scope(symbolTable *symTable, char value[], double currscope) {
        symbolTableEntry *list;
        unsigned int hashval = hash_entry(symTable, value);

        for(list = symTable->table[hashval]; list != NULL; list = list->next) {
		if ((strcmp(list->value, value) == 0) && (list->scope == currscope)) return list;
        }
        return NULL;
}

symbolTableEntry* lookup_enclosing_scope(symbolTable *symTable, char value[], double currscope) {
        symbolTableEntry *list;
        unsigned int hashval = hash_entry(symTable, value);

        for(list = symTable->table[hashval]; list != NULL; list = list->next) {
		if (strcmp(list->value, value) == 0 && (list->scope <= currscope)) return list;
        }
        return NULL;
}

symbolTableEntry* lookup(symbolTable *symTable, char value[]) {
        symbolTableEntry *list;
        unsigned int hashval = hash_entry(symTable, value);

        for(list = symTable->table[hashval]; list != NULL; list = list->next) {
		if (strcmp(list->value, value) == 0) return list;
        }
        return NULL;
}

symbolTable* insert_entry(symbolTable *symTable, symbolTableEntry *entry) { 

	symbolTableEntry* se = (symbolTableEntry*)malloc(sizeof(symbolTableEntry));
	strcpy(se->value, entry->value);
	se->enumval = entry->enumval;
	se->returntype = entry->returntype;
	se->declaration = entry->declaration;
	se->lowerbound = entry->lowerbound;
	se->upperbound = entry->upperbound;
	se->argc = entry->argc;
	se->scope = entry->scope;
	memcpy(se->param_types, entry->param_types, sizeof(entry->param_types));
	memcpy(se->referenced, entry->referenced, sizeof(entry->referenced));

	unsigned int hashval = hash_entry(symTable, se->value);
	symbolTableEntry *temp;
	temp = symTable->table[hashval];
	if(temp == NULL) {
        se->next = NULL;
        symTable->table[hashval] = se; }
	else {
	symTable->table[hashval] = se;
	se->next = temp;
	}
        return symTable;
}

void print_symbol_table(symbolTable *symTable, FILE *fp) {

	symbolTableEntry *list;
	int i;
	fprintf(fp, "\n  %-10s \t| %-15s \t| %-5s \t| %-3s \t| %-5s \t| %-5s \t| %-3s \t| %-5s", "VALUE", "TYPE", "LINENO", "SCOPE", "LBOUND", "UBOUND", "ARGC", "RET_TYPE");
	for (i=0; i<symTable->size; i++) {
		for(list = symTable->table[i]; list != NULL; list = list->next) {
			//printf("%s\n", list->value);
			fprintf(fp, "\n  %-10s \t| %-15s \t| %-5d \t| %-5lf \t| %-5d \t| %-5d \t| %-3d \t| %-5d", list->value, giveName(list->enumval), list->declaration, list->scope, list->lowerbound, list->upperbound, list->argc, list->returntype);
		}
	}

}

void print_symbol_table_entry(symbolTableEntry *entry) {
	
	printf("Printing symbol table entry:\n");
	printf("Value:\t %s\n", entry->value);
	printf("Type:\t %s\n", giveName(entry->enumval));
	printf("Decl:\t %d\n", entry->declaration);
	printf("Scope:\t %lf\nLower:\t %d\nUpper:\t %d\nArgc:\t %d\n", entry->scope, entry->lowerbound, entry->upperbound, entry->argc);
	printf("RetType:\t %s\n", giveName(entry->returntype));
	int i;
	for(i=0; i<entry->argc;i++) {
	printf("Argc type:\t %s\n", giveName(entry->param_types[i]));
	}
	for(i=0; i<entry->refcount;i++) {
	printf("Variable referenced in line:\t %d\n", entry->referenced[i]);
	}
	//Refcount and referenced
}

symbolTable* populate_symbol_table(list* tokenStream, symbolTable *symTable) {
	
	double currscope = 0;
	double prevscope = 0;
	double tempscope = 0;
	int scopecount[MAX_SCOPE_COUNT];
	int temp = 0;
	for (temp = 0; temp < MAX_SCOPE_COUNT; temp++) {
	scopecount[temp] = 0;
	}
	temp = 0;
	node_t *ptr = tokenStream->head;
	while(ptr != NULL)
    	{
	symbolTableEntry* entry = (symbolTableEntry*)malloc(sizeof(symbolTableEntry));
	symbolTableEntry* param = (symbolTableEntry*)malloc(sizeof(symbolTableEntry));
	switch(ptr->tk.enumval) {
	case TK_START:			 prevscope = currscope;
					 temp = (int) currscope;
					 temp++;
					 scopecount[temp]++;
					 currscope = temp + scopecount[temp]*0.1;
					 break;
	
	case TK_END:			 prevscope = currscope;
					 temp = (int) currscope;
					 temp--;
					 //printf("temp %d curr %lf\n", temp, currscope);
					 currscope = temp + scopecount[temp]*0.1;
					 //printf("curr %lf \n", currscope);
					 break;
					 
	case TK_IDENTIFIER:		 entry = lookup_enclosing_scope(symTable, ptr->tk.value, currscope);
					 // Has the variable been defined?
					 if(entry == NULL) { 
						printf("ERROR: Line no. %d : Variable '%s' not defined before use in current scope.\n", ptr->tk.lineno, ptr->tk.value); break;}
					 else	{ entry->referenced[entry->refcount] = ptr->tk.lineno;
						  entry->refcount++; //printf("%s found at %d.\n", entry->value, ptr->tk.lineno);
					 }
					 break;
	case TK_DATA_BASE:
	case TK_DATA_INT:		 entry->enumval = ptr->tk.enumval;
					 temp = ptr->tk.enumval;
					 ptr = ptr->next;
					 
					 // For function signatures
					 if(ptr->next->tk.enumval == TK_LP) {
					 //printf("Function call here %d\n", ptr->tk.lineno); 
					 strcpy(entry->value, ptr->tk.value);
					 entry->enumval = function;
					 entry->declaration = ptr->tk.lineno; 
					 entry->scope = currscope;
					 entry->lowerbound = entry->upperbound = -1;
					 entry->returntype = temp;
					 int argc = 0;
					 ptr = ptr->next;
					 while(ptr->tk.enumval != TK_RP) {
					     if(ptr->tk.enumval == TK_DATA_INT || ptr->tk.enumval == TK_DATA_BASE || ptr->tk.enumval ==  TK_DATA_STRAND) {
					     entry->param_types[argc] = ptr->tk.enumval;
					     argc++;
					     strcpy(param->value, ptr->next->tk.value);
					     param->enumval = ptr->tk.enumval;
					     param->declaration = ptr->next->tk.lineno;
					     param->scope = currscope;
					     param->lowerbound = param->upperbound = param->returntype = param->argc = param->refcount = 0;
					     symTable = insert_entry(symTable, param);
					     }			 
                   			 ptr = ptr->next;
					 } 
					 entry->argc = argc;
					 entry->referenced[0] = -1;
					if(lookup_current_scope(symTable, entry->value, currscope) != NULL) {
						printf("ERROR: Line no. %d : Function '%s': Overloading not permitted. '%s' first defined at line %d.\n", entry->declaration, entry->value, entry->value, lookup_current_scope(symTable, entry->value, currscope)->declaration);
						break;
						}
					 symTable = insert_entry(symTable, entry);
					 break;	
					 }		

					 // For variable declarations
					 while(ptr->tk.enumval != TK_SEMI) {
					 if(ptr->tk.enumval == 55) { 
						strcpy(entry->value, ptr->tk.value); 
						entry->declaration = ptr->tk.lineno;
						entry->scope = currscope;
						entry->lowerbound = entry->upperbound = entry->argc = -1;
						entry->returntype = -1;
						entry->param_types[0] = -1;
						entry->referenced[0] = -1;
						if(lookup_current_scope(symTable, entry->value, currscope) != NULL) {
						printf("ERROR: Line no. %d : Multiple definitions of '%s' within same scope. '%s' first defined at line %d.\n", entry->declaration, entry->value, entry->value, lookup_current_scope(symTable, entry->value, currscope)->declaration);
						break;
						}
						symTable = insert_entry(symTable, entry);
						}					 
                   			 ptr = ptr->next;
					 } 
					 break;

	case TK_DATA_STRAND:		 entry->enumval = ptr->tk.enumval;
					 temp = ptr->tk.enumval;
					 ptr = ptr->next;

					 // For function signatures
					 if(ptr->next->tk.enumval == TK_LP) {
					 //printf("Function call here %d\n", ptr->tk.lineno); 
					 strcpy(entry->value, ptr->tk.value);
					 entry->enumval = function;
					 entry->declaration = ptr->tk.lineno; 
					 entry->scope = currscope;
					 entry->lowerbound = entry->upperbound = -1;
					 entry->returntype = temp;
					 int argc = 0;
					 ptr = ptr->next;
					 while(ptr->tk.enumval != TK_RP) {
					     if(ptr->tk.enumval == TK_DATA_INT || ptr->tk.enumval == TK_DATA_BASE || ptr->tk.enumval ==  TK_DATA_STRAND) {
					     entry->param_types[argc] = ptr->tk.enumval;
					     argc++;
					     strcpy(param->value, ptr->next->tk.value);
					     param->enumval = ptr->tk.enumval;
					     param->declaration = ptr->next->tk.lineno;
					     param->scope = currscope;
					     param->lowerbound = param->upperbound = param->returntype = param->argc = param->refcount = 0;
					     symTable = insert_entry(symTable, param);
					     }			 
                   			 ptr = ptr->next;
					 } 
					 entry->argc = argc;
					 entry->referenced[0] = -1;
                         		 if(lookup_current_scope(symTable, entry->value, currscope) != NULL) {
						printf("ERROR: Line no. %d : Function '%s': Overloading not permitted. '%s' first defined at line %d.\n", entry->declaration, entry->value, entry->value, lookup_current_scope(symTable, entry->value, currscope)->declaration);
						break;
						}
					 symTable = insert_entry(symTable, entry);
					 break;	
					 }						

					 // For variable declarations
					 while(ptr->tk.enumval != TK_SEMI) {
					 if(ptr->tk.enumval == 55) { 
					
						  strcpy(entry->value, ptr->tk.value);
						  entry->declaration = ptr->tk.lineno;
				 	     	
						  while(ptr->tk.enumval != TK_RB) {
						    if(ptr->tk.enumval == 51) {
						    entry->upperbound = atoi(ptr->tk.value) - 1; }		
						    ptr = ptr->next; }
						    entry->scope = currscope;
						    entry->lowerbound = 0;
						    entry->argc = -1;
						    entry->returntype = -1;
						    entry->param_types[0] = -1;
						    entry->referenced[0] = -1;
					            if(lookup_current_scope(symTable, entry->value, currscope) != NULL) {
							printf("ERROR: Line no. %d : Multiple definitions of '%s' within same scope. '%s' first defined at line %d.\n", entry->declaration, entry->value, entry->value, lookup_current_scope(symTable, entry->value, currscope)->declaration);
						break;
						}
	         				    symTable = insert_entry(symTable, entry);
						  }					 
                   			 ptr = ptr->next;
					 } 
					 break;
	}
	ptr = ptr->next;
    	}
	return symTable;
}
