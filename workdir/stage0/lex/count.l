%{
    #include<stdio.h>
    #include<stdlib.h>
    int chars=0;
    int lines=0;
    int words=0;
    int spchar=0;
%}
char_1 [a-zA-Z]
spchar_1 [0-9!@#$%^&*()_+\-=\[\]{};':"\\|,.<>\/?]
word_1 {char_1}+
newline_1 \n
%%
{char_1} { chars++; }
{word_1}  {words++; chars+=yyleng; }
{newline_1}   { lines++;}
{spchar_1} {spchar++;}
%%

int yywrap()
{
    return 1;
}

int main()
{

    printf("Enter what ever you want\n");
    
    yylex();
    printf("words = %d ",words);
    printf("chars = %d ",chars+spchar);
    printf("lines = %d \n",lines);


    return 0;

}
