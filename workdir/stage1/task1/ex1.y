%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "ex1.c"
	#include "ex1.h"
	int yylex(void);
    int yyerror(const char*);
	extern FILE* yyin;
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
                $$ = $2;
				printf("Answer : %d\n",evaluate($1));
				
				exit(1);
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


int main(void) 
{
	
	/* FILE *fp = fopen("input1.txt", "r");
	if (fp == NULL) 
	{
		
		perror("Error opening file");
		return 1;
	}
	yyin=fp; */
	yyparse();
	
	
	return 0;
}