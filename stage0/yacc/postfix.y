%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<ctype.h>
    int yyerror();
    int yylex();

%}
%token DIGIT
%left '+'
%right '*'
%%
start : expr {printf("\nDone\n");exit(1);}
      ;
expr  : expr '+' expr  {printf("+");}
      | expr '*' expr  {printf("*");}
      | '('expr')'    {}
      | DIGIT        {printf(" %d ",$1);}
      ;
%%
int yyerror()
{
    printf("Error\n");
    return 1;
}
int yylex()
{
	int c;
	c = getchar();
	if(isdigit(c))
	{
		yylval = c - '0';
		return DIGIT;
	}
	return c;
}
int main()
{
    yyparse();
    return 0;
}

