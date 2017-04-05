/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include <stdio.h>
#include "tree.h"
#include "lex.h"
#include "parser.h"
#include "AST.h"
#include "symbolTable_new.h"
#include "typecheck.h"

int main(int argc, char **argv) {
	
if(argc==1) {
	printf("Please enter file name.\n");
	return 0;
}

char ch;
FILE *fp;
fp = fopen(argv[1], "r");

list* tokenStream;
tokenStream = tokenize(fp);
FILE *tok;
tok = fopen("Output/tokens.txt", "w");
print_tokens(tokenStream, tok);

symbolTable *symbol_table;
symbol_table = create_symbol_table(20);
symbol_table = populate_symbol_table(tokenStream, symbol_table);
FILE *s;
s = fopen("Output/SymbolTable.txt", "w");
print_symbol_table(symbol_table, s);

/*symbolTableEntry *e;
while(1) {
if((e = lookup_current_scope(symbol_table, "yes", 0))==NULL) printf("entry not found\n");
else printf("entry found. Type is %d.\n", e->enumval);
if(lookup_current_scope(symbol_table, "no", 0)==NULL) printf("entry not found\n");
else printf("entry found.\n");
return 0;
}
*/
Tree t;
t = createTree();

/* Old ST:
symbolTable *symbol_table;
symbol_table = create_symbol_table(20);

FILE *s;
s = fopen("symbolTable.txt", "w");*/

Tree *tptr = parse(tokenStream, &t);
if(tptr == NULL)
	return 0;
/* Old ST:
Tree *tptr = parse(tokenStream, &t, symbol_table);
print_symbol_table(symbol_table, s);
printf("\tSymbol table printed to file \"symbolTable.txt\"\n");
*/
FILE *fpt = fopen("Output/parseTree.txt", "w");
printTree(tptr, fpt);
printf("Parse tree printed to file \"Output/parseTree.txt\"\n");

printf("Starting AST conversion\n");

tptr =  _convertAST(tptr);
printf("\nStarting Type checker\n");
_typecheck(tptr,symbol_table);
}

