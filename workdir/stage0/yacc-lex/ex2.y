%{
    #include<stdio.h>
    int yylex();
    int yyerror(const char *);
%}
%union
{
    char* s;
    char op;
}
%left '+' '-'
%left '*' '/' '%'
%token<op> OP 
%token <s> STR
%token NL
%%
start : expr NL
      ;
expr  : expr '+' expr {printf("+");}
      | expr '-' expr {printf("-");}
      | expr '*' expr {printf("*");}
      | expr '/' expr {printf("/");}
      | expr '%' expr {printf("%%");}
      | '('expr')'
      | STR {$<s>$=$<s>1; printf(" %s ",$<s>1);}
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