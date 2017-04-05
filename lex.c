/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "type.h"
#include "lex.h"
#include "lookup.h"
#include "list.h"
#include "parseFunctions.h"

#define 	letter		0
#define 	digit		1
#define 	lt		2			
#define 	gt		3
#define 	ne		4
#define 	eq		5
#define 	lp		6
#define 	rp		7
#define 	comma		8
#define 	semi		9
#define 	dot		10
#define 	hash		11
#define 	subassg		12
#define 	add		13
#define 	mul		14
#define 	div		15
#define 	strand		16
#define 	lb		17
#define 	rb		18
#define 	string		19
#define		MAX_TOK_LENGTH	25

static char lexeme[MAX_TOK_LENGTH];
static char null[MAX_TOK_LENGTH] = "";
static int lexlen = 0;
static int linecount = 1;
//static int colcount = 0, prevcol = 0;

/*void incCol(char ch) {
switch(ch) {
	prevcol = colcount;
	case '\n' : colcount = 0; break;
	case '\t' : colcount += 8; break;
	default   : colcount++; 
	}	
}

void decCol(char ch) {
switch(ch) {
	case '\n' : colcount = prevcol; break;
	case '\t' : colcount -= 8; break;
	default   : colcount--;
	}	
}*/

// Character lookahead
char lookahead(FILE *fp) {
if(feof(fp)) return '$';
char ch = fgetc(fp);
char temp = ch;
ungetc(temp, fp);
return ch;
}

// Character classes	
int charClass(char ch){
if(isalpha(ch)) { return letter; }
if(isdigit(ch)) { return digit; }
if(ch == '<') { return lt; }
if(ch == '>') { return gt; }
if(ch == '!') { return ne; }
if(ch == '=') { return eq; }
if(ch == '(') { return lp; }
if(ch == ')') { return rp; }
if(ch == ',') { return comma; }
if(ch == ';') { return semi; }
if(ch == '.') { return dot; }
if(ch == '#') { return hash; }
if(ch == '-') { return subassg; }
if(ch == '+') { return add; }
if(ch == '*') { return mul; }
if(ch == '/') { return div; }
if(ch == '{') { return strand; }
if(ch == '[') { return lb; }
if(ch == ']') { return rb; }
if(ch == '"') { return string; }
else return -1;
}

// Get first nonblank character	
char getNonBlank(FILE *fp) {
char ch = fgetc(fp);
while((ch == '\n') || (ch == '\t') || (ch == ' ')) {
if(ch=='\n') linecount+=1;
ch = fgetc(fp);
} 
return ch;
}

// Accumulate characters into current lexeme	
void addChar(char ch) {
if(lexlen<25) { 
lexeme[lexlen] = ch;
lexlen++;
}
else
printf("Lexeme length exceeded. Cannot add character.\n");
}

void clearBuffer() {
memcpy(lexeme, null, MAX_TOK_LENGTH);
lexlen = 0;
}

