%{
    #include<stdio.h>
    #include "y.tab.h"

%}
digit [0-9]
alpha [a-zA-Z]
op [*+-/()%]
NL \n 
alphanum ({digit}|{alpha})+
%%
{alphanum} {yylval.s=strdup(yytext);return STR;}
{op} {yylval.op=yytext[0];return yytext[0];}
{NL} {return NL;}
[ \t]+  {} 
. {printf("NO SYMBOL EXIST");}
%%
int yywrap()
{
    return 1;
}