%{
    #include<stdio.h>
%}
one_line \/\/(.)*
%%
{one_line} {printf("%s ",yytext);}
.|\n {}
%%
int yywrap()
{
    return 1;
}
int main()
{
    printf("Enter what ever you want\n");
    yylex();
    printf("\n");

    return 0;
}
