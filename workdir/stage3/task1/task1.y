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

%type <node> program stmt_list stmt expr ID_T NUM_T E Ifstmt Whilestmt
%token PLUS_T MINUS_T MUL_T DIV_T
%token BEGIN_T END_T READ_T WRITE_T ID_T NUM_T IF_T ELSE_T THEN_T ENDIF_T WHILE_T DO_T ENDWHILE_T
%token LT_T GT_T LE_T GE_T NE_T EQ_T
%left PLUS_T MINUS_T
%left MUL_T DIV_T

%%

program : BEGIN_T stmt_list END_T ';' {
								$$ = $2;
                                    //print_dot($2);
                                    // fprintf(intermediate, "MAIN:\n");
                                    // codegen($2); 
                                    // fprintf(intermediate, "RET\n");
                                    // fclose(intermediate);
									print_dot($2);

								exit(1);
							}
		| BEGIN_T END_T ';' {
			printf("Empty Program\n");
			printf("Parsing Successful\n");
			exit(1);
		}
		;

stmt_list: stmt_list stmt {$$ = createTree(VOID_NODE_CONST, 0, NODE_CONNECTOR, NULL, $1, $2, NULL);}
	| stmt {$$ = $1;}
	;

stmt : READ_T '(' ID_T ')' ';' { $$ = createTree(TYPE_VOID, 0, READ_NODE_CONST, NULL, $3, NULL, NULL);}	
	| WRITE_T '(' expr ')' ';' { $$ = createTree(TYPE_VOID, 0, WRITE_NODE_CONST, NULL, $3, NULL, NULL);}	
	| ID_T '=' expr ';' { $$ = createTree(TYPE_VOID, 0, ASSIGN_NODE_CONST, NULL, $1, $3, NULL);}	
	| Ifstmt
	| Whilestmt 
	;

expr : expr PLUS_T expr		{$$ = createTree(STATEMENT_NODE_CONST, 0, PLUS_NODE_CONST, NULL, $1, $3, NULL);  printf("Parsed PLUS expression\n");}
	| expr MINUS_T expr  	{$$ = createTree(STATEMENT_NODE_CONST, 0, MINUS_NODE_CONST, NULL, $1, $3, NULL);  printf("Parsed MINUS expression\n");}
	| expr MUL_T expr	{$$ = createTree(STATEMENT_NODE_CONST, 0, MUL_NODE_CONST, NULL, $1, $3, NULL);  printf("Parsed MUL expression\n");}
	| expr DIV_T expr	{$$ = createTree(STATEMENT_NODE_CONST, 0, DIV_NODE_CONST, NULL, $1, $3, NULL);  printf("Parsed DIV expression\n");}
	| '(' expr ')' 	{$$ = $2;}
	| E {$$=$1;}
    ;
Ifstmt : IF_T '(' E ')' THEN_T stmt_list ELSE_T stmt_list ENDIF_T {$$ = createTree(TYPE_VOID, 0, IF_ELSE_NODE_CONST, NULL, $3, $8, $6);}
		| IF_T '(' E ')' THEN_T stmt_list ENDIF_T  {$$ = createTree(TYPE_VOID, 0,IF_NODE_CONST, NULL, $3, $6, NULL);}
		;
Whilestmt : WHILE_T '(' E ')' DO_T stmt_list ENDWHILE_T {$$ = createTree(TYPE_VOID, 0, NODE_WHILE, NULL, $3, $6, NULL);}
		  ;

 E : E LT_T E { $$ = createTree(TYPE_BOOL_NODE_CONST, 0,LT_NODE_CONST, NULL, $1, $3, NULL);}
   | E GT_T E {$$ = createTree(TYPE_BOOL_NODE_CONST, 0,GT_NODE_CONST, NULL, $1, $3, NULL); }
   | E LE_T E {$$ = createTree(TYPE_BOOL_NODE_CONST, 0,LE_NODE_CONST, NULL, $1, $3, NULL);}
   | E GE_T E {$$ = createTree(TYPE_BOOL_NODE_CONST, 0,GE_NODE_CONST, NULL, $1, $3, NULL);}
   | E NE_T E {$$ = createTree(TYPE_BOOL_NODE_CONST, 0,NE_NODE_CONST, NULL, $1, $3, NULL);}
   | E EQ_T E {$$ = createTree(TYPE_BOOL_NODE_CONST, 0,EQ_NODE_CONST, NULL, $1, $3, NULL);}
   | ID_T  {$$=$1;}
   | NUM_T  {$$=$1;}
   ; 

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