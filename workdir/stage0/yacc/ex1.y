%{
    #include<stdio.h>
    #include<stdlib.h>
    int nesting=0;
    char yylex();
    void yyerror();
%}
%token RELOP ID NUM IF STMT NL
%%

start: if_stmt NL {printf("Levels of nesting are %d\n", nesting);exit(0);}
     ;

if_stmt: IF '(' cond ')' '{' stmt '}' {nesting++;}
       ;

stmt: STMT
    | if_stmt
    ;

cond: x RELOP x
    ;

x: ID
 | NUM
 ;

%%
char yylex()
{

}
void yyerror() 
{
    printf("\nIts not a identifier!\n");
    return;
}
int main() 
{
    printf("\nEnter:");
    yyparse();
    return 0;
}