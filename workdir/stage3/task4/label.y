%{
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
    #include<ctype.h>

	int yylex(void);
    int yyerror(const char*);
        extern FILE *yyin;
        FILE *fp;
        FILE *intermediate,*intermediate2,*t1;
        void print(int);
%}

%union 
{
	struct tnode *nptr;
}

%%

%%

int yyerror(const char *s) 
{
    printf("yyerror %s",s);
	return 1;
}

int main(int argc, char *argv[]) 
{
    
    if (argc < 2) 
    {
        printf("Please provide an input filename\n");
        exit(1);
    }
    else 
    {
        fp = fopen(argv[1], "r");
        if (!fp) 
        {
            printf("Invalid input file specified\n");
            exit(1);
        } 
        else 
        {
            yyin = fp;
        }
    }
    return 0;
}