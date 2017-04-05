/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include <string.h>

#include <stdlib.h>
#include <stdio.h>
#include "parser.h"
#include "stack.h"
#include "tree.h"
Tree createTree()
{
	Tree t;
	t.root = NULL;
	t.totalLeafNodes = 0;
	t.totalNodes = 0;
	//printf("TREE CREATED SUCCESSFULLY\n");
	return t;
}

TLink createNode(int enumval,char value[25])
{
	TNode* newNode;
	newNode = (TNode*)malloc(sizeof(TNode));
	newNode->enumval = enumval;
	strcpy(newNode->value, value);
	newNode->type = -1;
	newNode->no_of_children = 0;
	newNode->parent = NULL;
	newNode->childID= -1;
	return newNode;
	
}

void addNode(Tree *t, TLink linkParent, TLink linkChild)
{
	//printf("**********NUMBER OF NODES BEFORE ADDNODE ARE %d*******************************\n", t->totalNodes);
	
	if (linkParent == NULL && t->totalNodes != 0) return;
	//error

	linkChild->parent = linkParent;
	
	 
	if (t->totalNodes > 0) //root node already exits 
	{
		linkChild->childID = linkParent->no_of_children; //this is the current number of children 
		linkParent->children[linkParent->no_of_children] = linkChild;//index starts from 0
		linkParent->no_of_children++;
		
		if (linkParent->no_of_children > 1)
		{	//only when after adding no of chidren > 1 then new leaf added 
			t->totalLeafNodes++;
		}
	}
	else//root node 
	{	linkParent->childID = 0;
		t->root = linkParent;
		linkChild->childID = linkParent->no_of_children; //this is the current number of children 
		linkParent->children[linkParent->no_of_children] = linkChild;//index starts from 0
		linkParent->no_of_children++;
		t->totalLeafNodes = 1;
		t->totalNodes = 1;
	}
	t->totalNodes++;
	//printf("************************NODE ADDED, NUMBER OF NODES ARE %d*******************************\n", t->totalNodes);
	
}

void printNodes(TLink t, FILE *fp) {
int i;
fprintf(fp, "NODE:%s\n",t->value);
Stack* s = createStack(MAX_NO_CHILDREN);
sElem se;
for(i=0;i<t->no_of_children;i++)
{
	fprintf(fp, "CHILD %d:%s %d\n",i+1,t->children[i]->value, t->no_of_children);
	se.child = t->children[i]->enumval;
	se.parent = t->children[i];
	Push(s,se);
}
while(NotEmpty(s))
{
se = Top(s);
printNodes(se.parent, fp);
}
}

void printTree(Tree *t, FILE *fp) {
fprintf(fp, "NODE:%s\n",t->root->value);
printNodes(t->root, fp);
}

