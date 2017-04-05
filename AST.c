/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include <stdlib.h>
#include <stdio.h>
#include "type.h"
#include "tree.h"
#include "parseFunctions.h"
#include "stack.h"

int impNode(TLink link)
{	
	switch(link->enumval)
	{
		case TK_MAIN:
		case TK_START:
		//case TK_END:
		//case TK_ENDMAIN:
		case TK_IDENTIFIER:
		//case TK_DOT: 
		case TK_INSERT:  
		case TK_ASSIGNOP: 
		case TK_INT: 
		case TK_STRINGCONSTANT:
		case TK_OR:
		case TK_AND:
		case TK_LT:
		case TK_GT:
		case TK_LE:
		case TK_GE:
		case TK_EQUAL: 
		case TK_NOTEQUAL:
		case TK_ADD:
		case TK_SUB:
		case TK_MUL:
		case TK_DIV: 
		case TK_BASE:
	    case TK_STRAND:
		case TK_LENGTH:
		case TK_GET:
		case TK_FOR:
		case TK_WHILE: 
		case TK_IF:
		case TK_RETURN:
		case TK_BREAK:
		case TK_DATA_INT:
		case TK_DATA_BASE: 
		case TK_DATA_STRAND:
		case TK_READSTRAND:
		case TK_PRINTINT:
		case TK_DOLLAR:
		case TK_PRINTBASE: return 1;
		default: return 0;
	}
}

int weight(TLink link)
{
	switch(link->enumval)
	{
		case TK_MAIN:
			return 5;
		case TK_START:
			return 5;
		//case TK_END:
		//case TK_ENDMAIN:
		case TK_IDENTIFIER:
			return 5;
		//case TK_DOT: 
		case TK_INSERT: 
			return 1000; 
		case TK_ASSIGNOP: 
			return 1001; 
		case TK_INT: 
			return 950;
		case TK_STRINGCONSTANT:
			return 950;
		case TK_OR:
			return 999;
		case TK_AND:
			return 998;
		case TK_LT:
			return 997;
		case TK_GT:
			return 997;
		case TK_LE:
			return 997;
		case TK_GE:
			return 997;
		case TK_EQUAL: 
			return 997;
		case TK_NOTEQUAL:
			return 997;
		case TK_ADD:
			return 996;
		case TK_SUB:
			return 996;
		case TK_MUL:
			return 995;
		case TK_DIV: 
			return 995;
		case TK_BASE:
			return 950;
	    case TK_STRAND:
	    	return 950;
		case TK_LENGTH:
			return 950;
		case TK_GET:
			return 950;
		case TK_FOR:
			return 1000;
		case TK_WHILE: 
			return 1000;
		case TK_IF:
			return 1000;
		case TK_RETURN:
			return 1000;
		case TK_BREAK:
			return 1000;
		case TK_DATA_INT:
			return 1000;
		case TK_DATA_BASE:
			return 1000; 
		case TK_DATA_STRAND:
			return 1000;
		case TK_READSTRAND:
			return 1000;
		case TK_PRINTINT:
			return 1000;
		case TK_PRINTBASE: 
			return 1000;
		default: return 0;
	}

}
void deleteNode(TLink linkP,TLink linkC,int i)
{	
	if(linkP == NULL || linkC == NULL) return;
	linkP->children[i] =NULL;
	linkP->no_of_children--;
	linkC->parent = NULL;
	free(linkC);
	return;
}

void nullNodes(TLink link)
{	//recursive function removes all e 
	if(link == NULL) return;
	int i;
	for(i=0;i<MAX_NO_CHILDREN;i++)
	{	
		if(link->children[i] == NULL)
			break;
		nullNodes(link->children[i]);
		if(link->children[i] != NULL && link->children[i]->enumval == e)
		{   
			deleteNode(link,link->children[i],i);
		}

	}
}

Tree * _nullNodes(Tree* t)
{	
	if(t->root == NULL)
	{
		printf("NO TREE PRESTENT\n");
		return NULL;
	}
	nullNodes(t->root);
	return t;
}

void printAST(TLink t,FILE * tok) 
{
int i;
fprintf(tok,"NODE:%s\t\tTYPE:%s\n",t->value,giveName(t->enumval));
//printf("NODE:%s\n",t->value);
Stack* s = createStack(MAX_NO_CHILDREN);
sElem se;
//printf("here i am at node \n");
for(i= MAX_NO_CHILDREN - 1;i>=0;i--)
{	
	if(t == NULL)
	{	
		break;  
	}
	if( t->children[i] != NULL )
	{   
		fprintf(tok,"CHILD %d:\t\tTYPE:%s\t\tVALUE:%s\n",i+1,giveName(t->children[i]->enumval),t->children[i]->value);
		se.child = t->children[i]->enumval;
		se.parent = t->children[i];
		Push(s,se);
	}
}	

while(NotEmpty(s))
{
se = Top(s);
printAST(se.parent,tok);
}
}

void _printAST(Tree *t,FILE *tok) {
printAST(t->root,tok);
}


