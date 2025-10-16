%{
    #include<stdio.h>
    int count=0;
%}
char_1 [a-zA-Z]
dig_1 [0-9]
word_1 {char_1}({char_1}|{dig_1})*
%%
{word_1} {count++;
          printf("%s ",yytext);
         }
.|\n {}
%%
int yywrap()
{
    return 1;
}
int main()
{
    printf("Write something...\n");
    yylex();
    printf("%d \n",count);
    return 0;
}