/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include "type.h"
#include <stdio.h>

#ifndef LIST_H
#define LIST_H

typedef struct node {
    token tk;
    struct node * next;
} node_t;

typedef struct _list {
    node_t* head;
    int size;
} list;

list* create_list(token tk);
list* addListNode(token tk, list *l);
void print_tokens(list *s, FILE *fp);

#endif