void removeUseless(TLink link)
{	if(link == NULL) return;
	int i;
	for(i=0;i<MAX_NO_CHILDREN;i++)
	{	
		if(link->children[i] == NULL) break;
		removeUseless(link->children[i]);
		if(link->children[i] != NULL)
		{
			if(link->children[i]->no_of_children == 0 && !(impNode(link->children[i])))
			{	//then link->children[i] can be deleted
				deleteNode(link,link->children[i],i);
			}
		}

	}	
}

Tree* _removeUseless(Tree* t)
{
	removeUseless(t->root);
	return t;
}


TLink pushNode(TLink link)
{	if(link == NULL) return;
	//printf("a\n");
	int i,count;
	count = 0;
	TLink temp;
	//printf("b\n");
	switch(link->enumval)
	{
		case functionbody:
			//printf("c\n");
			for(i=0;i<MAX_NO_CHILDREN;i++)
			{	
				
				if(link->children[i] != NULL)
				{
					if(link->children[i]->enumval = TK_START)
					{
					temp = link->children[i];
					//printf("here we are. hklkmll;l;\n");
					//printf("\n\n blah blah %s\n",link->children[i]->value );
					return temp;
					}
					
				}
			}
		case funsignature:
		//printf("d\n");
			for(i=0;i<MAX_NO_CHILDREN;i++)
			{	
				
				if(link->children[i] != NULL)
				{
					if(link->children[i]->enumval == TK_IDENTIFIER)
					{
					temp = link->children[i];
					//printf("here we are. njvnbknbfkl\n");
					//printf("\n\n blah blah %s\n",link->children[i]->value );
					return temp;
					}
					
				}
			}
		//printf("bye bye bye bye \n");

	}
	if(link->enumval == statements && link->parent->enumval == statements)
	{
		printf("bitch please--------------->\n");
		return NULL;
	}
	if(link->no_of_children == 1)
	{	//printf("No of children == 1\n");
		for(i=0;i<MAX_NO_CHILDREN;i++)
		{	
			
			if(link->children[i] != NULL)
			{
				//printf("No of children == 1 : found not null child\n");
				temp = link->children[i];
				return temp;
			}
		}
	}
	if( link->no_of_children > 1 )
	{	int a,l,j;
		j=0;
		int count = 1;
		//printf("PUSH NODE No of children >1\n");
		for(i=0;i<MAX_NO_CHILDREN;i++)
		{	
			
			if(link->children[i] != NULL)
			{   
				if(j==0)
				{
					//initialize least and l
					printf("initialize\n");
					temp = link->children[i];
					printf("%s\n",link->children[i]->value );
					l = weight(link->children[i]);
					count = 0;
					j++;
				}
				//temp = link->children[i];
				else{
					a = weight(link->children[i]);
					if(a>l)
					{
						//code to swap
						printf("a > l \n"); 
						temp = link->children[i];
						printf("%s\n",link->children[i]->value );
						l = a;
						count = 0;
					}
					else if(a == l)
					{
						printf("a ==l \n");
						if(temp->enumval == link->children[i]->enumval)
						{
						//keep thr first one 	
						}
						else{
						printf("%s\n",link->children[i]->value );
						count++;
						}
					}
					else 
					{}
					//j++;
				}
			}
		}
	if(count == 0)
	{
		//printf()
		return temp;	
	}
	else 
		return NULL;

	}
}

