/*	Group 29: Team 2
	2012A7PS084P: Srishti Dhamija
	2012C6PS736P: Astha Gupta	*/

#include <stdio.h>
#include "type.h"
#include "parseFunctions.h"


int follow(int nt,int t)
{
	switch(nt)
	{
		case 1:	// "Program "
			switch(t)
			{
				case TK_DOLLAR:	return 1;
				default: return 0;			
			}
		case 2: // "functions"
			switch(t)
			{
				
				case TK_MAIN:return 1;
				default: return 0;

			}
		case 3: // "function"
			switch(t)
			{
				case TK_DATA_BASE:
				case TK_DATA_INT:
				case TK_DATA_STRAND:
				case TK_MAIN:return 1;
				default: return 0;

			}
		case 4: // "funsignature"
			switch(t)
			{
				case TK_START:return 1;
				default: return 0;
			} 
		case 5: // "params1"
			switch(t)
			{
				case TK_RP:return 1;
				default: return 0;

			} 
		case 6: // "params2"
			switch(t)
			{
				case TK_RP:return 1;
				default: return 0;
			}
		case 7: // "functionbody"
			switch(t)
			{

				case TK_ENDMAIN: 
				case TK_DATA_BASE: 
				case TK_DATA_INT:
				case TK_DATA_STRAND:
				case TK_MAIN:return 1;
				default: return 0;
			} 
		case 8: // "statements"
			switch(t)
			{
				case TK_END:return 1;
				default: return 0;
			}
		case 9: // "statement"
			switch(t)
			{
				
				case TK_IDENTIFIER:
				case TK_FOR:
				case TK_WHILE:
				case TK_IF:
				case TK_DATA_BASE:
				case TK_DATA_INT:
				case TK_DATA_STRAND:
				case TK_RETURN:
				case TK_BREAK:
				case TK_END:return 1;
				default: return 0;
				
			}
		case 10: // "Exp_stmt"
			switch(t)
			{
				
				case TK_IDENTIFIER:
				case TK_FOR:
				case TK_WHILE:
				case TK_IF:
				case TK_DATA_BASE:
				case TK_DATA_INT:
				case TK_DATA_STRAND:
				case TK_RETURN:
				case TK_BREAK:
				case TK_END:return 1;
				default: return 0;
			}
		case 11: // "Exp_Con"
			switch(t)
			{
				case TK_SEMI:return 1;
				default: return 0;
			}
		case 12: // "more"
			switch(t)
			{
				case TK_MUL:
				case TK_DIV:
				case TK_ADD:
				case TK_SUB:
				case TK_LT: 
				case TK_GT:
				case TK_LE: 
				case TK_GE: 
				case TK_EQUAL:
				case TK_NOTEQUAL:
				case TK_AND:
				case TK_OR:
				case TK_RP:
				case TK_SEMI:return 1;
				default: return 0;
	
			}
		case 13: // "args1"
			switch(t)
			{
				case TK_RP:return 1;
				default: return 0;
				
			} 
		case 14: // "args2"
			switch(t)
			{
				case TK_RP:return 1;
				default: return 0;

			}
		case 15: // "args3"
			switch(t)
			{
				
				case TK_COMMA:
				case  TK_RP:return 1;
				default: return 0;
			} 
		case 16: // "Exp"
			switch(t)
			{
				
				case TK_RP:
				case  TK_SEMI:return 1;
				default: return 0;
			}
		case 17: // "Exp_Cont"
			switch(t)
			{
				case TK_RP:
				case  TK_SEMI:return 1;
				default: return 0;
			} 
		case 18: // "AndExp"
			switch(t)
			{
				
				case TK_OR:
				case TK_RP:
				case TK_SEMI:return 1;
				default: return 0;
			}
		case 19: // "AndExp_Cont"
			switch(t)
			{
				
				case TK_OR:
				case TK_RP:
				case TK_SEMI:return 1;
				default: return 0;
			}
		case 20: // "CompExp"
			switch(t)
			{
				case TK_AND:
				case TK_OR:
				case TK_RP:
				case TK_SEMI:return 1;
				default: return 0;
			}
		case 21: // "CompExp_Cont"
			switch(t)
			{
			case TK_AND:
			case TK_OR:
			case TK_RP:
			case TK_SEMI:return 1;
			default: return 0;
			} 
		case 22: // "CompOp"
			switch(t)
			{
				
				case TK_IDENTIFIER:
				case TK_INT: 
				case TK_LP: 
				case TK_BASE:
				case TK_STRAND:return 1;
				case  TK_READSTRAND:
				default: return 0;
			}
		case 23: // "PlusExp"
			switch(t)
			{
			case TK_LT:
			case TK_GT:
			case TK_LE: 
			case TK_GE: 
			case TK_EQUAL:
			case TK_NOTEQUAL:
			case TK_AND:
			case TK_OR:
			case TK_RP:
			case TK_SEMI:return 1;
			default: return 0;
			}
		case 24: // "PlusExp_Cont"
			switch(t)
			{
			
			case TK_LT: 
			case TK_GT:
			case TK_LE: 
			case TK_GE: 
			case TK_EQUAL:
			case TK_NOTEQUAL:
			case TK_AND:
			case TK_OR:
			case TK_RP:
			case TK_SEMI:return 1;
			default: return 0;
			}
		case 25: // "MulExp"
			switch(t)
			{
				
			case TK_ADD:
			case TK_SUB:
			case TK_LT: 
			case TK_GT:
			case TK_LE: 
			case TK_GE: 
			case TK_EQUAL:
			case TK_NOTEQUAL:
			case TK_AND:
			case TK_OR:
			case TK_RP:
			case TK_SEMI:return 1;
			default: return 0;
			}
		case 26: // "MulExp_Cont"
			switch(t)
			{
			case TK_ADD:
			case TK_SUB:
			case TK_LT: 
			case TK_GT:
			case TK_LE: 
			case TK_GE:
			case TK_EQUAL:
			case TK_NOTEQUAL:
			case TK_AND:
			case TK_OR:
			case TK_RP:
			case TK_SEMI:return 1;
			default: return 0;
			}
		case 27: // "RootExp"
			switch(t)
			{
				
				case TK_MUL:
				case TK_DIV:
				case TK_ADD:
				case TK_SUB:
				case TK_LT: 
				case TK_GT:
				case TK_LE: 
				case TK_GE: 
				case TK_EQUAL:
				case TK_NOTEQUAL:
				case TK_AND:
				case TK_OR:
				case TK_RP:
				case TK_SEMI:return 1;
				default: return 0;
			}
		case 28: // "DotOperators"
			switch(t)
			{
				case TK_MUL:
				case TK_DIV:
				case TK_ADD:
				case TK_SUB:
				case TK_LT: 
				case TK_GT:
				case TK_LE: 
				case TK_GE: 
				case TK_EQUAL:
				case TK_NOTEQUAL:
				case TK_AND:
				case TK_OR:
				case TK_RP:
				case TK_SEMI:return 1;
				default: return 0;
			} 
		case 29: // "Operator"
			switch(t)
			{
				case TK_MUL:
				case TK_DIV:
				case TK_ADD:
				case TK_SUB:
				case TK_LT: 
				case TK_GT:
				case TK_LE: 
				case TK_GE: 
				case TK_EQUAL:
				case TK_NOTEQUAL:
				case TK_AND:
				case TK_OR:
				case TK_RP:
				case TK_SEMI:return 1;
				default: return 0;
			} 
		case 30: // "Index"
			switch(t)
			{
				
				case TK_RP:return 1;
				default: return 0;
			}
		case 31: // "Iterative_stmt"
			switch(t)
			{
				case TK_IDENTIFIER:
				case TK_FOR:
				case TK_WHILE:
				case TK_IF:
				case TK_DATA_BASE:
				case TK_DATA_INT:
				case TK_DATA_STRAND:
				case TK_RETURN:
				case TK_BREAK:
				case TK_END:return 1;
				default: return 0;
			}
		case 32: // "For_stmt"
			switch(t)
			{
				case TK_IDENTIFIER:
				case TK_FOR:
				case TK_WHILE:
				case TK_IF:
				case TK_DATA_BASE:
				case TK_DATA_INT:
				case TK_DATA_STRAND:
				case TK_RETURN:
				case TK_BREAK:
				case TK_END:return 1;
				default: return 0;
			} 
		case 33: // "For_Con"
			switch(t)
			{
				case TK_RP:return 1;
				default: return 0;
			}
		case 34: // "While_stmt"
			switch(t)
			{
				case TK_IDENTIFIER:
				case TK_FOR:
				case TK_WHILE:
				case TK_IF:
				case TK_DATA_BASE:
				case TK_DATA_INT:
				case TK_DATA_STRAND:
				case TK_RETURN:
				case TK_BREAK:
				case TK_END:return 1;
				default: return 0;
			}
		case 35: // "Selection_stmt"
			switch(t)
			{
				case TK_IDENTIFIER:
				case TK_FOR:
				case TK_WHILE:
				case TK_IF:
				case TK_DATA_BASE:
				case TK_DATA_INT:
				case TK_DATA_STRAND:
				case TK_RETURN:
				case TK_BREAK:
				case TK_END:return 1;
				default: return 0;

			}
		case 36: // "Selection_Con"
			switch(t)
			{
				case TK_IDENTIFIER:
				case TK_FOR:
				case TK_WHILE:
				case TK_IF:
				case TK_DATA_BASE:
				case TK_DATA_INT:
				case TK_DATA_STRAND:
				case TK_RETURN:
				case TK_BREAK:
				case TK_END:return 1;
				default: return 0;
			}
		case 37: // "else_if"
			switch(t)
			{
				case TK_IDENTIFIER:
				case TK_FOR:
				case TK_WHILE:
				case TK_IF:
				case TK_DATA_BASE:
				case TK_DATA_INT:
				case TK_DATA_STRAND:
				case TK_RETURN:
				case TK_BREAK:
				case TK_END:return 1;
				default: return 0;
				
			}
		case 38: // "Declaration_stmt"
			switch(t)
			{
				case TK_IDENTIFIER:
				case TK_FOR:
				case TK_WHILE:
				case TK_IF:
				case TK_DATA_BASE:
				case TK_DATA_INT:
				case TK_DATA_STRAND:
				case TK_RETURN:
				case TK_BREAK:
				case TK_END:return 1;
				default: return 0;
			} 
		case 39: // "idList"
			switch(t)
			{
				case TK_SEMI:return 1;
				default: return 0;
			}
		case 40: // "idList_array"
			switch(t)
			{
				case TK_SEMI:return 1;
				default: return 0;

			} 
		case 41: // "//_stmt"
			switch(t)
			{
				case TK_IDENTIFIER:
				case TK_FOR:
				case TK_WHILE:
				case TK_IF:
				case TK_DATA_BASE:
				case TK_DATA_INT:
				case TK_DATA_STRAND:
				case TK_RETURN:
				case TK_BREAK:
				case TK_END:	return 1;
				default: return 0;
			}
		case 42: // "//_Root"
			switch(t)
			{
				case TK_SEMI:return 1;
				default: return 0;
			} 
		case 43: // "Break_stmt"
			switch(t)
			{
			    case TK_IDENTIFIER:
				case TK_FOR:
				case TK_WHILE:
				case TK_IF:
				case TK_DATA_BASE:
				case TK_DATA_INT:
				case TK_DATA_STRAND:
				case TK_RETURN:
				case TK_BREAK:
				case TK_END:return 1;
				default: return 0;
			}
		case 44: // "type"
			switch(t)
			{
				case TK_IDENTIFIER:return 1;
				default: return 0;
			}
		case 45: // "type_basic"
			switch(t)
			{
				case TK_IDENTIFIER:return 1;
				default: return 0;
			} 
		case 46: // "type_array"
			switch(t)
			{
				case TK_IDENTIFIER:return 1;
				default: return 0;
			}
		case 47: // "Base"
			switch(t)
			{
				case TK_RP:return 1;
				default: return 0;
			}
		case 48: // "Input_stmt"
			switch(t)
			{
				case TK_MUL:
				case TK_DIV:
				case TK_ADD:
				case TK_SUB:
				case TK_LT: 
				case TK_GT:
				case TK_LE: 
				case TK_GE: 
				case TK_EQUAL:
				case TK_NOTEQUAL:
				case TK_AND:
				case TK_OR:
				case TK_RP:
				case TK_SEMI: return 1;
				default: return 0;
			}
		case 49: // "PrintInt_stmt"
			switch(t)
			{
				case TK_IDENTIFIER:
				case TK_FOR:
				case TK_WHILE:
				case TK_IF:
				case TK_DATA_BASE:
				case TK_DATA_INT:
				case TK_DATA_STRAND:
				case TK_RETURN:
				case TK_BREAK:
				case TK_END: return 1;
				default: return 0;
			}
		case 50: // "PrintBase_stmt
			switch(t)
			{
				case TK_IDENTIFIER:
				case TK_FOR:
				case TK_WHILE:
				case TK_IF:
				case TK_DATA_BASE:
				case TK_DATA_INT:
				case TK_DATA_STRAND:
				case TK_RETURN:
				case TK_BREAK:
				case TK_END: return 1;
				default: return 0;
			}
	}
}

