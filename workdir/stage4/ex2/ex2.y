%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include "ex2.h"
	#include "ex2.c"
	int yylex(void);
    extern FILE *yyin;
    FILE *fp;
    FILE *intermediate;
    void print(int);
    int yyerror(char const *s);
%}

%union 
{
    struct tnode *nptr;
}

%token START END READ WRITE PLUS MINUS MUL DIV MOD ASSGN
%token<nptr> ID NUM STRVAL
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE EQ NEQ LE GE LT GT
%token BREAK CONT DECL ENDDECL INT STR 

%nonassoc LT GT LE GE
%right EQ NEQ
%left PLUS MINUS
%left MUL DIV MOD
%right ASSGN


%type <nptr> program Slist Stmt InputStmt OutputStmt AsgStmt expr id
%type <nptr> BrkStmt ContStmt IfStmt WhileStmt Declarations DeclList
%type <nptr> Type Decl VarList 

%%

program: Declarations START Slist END ';'   {
                                                $$ = $3;
                                                //print_tree($$);
                                                printSymbolTable();
                                                codegen($$);
                                            }
       | Declarations START END ';'         {$$ = $1;}
       ;

Slist: Slist Stmt       {$$ = createTree(TYPE_VOID, 0, NODE_CONNECTOR, NULL, $1, $2, NULL,NULL);}
    | Stmt              {$$ = $1;}
    ;

Stmt: InputStmt         {$$ = $1;}
    | OutputStmt        {$$ = $1;}
    | AsgStmt           {$$ = $1;}
    | IfStmt            {$$ = $1;}
    | WhileStmt         {$$ = $1;}
    | BrkStmt           {$$ = $1;}
    | ContStmt          {$$ = $1;}
    ;

Declarations: DECL DeclList ENDDECL ';' {$$= $2;}
            | DECL ENDDECL ';' {$$ = NULL;}
            ;

DeclList: DeclList Decl
        | Decl
        ;

Decl: Type VarList ';'
    ;

Type: INT   {declaration_type = TYPE_INT;}
    | STR   {declaration_type = TYPE_STR;}
    ;

VarList: VarList ',' ID                 {GInstall($3->varname, declaration_type, 1,0,0,0);}
       | VarList ',' ID '[' NUM ']'     {GInstall($3->varname, declaration_type, $5->val,0,0,0);}
       | VarList ',' ID '[' NUM ']''[' NUM ']' {GInstall($3->varname, declaration_type, ($5->val)*($8->val),1,$5->val,$8->val);}
       | ID '[' NUM ']''[' NUM ']' {GInstall($1->varname, declaration_type, ($3->val)*($6->val),1,$3->val,$6->val);}
       | ID '[' NUM ']'                 {GInstall($1->varname, declaration_type, $3->val,0,0,0);}
       | ID                             {GInstall($1->varname, declaration_type, 1,0,0,0);}
       | MUL ID                       {GInstall($2->varname,TYPE_INT_POINTER, 1,0,0,0);}
       ;

IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'     {
                                                                typecheck($3->type, TYPE_BOOL, 'e');
                                                                $$ = createTree(TYPE_VOID, 0, NODE_IF_ELSE, NULL, $3, $8, $6,NULL);
                                                            }
      | IF '(' expr ')' THEN Slist ENDIF ';'                {
                                                                typecheck($3->type, TYPE_BOOL, 'i');
                                                                $$ = createTree(TYPE_VOID, 0, NODE_IF, NULL, $3, $6, NULL,NULL);
                                                            }
      ;

WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'         {
                                                                typecheck($3->type, TYPE_BOOL, 'w');
                                                                $$ = createTree(TYPE_VOID, 0, NODE_WHILE, NULL, $3, $6, NULL,NULL);
                                                            }
         ;
BrkStmt: BREAK ';'                  {$$ = createTree(TYPE_VOID, 0, NODE_BREAK, NULL, NULL, NULL, NULL,NULL);}
       ;

ContStmt: CONT ';'                  {$$ = createTree(TYPE_VOID, 0, NODE_CONT, NULL, NULL, NULL, NULL,NULL);}
        ;

InputStmt: READ '(' id ')' ';'      {$$ = createTree(TYPE_VOID, 0, NODE_READ, NULL, $3, NULL, NULL,NULL);}
         ;

OutputStmt: WRITE '(' expr ')' ';'  {$$ = createTree(TYPE_VOID, 0, NODE_WRITE, NULL, $3, NULL, NULL,NULL);}
          ;

AsgStmt: id ASSGN expr ';'          {
                                        typecheck($1->type, $3->type, '=');
                                        $$ = createTree(TYPE_VOID, 0, NODE_ASSGN, NULL, $1, $3, NULL,NULL);
                                    }
       ;

