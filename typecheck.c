/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include <stdlib.h>
#include <stdio.h>
#include "type.h"
#include "tree.h"
#include "parseFunctions.h"
#include "stack.h"
#include "symbolTable_new.h"

void typecheck( TLink link, symbolTable *symbol_table  );

void _typecheck(Tree *t , symbolTable *symbol_table )
{
	typecheck(t->root,symbol_table);
	return;
}

void typecheck( TLink link, symbolTable *symbol_table  )
{
	//printf("\n\tHello World !\n");
	symbolTableEntry *e ;
	int i,j;
	int left,right;
	left = -1;
	right = -1;
	int left_type,right_type;
	left_type = -1;
	right_type = -2;
	//recursion
	for( i = 0 ; i < MAX_NO_CHILDREN ; i++ )
	{
		if(link->children[i] != NULL)
		{
			typecheck(link->children[i],symbol_table );
		}
	}
	// left and right of + - should have same type 
	if ( link->enumval == TK_ADD || link->enumval == TK_SUB || link->enumval == TK_MUL|| link->enumval == TK_DIV || link->enumval == TK_LT || link->enumval == TK_GT || link->enumval == TK_GE || link->enumval == TK_LE)
	{	printf("NODE:%s\n",link->value );
		j = 0; 
		for ( i = 0 ; i < MAX_NO_CHILDREN ; i++ )
		{
			if( j == 0 && link->children[i] != NULL )
			{
				left = i;
				j++;
				printf("CHILD%d:%s\n",j,link->children[i]->value );
			}
			else if ( j == 1 && link->children[i] != NULL)
			{
				right = i;
				j++;
				printf("CHILD%d:%s\n",j,link->children[i]->value );
			}
		
			else
			{
				//don't do anything
			}
		}
		//printf("after for statement\n");
		//printf("%d",left);
		if( left >= 0 ) // children Id from 0 to MAX_NO_CHILDREN
		{
			//printf("here 0\n");
			if(link->children[left]->type != -1)
			{
				//printf("here 1\n");
				left_type = link->children[left]->type;
			}
			else if( link->children[left]->enumval == TK_INT)
			{	//printf("here 2\n");
				left_type = TK_DATA_INT;
				link->children[left]->type = TK_DATA_INT;
			}
			else
			{
				//printf("here 3\n");
				if((e = lookup(symbol_table,link->children[left]->value))==NULL) 
					printf("Type Check: entry not found %s\n",link->children[left]->value);
				else 
				{
					//printf("entry found. Type is %d.\n", e->enumval);
					left_type = e->enumval;
				}
			}
			printf("left_type is %s\n",giveName(left_type) );
		}
		if( right >= 0 )// children Id from 0 to MAX_NO_CHILDREN
		{
			//printf("here 4\n");
			if(link->children[right]->type != -1)
			{
				//printf("here 5\n");
				right_type = link->children[right]->type;
			}
			else if( link->children[right]->enumval == TK_INT)
			{
				//printf("here 6\n");
				right_type = TK_DATA_INT;
				link->children[right]->type = TK_DATA_INT;
			}
			else
			{
				//printf("here 7 \n");
				if((e = lookup(symbol_table,link->children[right]->value))==NULL) 
					printf("Type Check: entry not found %s\n",link->children[right]->value);
				else 
				{
					//printf("entry found. Type is %d.\n", e->enumval);
					right_type = e->enumval;
				}
			}
			printf("right_type is %s\n",giveName(right_type) );	
		}
		if( left_type == right_type )
		{
			if(left_type == TK_DATA_INT)
			{
				if(!strcmp(link->children[right]->value,"0") && link->enumval == TK_DIV)
				{
					printf("Error: Division by zero not allowed\n");
				}
				//correct match
				link->type = TK_DATA_INT;
				printf("type of link is %s\n",giveName(link->type));
			}
			else
			{
				printf("Type Mismatch at %s,can support only int type\n",link->value );
			} 
		}
		else
		{
			printf("Type Mismatch at %s,left:%s,right:%s\n",link->value,link->children[left]->value,link->children[right]->value);
		}
	}
	
	else if ( link->enumval == TK_ASSIGNOP )
	{
		printf("NODE:%s\n",link->value );
		j = 0; 
		for ( i = 0 ; i < MAX_NO_CHILDREN ; i++ )
		{
			if( j == 0 && link->children[i] != NULL )
			{
				left = i;
				j++;
				printf("CHILD%d:%s\n",j,link->children[i]->value );
			}
			else if ( j == 1 && link->children[i] != NULL)
			{
				right = i;
				j++;
				printf("CHILD%d:%s\n",j,link->children[i]->value );
			}
		
			else
			{
				//don't do anything
			}
		}
		if( left >= 0 ) // children Id from 0 to MAX_NO_CHILDREN
		{
			//printf("here 0\n");
			if(link->children[left]->type != -1)
			{
				//printf("here 1\n");
				left_type = link->children[left]->type;
			}
			else if( link->children[left]->enumval == TK_INT)
			{	//printf("here 2\n");
				left_type = TK_DATA_INT;
				link->children[left]->type = TK_DATA_INT;
			}
			else if( link->children[left]->enumval == TK_STRAND)
			{	//printf("here 2\n");
				left_type = TK_DATA_STRAND;
				link->children[left]->type = TK_DATA_STRAND;
			}
			else if( link->children[left]->enumval == TK_BASE)
			{	//printf("here 2\n");
				left_type = TK_DATA_BASE;
				link->children[left]->type = TK_DATA_BASE;
			}
			else
			{
				//printf("here 3\n");
				if((e = lookup(symbol_table,link->children[left]->value))==NULL) 
					printf("Type Check: entry not found %s\n",link->children[left]->value);
				else 
				{
					//printf("entry found. Type is %d.\n", e->enumval);
					left_type = e->enumval;
				}
			}
			printf("left_type is %s\n",giveName(left_type) );
		}
		if( right >= 0 )// children Id from 0 to MAX_NO_CHILDREN
		{
			if(link->children[right]->type != -1)
			{
				//printf("here 5\n");
				right_type = link->children[right]->type;
			}
			else if( link->children[right]->enumval == TK_INT)
			{
				//printf("here 6\n");
				right_type = TK_DATA_INT;
				link->children[right]->type = TK_DATA_INT;
			}
			else if( link->children[right]->enumval == TK_STRAND)
			{
				//printf("here 6\n");
				right_type = TK_DATA_STRAND;
				link->children[right]->type = TK_DATA_STRAND;
			}
			else if( link->children[right]->enumval == TK_BASE)
			{
				//printf("here 6\n");
				right_type = TK_DATA_BASE;
				link->children[right]->type = TK_DATA_BASE;
			}
			else
			{
				//printf("here 7 \n");
				if((e = lookup(symbol_table,link->children[right]->value))==NULL) 
					printf("Type Check: entry not found %s\n",link->children[right]->value);
				else 
				{
					//printf("entry found. Type is %d.\n", e->enumval);
					right_type = e->enumval;
				}
			}
			printf("right_type is %s\n",giveName(right_type) );	
		}
		if( left_type == right_type )
		{
			link->type = left_type;
			printf("type of link is %s\n",giveName(link->type));
			//both sides of operator have same type 
			//maybe if we want to set types 
		}
		else
		{
			printf("Type Mismatch at %s,left:%s,right:%s\n",link->value,link->children[left]->value,link->children[right]->value);
		}
	}
	
	else if( link->enumval == TK_INSERT )
	{
		printf("NODE:%s\n",link->value );
		j = 0; 
		for ( i = 0 ; i < MAX_NO_CHILDREN ; i++ )
		{
			if( j == 0 && link->children[i] != NULL )
			{
				left = i;
				j++;
				printf("CHILD%d:%s\n",j,link->children[i]->value );
			}
			else if ( j == 1 && link->children[i] != NULL)
			{
				right = i;
				j++;
				printf("CHILD%d:%s\n",j,link->children[i]->value );
			}
		
			else
			{
				//don't do anything
			}
		}
		if( left >= 0 ) // children Id from 0 to MAX_NO_CHILDREN
		{
			if(link->children[left]->type != -1)
			{
				//printf("here 1\n");
				left_type = link->children[left]->type;
			}
			else if( link->children[left]->enumval == TK_STRAND)
			{	//printf("here 2\n");
				left_type = TK_DATA_STRAND;
				link->children[left]->type = TK_DATA_STRAND;
			}
			else
			{
				//printf("here 3\n");
				if((e = lookup(symbol_table,link->children[left]->value))==NULL) 
					printf("Type Check: entry not found %s\n",link->children[left]->value);
				else 
				{
					//printf("entry found. Type is %d.\n", e->enumval);
					left_type = e->enumval;
				}
			}
			printf("left_type is %s\n",giveName(left_type) );
		}
		if( right >= 0 )// children Id from 0 to MAX_NO_CHILDREN
		{
			if(link->children[right]->type != -1)
			{
				//printf("here 5\n");
				right_type = link->children[right]->type;
			}
			else if( link->children[right]->enumval == TK_INT)
			{
				//printf("here 6\n");
				right_type = TK_DATA_INT;
				link->children[right]->type = TK_DATA_INT;
			}
			else if( link->children[right]->enumval == TK_STRAND)
			{
				//printf("here 6\n");
				right_type = TK_DATA_STRAND;
				link->children[right]->type = TK_DATA_STRAND;
			}
			else if( link->children[right]->enumval == TK_BASE)
			{
				//printf("here 6\n");
				right_type = TK_DATA_BASE;
				link->children[right]->type = TK_DATA_BASE;
			}
			else
			{
				//printf("here 7 \n");
				if((e = lookup(symbol_table,link->children[right]->value))==NULL) 
					printf("Type Check: entry not found %s\n",link->children[right]->value);
				else 
				{
					//printf("entry found. Type is %d.\n", e->enumval);
					right_type = e->enumval;
				}
			}
			printf("right_type is %s\n",giveName(right_type) );	
		}
		if( left_type == TK_DATA_STRAND && right_type == TK_DATA_BASE )
		{
			//both sides of operator have same type 
			//maybe if we want to set types 
		}
		else
		{
			printf("Type Mismatch at,strand.insert(base) is required\n");
			printf("Found %s,left:%s,right:%s\n",link->value,link->children[left]->value,link->children[right]->value);
		}
	}
	
	else if ( link->enumval == TK_LENGTH || link->enumval == TK_GET )
	{
		printf("NODE:%s\n",link->value );
		j = 0; 
		for ( i = 0 ; i < MAX_NO_CHILDREN ; i++ )
		{
			if( j == 0 && link->children[i] != NULL )
			{
				left = i;
				j++;
				printf("CHILD%d:%s\n",j,link->children[i]->value );
			}
		}
		if( left >= 0 ) // children Id from 0 to MAX_NO_CHILDREN
		{
			if(link->children[left]->type != -1)
			{
				//printf("here 1\n");
				left_type = link->children[left]->type;
			}
			else if( link->children[left]->enumval == TK_STRAND)
			{	//printf("here 2\n");
				left_type = TK_DATA_STRAND;
				link->children[left]->type = TK_DATA_STRAND;
			}
			else
			{
				//printf("here 3\n");
				if((e = lookup(symbol_table,link->children[left]->value))==NULL) 
					printf("Type Check: entry not found %s\n",link->children[left]->value);
				else 
				{
					//printf("entry found. Type is %d.\n", e->enumval);
					left_type = e->enumval;
				}
			}
			printf("left_type is %s\n",giveName(left_type) );
		}
		if( left_type == TK_DATA_STRAND )
		{
			//return type of length anf get is int 
			if(link->enumval ==TK_LENGTH)
			{
				link->type = TK_DATA_INT;
				printf("type of link is %s\n",giveName(link->type));
			}
			else
			{
				link->type = TK_DATA_BASE;
				printf("type of link is %s\n",giveName(link->type));
			}
			//both sides of operator have same type 
			//maybe if we want to set types 
		}
		else
		{
			printf("Type Mismatch at %s,left:%s\n",link->value,link->children[left]->value);
			printf("Expected strand.operator()\n");
		}
	}
	
	else if ( link->enumval == TK_EQUAL || link->enumval == TK_NOTEQUAL )
	{
		printf("NODE:%s\n",link->value );
		j = 0; 
		for ( i = 0 ; i < MAX_NO_CHILDREN ; i++ )
		{
			if( j == 0 && link->children[i] != NULL )
			{
				left = i;
				j++;
				printf("CHILD%d:%s\n",j,link->children[i]->value );
			}
			else if ( j == 1 && link->children[i] != NULL)
			{
				right = i;
				j++;
				printf("CHILD%d:%s\n",j,link->children[i]->value );
			}
		
			else
			{
				//don't do anything
			}
		}
		if( left >= 0 ) // children Id from 0 to MAX_NO_CHILDREN
		{
			//printf("here 0\n");
			if(link->children[left]->type != -1)
			{
				//printf("here 1\n");
				left_type = link->children[left]->type;
			}
			else if( link->children[left]->enumval == TK_INT)
			{	//printf("here 2\n");
				left_type = TK_DATA_INT;
				link->children[left]->type = TK_DATA_INT;
			}
			else if( link->children[left]->enumval == TK_STRAND)
			{	//printf("here 2\n");
				left_type = TK_DATA_STRAND;
				link->children[left]->type = TK_DATA_STRAND;
			}
			else if( link->children[left]->enumval == TK_BASE)
			{	//printf("here 2\n");
				left_type = TK_DATA_BASE;
				link->children[left]->type = TK_DATA_BASE;
			}
			else
			{
				//printf("here 3\n");
				if((e = lookup(symbol_table,link->children[left]->value))==NULL) 
					printf("Type Check: entry not found %s\n",link->children[left]->value);
				else 
				{
					//printf("entry found. Type is %d.\n", e->enumval);
					left_type = e->enumval;
				}
			}
			printf("left_type is %s\n",giveName(left_type) );
		}
		if( right >= 0 )// children Id from 0 to MAX_NO_CHILDREN
		{
			if(link->children[right]->type != -1)
			{
				//printf("here 5\n");
				right_type = link->children[right]->type;
			}
			else if( link->children[right]->enumval == TK_INT)
			{
				//printf("here 6\n");
				right_type = TK_DATA_INT;
				link->children[right]->type = TK_DATA_INT;
			}
			else if( link->children[right]->enumval == TK_STRAND)
			{
				//printf("here 6\n");
				right_type = TK_DATA_STRAND;
				link->children[right]->type = TK_DATA_STRAND;
			}
			else if( link->children[right]->enumval == TK_BASE)
			{
				//printf("here 6\n");
				right_type = TK_DATA_BASE;
				link->children[right]->type = TK_DATA_BASE;
			}
			else
			{
				//printf("here 7 \n");
				if((e = lookup(symbol_table,link->children[right]->value))==NULL) 
					printf("Type Check: entry not found %s\n",link->children[right]->value);
				else 
				{
					//printf("entry found. Type is %d.\n", e->enumval);
					right_type = e->enumval;
				}
			}
			printf("right_type is %s\n",giveName(right_type) );	
		}
		if( left_type == right_type )
		{
			if(left_type == TK_DATA_BASE || left_type ==TK_DATA_INT )
			{
				link->type = left_type;
				printf("type of link is %s\n",giveName(link->type));
				//both sides of operator have same type 
				//maybe if we want to set types
			}
			else
			{
				printf("Type Mismatch at %s,expected base or int \n",link->value);
			}
		}
		else
		{
			printf("Type Mismatch at %s,left:%s,right:%s\n",link->value,link->children[left]->value,link->children[right]->value);
			printf("Expected either base or int on both sides\n");
		}
	}
	
	else if ( link->enumval == TK_FOR )
	{
		printf("NODE:%s\n",link->value );
		j = 0; 
		for ( i = 0 ; i < MAX_NO_CHILDREN ; i++ )
		{
			if( j == 0 && link->children[i] != NULL )
			{
				left = i;
				j++;
				printf("CHILD%d:%s\n",j,link->children[i]->value );
			}
			else if ( j == 1 && link->children[i] != NULL)
			{
				right = i;
				j++;
				printf("CHILD%d:%s\n",j,link->children[i]->value );
			}
		
			else
			{
				//don't do anything
			}
		}
		if( left >= 0 ) // children Id from 0 to MAX_NO_CHILDREN
		{
			if(link->children[left]->type != -1)
			{
				//printf("here 1\n");
				left_type = link->children[left]->type;
			}
			else if( link->children[left]->enumval == TK_INT)
			{	//printf("here 2\n");
				left_type = TK_DATA_INT;
				link->children[left]->type = TK_DATA_INT;
			}
			else if( link->children[left]->enumval == TK_STRAND)
			{	//printf("here 2\n");
				left_type = TK_DATA_STRAND;
				link->children[left]->type = TK_DATA_STRAND;
			}
			else if( link->children[left]->enumval == TK_BASE)
			{	//printf("here 2\n");
				left_type = TK_DATA_BASE;
				link->children[left]->type = TK_DATA_BASE;
			}
			else
			{
				//printf("here 3\n");
				if((e = lookup(symbol_table,link->children[left]->value))==NULL) 
					printf("Type Check: entry not found %s\n",link->children[left]->value);
				else 
				{
					//printf("entry found. Type is %d.\n", e->enumval);
					left_type = e->enumval;
				}
			}
			printf("left_type is %s\n",giveName(left_type) );
		}
		if( right >= 0 )// children Id from 0 to MAX_NO_CHILDREN
		{
			if(link->children[right]->type != -1)
			{
				//printf("here 5\n");
				right_type = link->children[right]->type;
			}
			else if( link->children[right]->enumval == TK_INT)
			{
				//printf("here 6\n");
				right_type = TK_DATA_INT;
				link->children[right]->type = TK_DATA_INT;
			}
			else if( link->children[right]->enumval == TK_STRAND)
			{
				//printf("here 6\n");
				right_type = TK_DATA_STRAND;
				link->children[right]->type = TK_DATA_STRAND;
			}
			else if( link->children[right]->enumval == TK_BASE)
			{
				//printf("here 6\n");
				right_type = TK_DATA_BASE;
				link->children[right]->type = TK_DATA_BASE;
			}
			else
			{
				//printf("here 7 \n");
				if((e = lookup(symbol_table,link->children[right]->value))==NULL) 
					printf("Type Check: entry not found %s\n",link->children[right]->value);
				else 
				{
					//printf("entry found. Type is %d.\n", e->enumval);
					right_type = e->enumval;
				}
			}
			printf("right_type is %s\n",giveName(right_type) );	
		}
		if( left_type == TK_DATA_BASE && right_type == TK_DATA_STRAND)
		{

			//both sides of operator have same type 
			//maybe if we want to set types 
		}
		else
		{
			printf("Type Mismatch at %s,left:%s,right:%s\n",link->value,link->children[left]->value,link->children[right]->value);
			printf("Expected for each base in strand on both sides\n");
		}
	}
	else if ( link->enumval == TK_WHILE || link->enumval == TK_IF )
	{
		printf("NODE:%s\n",link->value );
		j = 0; 
		for ( i = 0 ; i < MAX_NO_CHILDREN ; i++ )
		{
			if( j == 0 && link->children[i] != NULL )
			{
				//left = i;
				//j++;
				if(link->children[i]->enumval >= TK_AND && link->children[i]->enumval <= TK_NOTEQUAL)
					typecheck(link->children[i],symbol_table );
				//printf("CHILD%d:%s\n",j,link->children[i]->value );
			}
		}
		for ( i = 0 ; i < MAX_NO_CHILDREN ; i++ )
		{
			if( j == 0 && link->children[i] != NULL )
			{
				left = i;
				j++;
				//if(link->children[i] >= TK_AND && link->children[i] =< TK_NOTEQUAL)
				//	typecheck(link->children[i],symbol_table );
				printf("CHILD%d:%s\n",j,link->children[i]->value );
			}
		}
		if( left >= 0 ) // children Id from 0 to MAX_NO_CHILDREN
		{
			if(link->children[left]->type != -1)
			{
				//printf("here 1\n");
				left_type = link->children[left]->type;
			}
			else if( link->children[left]->enumval == TK_INT)
			{	//printf("here 2\n");
				left_type = TK_DATA_INT;
				link->children[left]->type = TK_DATA_INT;
			}
			else if( link->children[left]->enumval == TK_STRAND)
			{	//printf("here 2\n");
				left_type = TK_DATA_STRAND;
				link->children[left]->type = TK_DATA_STRAND;
			}
			else if( link->children[left]->enumval == TK_BASE)
			{	//printf("here 2\n");
				left_type = TK_DATA_BASE;
				link->children[left]->type = TK_DATA_BASE;
			}
			else
			{
				//printf("here 3\n");
				if((e = lookup(symbol_table,link->children[left]->value))==NULL) 
					printf("Type Check: entry not found %s\n",link->children[left]->value);
				else 
				{
					//printf("entry found. Type is %d.\n", e->enumval);
					left_type = e->enumval;
				}
			}
			printf("left_type is %s\n",giveName(left_type) );
		}

		if( left_type == TK_DATA_INT || left_type == TK_DATA_BASE )
		{

			//both sides of operator have same type 
			//maybe if we want to set types 
		}
		else
		{
			printf("Type Mismatch at %s,left:%s\n",link->value,link->children[left]->value);
			printf("Expected some conditional operator\n");
		}
	}

	
	else if ( link->enumval == TK_PRINTINT )
	{
		printf("NODE:%s\n",link->value );
		j = 0; 
		for ( i = 0 ; i < MAX_NO_CHILDREN ; i++ )
		{
			if( j == 0 && link->children[i] != NULL )
			{
				left = i;
				j++;
				printf("CHILD%d:%s\n",j,link->children[i]->value );
			}
		}
		if( left >= 0 ) // children Id from 0 to MAX_NO_CHILDREN
		{
			if(link->children[left]->type != -1)
			{
				//printf("here 1\n");
				left_type = link->children[left]->type;
			}
			else if( link->children[left]->enumval == TK_INT)
			{	//printf("here 2\n");
				left_type = TK_DATA_INT;
				link->children[left]->type = TK_DATA_INT;
			}
			else if( link->children[left]->enumval == TK_STRAND)
			{	//printf("here 2\n");
				left_type = TK_DATA_STRAND;
				link->children[left]->type = TK_DATA_STRAND;
			}
			else if( link->children[left]->enumval == TK_BASE)
			{	//printf("here 2\n");
				left_type = TK_DATA_BASE;
				link->children[left]->type = TK_DATA_BASE;
			}
			else
			{
				//printf("here 3\n");
				if((e = lookup(symbol_table,link->children[left]->value))==NULL) 
					printf("Type Check: entry not found %s\n",link->children[left]->value);
				else 
				{
					//printf("entry found. Type is %d.\n", e->enumval);
					left_type = e->enumval;
				}
			}
			printf("left_type is %s\n",giveName(left_type) );
		}

		if( left_type >= TK_DATA_INT)
		{

			//both sides of operator have same type 
			//maybe if we want to set types 
		}
		else
		{
			printf("Type Mismatch at %s,left:%s\n",link->value,link->children[left]->value);
			printf("Expected some printInt(int identifier ) \n");
		}
	}
	else if ( link->enumval == TK_PRINTBASE )
	{
		printf("NODE:%s\n",link->value );
		j = 0; 
		for ( i = 0 ; i < MAX_NO_CHILDREN ; i++ )
		{
			if( j == 0 && link->children[i] != NULL )
			{
				left = i;
				j++;
				printf("CHILD%d:%s\n",j,link->children[i]->value );
			}
		}
		if( left >= 0 ) // children Id from 0 to MAX_NO_CHILDREN
		{
			if(link->children[left]->type != -1)
			{
				//printf("here 1\n");
				left_type = link->children[left]->type;
			}
			else if( link->children[left]->enumval == TK_INT)
			{	//printf("here 2\n");
				left_type = TK_DATA_INT;
				link->children[left]->type = TK_DATA_INT;
			}
			else if( link->children[left]->enumval == TK_STRAND)
			{	//printf("here 2\n");
				left_type = TK_DATA_STRAND;
				link->children[left]->type = TK_DATA_STRAND;
			}
			else if( link->children[left]->enumval == TK_BASE)
			{	//printf("here 2\n");
				left_type = TK_DATA_BASE;
				link->children[left]->type = TK_DATA_BASE;
			}
			else
			{
				//printf("here 3\n");
				if((e = lookup(symbol_table,link->children[left]->value))==NULL) 
					printf("Type Check: entry not found %s\n",link->children[left]->value);
				else 
				{
					//printf("entry found. Type is %d.\n", e->enumval);
					left_type = e->enumval;
				}
			}
			printf("left_type is %s\n",giveName(left_type) );
		}

		if( left_type >= TK_DATA_BASE)
		{

			//both sides of operator have same type 
			//maybe if we want to set types 
		}
		else
		{
			printf("Type Mismatch at %s,left:%s\n",link->value,link->children[left]->value);
			printf("Expected some printBase(base identifier ) \n");
		}
	}
	return;
}
	
