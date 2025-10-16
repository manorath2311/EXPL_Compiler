%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
    #include<ctype.h>
	#include "task4.h"
	#include "task4.c"

	int yylex(void);
    int yyerror(const char*);
        extern FILE *yyin;
        FILE *fp;
        FILE *intermediate,*intermediate2,*t1;
        void print(int);
%}

%union 
{
	struct tnode *nptr;
}

%token START END READ WRITE PLUS MINUS MUL DIV ASSGN
%token<nptr> ID NUM
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE EQ NEQ LE GE LT GT ENDDOWHILE ENDREPEAT REPEATUNTIL 
%token BREAK CONT
%left PLUS MINUS
%left MUL DIV
%right ASSGN
%nonassoc LT GT LE GE
%right EQ NEQ


%type <nptr> program Slist Stmt InputStmt OutputStmt AsgStmt expr IfStmt WhileStmt DoWhile RepeatUntil
%type <nptr> BrkStmt ContStmt 

%%

program: START Slist END ';'    {
                                    $$ = $2;
									//print_tree($$,0,0);
                                    codegen($$);
                                    //evaluate($$);
                                    printf("DONE\n");
                                }
       | START END ';'          {$$ = NULL;}
       ;

Slist: Slist Stmt       {$$ = createTree(TYPE_VOID, 0, NODE_CONNECTOR, NULL, $1, $2, NULL);}
    | Stmt              {$$ = $1;}
    ;

Stmt: InputStmt         {$$ = $1;}
    | OutputStmt        {$$ = $1;}
    | AsgStmt           {$$ = $1;}
    | IfStmt            {$$ = $1;}
    | WhileStmt         {$$ = $1;}
    | DoWhile           {$$ = $1;}
    | RepeatUntil       {$$ = $1;}
    | BrkStmt           {$$ = $1;}
    | ContStmt          {$$ = $1;}
    ;

IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'     {
                                                                typecheck($3->type, TYPE_BOOL, 'e');
                                                                $$ = createTree(TYPE_VOID, 0, NODE_IF_ELSE, NULL, $3, $8, $6);
                                                            }
      | IF '(' expr ')' THEN Slist ENDIF ';'                {
                                                                //printf("IF without ELSE\n");
                                                                typecheck($3->type, TYPE_BOOL, 'i');
                                                                $$ = createTree(TYPE_VOID, 0, NODE_IF, NULL, $3, $6, NULL);
                                                            }

WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'         {
                                                                //printf("WHILE\n");
                                                                typecheck($3->type, TYPE_BOOL, 'w');
                                                                $$ = createTree(TYPE_VOID, 0, NODE_WHILE, NULL, $3, $6, NULL);
                                                            }
DoWhile : DO WHILE '('expr')' Slist ENDDOWHILE ';'          {
                                                                typecheck($4->type, TYPE_BOOL, 'd');
                                                                $$ = createTree(TYPE_VOID, 0, NODE_DOWHILE, NULL, $4, $6, NULL);
                                                            }     
RepeatUntil: REPEATUNTIL '('expr')' Slist ENDREPEAT ';' {
                                                                typecheck($3->type, TYPE_BOOL, 'r');
                                                                $$ = createTree(TYPE_VOID, 0, NODE_REPEATUNTIL, NULL, $3, $5, NULL);
                                         
                                         }
BrkStmt: BREAK ';'                  {$$ = createTree(TYPE_VOID, 0, NODE_BREAK, NULL, NULL, NULL, NULL);}

ContStmt: CONT ';'                  {$$ = createTree(TYPE_VOID, 0, NODE_CONT, NULL, NULL, NULL, NULL);}

InputStmt: READ '(' ID ')' ';'      {$$ = createTree(TYPE_VOID, 0, NODE_READ, NULL, $3, NULL, NULL);}
         ;

OutputStmt: WRITE '(' expr ')' ';'  {$$ = createTree(TYPE_VOID, 0, NODE_WRITE, NULL, $3, NULL, NULL);}
          ;

AsgStmt: ID ASSGN expr ';'          {
                                        typecheck($1->type, $3->type, '=');
                                        $$ = createTree(TYPE_VOID, 0, NODE_ASSGN, NULL, $1, $3, NULL);
                                    }
       ;

expr : expr PLUS expr	{
                            typecheck($1->type, $3->type, 'a');
                            $$ = createTree(TYPE_INT, 0, NODE_PLUS, NULL, $1, $3, NULL);
                        }
     | expr MINUS expr  {
                            typecheck($1->type, $3->type, 'a');
                            $$ = createTree(TYPE_INT, 0, NODE_MINUS, NULL, $1, $3, NULL);
                        }
     | expr MUL expr	{
                            typecheck($1->type, $3->type, 'a');
                            $$ = createTree(TYPE_INT, 0, NODE_MUL, NULL, $1, $3, NULL);
                        }
     | expr DIV expr	{
                            typecheck($1->type, $3->type, 'a');
                            $$ = createTree(TYPE_INT, 0, NODE_DIV, NULL, $1, $3, NULL);
                        }
     | expr LT expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = createTree(TYPE_BOOL, 0, NODE_LT, NULL, $1, $3, NULL);
                        }
     | expr GT expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = createTree(TYPE_BOOL, 0, NODE_GT, NULL, $1, $3, NULL);
                        }
     | expr LE expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = createTree(TYPE_BOOL, 0, NODE_LE, NULL, $1, $3, NULL);
                        }
     | expr GE expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = createTree(TYPE_BOOL, 0, NODE_GE, NULL, $1, $3, NULL);
                        }
     | expr NEQ expr    {
                            typecheck($1->type, $3->type, 'b');
                            $$ = createTree(TYPE_BOOL, 0, NODE_NEQ, NULL, $1, $3, NULL);
                        }
     | expr EQ expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = createTree(TYPE_BOOL, 0, NODE_EQ, NULL, $1, $3, NULL);
                        }
     | '(' expr ')'	{$$ = $2;}
     | NUM		{$$ = $1;}
     | ID		{$$ = $1;}
     ;

%%

int yyerror(const char *s) 
{
    printf("yyerror %s",s);
	return 1;
}

int main(int argc, char *argv[]) 
{
    intermediate=fopen("temp.txt", "w");
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
    intermediate2=fopen("temp2.txt","w");
     t1=fopen("temp.txt","r");
    if (!t1) 
    {
        fprintf(stderr, "Failed to open temp.txt\n");
    }
    changeLabels(fp); 
    
    return 0;
}