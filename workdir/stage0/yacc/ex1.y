%{
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
int yylex();
int yyerror(const char *);
int lvl = 0;
%}

%token IF LBRACE RBRACE RELOP DIGIT ALPHA 

%%
start : stmt {exit(0);}
      ;

stmt  : IF '(' text ')' LBRACE { lvl++; printf("%d - level if\n", lvl); }
        stmt
        RBRACE { lvl--; }
      | text
      ;
text  : ALPHA text
      | RELOP text
      | DIGIT text
      | /*epsilon*/
      ;

%%

int yylex()
{
    int c;

    // Skip whitespace
    while ((c = getchar()) == ' ' || c == '\t' || c == '\n')
        ;

    if (c == EOF) return 0;

    // Parentheses
    if (c == '(') return '(';
    if (c == ')') return ')';

    // Braces
    if (c == '{') return LBRACE;
    if (c == '}') return RBRACE;

    // IF keyword detection
    if (c == 'i') {
        int d = getchar();
        if (d == 'f') {
            int next = getchar();
            if (!isalpha(next) && !isdigit(next)) {
                ungetc(next, stdin);
                return IF;
            }
            ungetc(next, stdin);
            ungetc('f', stdin);
            goto alpha_label;
        } else {
            ungetc(d, stdin);
            goto alpha_label;
        }
    }

    // Relational operators
    if (c == '<' || c == '>' || c == '=' || c == '!') {
        
        return RELOP;
    }

    // Digits
    if (isdigit(c)) {
        while (isdigit(c = getchar()))
            ;
        ungetc(c, stdin);
        return DIGIT;
    }

    // Alphabets
    if (isalpha(c)) {
alpha_label:
        while (isalnum(c = getchar()))
            ;
        ungetc(c, stdin);
        return ALPHA;
    }

    // Fallback: return char as-is
    return c;
}

int yyerror(const char *s)
{
    printf("Error: %s\n", s);
    return 1;
}

int main()
{
    yyparse();
    return 0;
}
