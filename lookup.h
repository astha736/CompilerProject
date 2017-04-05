/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include "type.h"

#ifndef _LOOKUP_H
#define _LOOKUP_H

typedef struct list_node {
	char str[25];
	int enumval;
	struct list_node *next;
} list_node;

typedef struct hash_table {
    int size;       
    list_node **table; 
} hash_table;

hash_table *create_hash_table(int size);
unsigned int hash(hash_table *hashtable, char str[]);
int lookup_string(hash_table *hashtable, char str[]);
int add_string(hash_table *hashtable, char str[], int  enumval);
void free_table(hash_table *hashtable);
hash_table *init_hash_table(int size);

#endif

