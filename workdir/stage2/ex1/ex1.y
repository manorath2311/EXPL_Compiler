%{
	#include <stdlib.h>
	#include <stdio.h>
	#include<string.h>
	#include "ex1.h"
	#include "ex1.c"
    //extern FILE* yyin;
    void yyerror(char const *s);
	int yylex(void);
%}

%union{
	struct tnode *node;
}

%type <node> program stmt_list stmt expr ID_T NUM_T
%token PLUS_T MINUS_T MUL_T DIV_T
%token BEGIN_T END_T READ_T WRITE_T ID_T NUM_T
%left PLUS_T MINUS_T
%left MUL_T DIV_T

%%

program : BEGIN_T stmt_list END_T ';' {
								$$ = $2;
								printf("Parsing Successful\n");
								//print_tree($2, 0, 0);
								//preorder($2);
                                evaluate($2);
								printf("\n");

								exit(1);
							}
		| BEGIN_T END_T ';' {
			printf("Empty Program\n");
			printf("Parsing Successful\n");
			exit(1);
		}

stmt_list: stmt_list stmt ';' {$$ = makeStmtNode(STATEMENT_NODE_CONST, $1, $2);}
	| stmt ';' {$$ = $1;}

stmt : READ_T '(' ID_T ')' { $$ = makeStmtNode(READ_NODE_CONST, $3, (struct tnode *)NULL); }
	| WRITE_T '(' expr ')' { $$ = makeStmtNode(WRITE_NODE_CONST, $3, (struct tnode *)NULL); }
	| ID_T '=' expr { $$ = makeExprNode(ASSIGN_NODE_CONST, '=', $1, $3); }

expr : expr PLUS_T expr		{$$ = makeExprNode(STATEMENT_NODE_CONST, '+',$1, $3);  printf("Parsed PLUS expression\n");}
	| expr MINUS_T expr  	{$$ = makeExprNode(STATEMENT_NODE_CONST, '-',$1, $3);  printf("Parsed MINUS expression\n");}
	| expr MUL_T expr	{$$ = makeExprNode(STATEMENT_NODE_CONST, '*',$1, $3);  printf("Parsed MUL expression\n");}
	| expr DIV_T expr	{$$ = makeExprNode(STATEMENT_NODE_CONST, '/',$1, $3);  printf("Parsed DIV expression\n");}
	| '(' expr ')' 	{$$ = $2;}
	| NUM_T		{$$ = $1;}
	| ID_T	{$$ = $1;}

%%

void yyerror(char const *s)
{
    printf("yyerror %s",s);
}


int main(void) 
{
	yyparse();
	
	return 0;
}