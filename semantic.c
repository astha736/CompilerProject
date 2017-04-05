#include <stdlib.h>
#include "list.h"
#include "symbolTable_new.h"
#include "parseFunctions.h"

#define MAX_SCOPE_COUNT 10

void semanticAnalysis(list* tokenStream, symbolTable* symTable) {
	double currscope = 0, prevscope = 0;
	int temp = 0, errcount = 0;
	node_t *ptr = tokenStream->head;
	int scopecount[MAX_SCOPE_COUNT];
	for (temp = 0; temp < MAX_SCOPE_COUNT; temp++) {
	scopecount[temp] = 0;
	}
	temp = 0;
	symbolTableEntry* entry = (symbolTableEntry*)malloc(sizeof(symbolTableEntry));
	symbolTableEntry* tempentry = (symbolTableEntry*)malloc(sizeof(symbolTableEntry));

	while(ptr != NULL) {
	int argcount = 0; int fargs[10]; temp = 0;
		switch(ptr->tk.enumval) {

			case TK_START:   	prevscope = currscope;
					 	temp = (int) currscope;
					 	temp++;
					 	scopecount[temp]++;
					 	currscope = temp + scopecount[temp]*0.1;
					 	break;

			case TK_END:     	prevscope = currscope;
					 	temp = (int) currscope;
					 	temp--;
					 	currscope = temp + scopecount[temp]*0.1;
					 	break;
	
			case TK_IDENTIFIER:	entry = lookup_enclosing_scope(symTable, ptr->tk.value, currscope);
						if(entry == NULL) break;
	
						//Is this the definition?
						if(ptr->tk.lineno == entry->declaration) {
						if(entry->enumval == function) {
							while(ptr->tk.enumval != TK_RETURN) {
								ptr = ptr->next;
								switch(ptr->tk.enumval) {
								case TK_START:   	prevscope = currscope;
					 						temp = (int) currscope;
					 						temp++;
					 						scopecount[temp]++;
					 						currscope = temp + scopecount[temp]*0.1;
					 						break;

								case TK_END:     	prevscope = currscope;
					 						temp = (int) currscope;
					 						temp--;
					 						currscope = temp + scopecount[temp]*0.1;
					 						break;
							
								/*case TK_IDENTIFIER:	tempentry = lookup_enclosing_scope(symTable, ptr->tk.value, currscope);
								if(tempentry->enumval == function) 
								if(strcmp(tempentry->value, entry->value) == 0) 
								printf("ERROR: Line no. %d: Function call '%s': Recursive function definitions not allowed.\n", ptr->tk.lineno, entry->value);*/
								}
							ptr = ptr->next;
							}
						if((temp = lookup_enclosing_scope(symTable, ptr->next->tk.value, currscope)->enumval) != entry->returntype)
						printf("ERROR: Line no. %d: Function '%s': Expected return type '%s', got '%s'.\n", ptr->tk.lineno, giveName(entry->enumval), giveName(entry->returntype), giveName(temp));
						}
						break; 
						}
				
						switch(entry->enumval) {
							
						case TK_DATA_STRAND: 
						//Check array index out of bounds for get()
						//What about negative numbers?
						if(ptr->next->next->tk.enumval == TK_GET && ptr->next->next->next->next->tk.enumval == TK_INT) 									{ 
							      	temp = atoi(ptr->next->next->next->next->tk.value); 
							      	if(temp < entry->lowerbound || temp>entry->upperbound) {  
							     	printf("ERROR: Line no. %d : Array index out of bounds.\n", ptr->tk.lineno); 
								errcount++; } }	
								break;

						case function: ptr = ptr->next;
							while(ptr->tk.enumval != TK_RP) {
							if(ptr->tk.enumval == TK_IDENTIFIER) {
							if(lookup_enclosing_scope(symTable, ptr->tk.value, currscope)!=NULL)
					     		fargs[argcount] = lookup_enclosing_scope(symTable, ptr->tk.value, currscope)->enumval;
					     		argcount++; }			 
                   			 		ptr = ptr->next;
					 		} 
		//printf("%d %d \n", argcount, entry->argc);
		if (argcount != entry->argc) {printf("ERROR: Line no. %d : Incorrect no. of arguments for function '%s'.\n", ptr->tk.lineno, entry->value);}
		for(temp = 0; temp<argcount; temp++) 
		if(entry->param_types[temp] != fargs[temp]) printf("ERROR: Line no. %d : Function '%s': Expected argument type '%s', got '%s'.\n", ptr->tk.lineno, entry->value, giveName(entry->param_types[temp]), giveName(fargs[temp]));

							break;
						
						} break;
						
		}
		ptr = ptr->next;
	}

}
