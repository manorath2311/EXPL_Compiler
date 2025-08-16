%{
    #include<stdio.h>
    #include<string.h>
    int yylex();
    int yyerror(const char *);
    char* strcat_3(char*, char*, char*);

%}
%union
{
    char* s;
    char op;
}
%left '+' '-'
%left '*' '/' '%'
%token<op> OP 
%token <s> STR
%token NL
%%
start : expr NL {printf(" %s ",$<s>1);}
      ;
expr  : expr '+' expr {$<s>$=strcat_3("+",$<s>1,$<s>3);}
      | expr '-' expr {$<s>$=strcat_3("-",$<s>1,$<s>3);}
      | expr '*' expr {$<s>$=strcat_3("*",$<s>1,$<s>3);}
      | expr '/' expr {$<s>$=strcat_3("/",$<s>1,$<s>3);}
      | expr '%' expr {$<s>$=strcat_3("%",$<s>1,$<s>3);}
      | '('expr')' {$<s>$=$<s>2;}
      | STR {$<s>$=$<s>1;}
      ;
%%
int yyerror(const char *s)
{
    printf("Error %s\n",s);

    return 0;
}
char* strcat_3(char* str1, char* str2, char* str3) 
{
    char *new_str = (char*)malloc(strlen(str1) + strlen(str2) + strlen(str3) + 3);
    strcpy(new_str, str1);
    strcat(new_str, " ");
    strcat(new_str, str2);
    strcat(new_str, " ");
    strcat(new_str, str3);
    return new_str;
}
int main()
{
    printf("Enter what ever you want\n");

    yyparse();
    return 0;
}