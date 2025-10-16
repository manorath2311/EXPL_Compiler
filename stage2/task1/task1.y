%{
	#include <stdlib.h>
	#include <stdio.h>
	#include<string.h>
	#include "task1.h"
	#include "task1.c"
    //extern FILE* yyin;
    void yyerror(char const *s);
	int yylex(void);
%}

%union{
	struct tnode *node;
}

%token PLUS_T MINUS_T MUL_T DIV_T
%token BEGIN_T END_T READ_T WRITE_T 
%left PLUS_T MINUS_T
%left MUL_T DIV_T
%type <node> program stmt_list stmt expr 
%token <node> ID_T NUM_T

%%

program : BEGIN_T stmt_list END_T ';' {
								$$ = $2;
								printf("Parsing Successful\n");
								print_tree($2, 0, 0);
								//preorder($2);
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


FILE *fp;
extern FILE *yyin;

int main(int argc, char *argv[]) 
{
	output=fopen("output.txt","w");
	if (argc < 2) 
	{
		printf("Please provide an input filename\n");
		exit(1);
	}
	else 
	{
		fp = fopen(argv[1], "r");
		if (!fp) 
		{
			printf("Invalid input file specified\n");
			exit(1);
		} 
		else 
		{
			yyin = fp;
		}
	}
	yyparse();
	return 0;
}
