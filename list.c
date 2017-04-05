/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"
#include "list.h"

node_t *head = NULL;
node_t *curr = NULL;
static int listsize = 0;

list* create_list(token tk)
{
    list* l = (list*)malloc(sizeof(list));
    node_t *ptr = (node_t*)malloc(sizeof(node_t));
    if(NULL == ptr)
    {
        printf("List creation unsuccessful.\n");
        return NULL;
    }
    ptr->tk = tk;
    ptr->next = NULL;

    head = curr = ptr;
    l->head = ptr;
    l->size = 1;
    return l;
}

list* addListNode(token tk, list *l)
{
    if(NULL == l->head)
    {
        return (create_list(tk));	
    }
    
    node_t *ptr = (node_t*)malloc(sizeof(node_t));
    if(NULL == ptr)
    {
        printf("Node addition unsuccessful.\n");
        return NULL;
    }
	
    ptr->tk = tk;
    ptr->next = NULL;
    curr->next = ptr;
    curr = ptr;
    l->size++;
    
    return l;
}

void print_tokens(list *s, FILE *fp)
{   	printf("\tPrinting tokens...\n");
    node_t *ptr = s->head;
	fprintf(fp, "\n  %-25s \t| %-20s \t| %-5s \t| %-5s", "TOKEN TYPE", "VALUE", "LINENO", "ENUM");
    while(ptr != NULL)
    {
	fprintf(fp, "\n  %-25s \t| %-20s \t| %-5d \t| %-5d", ptr->tk.type, ptr->tk.value, ptr->tk.lineno, ptr->tk.enumval);
        ptr = ptr->next;
    }
	printf("\t...End of token stream. \n\tAll tokens printed to file \"tokens.txt\".\n");
    return;
}