// Get next token
list* tokenize(FILE *fp) {
printf("\tStarting lexical analysis...\n");
hash_table *ht;
ht = init_hash_table(30);

int numtoken = 0;
int ch = fgetc(fp);

token tk;
list* tokenStream = (list*)malloc(sizeof(list));
node_t *ptr = (node_t*)malloc(sizeof(node_t));
ptr = NULL;
tokenStream->head = ptr;
tokenStream->size = 0;
char temp;
int flag = 0, errcount = 0;

while(ch != -1) {
addChar(ch);
//printf("Lexeme here is %s \n", lexeme);
switch(charClass(ch)) {

case letter:    ch = fgetc(fp);
		while(isdigit(ch) || isalpha(ch)) {
		addChar(ch);
		ch = fgetc(fp);	
		}	
		ungetc(ch,fp);
		int l = lookup_string(ht,lexeme);
		//printf("Printing l value %d\n", l);
		if(l == -1) {
		strcpy(tk.type, "TK_IDENTIFIER");
		tk.enumval = TK_IDENTIFIER;
		}
	
		else {
		tk.enumval = l;
		strcpy(tk.type, giveName(l));
		}
		//printf("Out of here.");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		clearBuffer();
		flag = 1;
		break;

case digit: 	ch = fgetc(fp);
		while(isdigit(ch)) {
		addChar(ch);
		ch = fgetc(fp);
		}
		ungetc(ch, fp);
		strcpy(tk.type, "TK_INT");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_INT;
		clearBuffer();
		flag = 1;
		break;

case lt:	ch = fgetc(fp);
		if((ch == 'A') || (ch == 'T') || (ch == 'G') || (ch == 'C')) {
		temp = ch;
		addChar(ch);
		ch = fgetc(fp);
		if (ch != '>') { //Backtracking 
		ungetc(ch, fp);
		ungetc(temp, fp);
		strcpy(tk.type, "TK_LT");
		strcpy(tk.value, "<");
		tk.lineno = linecount;
		tk.enumval = TK_LE;
		clearBuffer();
		flag = 1;
		break; }
		addChar(ch);
		strcpy(tk.type, "TK_BASE");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_BASE;
		clearBuffer();
		flag = 1;
		break;		
		}
		
		if(ch == '=') {
		addChar(ch); 
		strcpy(tk.type, "TK_LE");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_LE;
		clearBuffer();
		flag = 1;
		break;	
		}
		
		ungetc(ch, fp);
		strcpy(tk.type, "TK_LT");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_LT;
		clearBuffer();
		flag = 1;
		break; 	
			
case gt:	ch = fgetc(fp);
		if(ch == '=') {
		addChar(ch); 
		strcpy(tk.type, "TK_GE");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_GE;
		clearBuffer();
		flag = 1;
		break;	
		}
		
		else {
		ungetc(ch, fp);
		strcpy(tk.type, "TK_GT");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_GT;
		clearBuffer();
		flag = 1;
		break; }	

case ne:	ch = fgetc(fp);
		if(ch == '=') {
		addChar(ch); 
		strcpy(tk.type, "TK_NOTEQUAL");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_NOTEQUAL;
		clearBuffer();
		flag = 1;
		break;	
		}

		else {
		errcount++;
		printf("\tUnexpected character '%s' at line %d.\n", lexeme, linecount);
		clearBuffer();
		ungetc(ch, fp);
		break;
		}

case eq:	ch = fgetc(fp);
		if(ch == '=') {
		addChar(ch); 
		strcpy(tk.type, "TK_EQUAL");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_EQUAL;
		clearBuffer();
		flag = 1;
		break;	
		}

		else {
		errcount++;
		printf("\tUnexpected character '%s' at line %d.\n", lexeme, linecount);
		clearBuffer();
		ungetc(ch, fp);
		break;
		}

case lp:	strcpy(tk.type, "TK_LP");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_LP;
		clearBuffer();
		flag = 1;
		break;	
	
case rp:	strcpy(tk.type, "TK_RP");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_RP;
		clearBuffer();
		flag = 1;
		break;	

case comma:	strcpy(tk.type, "TK_COMMA");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_COMMA;
		clearBuffer();
		flag = 1;
		break;	

case semi:	strcpy(tk.type, "TK_SEMI");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_SEMI;
		clearBuffer();
		flag = 1;
		break;	

case dot:	strcpy(tk.type, "TK_DOT");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_DOT;
		clearBuffer();
		flag = 1;
		break;		

//case hash:	while(lookahead(fp) != '#' && ch != -1) {
//		ch = fgetc(fp); 
//		if (ch==-1) printf("Unterminated comment.");}
//		break;
		
case subassg:	ch = fgetc(fp);
		if(ch == '>') {
		addChar(ch); 
		strcpy(tk.type, "TK_ASSIGNOP");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_ASSIGNOP;
		clearBuffer();
		flag = 1;
		break;	
		}
		
		else {
		ungetc(ch, fp);
		strcpy(tk.type, "TK_SUB");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_SUB;
		clearBuffer();
		flag = 1;
		break; }	
	
case add:	strcpy(tk.type, "TK_ADD");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_ADD;
		clearBuffer();
		flag = 1;
		break;	
	
case mul:	strcpy(tk.type, "TK_MUL");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_MUL;
		clearBuffer();
		flag = 1;
		break;		

case div:	strcpy(tk.type, "TK_DIV");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_DIV;
		clearBuffer();
		flag = 1;
		break;	
	
case strand:	ch = fgetc(fp);
		while((ch == 'A') || (ch == 'T') || (ch == 'G') || (ch == 'C')) {
		addChar(ch);
		ch = fgetc(fp);
		}
		if(ch == '}') {
		addChar(ch);
		strcpy(tk.type, "TK_STRAND");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_STRAND;
		clearBuffer();
		flag = 1;
		break;	
		}

		else {
		errcount++;
		printf("\tUnexpected character '%s' at line %d.\n", lexeme, linecount);
		clearBuffer();
		ungetc(ch, fp);
		break;
		}			

case lb:	strcpy(tk.type, "TK_LB");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_LB;
		clearBuffer();
		flag = 1;
		break;	
		
case rb:	strcpy(tk.type, "TK_RB");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_RB;
		clearBuffer();
		flag = 1;
		break;	

case string:	ch = fgetc(fp);
		while(ch != '"') {
		addChar(ch);
		ch = fgetc(fp);		
		} 
		addChar(ch);	
		strcpy(tk.type, "TK_STRINGCONSTANT");
		strcpy(tk.value, lexeme);
		tk.lineno = linecount;
		tk.enumval = TK_STRINGCONSTANT;
		clearBuffer();
		flag = 1;
		break;

default:	errcount++;
		printf("\tUnexpected character '%s' at line %d.\n", lexeme, linecount);
		clearBuffer();

}

ch = getNonBlank(fp);
//printf("Character here is %c\n", ch);
numtoken++;
if (flag) {
if(numtoken == 0) tokenStream = create_list(tk);
else tokenStream = addListNode(tk, tokenStream); 
flag = 0; }
}
printf("\t...Lexical analysis complete.\n \t%d tokens read.\n", tokenStream->size);
printf("\t%d errors detected.\n", errcount);

/*if(tokenStream != NULL) {
FILE *tok;
tok = fopen("tokens.txt", "w");
print_tokens(tokenStream, tok); 
}
*/

if(errcount>0) {
printf("\tLexical analysis unsuccessful.\n");
}


return tokenStream;
}
