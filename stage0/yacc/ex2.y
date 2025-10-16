%{
    #include<stdio.h>
    #include<ctype.h>
    #include<stdlib.h>
    int yylex();
    int yyerror(const char *);
    char buf[101];
    int end=0;
%}
%token ALPHA NUM
%%
start : id '\n' {if(end!=-1){for(int i=0;i<end;i++){printf("%c",buf[i]);}} printf("\n");exit(0);}
      ;
id : ALPHA  {buf[0]=yylval; end++;}
    alphanum 
   | NUM {printf("invalid variable\n"); return 0;}
    
    ;
alphanum : ALPHA {buf[end]=yylval;end++;}
            alphanum 
         | NUM {buf[end]=yylval;end++;}
         alphanum 
         | /*epsilon*/ 
         ;
%%
int yylex()
{
    int c;
    while((c=getchar())==' ')
    {
        ;
    }
    if (c == EOF) return 0;

    if(isalpha(c))
    {
        yylval=c;
        return ALPHA;
    }
    if(isdigit(c))
    {
        yylval=c;
        return NUM;
    }

    return c;


}
int yyerror(const char *s)
{
    printf("Error: %s\n", s);
    return 1;
}
int main()
{
    yyparse();
    return 0;
}