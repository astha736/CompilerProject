/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include "stack.h"
#include "tree.h"

#ifndef PARSEFUNCTIONS_H
#define PARSEFUNCTIONS_H

int parse_table[51][99]; 

int follow(int nt,int t);
char * giveName(int element);
void init_table();
void table(Stack * stack , int action,TLink link);

#endif


