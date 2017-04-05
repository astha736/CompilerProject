/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include "tree.h"

#ifndef STACK_H
#define STACK_H

typedef struct sElem{
	int child;
	TLink parent;
} sElem;

typedef struct Stack
{
        int size;		//Capacity of the stack 
        int currsize;		//Current size of the stack
        sElem *elements;	//Pointer to the array of elements 
} Stack;

Stack * createStack(int maxElements);
int NotEmpty(Stack *S);
sElem Top(Stack *S);
void Push(Stack *S,sElem element);

#endif