char * giveName(int element)
{
switch(element)
	{
	case 1:	return "Program ";
	case 2: return "functions";
	case 3: return "function";
	case 4: return "funsignature"; 
	case 5: return "params1"; 
	case 6: return "params2";
	case 7: return "functionbody"; 
	case 8: return "statements";
	case 9: return "statement";
	case 10: return "Exp_stmt";
	case 11: return "Exp_Con";
	case 12: return "more";
	case 13: return "args1"; 
	case 14: return "args2";
	case 15: return "args3"; 
	case 16: return "Exp";
	case 17: return "Exp_Cont"; 
	case 18: return "AndExp";
	case 19: return "AndExp_Cont";
	case 20: return "CompExp";
	case 21: return "CompExp_Cont"; 
	case 22: return "CompOp";
	case 23: return "PlusExp";
	case 24: return "PlusExp_Cont";
	case 25: return "MulExp";
	case 26: return "MulExp_Cont";
	case 27: return "RootExp";
	case 28: return "DotOperators"; 
	case 29: return "Operator"; 
	case 30: return "Index";
	case 31: return "Iterative_stmt";
	case 32: return "For_stmt"; 
	case 33: return "For_Con";
	case 34: return "While_stmt";
	case 35: return "Selection_stmt";
	case 36: return "Selection_Con";
	case 37: return "else_if";
	case 38: return "Declaration_stmt"; 
	case 39: return "idList";
	case 40: return "idList_array"; 
	case 41: return "Return_stmt";
	case 42: return "Return_Root"; 
	case 43: return "Break_stmt";
	case 44: return "type";
	case 45: return "type_basic"; 
	case 46: return "type_array";
	case 47: return "Base";
	case 48: return "Input_stmt";
	case 49: return "PrintInt_stmt";
	case 50: return "PrintBase_stmt";
	case 51: return "TK_INT";
	case 52: return "TK_BASE";
	case 53: return "TK_STRAND";
	case 54: return "TK_STRINGCONSTANT";
	case 55: return "TK_IDENTIFIER";
	case 56: return "TK_MAIN";
	case 57: return "TK_ENDMAIN";
	case 58: return "TK_START";
	case 59: return "TK_END";
	case 60: return "TK_FOR";
	case 61: return "TK_EACH";
	case 62: return "TK_IN";
	case 63: return "TK_WHILE";
	case 64: return "TK_IF";
	case 65: return "TK_ELSE";
	case 66: return "TK_RETURN";
	case 67: return "TK_BREAK";
	case 68: return "TK_DATA_INT";
	case 69: return "TK_DATA_BASE";
	case 70: return "TK_DATA_STRAND";
	case 71: return "TK_AND";
	case 72: return "TK_OR";
	case 73: return "TK_ASSIGNOP";
	case 74: return "TK_ADD";
	case 75: return "TK_SUB";
	case 76: return "TK_MUL";
	case 77: return "TK_DIV";
	case 78: return "TK_LT";
	case 79: return "TK_GT";
	case 80: return "TK_GE";
	case 81: return "TK_LE";
	case 82: return "TK_EQUAL";
	case 83: return "TK_NOTEQUAL";
	case 84: return "TK_LENGTH";
	case 85: return "TK_GET";
	case 86: return "TK_INSERT";
	case 87: return "TK_LP";
	case 88: return "TK_RP";
	case 89: return "TK_LB";
	case 90: return "TK_RB";
	case 91: return "TK_COMMA";
	case 92: return "TK_SEMI";
	case 93: return "TK_DOT";
	case 94: return "TK_DOLLAR";
	case 95: return "TK_READSTRAND";
	case 96: return "TK_PRINTINT";
	case 97: return "TK_PRINTBASE";
	case 98: return "e";
	default: return "ERROR 301: input not valid";
	}

}