expr : expr PLUS expr	{
                            typecheck($1->type, $3->type, 'a');
                            $$ = createTree(TYPE_INT, 0, NODE_PLUS, NULL, $1, $3, NULL,NULL);
                        }
     | expr MINUS expr  {
                            typecheck($1->type, $3->type, 'a');
                            $$ = createTree(TYPE_INT, 0, NODE_MINUS, NULL, $1, $3, NULL,NULL);
                        }
     | expr MUL expr	{
                            typecheck($1->type, $3->type, 'a');
                            $$ = createTree(TYPE_INT, 0, NODE_MUL, NULL, $1, $3, NULL,NULL);
                        }
     | expr DIV expr	{
                            typecheck($1->type, $3->type, 'a');
                            $$ = createTree(TYPE_INT, 0, NODE_DIV, NULL, $1, $3, NULL,NULL);
                        }
     | expr MOD expr	{
                            typecheck($1->type, $3->type, 'a');
                            $$ = createTree(TYPE_INT, 0, NODE_MOD, NULL, $1, $3, NULL,NULL);
                        }
     | expr LT expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = createTree(TYPE_BOOL, 0, NODE_LT, NULL, $1, $3, NULL,NULL);
                        }
     | expr GT expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = createTree(TYPE_BOOL, 0, NODE_GT, NULL, $1, $3, NULL,NULL);
                        }
     | expr LE expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = createTree(TYPE_BOOL, 0, NODE_LE, NULL, $1, $3, NULL,NULL);
                        }
     | expr GE expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = createTree(TYPE_BOOL, 0, NODE_GE, NULL, $1, $3, NULL,NULL);
                        }
     | expr NEQ expr    {
                            typecheck($1->type, $3->type, 'b');
                            $$ = createTree(TYPE_BOOL, 0, NODE_NEQ, NULL, $1, $3, NULL,NULL);
                        }
     | expr EQ expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = createTree(TYPE_BOOL, 0, NODE_EQ, NULL, $1, $3, NULL,NULL);
                        }
     | '(' expr ')'	{$$ = $2;}
     | NUM		{$$ = $1;}
     | STRVAL           {$$ = $1;}
     | id		{$$ = $1;}
     | MUL id		{
                        if($2->Gentry == NULL) {
                            printf("Variable '%s' not declared!", $2->varname);
                            exit(1);
                        } else if($2->Gentry->type != TYPE_INT_POINTER) {
                            printf("Variable '%s' is not a pointer!", $2->varname);
                            exit(1);
                        }
                        $2->type = TYPE_INT_POINTER;
                         if ($2->Gentry->type == TYPE_INT_POINTER) 
                        {
                        $$ = createTree(TYPE_INT, 0, NODE_INT_PTR, NULL, $2, NULL, NULL,$2->Gentry);
                        }
                      else 
                      {
                            printf("Invalid dereference of non-integer pointer variable '%s'\n", $2->varname);
                            exit(1);
                        }
            }; 
     ;

id: ID                  {
                            $1->Gentry = GLookup($1->varname);
                            if($1->Gentry == NULL) {
                                printf("Variable '%s' not declared!", $1->varname);
                                exit(1);
                            }
                            $1->type = $1->Gentry->type;
                            $$ = $1;
                        }
  | ID '[' NUM ']'      {
                            $1->Gentry = GLookup($1->varname);
                            if($1->Gentry == NULL) {
                                printf("Variable '%s' not declared!", $1->varname);
                                exit(1);
                            } else if($1->Gentry->size <= $3->val || $3->val < 0) {
                                printf("Array '%s' out of bounds!", $1->varname);
                                exit(1);
                            }
                            $1->type = $1->Gentry->type;
                            $$ = createTree($1->type, 0, NODE_ARRAY, NULL, $1, $3, NULL,$1->Gentry);
                        }
  | ID '[' id ']'       {
                            $1->Gentry = GLookup($1->varname);
                            if($1->Gentry == NULL) {
                                printf("Variable '%s' not declared!", $1->varname);
                                exit(1);
                            }
                            $1->type = $1->Gentry->type;
                            $$ = createTree($1->type, 0, NODE_ARRAY, NULL, $1, $3, NULL,$1->Gentry);
                        }
    | ID '[' NUM ']''[' NUM ']' 
                            {
                            $1->Gentry = GLookup($1->varname);
                            if($1->Gentry == NULL) {
                                printf("Variable '%s' not declared!", $1->varname);
                                exit(1);
                            }
                            else if ($1->Gentry->is2D == 0) {
                                printf("Variable '%s' is not a 2D array!", $1->varname);
                                exit(1);
                            } 
                            else if($1->Gentry->arrleft_index <= ($3->val) || $1->Gentry->arrright_index <= ($6->val) || $3->val < 0 || $6->val < 0) {
                                printf("Array '%s' out of bounds!", $1->varname);
                                exit(1);
                            }
                           
                            
                            $1->type = $1->Gentry->type;
                            $$ = createTree($1->type, 0, NODE_2D_ARRAY, NULL, $1, $6, $3,$1->Gentry);
                        }
    | ID '[' id ']' '[' id ']' {
                            $1->Gentry = GLookup($1->varname);
                            if($1->Gentry == NULL) {
                                printf("Variable '%s' not declared!", $1->varname);
                                exit(1);
                            }
                            else if ($1->Gentry->is2D == 0) {
                                printf("Variable '%s' is not a 2D array!", $1->varname);
                                exit(1);
                            }
                            // We cannot do bounds checking here as indices are variables
                            $1->type = $1->Gentry->type;
                            $$ = createTree($1->type, 0, NODE_2D_ARRAY, NULL, $1, $6, $3,$1->Gentry);
                        } 
    | '*'ID               {
                            $2->Gentry = GLookup($2->varname);
                            if($2->Gentry == NULL) {
                                printf("Variable '%s' not declared!", $2->varname);
                                exit(1);
                            } else if($2->Gentry->type != TYPE_INT_POINTER) {
                                printf("Variable '%s' is not a pointer!", $2->varname);
                                exit(1);
                            }
                            $2->type = TYPE_INT_POINTER;
                            $$ = createTree(TYPE_INT, 0, NODE_INT_PTR, NULL, $2, NULL, NULL,$2->Gentry);
                        }                   
  ;

%%

int yyerror(char const *s) 
{
    printf("perror %s",s);
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
    return 0;
}