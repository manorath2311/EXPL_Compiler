%{
    #include<stdio.h>
    #include "y.tab.h"
%}
chars [a-zA-Z0-9]
new_line \n
opn [-+*/()]
%%
{chars} {yylval.c=yytext[0]; return CHAR;}
{new_line} {return NL;}
{opn} {return yytext[0];}
. {printf("INVALID CHAR %s",yytext);}
%%
int yywrap()
{
    return 1;
}