void init_table()
{
//populating data in the table 
parse_table[Program][TK_MAIN] = 1;
parse_table[Program][TK_DATA_INT] = 1;
parse_table[Program][TK_DATA_BASE] = 1;
parse_table[Program][TK_DATA_STRAND] = 1;

parse_table[functions][TK_MAIN] = 3;
parse_table[functions][TK_DATA_INT] = 2;
parse_table[functions][TK_DATA_BASE] = 2;
parse_table[functions][TK_DATA_STRAND] = 2;

parse_table[function][TK_DATA_INT] = 4;
parse_table[function][TK_DATA_BASE] = 4;
parse_table[function][TK_DATA_STRAND] = 4;

parse_table[funsignature][TK_DATA_INT] = 5;
parse_table[funsignature][TK_DATA_BASE] = 5;
parse_table[funsignature][TK_DATA_STRAND] = 5;

parse_table[params1][TK_DATA_INT] = 6;
parse_table[params1][TK_DATA_BASE] = 6;
parse_table[params1][TK_DATA_STRAND] = 6;

parse_table[params2][TK_RP] = 8;
parse_table[params2][TK_COMMA]=7;

parse_table[functionbody][TK_START]=9;

parse_table[statements][TK_IDENTIFIER] =10;
parse_table[statements][TK_END] =11;
parse_table[statements][TK_FOR] =10;
parse_table[statements][TK_WHILE] =10;
parse_table[statements][TK_IF] =10;
parse_table[statements][TK_RETURN] =10;
parse_table[statements][TK_BREAK] =10;
parse_table[statements][TK_DATA_INT] =10;
parse_table[statements][TK_DATA_BASE] =10;
parse_table[statements][TK_DATA_STRAND] =10;
parse_table[statements][TK_PRINTBASE] =10;
parse_table[statements][TK_PRINTINT] =10;

// A PROBABLE MISTAKE ON SELECTION OF IF 
parse_table[statement][TK_IDENTIFIER] =12;
parse_table[statement][TK_FOR] =13;
parse_table[statement][TK_WHILE] =13 ;
parse_table[statement][TK_IF] =14 ;
parse_table[statement][TK_RETURN] =16;
parse_table[statement][TK_BREAK] =17;
parse_table[statement][TK_DATA_INT] =15;
parse_table[statement][TK_DATA_BASE] =15;
parse_table[statement][TK_DATA_STRAND] =15;
parse_table[statement][TK_PRINTBASE] =19;
parse_table[statement][TK_PRINTINT] =18;

parse_table[Exp_stmt][TK_IDENTIFIER] =20;

parse_table[Exp_Con][TK_ASSIGNOP] = 22;
parse_table[Exp_Con][TK_LP] = 23;
parse_table[Exp_Con][TK_DOT] = 21;

parse_table[more][TK_LP] = 24;

parse_table[args1][TK_RP] = 26;
parse_table[args1][TK_INT] = 25;
parse_table[args1][TK_STRINGCONSTANT] = 25;
parse_table[args1][TK_IDENTIFIER] = 25;

parse_table[args2][TK_RP] = 28;
parse_table[args2][TK_COMMA] = 27;

parse_table[args3][TK_INT] = 30;
parse_table[args3][TK_STRINGCONSTANT] = 31;
parse_table[args3][TK_IDENTIFIER] = 29;

parse_table[Exp][TK_INT] = 32;
parse_table[Exp][TK_BASE] = 32;
parse_table[Exp][TK_STRAND] = 32;
parse_table[Exp][TK_IDENTIFIER] = 32;
parse_table[Exp][TK_LP] = 32;
parse_table[Exp][TK_READSTRAND] = 32;

parse_table[Exp_Cont][TK_OR] = 33;
parse_table[Exp_Cont][TK_RP] = 34;
parse_table[Exp_Cont][TK_SEMI] = 34;

parse_table[AndExp][TK_INT] = 35;
parse_table[AndExp][TK_BASE] = 35;
parse_table[AndExp][TK_STRAND] = 35;
parse_table[AndExp][TK_IDENTIFIER] = 35;
parse_table[AndExp][TK_LP] = 35;
parse_table[AndExp][TK_READSTRAND] = 35;

parse_table[AndExp_Cont][TK_AND] = 36;
parse_table[AndExp_Cont][TK_OR] = 37;
parse_table[AndExp_Cont][TK_RP] = 37;
parse_table[AndExp_Cont][TK_SEMI] = 37;

parse_table[CompExp][TK_INT] = 38;
parse_table[CompExp][TK_BASE] = 38;
parse_table[CompExp][TK_STRAND] = 38;
parse_table[CompExp][TK_IDENTIFIER] = 38;
parse_table[CompExp][TK_LP] = 38;
parse_table[CompExp][TK_READSTRAND] = 38;

parse_table[CompExp_Cont][TK_AND] = 40;
parse_table[CompExp_Cont][TK_OR] = 40;
parse_table[CompExp_Cont][TK_LT] = 39;
parse_table[CompExp_Cont][TK_GT] = 39;
parse_table[CompExp_Cont][TK_GE] = 39;
parse_table[CompExp_Cont][TK_LE] = 39;
parse_table[CompExp_Cont][TK_EQUAL] = 39;
parse_table[CompExp_Cont][TK_NOTEQUAL] = 39;
parse_table[CompExp_Cont][TK_RP] = 40;
parse_table[CompExp_Cont][TK_SEMI] = 40;

parse_table[CompOp][TK_LT] = 41;
parse_table[CompOp][TK_GT] = 42;
parse_table[CompOp][TK_GE] = 43;
parse_table[CompOp][TK_LE] = 44;
parse_table[CompOp][TK_EQUAL] = 45;
parse_table[CompOp][TK_NOTEQUAL] = 46;

parse_table[PlusExp][TK_INT] = 47;
parse_table[PlusExp][TK_BASE] = 47;
parse_table[PlusExp][TK_STRAND] = 47;
parse_table[PlusExp][TK_IDENTIFIER] = 47;
parse_table[PlusExp][TK_LP] = 47;
parse_table[PlusExp][TK_READSTRAND] = 47;

parse_table[PlusExp_Cont][TK_AND] = 50;
parse_table[PlusExp_Cont][TK_OR] = 50;
parse_table[PlusExp_Cont][TK_ADD] = 48;
parse_table[PlusExp_Cont][TK_SUB] = 49;
parse_table[PlusExp_Cont][TK_LT] = 50;
parse_table[PlusExp_Cont][TK_GT] = 50;
parse_table[PlusExp_Cont][TK_GE] = 50;
parse_table[PlusExp_Cont][TK_LE] = 50;
parse_table[PlusExp_Cont][TK_EQUAL] = 50;
parse_table[PlusExp_Cont][TK_NOTEQUAL] = 50;
parse_table[PlusExp_Cont][TK_RP] = 50;
parse_table[PlusExp_Cont][TK_SEMI] = 50;


parse_table[MulExp][TK_INT] = 51;
parse_table[MulExp][TK_BASE] = 51;
parse_table[MulExp][TK_STRAND] = 51;
parse_table[MulExp][TK_IDENTIFIER] = 51;
parse_table[MulExp][TK_LP] = 51;
parse_table[MulExp][TK_READSTRAND] = 51;

parse_table[MulExp_Cont][TK_AND] = 54;
parse_table[MulExp_Cont][TK_OR] = 54;
parse_table[MulExp_Cont][TK_ADD] = 54;
parse_table[MulExp_Cont][TK_SUB] = 54;
parse_table[MulExp_Cont][TK_MUL] = 52;
parse_table[MulExp_Cont][TK_DIV] = 53;
parse_table[MulExp_Cont][TK_LT] = 54;
parse_table[MulExp_Cont][TK_GT] = 54;
parse_table[MulExp_Cont][TK_GE] = 54;
parse_table[MulExp_Cont][TK_LE] = 54;
parse_table[MulExp_Cont][TK_EQUAL] = 54;
parse_table[MulExp_Cont][TK_NOTEQUAL] = 54;
parse_table[MulExp_Cont][TK_RP] = 54;
parse_table[MulExp_Cont][TK_SEMI] = 54;

parse_table[RootExp][TK_INT] = 56;
parse_table[RootExp][TK_BASE] = 58;
parse_table[RootExp][TK_STRAND] = 59;
parse_table[RootExp][TK_IDENTIFIER] = 55;
parse_table[RootExp][TK_LP] = 57;
parse_table[RootExp][TK_READSTRAND] = 60;

parse_table[DotOperators][TK_AND] = 63;
parse_table[DotOperators][TK_OR] = 63;
parse_table[DotOperators][TK_ADD] = 63;
parse_table[DotOperators][TK_SUB] = 63;
parse_table[DotOperators][TK_MUL] = 63;
parse_table[DotOperators][TK_DIV] = 63;
parse_table[DotOperators][TK_LT] = 63;
parse_table[DotOperators][TK_GT] = 63;
parse_table[DotOperators][TK_GE] = 63;
parse_table[DotOperators][TK_LE] = 63;
parse_table[DotOperators][TK_EQUAL] = 63;
parse_table[DotOperators][TK_NOTEQUAL] = 63;
parse_table[DotOperators][TK_LP] = 62;
parse_table[DotOperators][TK_RP] = 63;
parse_table[DotOperators][TK_SEMI] = 63;
parse_table[DotOperators][TK_DOT] = 61;

parse_table[Operator][TK_LENGTH] = 64;
parse_table[Operator][TK_GET] = 65;

parse_table[Index][TK_INT] = 66;
parse_table[Index][TK_IDENTIFIER] = 67;

parse_table[Iterative_stmt][TK_FOR] = 68;
parse_table[Iterative_stmt][TK_WHILE] = 69;

parse_table[For_stmt][TK_FOR] = 70;

parse_table[For_Con][TK_RP] = 72;
parse_table[For_Con][TK_COMMA] = 71;

parse_table[While_stmt][TK_WHILE] = 73;

parse_table[Selection_stmt][TK_IF] = 74;

parse_table[Selection_Con][TK_IDENTIFIER] = 76;
parse_table[Selection_Con][TK_END] = 76;
parse_table[Selection_Con][TK_FOR] = 76;
parse_table[Selection_Con][TK_WHILE] = 76;
parse_table[Selection_Con][TK_IF] = 76;
parse_table[Selection_Con][TK_ELSE] = 75;
parse_table[Selection_Con][TK_RETURN] = 76;
parse_table[Selection_Con][TK_BREAK] = 76;
parse_table[Selection_Con][TK_DATA_INT] = 76;
parse_table[Selection_Con][TK_DATA_BASE] = 76;
parse_table[Selection_Con][TK_DATA_STRAND] = 76;

parse_table[else_if][TK_START] = 78;
parse_table[else_if][TK_IF] = 77;

parse_table[Declaration_stmt][TK_DATA_INT] = 79;
parse_table[Declaration_stmt][TK_DATA_BASE] = 79;
parse_table[Declaration_stmt][TK_DATA_STRAND] = 80;

parse_table[idList][TK_COMMA]=81;
parse_table[idList][TK_SEMI]=82;

parse_table[idList_array][TK_COMMA]=83;
parse_table[idList_array][TK_SEMI]=84;

parse_table[Return_stmt][TK_RETURN] = 85;

parse_table[Return_Root][TK_INT] = 86;
parse_table[Return_Root][TK_BASE] = 86;
parse_table[Return_Root][TK_STRAND] = 86;
parse_table[Return_Root][TK_IDENTIFIER] = 86;
parse_table[Return_Root][TK_LP] = 86;
parse_table[Return_Root][TK_SEMI] = 87;
parse_table[Return_Root][TK_READSTRAND] = 86;

parse_table[Break_stmt][TK_BREAK] = 88;

parse_table[type][TK_DATA_INT] = 89;
parse_table[type][TK_DATA_BASE] = 89;
parse_table[type][TK_DATA_STRAND] = 90;

parse_table[type_basic][TK_DATA_INT] = 91;
parse_table[type_basic][TK_DATA_BASE] = 92;

parse_table[type_array][TK_DATA_STRAND] = 93;

parse_table[Base][TK_BASE] = 94;
parse_table[Base][TK_IDENTIFIER] = 95;

parse_table[Input_stmt][TK_READSTRAND]=96;

parse_table[PrintInt_stmt][TK_PRINTINT]=97;

parse_table[PrintBase_stmt][TK_PRINTBASE]=98;
}

