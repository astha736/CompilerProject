/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include <stdio.h>
#include <string.h>
#include "stack.h"
#include "parser.h"
#include "parseFunctions.h"
#include "tree.h"
#include "lex.h"

Tree* parse(list *tokenStream,Tree* t)
{
//*********************************INITIALIZATION*************************************************************************
	int errcount = 0;
	Stack * stack = createStack(100); 
	sElem se;
	se.child= TK_DOLLAR;
	se.parent = NULL; 
	Push(stack,se);
	se.child= Program;
	TLink linkParent = createNode(TK_DOLLAR,"$");
	se.parent = linkParent;
	TLink linkChild;
	Push(stack,se); 

	int action, i, length;
	i = 0;

	sElem selem;			//selem = stack element and action is perform steps given in table 

	init_table();

	length = tokenStream->size;

	node_t* ptr = tokenStream->head;

	FILE *tok;
	tok = fopen("Output/output.txt", "w");
//******************************END INITIALIZATION*************************************************************************

//******************************MAIN LOGIC*********************************************************************************
	
	while(NotEmpty(stack) && i<length)	
	{	
		selem = Top(stack);		//first element in stack
		//printf("Top:%s,%s\n",giveName(selem.child),giveName(selem.parent->enumval));
		//printf("here my i and length is %d,%d\n",i,length);
		//printf(",hahaa %d %d %s\n",length,i,giveName(ptr->tk.enumval));
		linkParent =  selem.parent;
		if(ptr == NULL)
		{
			//printf("final here is break\n");
			break;
		}
	
		if((selem.child == TK_DOLLAR) && (i==length))  		// $ ==> end of program in stack
		{     
			fprintf(tok, "element:%s\ntoken: %s\n",giveName(selem.child),giveName(ptr->tk.enumval));  
			printf("ACCEPT STATE\n");
			break;
		}
		
		else if(selem.child == e && i<length)
		{ 
			fprintf(tok, "element:%s\ntoken: %s\n",giveName(selem.child),giveName(ptr->tk.enumval));
			//linkChild = createNode(selem.child,ptr->tk.value);
			linkChild = selem.child >0 && selem.child <51 ? createNode(selem.child,giveName(selem.child)) : createNode(selem.child,ptr->tk.value);
			//printf("tk.value is %s for type %s\n",ptr->tk.value,giveName(selem.child));
			addNode(t,linkParent,linkChild);
		}

		else if(i<=length) 		//first stack elemet is a nonterminal then
	  	{	

	  		fprintf(tok, "element:%s\ntoken: %s\n",giveName(selem.child),giveName(ptr->tk.enumval));
	  		//if (giveName(selem.child) == "functionbody")fprintf(tok,",hahaa\n");
	    		
			if(ptr->tk.enumval>50 && ptr->tk.enumval <99 && selem.child >0 && selem.child <51)
			{
				action = parse_table[selem.child][ptr->tk.enumval];	
				//action ==> which grammer rule to apply 
				
			}
			else if (ptr->tk.enumval>50 && ptr->tk.enumval <99 && selem.child >50 && selem.child <99) 
			{ 
				
				if(selem.child == ptr->tk.enumval){ 
					//printf( "element:%s\ntoken: %s\n",giveName(selem.child),giveName(ptr->tk.enumval));			
					action = -1;
					i++;
					linkChild = selem.child >0 && selem.child <51 ? createNode(selem.child,giveName(selem.child)) : createNode(selem.child,ptr->tk.value);
					//printf("tk.value is %s for type %s\n",ptr->tk.value,giveName(selem.child));
					addNode(t,linkParent,linkChild);
					//("did my action\n");
					//code for inserting in the TREE
					ptr = ptr->next;
					if(ptr==NULL)
						{
						//printf("next is null\n");
						//printf("what is i and length: %d,%d\n",i,length);
						break;
						}
					
					
				}
				else 
				{	
					printf("ERROR 202:LINENO %d,%s missing \n",ptr->tk.lineno,giveName(selem.child));  	
					errcount++;
					//details of syntax error and dealing with error needs to be added 	
				}
			}
			else
			{
				printf("ERROR 201: error in terminals and non terminals");
				errcount++;
			}
			// NOW WE ARE CHECKING ACTION VALUE 
	  	    if(action == -1)
			{
				//dont do anything  
			}
		    else if(action >0)//action > 0 means that it has some rule to apply
	  		{	linkChild = selem.child >0 && selem.child <51 ? createNode(selem.child,giveName(selem.child)) : createNode(selem.child,ptr->tk.value);	
	  			//linkChild = selem.child createNode(selem.child,ptr->tk.value);
	  			//printf("tk.value is %s for type %s\n",ptr->tk.value,giveName(selem.child));
				addNode(t,linkParent,linkChild);
	  			table(stack,action,linkChild);
				//goto a switch case where we actually push in the rule
			}
	  	    else	//0 is a default in parse_table == ERROR
			{				
				//LOOK FOR THE FOLLOW 
				//printf("ERROR 203: LINE NO %d,unexpected %s\n",ptr->tk.lineno,ptr->tk.value);
				//errcount++;
				while(!follow(selem.child,ptr->tk.enumval))
				{
					printf("ERROR 203: LINE NO %d,unexpected %s\n",ptr->tk.lineno,ptr->tk.value);
					printf("%s\n",giveName(selem.child));
					errcount++;
					ptr = ptr->next;
					i++;
					if(ptr == NULL)
					{	//printf("\nI am breaking off here\n");
						break;
					}
					

				}	
			}
		}
		else 
		{	
			printf("element value is %s\n",giveName(selem.child));
			//printf("%d and %d \n",i ,length);
			if(NotEmpty(stack)) printf("Yes\n");
			printf("ERROR 20F: some other error\n");
			errcount++;
		}
	}


	

	if(NotEmpty(stack) && i>=length)
	{
		selem = Top(stack);
		//printf( "element:%s\n",giveName(selem.child));
		if((selem.child == TK_DOLLAR))  		// $ ==> end of program in stack
		{     
			fprintf(tok, "element:%s\n",giveName(selem.child));  
			printf("ACCEPT STATE\n");
		}
		i = 1;
		
		while(NotEmpty(stack))
		{	selem = Top(stack);
			printf("ERROR 301: Program incomplete,Tokens expected:\n");
			printf("%d. %s\n",i,giveName(selem.child));
			errcount++;
		}
		
	}
	if(!(NotEmpty(stack)) && i<length)
	{
		while(i<length)
		{	
			if(ptr == NULL)
				break;
			printf("ERROR 302: LINE NO %d,token %s are not considered as part of the program \n",ptr->tk.lineno,ptr->tk.value);
			errcount++;
			ptr = ptr->next;
			i++;
		}
	}
	
	printf("Parsing successful. End of parser.\n");
	printf("Number of nodes in the parse tree: %d\n", t->totalNodes);
	printf("Number of leaf nodes in the parse tree: %d\n", t->totalLeafNodes);
	printf("Number of Errors:%d\n",errcount);
	if(errcount == 0)
	{
	return t;
	}
	else
	{
		printf("Cannot process further. Please remove all Errors\n");
		return NULL;
	}
}



