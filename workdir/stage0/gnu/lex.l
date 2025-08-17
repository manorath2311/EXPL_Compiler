%{
	#include <stdio.h>
	#include "y.tab.h"
	#include "tree.h"
	#include <string.h>
	#include<stdlib.h>
	#include<stddef.h>
	#include<ctype.h>
	int number;
	char*temp;

%}

%%
"begin"     { return TBEGIN; }
"end"       { return TEND; }
"read"      { return TREAD; }
"write"     { return TWRITE; }
"if"        { return TIF; }
"then"      { return TTHEN; }
"else"      { return TELSE; }
"endif"     { return TENDIF; }
"while"     { return TWHILE; }
"do"        { return TDO; }
"endwhile"  { return TENDWHILE; }
"+"         { return PLUS; }
"-"         { return MINUS; }
"*"         { return MUL; }
"/"         { return DIV; }
"<"         { return LT; }
">"         { return GT; }
"<="        { return LE; }
">="        { return GE; }
"=="        { return EQ; }
"!="        { return NE; }
"="         { return ASSIGN; }
";"         { return ';'; }  /* or TEOL if you want */
[ \t\n]+    ;                /* ignore whitespace */
.           { /* ignore anything else */ }

%%

int yywrap(void) {
	return 1;
}