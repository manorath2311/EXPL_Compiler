%{
    #include<stdio.h>

%}
word_1 " "A[A-Z]{2}" "
%%
{word_1} {printf("%s ",yytext);}
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