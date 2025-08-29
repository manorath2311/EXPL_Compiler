%{
	#include <stdlib.h>
	#include <stdio.h>
	#include "ex1.h"
	#include "ex1.c"
	#include <string.h>
	int yylex(void);
        extern FILE *yyin;
        FILE *fp;
        FILE *intermediate;
        void print(int);
		int yyerror(const char*);
%}

%union {
	struct tnode *nptr;
}

%token START END READ WRITE PLUS MINUS MUL DIV ASSGN 
%token <nptr> NUM ID
%left PLUS MINUS
%left MUL DIV

%type <nptr> program Slist Stmt InputStmt OutputStmt AsgStmt expr

%%

program: START Slist END ';'    {
                                    $$ = $2;
                                    evaluate($2);

                                }
       | START END ';'          {$$ = NULL;}
       ;

Slist: Slist Stmt       {$$ = createTree(1, 0, NODE_CONNECTOR, NULL, $1, $2);}
    | Stmt              {$$ = $1;}
    ;

Stmt: InputStmt         {$$ = $1;}
    | OutputStmt        {$$ = $1;}
    | AsgStmt           {$$ = $1;}
    ;

InputStmt: READ '(' ID ')' ';'  {$$ = createTree(1, 0, NODE_READ, NULL, $3, NULL);}
         ;

OutputStmt: WRITE '(' expr ')' ';' {$$ = createTree(1, 0, NODE_WRITE, NULL, $3, NULL);}
          ;

AsgStmt: ID ASSGN expr ';'      {$$ = createTree(1, 0, NODE_ASSGN, NULL, $1, $3);}
       ;

expr : expr PLUS expr	{$$ = createTree(1, 0, NODE_PLUS, NULL, $1, $3);}
     | expr MINUS expr  {$$ = createTree(1, 0, NODE_MINUS, NULL, $1, $3);}
     | expr MUL expr	{$$ = createTree(1, 0, NODE_MUL, NULL, $1, $3);}
     | expr DIV expr	{$$ = createTree(1, 0, NODE_DIV, NULL, $1, $3);}
     | '(' expr ')'	{$$ = $2;}
     | NUM		{$$ = $1;}
     | ID		{$$ = $1;}
     ;

%%

int yyerror(const char *s) 
{
    printf("yyerror %s",s);
	return 0;
}

int main(int argc, char *argv[]) 
{
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