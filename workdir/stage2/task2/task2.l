%{
	#include <stdlib.h>
	#include <stdio.h>
	#include<string.h>
	#include "y.tab.h"
	#include "task2.h"
	int yyerror(const char *s);
	int number;
	char variable;
%}

%%

"begin" {return BEGIN_T;}
"end" {return END_T;}
"read" {return READ_T;}
"write" {return WRITE_T;}
[a-z] {variable = *yytext; yylval.node = makeVariableNode(ID_NODE_CONST ,yytext); return ID_T;}
[0-9]+	{number = atoi(yytext); yylval.node = makeConstantNode(INT_NODE_CONST,number); return NUM_T;}
"+" {return PLUS_T;}
"-" {return MINUS_T;}
"*" {return MUL_T;}
"/" {return DIV_T;}
"=" {return *yytext;}
[\(\);] { return *yytext; }
[ \t\n]	{}
. {
    yyerror("unknown character\n");
    exit(1);
}

%%

int yywrap() 
{
	return 1;
}