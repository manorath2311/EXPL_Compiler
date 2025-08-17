%{
	#include <stdio.h>
	#include <stdlib.h>
	#include<string.h>
	#include<ctype.h>
	#include<stddef.h>
	//#define YYSTYPE tnode*
	#include "tree.h"
	#include "tree.c"
	extern struct tnode* idptr;
	FILE* targetFile;
	int yylex(void);
	extern FILE *yyin;
	extern char* yytext;
	int yyerror(const char *);
	
%}
%union {
    struct tnode* p;
    int i;
    char* s;
}

%token <i> NUM
%token <p> ID
%token<s> PLUS MINUS MUL DIV GT LT LE GE NE EQ ASSIGN BREAK CONTINUE
%token<s> TBEGIN TEND TREAD TWRITE TIF TTHEN TELSE TENDIF TWHILE TDO TENDWHILE EOL

%type <p> expr Slist Stmt Breakstmt Continuestmt InputStmt OutputStmt AsgStmt Ifstmt Whilestmt

%left PLUS MINUS
%left MUL DIV
%nonassoc GT LT LE GE EQ NE
%%
Program : TBEGIN Slist TEND EOL	{fprintf(targetFile,"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\nMOV SP, 4121\n",0,2056,0,0,0,0,1,0);
				//codeGen(targetFile,$2);
				infixtoprefix(targetFile,$2);
				printExit(targetFile);
				return 0;				
				}
	| TBEGIN TEND EOL	{printf("Empty program\n;");return 0;}
	;
Slist : Slist Stmt		{$$=createTree(-1,-1,NULL,tCONNECT,$1,$2,NULL);}
	| Stmt			{$$=$1;} 	
	;

Stmt : InputStmt 		{$$=$1;}
	| OutputStmt 		{$$=$1;}
	| AsgStmt 		{$$=$1;}
	| Ifstmt		{$$=$1;}
	| Whilestmt		{$$=$1;}
	| Breakstmt		{$$=$1;}
	| Continuestmt		{$$=$1;}
	;

Breakstmt : BREAK EOL			{$$=createTree(-1,-1,NULL,tBREAK,NULL,NULL,NULL);}
	;

Continuestmt : CONTINUE EOL		{$$=createTree(-1,-1,NULL,tCONTINUE,NULL,NULL,NULL);}
	;
InputStmt : TREAD '(' ID ')' EOL	{$$=createTree(-1,-1,NULL,tREAD,$3,NULL,NULL);}  
	;

OutputStmt : TWRITE '(' expr ')' EOL	{$$=createTree(-1,-1,NULL,tWRITE,$3,NULL,NULL);} 
	;

AsgStmt : ID ASSIGN expr EOL {$$ = createTree(-1,-1,NULL,tASSIGN,$1,$3,NULL);} 
	;
Ifstmt : TIF '(' expr ')' TTHEN Slist TELSE Slist TENDIF EOL	{$$=createTree(-1,-1,NULL,tIF,$3,$6,$8);}
	| TIF '(' expr ')' TTHEN Slist TENDIF EOL		{$$=createTree(-1,-1,NULL,tIF,$3,$6,NULL);}
	;
Whilestmt : TWHILE '(' expr ')' TDO Slist TENDWHILE EOL		{$$=createTree(-1,-1,NULL,tWHILE,$3,$6,NULL);}
	;
expr : expr PLUS expr		{$$ = createTree(-1,-1,"+",tADD,$1,$3,NULL);}
	 | expr MINUS expr  	{$$ = createTree(-1,-1,"-",tSUB,$1,$3,NULL);}
	 | expr MUL expr	{$$ = createTree(-1,-1,"*",tMUL,$1,$3,NULL);}
	 | expr DIV expr	{$$ = createTree(-1,-1,"/",tDIV,$1,$3,NULL);}
	 | '(' expr ')'	{$$ = $2;}
	 | expr LT expr 		{$$ = createTree(-1,-1,NULL,tLT,$1,$3,NULL);}
	 | expr GT expr 		{$$ = createTree(-1,-1,NULL,tGT,$1,$3,NULL);}
	 | expr LE expr 		{$$ = createTree(-1,-1,NULL,tLE,$1,$3,NULL);}
	 | expr GE expr 		{$$ = createTree(-1,-1,NULL,tGE,$1,$3,NULL);}
	 | expr NE expr 		{$$ = createTree(-1,-1,NULL,tNE,$1,$3,NULL);}
	 | expr EQ expr		{$$ = createTree(-1,-1,NULL,tEQ,$1,$3,NULL);}
	 | NUM			{$$ = createTree(atoi(yytext),tINT,NULL,tNUM,NULL,NULL,NULL);}
	 | ID			{$$=$1;}
	 ;

%%

int yyerror(char const *s)
{
    printf("yyerror %s and %s",s,yytext);
	return 0;
}


int main(int argc, char*argv[]) {
	targetFile=fopen("targetFile.xsm","w");
	if(targetFile==NULL){
		printf("file error\n");
	}
	yyin=fopen(argv[1],"r");
	yyparse();
	fclose(targetFile);
	return 0;
}

                            