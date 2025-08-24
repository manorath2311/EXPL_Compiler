%{
	#include <stdlib.h>
	#include <stdio.h>
	#include<string.h>
	#include "y.tab.h"
	#include "task1.h"
	int yyerror(const char *s);
	int number;
	char variable;
%}

%%

"begin" {return BEGIN_T;}
"end" {return END_T;}
"read" {return READ_T;}
"write" {return WRITE_T;}
"IF" {return IF_T;}
"Else" {return ELSE_T;}
"then" {return THEN_T;}
"ENDIF" {return ENDIF_T;}
"WHILE" {return WHILE_T;}
"DO" {return DO_T;}
"ENDWHILE" {return ENDWHILE_T;}
[a-z] {variable = *yytext; yylval.node = makeVariableNode(ID_NODE_CONST ,yytext); return ID_T;}
[0-9]+	{number = atoi(yytext); yylval.node = makeConstantNode(INT_NODE_CONST,number); return NUM_T;}
"+" {return PLUS_T;}
"-" {return MINUS_T;}
"*" {return MUL_T;}
"/" {return DIV_T;}
"=" {return *yytext;}
"==" {return EQ_T;}
'<' {return LT_T;}
'>' {return GT_T;}
"<=" {return LE_T;}
">=" {return GE_T;}
"!=" {return NE_T;}
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