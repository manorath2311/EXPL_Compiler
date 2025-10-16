%{
    #include<stdio.h>
    int yylex();
    int yyerror(const char *);
%}
%union
{
    char c;
    int i;
}
%left '+' '-'
%left '/' '%' '*'
%token NL
%token <c> CHAR
%token <c> OP
%%
start : expr NL
      ;
expr: expr '+' expr {printf("+");}
    | expr '-' expr {printf("-");}
    | expr '/' expr {printf("/");}
    | expr '*' expr {printf("*");}
    | expr '%' expr {printf("%%");}
    | '('expr')' 
    | CHAR {$<c>$=$<c>1; printf("%c ",$<c>1);}
    ;
%%
int yyerror(const char *s)
{
    printf("Error %s\n",s);

    return 0;
}
int main()
{
    printf("Enter what ever you want\n");

    yyparse();
    return 0;
}