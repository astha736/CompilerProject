/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack * createStack(int maxElements)
{
        
        Stack *S;						//declaration for Stack 
        S = (Stack *)malloc(sizeof(Stack));			//assigning space for Stack structure 

        S->elements = (sElem *)malloc(sizeof(sElem)*maxElements);//assign space corresponding to the size(maximum no of elements in an array)
        S->currsize = 0;					//initializing no of current elements to 0
        S->size = maxElements;					//size of the array 

        return S;
}

int NotEmpty(Stack *S)
{
	if(S->currsize==0)
	{
		//printf("Stack is empty\n");
		return 0;
	}
	else
	{
		return 1;
	}
}

sElem Top(Stack *S)
{	sElem se;
	se.child = 999;
	se.parent = NULL;
       
        if(S->currsize==0)
        {	//printf("%d current size\n",S->currsize);
                printf("Stack is Empty: function Top\n");
                return se;
        }
        else
        {	//printf("%d current size\n",S->currsize);
                S->currsize--;					
		//current size needs to be decreased by one since element is being removed 
		//also for first element pointer address+0 thus for n = address+(currsize-1)
		//printf("TOP:%s\n",giveName(S->elements[S->currsize].child));
		return (S->elements[S->currsize]);
        }
        //printf("stack element being pushed is %s\n",giveName(se.child));
        return se;
}

void Push(Stack *S,sElem element)
{
        if(S->currsize == S->size)
        {
                printf("Stack is Full\n");
        }
        else
        { 	
          S->elements[S->currsize] = element; 	//the actual index is one less than the current size
          //printf("stack element being pushed is %s\n",giveName(element.child));
		  S->currsize++;
		//printf("elemet bein pushed is %s ,s->current size: %d\n",giveName(element),S->currsize);
        }
        return;
}