void table(Stack * stack , int action, TLink link) 	//Look up in the parse table 
{	sElem se;
	switch(action)
	{
	case 1:		//Program === functions TK_MAIN functionbody TK_ENDMAIN
	{	se.parent = link;
		se.child = TK_ENDMAIN;
		Push(stack,se);
		se.child = functionbody;
		Push(stack,se);
		se.child = TK_MAIN;
		Push(stack,se);
		se.child = functions;
		Push(stack,se);
		//printf("Pushed TK_ENDMAIN\n");
		break;
			
	}
	case 2:		//functions === function functions 
	{	se.parent = link;
		se.child = functions;
		Push(stack,se);
		se.child = function;
		Push(stack,se);
		break;
	}
	case 3:		//functions ===  e
	{	se.parent = link;
		se.child = e ;
		Push(stack,se);
		break;
	}
	case 4:		//function === funsignature functionbody
	{	se.parent = link;
		se.child = functionbody;
		Push(stack,se);
		se.child = funsignature;
		Push(stack,se);
		break;	
	}
	case 5:		//funsignature === type TK_IDENTIFIER TK_LP params1 TK_RP
	{	se.parent = link;
		se.child =TK_RP ;
		Push(stack,se);
		se.child = params1;
		Push(stack,se);
		se.child = TK_LP;
		Push(stack,se);
		se.child = TK_IDENTIFIER;
		Push(stack,se);
		se.child = type;
		Push(stack,se);
		break;
	}
	case 6:		//params1 === type TK_IDENTIFIER params2  
	{	se.parent = link;
		se.child = params2;
		Push(stack,se);
		se.child = TK_IDENTIFIER;
		Push(stack,se);
		se.child = type;
		Push(stack,se);
		break;
	}
	case 7:		//params2 === TK_COMMA params1
	{	se.parent = link;
		se.child = params1;
		Push(stack,se);
		se.child = TK_COMMA;
		Push(stack,se);
		break;
	} 
	case 8:		//params2 ===  e
	{	se.parent = link;
		se.child = e;
		Push(stack,se);
		break;
	}
	case 9:		//functionbody ===TK_START statements TK_END
	{	se.parent= link;
		se.child = TK_END;
		Push(stack,se);
		se.child = statements;
		Push(stack,se);
		se.child = TK_START ;
		Push(stack,se);
		break;
	}
	case 10:        //statements === statement statements
	{	se.parent = link;
		se.child = statements;
		Push(stack,se);
		se.child =statement ;
		Push(stack,se);
		break;
	} 
	case 11:	//statements ===  e
	{	se.parent = link;
		se.child = e;
		Push(stack,se);
		break;
	}
	case 12:	//statement === Exp_stmt
	{	se.parent = link;
		se.child = Exp_stmt;
		Push(stack,se);
		break;
	}
	case 13:	//statement ===Iterative_stmt
	{	se.parent = link;
		se.child = Iterative_stmt;
		Push(stack,se);
		break;
	}
	case 14:	//statement === Selection_stmt
	{	se.parent = link;
		se.child = Selection_stmt;
		Push(stack,se);
		break;
	} 
	case 15:	//statement ===  Declaration_stmt 
	{	se.parent = link;
		se.child =Declaration_stmt ;
		Push(stack,se);
		break;
	}
	case 16:	//statement ===Return_stmt
	{	se.parent = link;
		se.child = Return_stmt;
		Push(stack,se);
		break;
	}
	case 17:	//statement === Break_stmt 
	{	se.parent = link;
		se.child = Break_stmt;
		Push(stack,se);
		break;
	}
	case 18:	//statement ===PrintInt_stmt
	{	se.parent = link;
		se.child = PrintInt_stmt;
		Push(stack,se);
		break;
	}
	case 19:	//statement ===  PrintBase_stmt
	{	se.parent = link;
		se.child = PrintBase_stmt;
		Push(stack,se);
		break;
	}
	case 20:	//Exp_stmt === TK_IDENTIFIER Exp_Con TK_SEMI
	{	se.parent = link;
		se.child = TK_SEMI;
		Push(stack,se);
		se.child = Exp_Con;
		Push(stack,se);
		se.child = TK_IDENTIFIER;
		Push(stack,se);
		break;
	}
	case 21:	//Exp_Con === TK_DOT TK_INSERT TK_LP Base TK_RP
	{	se.parent = link;
		se.child = TK_RP;
		Push(stack,se);
		se.child = Base;
		Push(stack,se);
		se.child = TK_LP;
		Push(stack,se);
		se.child = TK_INSERT;
		Push(stack,se);
		se.child = TK_DOT;
		Push(stack,se);
		break;
	}
	case 22:	//Exp_Con ===  TK_ASSIGNOP Exp
	{	se.parent = link;
		se.child = Exp;
		Push(stack,se);
		se.child = TK_ASSIGNOP;
		Push(stack,se);
		break;
	}
	case 23:	//Exp_Con ===  more
	{	se.parent = link;
		se.child = more;
		Push(stack,se);
		break;
	}
	case 24:	//more === TK_LP args1 TK_RP
	{	se.parent = link;
		se.child = TK_RP;
		Push(stack,se);
		se.child = args1;
		Push(stack,se);
		se.child = TK_LP;
		Push(stack,se);
		break;
	}
	case 25:	//args1 === args3 args2
	{	se.parent= link;
		se.child = args2;
		Push(stack,se);
		se.child = args3;
		Push(stack,se);
		break;
	} 
	case 26:	//args1 === e
	{	se.parent= link;
		se.child = e;
		Push(stack,se);
		break;
	} 
	case 27:	//args2 === TK_COMMA args3 args2 
	{	se.parent = link;
		se.child =args2 ;
		Push(stack,se);
		se.child = args3;
		Push(stack,se);
		se.child =TK_COMMA ;
		Push(stack,se);
		break;
	}
	case 28:	//args2 ===  e
	{	se.parent = link;
		se.child = e;
		Push(stack,se);
		break;
	}
	case 29:	//args3 === TK_IDENTIFIER 
	{	se.parent = link;
		se.child = TK_IDENTIFIER;
		Push(stack,se);
		break;
	}
	case 30:	//args3 ===  TK_INT 
	{	se.parent = link;
		se.child =TK_INT ;
		Push(stack,se);
		break;
	}
	case 31:	//args3 ===TK_STRINGCONSTANT
	{	se.parent = link;
		se.child = TK_STRINGCONSTANT;
		Push(stack,se);
		break;
	}
	case 32:	//Exp === AndExp Exp_Cont
	{	se.parent = link;
		se.child = Exp_Cont;
		Push(stack,se);
		se.child = AndExp;
		Push(stack,se);
		break;
	}
	case 33:	//Exp_Cont === TK_OR Exp
	{	se.parent = link;
		se.child = Exp;
		Push(stack,se);
		se.child = TK_OR;
		Push(stack,se);
		break;
	} 
	case 34:	//Exp_Cont === e
	{	se.parent = link;
		se.child = e;
		Push(stack,se);
		break;
	}
	case 35:	//AndExp === CompExp AndExp_Cont
	{	se.parent = link;
		se.child = AndExp_Cont;
		Push(stack,se);
		se.child = CompExp;
		Push(stack,se);
		break;
	}
	case 36:	//AndExp_Cont === TK_AND AndExp
	{	se.parent = link;
		se.child = AndExp;
		Push(stack,se);
		se.child = TK_AND;
		Push(stack,se);
		break;
	} 
	case 37:	//AndExp_Cont ===  e
	{	se.parent = link;
		se.child = e;
		Push(stack,se);
		break;
	}
	case 38:	//CompExp === PlusExp CompExp_Cont
	{	se.parent = link;
		se.child = CompExp_Cont;
		Push(stack,se);
		se.child = PlusExp;
		Push(stack,se);
		break;
	}
	case 39:	//CompExp_Cont === CompOp PlusExp
	{	se.parent = link;
		se.child = PlusExp;
		Push(stack,se);
		se.child = CompOp;
		Push(stack,se);
		break;
	}
	case 40:	//CompExp_Cont ===  e
	{	se.parent = link;
		se.child = e;
		Push(stack,se);
		break;
	}
	case 41:	//CompOp === TK_LT 
	{	se.parent = link;
		se.child = TK_LT;
		Push(stack,se);
		break;
	}
	case 42:	//CompOp === TK_GT
	{	se.parent = link;
		se.child = TK_GT;
		Push(stack,se);
		break;
	}
	case 43:	//CompOp === TK_LE
	{	se.parent = link;
		se.child =TK_LE ;
		Push(stack,se);
		break;
	}
	case 44:	//CompOp ===  TK_GE
	{	se.parent = link;
		se.child = TK_GE;
		Push(stack,se);
		break;
	}
	case 45:	//CompOp ===  TK_EQUAL
	{	se.parent = link;
		se.child = TK_EQUAL;
		Push(stack,se);
		break;
	} 
	case 46:	//CompOp ===  TK_NOTEQUAL
	{	se.parent = link;
		se.child = TK_NOTEQUAL;
		Push(stack,se);
		break;
	}
	case 47:	//PlusExp === MulExp PlusExp_Cont 
	{	se.parent = link;
		se.child = PlusExp_Cont;
		Push(stack,se);
		se.child = MulExp;
		Push(stack,se);
		break;
	} 
	case 48:	//PlusExp_Cont === TK_ADD PlusExp
	{	se.parent = link;
		se.child = PlusExp;
		Push(stack,se);
		se.child = TK_ADD;
		Push(stack,se);
		break;
	} 
	case 49:	//PlusExp_Cont ===TK_SUB PlusExp
	{	se.parent = link;
		se.child = PlusExp;
		Push(stack,se);
		se.child = TK_SUB;
		Push(stack,se);
		break;
	} 
	case 50:	//PlusExp_Cont ===  e
	{	se.parent = link;
		se.child = e;
		Push(stack,se);
		break;
	}
	case 51:	//MulExp === RootExp MulExp_Cont
	{	se.parent =link;
		se.child = MulExp_Cont;
		Push(stack,se);
		se.child = RootExp;
		Push(stack,se);
		break;
	} 
	case 52:	//MulExp_Cont === TK_MUL MulExp
	{	se.parent = link;
		se.child = MulExp;
		Push(stack,se);
		se.child = TK_MUL;
		Push(stack,se);
		break;
	} 
	case 53:	//MulExp_Cont === TK_DIV MulExp
	{	se.parent = link;
		se.child = MulExp;
		Push(stack,se);
		se.child =TK_DIV ;
		Push(stack,se);
		break;
	} 
	case 54:	//MulExp_Cont === e
	{	se.parent = link;
		se.child =e ;
		Push(stack,se);
		break;
	}
	case 55:	//RootExp === TK_IDENTIFIER DotOperators
	{	se.parent = link;
		se.child =DotOperators ;
		Push(stack,se);
		se.child = TK_IDENTIFIER;
		Push(stack,se);
		break;
	}
	case 56:	//RootExp ===  TK_INT
	{	se.parent = link;
		se.child = TK_INT;
		Push(stack,se);
		break;
	} 
	case 57:	//RootExp === TK_LP Exp TK_RP
	{	se.parent = link;
		se.child = TK_RP;
		Push(stack,se);
		se.child =Exp ;
		Push(stack,se);
		se.child = TK_LP;
		Push(stack,se);
		break;
	}
	case 58:	//RootExp === TK_BASE
	{	se.parent = link;
		se.child = TK_BASE;
		Push(stack,se);
		break;
	} 
	case 59:	//RootExp ===  TK_STRAND
	{	se.parent = link;
		se.child = TK_STRAND;
		Push(stack,se);
		break;
	}
	case 60:	//RootExp ===Input_stmt
	{	se.parent = link;
		se.child = Input_stmt;
		Push(stack,se);
		break;
	}
	case 61:	//DotOperators === TK_DOT Operator
	{	se.parent = link;
		se.child = Operator;
		Push(stack,se);
		se.child = TK_DOT;
		Push(stack,se);
		break;
	}
	case 62:	//DotOperators === more
	{	se.parent = link;
		se.child = more;
		Push(stack,se);
		break;
	}
	case 63:	//DotOperators ===  e
	{	se.parent = link;
		se.child = e;
		Push(stack,se);
		break;
	}
	case 64:	//Operator === TK_LENGTH 
	{	se.parent = link;
		se.child = TK_LENGTH;
		Push(stack,se);
		break;
	}
	case 65:	//Operator === TK_GET TK_LP Index TK_RP
	{	se.parent = link;
		se.child = TK_RP;
		Push(stack,se);
		se.child =Index ;
		Push(stack,se);
		se.child = TK_LP;
		Push(stack,se);
		se.child = TK_GET;
		Push(stack,se);
		break;
	}
	case 66:	//Index === TK_INT
	{	se.parent = link;
		se.child = TK_INT;
		Push(stack,se);
		break;
	}
	case 67:	//Index === TK_IDENTIFIER
	{	se.parent = link;
		se.child = TK_IDENTIFIER;
		Push(stack,se);
		break;
	}
	case 68:	//Iterative_stmt === For_stmt
	{	se.parent = link;
		se.child =For_stmt ;
		Push(stack,se);
		break;
	} 
	case 69:	//Iterative_stmt === While_stmt
	{	se.parent = link;
		se.child = While_stmt;
		Push(stack,se);
		break;
	}
	case 70:	//For_stmt === TK_FOR TK_EACH TK_LP TK_IDENTIFIER TK_IN TK_IDENTIFIER For_Con TK_RP TK_START statements TK_END
	{	se.parent = link;
		se.child = TK_END;
		Push(stack,se);
		se.child = statements;
		Push(stack,se);
		se.child =TK_START ;
		Push(stack,se);
		se.child = TK_RP;
		Push(stack,se);
		se.child = For_Con;
		Push(stack,se);
		se.child = TK_IDENTIFIER;
		Push(stack,se);
		se.child = TK_IN;
		Push(stack,se);
		se.child = TK_IDENTIFIER;
		Push(stack,se);
		se.child = TK_LP;
		Push(stack,se);
		se.child = TK_EACH;
		Push(stack,se);
		se.child =TK_FOR ;
		Push(stack,se);
		break;
	} 
	case 71:	//For_Con === TK_COMMA TK_IDENTIFIER TK_IN TK_IDENTIFIER For_Con
	{	se.parent = link;
		se.child = For_Con;
		Push(stack,se);
		se.child = TK_IDENTIFIER;
		Push(stack,se);
		se.child = TK_IN;
		Push(stack,se);
		se.child = TK_IDENTIFIER;
		Push(stack,se);
		se.child = TK_COMMA;
		Push(stack,se);
		break;
	}  
	case 72:	//For_Con === e
	{	se.parent = link;
		se.child = e;
		Push(stack,se);
		break;
	}
	case 73:	//While_stmt === TK_WHILE TK_LP Exp TK_RP TK_START statements TK_END
	{	se.parent = link;
		se.child = TK_END;
		Push(stack,se);
		se.child = statements;
		Push(stack,se);
		se.child = TK_START;
		Push(stack,se);
		se.child = TK_RP;
		Push(stack,se);
		se.child = Exp;
		Push(stack,se);
		se.child = TK_LP;
		Push(stack,se);
		se.child = TK_WHILE;
		Push(stack,se);
		break;
	} 
	case 74:	//Selection_stmt=== TK_IF TK_LP Exp TK_RP TK_START statements TK_END Selection_Con
	{	se.parent = link;
		se.child = Selection_Con;
		Push(stack,se);
		se.child = TK_END;
		Push(stack,se);
		se.child = statements;
		Push(stack,se);
		se.child = TK_START;
		Push(stack,se);
		se.child = TK_RP;
		Push(stack,se);
		se.child = Exp;
		Push(stack,se);
		se.child = TK_LP;
		Push(stack,se);
		se.child = TK_IF;
		Push(stack,se);
		break;
	} 
	case 75:	//Selection_Con=== TK_ELSE else_if
	{	se.parent = link;
		se.child = else_if;
		Push(stack,se);
		se.child = TK_ELSE;
		Push(stack,se);
		break;
	}
	case 76:	//Selection_Con=== e
	{	se.parent= link;
		se.child = e;
		Push(stack,se);
		break;
	}
	case 77:	//else _if === TK_IF TK_LP Exp TK_RP TK_START statements TK_END TK_ELSE else_if
	{	se.parent = link;
		se.child = else_if;
		Push(stack,se);
		se.child = TK_ELSE;
		Push(stack,se);
		se.child = TK_END;
		Push(stack,se);
		se.child = statements;
		Push(stack,se);
		se.child = TK_START;
		Push(stack,se);
		se.child = TK_RP;
		Push(stack,se);
		se.child = Exp;
		Push(stack,se);
		se.child = TK_LP;
		Push(stack,se);
		se.child = TK_IF;
		Push(stack,se);
		break;
	}
	case 78:	//else _if ===  TK_START statements TK_END
	{	se.parent = link;
		se.child = TK_END;
		Push(stack,se);
		se.child = statements;
		Push(stack,se);
		se.child = TK_START;
		Push(stack,se);
		break;
	}
	case 79:	//Declaration_stmt === type_basic  TK_IDENTIFIER idList TK_SEMI
	{	se.parent = link;
		se.child = TK_SEMI;
		Push(stack,se);
		se.child = idList;
		Push(stack,se);
		se.child = TK_IDENTIFIER;
		Push(stack,se);
		se.child = type_basic;
		Push(stack,se);
		break;
	} 
	case 80:	//Declaration_stmt === type_array TK_IDENTIFIER TK_LB TK_INT TK_RB idList_array TK_SEMI
	{	se.parent = link;
		se.child = TK_SEMI;
		Push(stack,se);
		se.child = idList_array;
		Push(stack,se);
		se.child = TK_RB;
		Push(stack,se);
		se.child = TK_INT;
		Push(stack,se);
		se.child = TK_LB;
		Push(stack,se);
		se.child = TK_IDENTIFIER;
		Push(stack,se);
		se.child = type_array;
		Push(stack,se);
		break;
	}
	case 81:	//idList === TK_COMMA TK_IDENTIFIER idList
	{	se.parent = link;
		se.child = idList;
		Push(stack,se);
		se.child = TK_IDENTIFIER;
		Push(stack,se);
		se.child = TK_COMMA;
		Push(stack,se);
		break;
	}
	case 82:	//idList === e
	{	se.parent = link;
		se.child = e;
		Push(stack,se);
		break;
	}
	case 83:	//idList_array === TK_COMMA TK_IDENTIFIER TK_LB TK_INT TK_RB idList_array
	{	se.parent = link;
		se.child = idList_array;
		Push(stack,se);
		se.child = TK_RB;
		Push(stack,se);
		se.child = TK_INT;
		Push(stack,se);
		se.child = TK_LB;
		Push(stack,se);
		se.child = TK_IDENTIFIER;
		Push(stack,se);
		se.child = TK_COMMA;
		Push(stack,se);
		break;
	}
	case 84:	//idList_array === e
	{	se.parent = link;
		se.child = e;
		Push(stack,se);
		break;
	}
	case 85:	//Return_stmt === TK_RETURN Return_Root TK_SEMI
	{	se.parent = link;
		se.child = TK_SEMI;
		Push(stack,se);
		se.child = Return_Root;
		Push(stack,se);
		se.child = TK_RETURN;
		Push(stack,se);
		break;
	}
	case 86:	//Return_Root === Exp
	{	se.parent = link;
		se.child = Exp;
		Push(stack,se);
		break;
	} 
	case 87:	//Return_Root ===e
	{	se.parent = link;
		se.child = e;
		Push(stack,se);
		break;
	}
	case 88:	//Break_stmt === TK_BREAK TK_SEMI
	{	se.parent = link;
		se.child = TK_SEMI;
		Push(stack,se);
		se.child =TK_BREAK ;
		Push(stack,se);
		break;
	}
	case 89:	//type === type_basic
	{	se.parent = link;
		se.child = type_basic;
		Push(stack,se);
		break;
	} 
	case 90:	//type ===type_array
	{	se.parent = link;
		se.child = type_array;
		Push(stack,se);
		break;
	}
	case 91:	//type_basic === TK_DATA_INT
	{	se.parent = link;
		se.child = TK_DATA_INT;
		Push(stack,se);
		break;
	}
	case 92:	//type_basic ===TK_DATA_BASE
	{	se.parent = link;
		se.child = TK_DATA_BASE;
		Push(stack,se);
		break;
	} 
	case 93:	//type_array === TK_DATA_STRAND
	{	se.parent = link;
		se.child = TK_DATA_STRAND;
		Push(stack,se);
		break;
	}
	case 94:	//Base === TK_BASE
	{	se.parent = link;
		se.child = TK_BASE;
		Push(stack,se);
		break;
	}
	case 95:	//Base === TK_IDENTIFIER
	{	se.parent = link;
		se.child = TK_IDENTIFIER;
		Push(stack,se);
		break;
	}
	case 96:	//Input_stmt=== TK_READSTRAND TK_LP TK_STRINGCONSTANT TK_RP
	{	se.parent =link;
		se.child = TK_RP;
		Push(stack,se);
		se.child = TK_STRINGCONSTANT;
		Push(stack,se);
		se.child = TK_LP;
		Push(stack,se);
		se.child = TK_READSTRAND;
		Push(stack,se);
		break;

	}
	case 97:	//PrintInt_stmt === TK_PRINTINT TK_LP Index TK_RP TK_SEMI
	{	se.parent = link;
		se.child = TK_SEMI;
		Push(stack,se);
		se.child = TK_RP;
		Push(stack,se);
		se.child = Index;
		Push(stack,se);
		se.child = TK_LP;
		Push(stack,se);
		se.child = TK_PRINTINT;
		Push(stack,se);
		break;

	}
	case 98:	//PrintBase_stmt === TK_PRINTBASE TK_LP Base TK_RP TK_SEMI
	{	se.parent = link;
		se.child =TK_SEMI ;
		Push(stack,se);
		se.child = TK_RP;
		Push(stack,se);
		se.child = Base;
		Push(stack,se);
		se.child = TK_LP;
		Push(stack,se);
		se.child = TK_PRINTBASE;
		Push(stack,se);
		break;
	}
	default:
	{
		printf("ERROR 201: error while looking up at parse table");
	}

	}
}

