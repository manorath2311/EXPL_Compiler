%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "y.tab.h"
%}

digit   [0-9]
alpha   [a-zA-Z]
op      [*+\-/%()]
NL      \n
alphanum ({digit}|{alpha})+

%%
{alphanum} { yylval.s = strdup(yytext); return STR; }
{op}       { return yytext[0]; }
{NL}       { return NL; }
[ \t]+     {}
.          { printf("Unrecognized symbol: %s\n", yytext); }
%%
int yywrap() { return 1; }
