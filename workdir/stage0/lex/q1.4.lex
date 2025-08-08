%{
    #include<stdio.h>
%}
one_line \/\/([^\n])*
multi_line \/\*([^*]|\*+[^*/])*\*+\/ 
%%
{one_line} {printf("%s \n",yytext);}
{multi_line} {printf("%s \n",yytext);}
.|\n {}
%%
int yywrap()
{
    return 1;
}
int main()
{
    //printf("Enter what ever you want\n");
    FILE *fp=fopen("input4.txt","r");
    if(fp)
    {
        yyin=fp;
    }
    yylex();
    printf("\n");

    return 0;
}

