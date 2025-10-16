%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "ex1.h"
	#include "ex1.c"
	int yylex(void);
    int yyerror(const char*);
%}

%union{
	struct tnode *no;
	
}
%type <no> expr NUM program END
%token NUM PLUS MINUS MUL DIV END
%left PLUS MINUS
%left MUL DIV

%%

program : expr END	
{
                printf("Prefix \n");
                printPrefix($1);
                printf("\n");
                printf("Postfix \n");
                printPostfix($1);
                printf("\n");
}
		;

expr : expr PLUS expr		{$$ = makeOperatorNode('+',$1,$3);}
	 | expr MINUS expr  	{$$ = makeOperatorNode('-',$1,$3);}
	 | expr MUL expr	{$$ = makeOperatorNode('*',$1,$3);}
	 | expr DIV expr	{$$ = makeOperatorNode('/',$1,$3);}
	 | '(' expr ')'		{$$ = $2;}
	 | NUM			{$$ = $1;}
	 ;

%%

int yyerror(char const *s)
{
    printf("yyerror %s",s);
    return 0;
}


int main(void) {
	yyparse();
	
	return 0;
}