%{
int line_count = 0;
int arr[100];
int size=0;
char l[100];
FILE *fp;
FILE *fp2;
int addr;
int line=0;
%}

%%
L[0-9]+:    { 
                    int label_num = 0;
                    char *p = yytext + 1; 
                    while (*p != ':' && *p != '\0') 
                    {
                        label_num = label_num * 10 + (*p - '0');
                        p++;
                    }
                    arr[label_num] = line_count; 
                    addr=2056+2*(line_count);
                    printf("Found label %d at line %d\n", label_num, line_count);
                    fprintf(fp2,"%d:",addr);          
           }
L[0-9]+ {
                int label_num = 0;
                char *p = yytext + 1; 
                while (*p != '\0') 
                {
                    label_num = label_num * 10 + (*p - '0');
                    p++;
                }
                line=2056+2*(arr[label_num]);
                fprintf(fp2,"%d",line);
            }
            
\n              { line_count++; fprintf(fp2,"\n");}
.|\t            {fprintf(fp2,"%s",yytext);}
%%

int yywrap()
{
    return 1;
}
int main(int argc,char *argv[]) 
{
    
    if (argc < 2) 
    {
        printf("Please provide an input filename\n");
        exit(1);
    }
    else 
    {
        fp = fopen(argv[1], "r");
        fp2=fopen("out1.txt","w");
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
    yylex();
    return 0;

}