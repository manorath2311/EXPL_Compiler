%{
	#include <stdlib.h>
	#include <stdio.h>
    #include <string.h>
	#include "y.tab.h"
	#include "ex2.h"

	static int number, i, lineno = 1;
    char *variable;
    //int yyerror(const char *s);
%}

id [a-zA-Z_][0-9a-zA-Z_]*
str \"(\\.|[^\\\"])*\"

%%

[0-9]+	    {
                number = atoi(yytext);
                union Constant *value = (union Constant*)malloc(sizeof(union Constant));
                value->intval = number;
                yylval.nptr = TreeCreate(TYPE_INT, NODE_NUM, NULL, value, NULL, NULL, NULL, NULL);
                return NUM;
            }
"main"      {return MAIN;}
"return"    {return RETURN;}
"begin"     {return START;}
"end"       {return END;}
"read"      {return READ;}
"write"     {return WRITE;}
"if"        {return IF;}
"then"      {return THEN;}
"else"      {return ELSE;}
"endif"     {return ENDIF;}
"while"     {return WHILE;}
"do"        {return DO;}
"endwhile"  {return ENDWHILE;}
"break"     {return BREAK;}
"continue"  {return CONT;}
"decl"      {return DECL;}
"enddecl"   {return ENDDECL;}
"and"       {return AND;}
"AND"       {return AND;}
"or"        {return OR;}
"OR"        {return OR;}
"int"       {return INT;}
"str"       {return STR;}
"=="        {return EQ;}
"!="        {return NEQ;}
"<="        {return LE;}
">="        {return GE;}
"<"         {return LT;}
">"         {return GT;}
"+"         {return PLUS;}
"-"         {return MINUS;}
"*"         {return MUL;}
"/"         {return DIV;}
"%"         {return MOD;}
"="         {return ASSGN;}
"&"         {return ADDR;}
"type"      {return TYPE;}
"endtype"   {return ENDTYPE;}
{id}        {
                variable = (char*)malloc(sizeof(yytext));
                strcpy(variable, yytext);
                yylval.nptr = TreeCreate(TYPE_INT, NODE_ID, variable, NULL, NULL, NULL, NULL, NULL);
                return ID;
            }
{str}       {
                variable = (char*)malloc(sizeof(yytext));
                strcpy(variable, yytext);
                union Constant *value = (union Constant*)malloc(sizeof(union Constant));
                value->strval = variable;
                yylval.nptr = TreeCreate(TYPE_STR, NODE_STRVAL, NULL, value, NULL, NULL, NULL, NULL);
                return STRVAL;
            }
[ \t]	    {}
\n          {lineno++;}
[{}()\[\];,.]  {return *yytext;}
.	        {
                char msg[50];
                snprintf(msg, sizeof(msg), "unknown character: '%c'", yytext[0]);
                yyerror_impl(msg, NULL);
                exit(1);
            }

%%

int yywrap(void) {
    return 1;
}