%{
    #include<stdio.h>
    #include<stdlib.h>
    #include <ctype.h>
    int di=0;
    int inti=0;
    int flo=0;
    
%}
/* float_1 [+-]?{digit_1}+([.]{digit_1}+)?       //why even integer is kept first , it is considerign as digit ? 
integer_1 [+-]?{digit_1}+
digit_1 [0-9] */
float_1 [+-]?[0-9]+([.][0-9]+)?   
integer_1 [+-]?[0-9]+
digit_1 [0-9] 
%%
{digit_1}   {   di++;
                inti++;
            }
{integer_1} {   inti++; 
                for(int i=0;i<yyleng;i++)
                {
                    if(isdigit(yytext[i]))
                    {
                        di++;
                    }
                }
            }
{float_1} {

                flo++; 
                for(int i=0;i<yyleng;i++)
                {
                    if(isdigit(yytext[i]))
                    {
                        di++;
                    }
                }
            }
%%
int yywrap()
{
    return 1;
}
int main()
{
    printf("Eneter what ever you want\n");
    yylex();
    printf("digits: %d\n",di);
    printf("integers: %d\n",inti);
    printf("float: %d\n",flo);

    return 0;
}