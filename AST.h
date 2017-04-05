/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include "tree.h"
#ifndef _AST_H
#define  _AST_H

Tree * _nullNodes(Tree* t);
void nullNodes(TLink link);

void _printAST(Tree *t,FILE *tok);
void printAST(TLink t,FILE *tok);

void deleteNode(TLink linkP,TLink linkC,int i);

Tree* _removeUseless(Tree* t);
void removeUseless(TLink link);

TLink pushNode(TLink link);
int weight(TLink link);
int impNode(TLink link);
Tree* _pruning( Tree * t);
void pruning(TLink link);

Tree* _convertAST(Tree * t);

#endif
