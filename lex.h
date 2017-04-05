/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include "type.h"
#include "list.h"

#ifndef LEX_H
#define LEX_H

extern char lookahead(FILE *fp);
extern int charClass(char ch);
extern char getNonBlank(FILE *fp);
extern void addChar(char ch);
extern void clearBuffer();
extern list* tokenize(FILE *fp);

#endif 
