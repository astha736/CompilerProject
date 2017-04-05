/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#ifndef TYPE_H
#define TYPE_H

typedef struct {

	char type[25];
	char value[25];
	int lineno;
	int enumval;

} token;

enum Token{
	TK_INT = 51,
	TK_BASE= 52,
	TK_STRAND= 53,
	TK_STRINGCONSTANT=54,
	TK_IDENTIFIER = 55,
	TK_MAIN=56,
	TK_ENDMAIN=57,
	TK_START=58,
	TK_END=59,
	TK_FOR=60,
	TK_EACH=61,
	TK_IN=62,
	TK_WHILE=63,
	TK_IF=64,
	TK_ELSE=65,
	TK_RETURN=66,
	TK_BREAK=67,
	TK_DATA_INT=68,
	TK_DATA_BASE=69,
	TK_DATA_STRAND=70,
	TK_AND=71,
	TK_OR=72,
	TK_ASSIGNOP=73,
	TK_ADD=74,
	TK_SUB=75,
	TK_MUL=76,
	TK_DIV=77,
	TK_LT=78,
	TK_GT=79,
	TK_GE=80,
	TK_LE=81,
	TK_EQUAL=82,
	TK_NOTEQUAL=83,
	TK_LENGTH=84,
	TK_GET=85,
	TK_INSERT=86,
	TK_LP=87,
	TK_RP=88,
	TK_LB=89,
	TK_RB=90,
	TK_COMMA=91,
	TK_SEMI=92,
	TK_DOT=93,
	TK_DOLLAR=94,
	TK_READSTRAND=95,
	TK_PRINTINT = 96,
	TK_PRINTBASE = 97,
	e=98
};

enum non_term {
	Program = 1,
	functions = 2,
	function = 3 ,
	funsignature = 4 , 
	params1=5, 
	params2=6,
	functionbody=7, 
	statements=8,
	statement=9,
	Exp_stmt=10,
	Exp_Con=11,
	more=12,
	args1=13, 
	args2=14,
	args3=15, 
	Exp=16,
	Exp_Cont=17, 
	AndExp=18, 
	AndExp_Cont=19,
	CompExp=20,
	CompExp_Cont=21, 
	CompOp=22,
	PlusExp=23, 
	PlusExp_Cont=24,
	MulExp=25,
	MulExp_Cont=26,
	RootExp=27, 
	DotOperators=28, 
	Operator=29, 
	Index=30,
	Iterative_stmt=31,
	For_stmt=32, 
	For_Con=33, 
	While_stmt=34,
	Selection_stmt=35,
	Selection_Con=36,
	else_if=37,
	Declaration_stmt=38, 
	idList=39,
	idList_array=40, 
	Return_stmt=41,
	Return_Root=42, 
	Break_stmt=43,
	type=44,
	type_basic=45, 
	type_array=46,
	Base=47,
	Input_stmt=48,
	PrintInt_stmt=49,
	PrintBase_stmt=50
};


#endif