void pruning(TLink link)
{
	//printf("check 1\n");
	if(link == NULL)
		return;
	int i,childID,id,j;
	TLink temp;
	TLink extra;
	TLink parent;
	printf("###############%s#################\n",giveName(link->enumval) );
	int count= 0;
	//printf("check 2\n");
	if(link->no_of_children >= 1)
	{ //printf("check 2.1\n");
		for(i=0;i<MAX_NO_CHILDREN;i++)
		{
			//printf("check 3\n");
			if(link->children[i] != NULL)
			{
				count++;
				//printf("here i am going for pruning child %d\n",i);
				pruning(link->children[i]);
				if(count == link->no_of_children)
					break;
				//temp = pushNode(link);
			}
		}

	}
	
	
	
	if(link->no_of_children == 0)
	{	
				printf("0**********no_of_children ==0 ***************\n");
				//printf("check 5\n");
				printf("link here is %s\n",giveName(link->enumval) );
				printf("parent here is %s\n",giveName(link->parent->enumval) );
				if( !(impNode(link) ))
				{// remove the leaf node 
					//printf("check 6\n");
					childID = link->childID;
					parent = link->parent;
					link->parent = NULL;
					parent->children[childID] = NULL;
					printf("removed someone \n");
				}
				else
				{
				//	printf("check 7\n");
					printf("...link was important...\n");
				}
				//else let the important node remain 
				//printf("********END\n");
						
	}
	else if(link->no_of_children == 1)
	{	printf("1**********no_of_children ==1 ***************\n");
				printf("link here is %s\n",giveName(link->enumval) );
				/*if(link->enumval == TK_DOLLAR)
					{	
						printf("hello");
						printf("i am out");
						sleep(1);
						return;
					}*/
				//printf("haha\n");
				if(link->parent == NULL)
				{
					printf("parent here is NUll\n");
				}
				else
				{
					printf("parent here is %s\n",giveName(link->parent->enumval) );
				}
				//printf("check 8\n");
				//int childID,id;
				if(link != NULL && link->enumval ==statements)
				{
					//if(link->parent->enumval ==functionbody || link->parent->enumval == statements )
					//{
						return;
					//}
				}

				/*if(link != NULL && link->enumval ==statements)
				{
					if(link->parent->enumval = statements)
					{
					childID = link->childID;
					int i;
					for (i = 0; i < MAX_NO_CHILDREN; i++)
					{
						if(link->children[i] != NULL)
						{
							id = i;
						}
					}
					parent = link->parent;
					//printf("childId:%d\n",childID);
					
					//printf("Id:%d\n",id);
					link->children[id]->parent = parent;
					//printf("balh1\n");
					link->parent = NULL;

				//	temp -> childID = childID;
					//temp->parent = parent;
					parent->children[childID] = link->children[id];//children node ;

					free(link);
					printf("link is removed\n");
					}
					return;
				}
				*/
				temp = pushNode(link); //temp will be the child 
				//printf("check 10\n");
				if(temp != NULL && (!impNode(link)))
				{	
					/*if(link->enumval == TK_DOLLAR)
					{	
						printf("hello");
						//printf("i am out");
						//sleep(1);
						return;
					}*/
					
					//printf("check 11\n");
					printf("temp is not null %s\n",giveName(temp->enumval) );
					//printf("check 9\n");

					if(link->enumval == TK_DOLLAR)
					{	
						//printf("hello");
						//printf("i am out");
						sleep(5);
						return;
					}
					else 
					{
						//printf("blah blah\n");
					}
					//printf("hello1");
					if(link->parent == NULL)
						return;
					//printf("hello2");
					childID = link->childID;
					id = temp->childID;
					parent = link->parent;
					//printf("childId:%d\n",childID);
					
					//printf("Id:%d\n",id);
					
					//printf("balh1\n");
					link->parent = NULL;

					temp -> childID = childID;
					temp->parent = parent;
					parent->children[childID] = temp;//children node ;

					free(link);
					printf("link is removed\n");
				}
	}
	
	else
	{	printf("2**********no_of_children >1 ***************\n");	
	//printf("here i am %d\n",i);
				//printf("check 10\n");
				printf("link here is %s\n",giveName(link->enumval) );
				printf("parent here is %s\n",giveName(link->parent->enumval) );
				if(link != NULL && link->enumval ==statements)
				{
					//if(link->parent->enumval == functionbody || link->parent->enumval == statements )
					//{
						return;
					//}
				}
				temp = pushNode(link);
				if(temp == NULL)
					printf("NULL\n");
					if(temp != NULL )
					{	//printf("check 11\n");
						extra = createNode(temp->enumval,temp->value);
						printf("temp is not null %s\n",giveName(temp->enumval) );
						id = temp->childID;
						parent = link->parent;
						childID = link->childID; 
						link->children[id] = NULL;// free the pushnode 
						id = 0;
						for(j = 0;j<MAX_NO_CHILDREN ;j++)
						{	//connect children to its pushnode
							//printf("check 12\n");
							if(link->children[j] != NULL)
							{
								link->children[j]->parent = extra;//set its parent link to temp
								extra->children[id] = link->children[j];//link temp to children
								extra->children[id]->childID = id;//set its child id
								id++;
							} 
						}
						//printf("check 12\n");
						link->parent = NULL;
						free(link);
						for(j = 0;j<MAX_NO_CHILDREN ;j++)
						{	//connect children to its pushnode
							//printf("check 12\n");
							if(temp->children[j] != NULL)
							{
								temp->children[j]->parent = extra;//set its parent link to temp
								extra->children[id] = temp->children[j];//link temp to children
								extra->children[id]->childID = id;//set its child id
								id++;
							} 
						}
						//join temp and parent 
						free(temp);
						extra->childID = childID;
						extra->no_of_children = id;
						parent->children[childID] = extra;
						extra->parent = parent;
						printf("link is removed \n");
					}

	}
	return;
}

Tree* _pruning( Tree * t)
{
	pruning(t->root);

	return t;
}

Tree* _convertAST(Tree * tptr)
{	
	tptr = _nullNodes(tptr);
	FILE *to1;
	to1 = fopen("Output/AST1.txt", "w");
	_printAST(tptr,to1);
	printf("AST tree printed to file \"Output/AST1.txt\"\n");

	tptr = _removeUseless(tptr);
	FILE *to2;
	to2 = fopen("Output/AST2.txt", "w");
	_printAST(tptr,to2);
	printf("AST tree printed to file \"Output/AST2.txt\"\n");

	tptr =  _pruning( tptr);
	FILE *to3;
	to3 = fopen("Output/AST3.txt", "w");
	_printAST(tptr,to3);
	printf("AST tree printed to file \"Output/AST3.txt\"\n");
	return tptr;
}
