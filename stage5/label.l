%{
    #include <stdio.h>
    #include <string.h>
    #include "label.c"

    
    int step = 0;
    int addr = 2040;
    FILE* label_file = NULL;
    FILE* output_file = NULL;

%}

label   L[0-9]+
Func F[0-9]+
Main  MAIN
%%
{Main}:\n          {
                    if(step == 0)
                    {
                        createLabel("MAIN", addr);
                        printf("Created MAIN at address %d\n", addr);
                    }
                }
{Main}         {
                    if(step == 1)
                    {
                        int address = getLabelAddr("MAIN");
                        fprintf(output_file, "%d", address);
                        printf("Found MAIN at address %d\n", address);
                    }
                }
{label}:\n      {
                    if(step == 0)
                    {
                        int len = yyleng - 2;
                        char* label = strndup(yytext, len);
                        createLabel(label, addr);
                    }
                }
{Func}:\n       {
                    if(step == 0)
                    {
                        int len = yyleng - 2;
                        char* label = strndup(yytext, len);
                        createLabel_func(label, addr);
                        printf("Created function %s at address %d\n", label, addr);
                    }

                }
{Func}          {
                    if(step == 1)
                    {
                        int address = getLabelAddr_func(yytext);
                        fprintf(output_file, "%d", address);
                        printf("Found function %s at address %d\n", yytext, address);
                    }

                }

{label}         {
                    if(step == 1)
                    {
                        int address = getLabelAddr(yytext);
                        fprintf(output_file, "%d", address);
                    }
                }

(.)             {
                    if(step == 1)
                    {
                        fprintf(output_file, "%c", *yytext);
                    }
                }

\n              {
                    if(step == 0)
                    {
                        addr += 2;
                    }
                    else 
                    {
                        fprintf(output_file, "\n");
                    }
                }
%%

int yywrap()
{
    if(step == 0)
    {
        rewind(yyin);
        step = 1;
        return 0;
    }
    return 1;
}

int main(int argc, char* argv[])
{
    label_file = fopen(argv[1], "r");
    output_file = fopen(argv[2], "w");


    if(label_file == NULL || output_file == NULL)
    {
        printf("Error opening file: label/output\n");
        exit(1);
    }

    yyin = label_file;
    yylex();
    printLabels();
    return 0;
}