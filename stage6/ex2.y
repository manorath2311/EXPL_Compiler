%{
	#include <stdlib.h>
	#include <stdio.h>
    #include <string.h>
	#include "ex2.h"
    #include "ex2.c"

	int yylex(void);
        extern FILE *yyin;
        extern int lineno;
        FILE *fp;
        FILE *intermediate;
        void print(int);
        struct Paramstruct *argList1, *argList2;
        int declCount = 0, defCount = 0; // Definition and Declaration count of functions
        int testing = 0; // can use to test ASTree
        
        // Internal yyerror implementation for two arguments
        int yyerror_impl(const char *s, const char *var);
        
        // Wrapper for Bison's single-argument calls
        #define yyerror(msg) yyerror_impl(msg, NULL)
        int size=0;
        int tbv=0;
        char nameType[20];
        char declaredType[20];
       
%}

%union {
    struct ASTNode *nptr;
    struct Paramstruct *pptr;
    struct Fieldstruct *fptr;
    struct TypeDef *tptr;
}


%token <nptr> NUM ID STRVAL
%token START END READ WRITE PLUS MINUS MUL DIV MOD ASSGN AND OR
%token IF THEN ELSE ENDIF WHILE DO ENDWHILE EQ NEQ LE GE LT GT
%token BREAK CONT DECL ENDDECL INT STR MAIN RETURN ADDR
%token TYPE ENDTYPE

%left AND OR
%nonassoc LT GT LE GE
%right EQ NEQ
%left PLUS MINUS
%left MUL DIV MOD
%right ASSGN


%type <nptr> program Slist Stmt InputStmt OutputStmt AsgStmt expr id
%type <nptr> BrkStmt ContStmt IfStmt WhileStmt Type GDeclBlock FDefBlock TDeclBlock
%type <nptr> TypeList TypeDef Field
%type <nptr> MainBlock GDeclList GDecl GIdList GId ParamList FDef FType
%type <nptr> LDeclBlock Body Param LDecList LDecl IdList RetStmt
%type <nptr> ExprList func 
%type <fptr> TypeFieldList TypeField



%%

program: TDeclBlock GDeclBlock FDefBlock MainBlock {}
       | GDeclBlock MainBlock           {}
       | MainBlock                      {}
       ;

TDeclBlock : TYPE TypeList ENDTYPE      {
                                            
                                            printTypeTable();
                                        }
            |TYPE ENDTYPE              {}
            ;
TypeList : TypeDef TypeList
         | TypeDef
         ;
TypeDef : ID '{' TypeFieldList '}' ';'   {
                                            checkAvailability($1->name, 2);
                                            int count=0;
                                            struct Fieldstruct* temp=$3;
                                            while(temp!=NULL)
                                            {
                                                count++;
                                                temp = temp->next;
                                            }
                                            printf("Type %s with %d fields\n", $1->name, count);
                                            //TInstall($1->name,$3, count);
                                            
                                            struct TypeDef* tempTypeDef = (struct TypeDef*)malloc(sizeof(struct TypeDef));
                                            tempTypeDef->name = $1->name;
                                            tempTypeDef->fields = $3;
                                            tempTypeDef->size = count;
                                            tempTypeDef->next = NULL;
                                            struct Fieldstruct* temp1=Fhead;
                                            while(temp1!=NULL)
                                            {
                                                if(temp1->tbv)
                                                {
                                                    printf("verification in progress for %s %s\n",$1->name,temp1->typeName);
                                                    if(strcmp(temp1->typeName,$1->name)==0)
                                                    {
                                                        temp1->tbv=0;
                                                    }
                                                    else
                                                    {
                                                        printf("Error in type fields of user defined %s in field %s\n", $1->name, temp1->typeName);
                                                        exit(1);
                                                    }
                                                }
                                                temp1=temp1->next;
                                            }
                                            if(Thead == NULL) 
                                            {
                                                Thead = tempTypeDef;
                                                Ttail = tempTypeDef;
                                            } 
                                            else 
                                            {
                                                Ttail->next = tempTypeDef;
                                                Ttail = tempTypeDef;
                                            }
                                            Fhead = NULL;
                                            Ftail = NULL;

                                        }
         ;
TypeFieldList : TypeFieldList TypeField {
                                            struct Fieldstruct* tempFieldList = (struct Fieldstruct*)malloc(sizeof(struct Fieldstruct));
                                            tempFieldList = $2;
                                            struct Fieldstruct* temp = $1;
                                            Fhead = $1;
                                            tempFieldList->next = NULL;
                                            int cnt=1;
                                            while(temp->next != NULL) 
                                            {
                                                temp = temp->next;
                                                if(temp->type==TYPE_USER_DEC)
                                                {
                                                    struct TypeDef* tempTypeDef = TLookup(temp->typeName);
                                                    if(tempTypeDef==NULL)
                                                    {
                                                        printf("Error in type fields of user defined %s in field %s\n", nameType, temp->typeName);
                                                        exit(1);
                                                    }
                                                    else
                                                    {
                                                        cnt=cnt+tempTypeDef->size;
                                                    }
                                                }
                                                else
                                                {
                                                    cnt++;
                                                }
                                                
                                            }
                                            tempFieldList->fieldIndex=cnt;
                                            tempFieldList->tbv=tbv;
                                            tempFieldList->typeName=nameType;
                                            temp->next = tempFieldList;
                                            Ftail = tempFieldList;
                                            $$ = $1;
                        }
              | TypeField {
                                        struct Fieldstruct* tempFieldList = (struct Fieldstruct*)malloc(sizeof(struct Fieldstruct));
                                        tempFieldList = $1;
                                        tempFieldList->next = NULL;
                                        tempFieldList->fieldIndex=0;
                                        tempFieldList->tbv=tbv;
                                        tempFieldList->typeName=nameType;
                                        $$ = tempFieldList;
                                        Fhead = tempFieldList;
                                        Ftail = tempFieldList;
                        }
              ;
TypeField : FIType ID ';'   {
                                    struct Fieldstruct* tempFieldList = (struct Fieldstruct*)malloc(sizeof(struct Fieldstruct));
                                    tempFieldList->name = $2->name;
                                    tempFieldList->type = declarationType;
                                    tempFieldList->tbv=tbv;
                                    tempFieldList->typeName=nameType;
                                    tempFieldList->next = NULL;

                                    $$ = tempFieldList;
                        }
          ;

FIType    : INT { declarationType = TYPE_INT; tbv=0;strcpy(nameType,"Integer");}
          | STR { declarationType = TYPE_STR; tbv=0;strcpy(nameType,"String");}
          | ID  { 
                    declarationType = TYPE_USER_DEC;
                    struct TypeDef* temp=Thead;

                    while(temp!=NULL)
                    {
                        if(strcmp(temp->name,$1->name)==0)
                        {
                            printf("User-defined type %s found\n", $1->name);
                            tbv=0;
                            strcpy(nameType,$1->name);
                            break;
                        }
                        temp = temp->next;
                    }
                    if(temp==NULL)
                    { 
                        tbv=1;
                        strcpy(nameType,$1->name);
                    }
                }
          ;


Field : Field '.' ID 
                    {
                        // Field is already validated, now validate next level==-
                        struct TypeDef* parentType = $1->userType;
                        if(parentType == NULL) 
                        {
                            printf("Error: Previous field is not a user-defined type\n");
                            exit(1);
                        }
                        
                        // Search for $3 (ID) in parentType's fields
                        struct Fieldstruct* field = parentType->fields;
                        int found = 0;
                        struct TypeDef* currentType = NULL;
                        
                        while(field != NULL) 
                        {
                            if(strcmp(field->name, $3->name) == 0) 
                            {
                                found = 1;
                                // If this field is also user-defined, get its type
                                if(field->type == TYPE_USER_DEC) 
                                {
                                    currentType = TLookup(field->typeName);
                                }
                                break;
                            }
                            field = field->next;
                        }
                        
                        if(!found) {
                            printf("Error: Field %s not found in type %s\n", $3->name, parentType->name);
                            exit(1);
                        }
                        
                        $$ = TreeCreate(field->type, NODE_FIELD, $3->name, NULL, NULL, $1, NULL, NULL);
                        $$->userType = currentType;
                    }
                    
      | ID '.' ID   {
                        // Look up ID in global symbol table
                        struct Gsymbol* var = GLookup($1->name);
                        if(var == NULL) 
                        {
                            printf("Error: Variable %s not declared\n", $1->name);
                            exit(1);
                        }
                        
                        // Check if it's a user-defined type
                        if(var->type != TYPE_USER_DEC) 
                        {
                            printf("Error: Variable %s is not of user-defined type\n", $1->name);
                            exit(1);
                        }
                        
                        // Get the type definition from type table
                        struct TypeDef* userType = var->userType;
                        if(userType == NULL) 
                        {
                            printf("Error: Type definition not found for %s\n", var->userType->name);
                            exit(1);
                        }
                        
                        // Search for field ID in the type's field list
                        struct Fieldstruct* field = userType->fields;
                        int found = 0;
                        struct TypeDef* fieldType = NULL;
                        
                        while(field != NULL) 
                        {
                            if(strcmp(field->name, $3->name) == 0) 
                            {
                                found = 1;
                                // If field is also user-defined, get its type for further chaining
                                if(field->type == TYPE_USER_DEC) 
                                {
                                    fieldType = TLookup(field->typeName);
                                }
                                break;
                            }
                            field = field->next;
                        }
                        
                        if(!found) 
                        {
                            printf("Error: Field %s not found in type %s\n", $3->name, userType->name);
                            exit(1);
                        }
                        
                        $$ = TreeCreate(field->type, NODE_FIELD, $3->name, NULL, NULL, $1, NULL, NULL);
                        $$->Gentry = var;
                        $$->userType = fieldType;  // Store for further chaining
                    }


GDeclBlock: DECL GDeclList ENDDECL      { printGSymbolTable() ;print_header();}
          | DECL ENDDECL                { printGSymbolTable() ;print_header();}
          ;

GDeclList: GDeclList GDecl
         | GDecl
         ;

GDecl: Type GIdList ';'
    /* | TUPLE ID '('ARGS ')' ';'  {
                                checkAvailability($2->name, 1);
                                
                                int count=  0;
                                struct Paramstruct* temp=$4;
                                while(temp!=NULL)
                                {
                                    count++;
                                 
                                    temp = temp->next;
                                }
                                printf("Tuple %s with %d elements\n", $2->name, count);
                                GInstall($2->name, TYPE_TUPLE, count, $4);
                 
                            } */
        /* | ID TD ';'    {
                                checkAvailability($1->name, 1);
                                
                                struct TypeDef* tempTypeDef = TLookup($1->name);
                                if(tempTypeDef == NULL)
                                {
                                    printf("User-defined type %s not defined\n", $1->name);
                                    exit(1);
                                }
                                int count=0;
                                struct TypeDef* temp=$2;
                                while(temp!=NULL)
                                {
                                    count++;
                                    temp = temp->next;
                                }
                                printf("Variable of user-defined type %s with %d instances\n", $1->name, count);
                                GInstall($1->name, TYPE_USER_DEC, count, NULL);
                            } */

     ;

/* TD : TD ',' ID              {                         
                                struct TypeDef* tempTypeFieldList = (struct TypeDef*)malloc(sizeof(struct TypeDef));
                                tempTypeFieldList->name = $3->name;
                                tempTypeFieldList->next = NULL;

                                struct TypeDef* temp = $1;
                                while(temp->next != NULL) 
                                {
                                    temp = temp->next;
                                }
                                temp->next = tempTypeFieldList;
                                $$ = $1;

                                
                            }
    | ID                    {
                                struct TypeDef* tempTypeFieldList = (struct TypeDef*)malloc(sizeof(struct TypeDef));
                                tempTypeFieldList->name = $1->name;
                                tempTypeFieldList->next = NULL;
                                $$ = tempTypeFieldList;
                                
                            } */
    ;
Type: INT   {declarationType = TYPE_INT;}
    | STR   {declarationType = TYPE_STR;}
    | ID    {
                declarationType = TYPE_USER_DEC;
                struct TypeDef* tempTypeDef = TLookup($1->name);
                if(tempTypeDef == NULL)
                {
                    printf("User-defined type %s not defined\n", $1->name);
                    exit(1);
                }
                
                strcpy(declaredType, $1->name);
            }
   
    ;

FType: INT   {FDeclarationType = TYPE_INT;}
     | STR   {FDeclarationType = TYPE_STR;}
     ;


GIdList: GIdList ',' GId
       | GId
       ;


GId: ID '(' ParamList ')'   {
                                if(declarationType==TYPE_USER_DEC)
                                {
                                    checkAvailability($1->name, 1);
                                    GInstallType($1->name, declarationType, -1, TLookup(declaredType));
                                    declCount++;
                                    Phead = NULL;
                                    Ptail = NULL;
                                    
                                }
                                else
                                {
                                    declCount++;
                                    checkAvailability($1->name, 1);
                                    GInstall($1->name, declarationType, -1, Phead);
                                    Phead = NULL;
                                    Ptail = NULL;
                                }
                                


                            }
   | ID                     {
                                if(declarationType==TYPE_USER_DEC)
                                {
                                    checkAvailability($1->name, 1);
                                    GInstallType($1->name, declarationType, 1, TLookup(declaredType));
                                }
                                else
                                {   
                                checkAvailability($1->name, 1);
                                GInstall($1->name, declarationType, 1, NULL);
                                }
                            }
   | ID '[' NUM ']'         {
                                checkAvailability($1->name, 1);
                                if($3->value.intval < 1) 
                                {
                                    yyerror_impl("Invalid array size for", $1->name);
                                    exit(1);
                                }
                                GInstall($1->name, declarationType, $3->value.intval, NULL);
                            }
    /* | MUL ID                {
                                checkAvailability($2->name, 1);
                                GInstall($2->name, TYPE_INT_PTR, 1, NULL); 
                            } */
      

   ;
/* ARGS : Type ID {
                                struct Paramstruct* tempParamList = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
                                tempParamList->name = $2->name;
                                tempParamList->type = declarationType;
                                tempParamList->next = NULL;
                                $$ = tempParamList;
                            }

     | ARGS ',' Type ID {
                                struct Paramstruct* tempParamList = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
                                tempParamList->name = $4->name;
                                tempParamList->type = declarationType;
                                tempParamList->next = NULL;

                                struct Paramstruct* temp = $1;
                                while(temp->next != NULL) 
                                {
                                    temp = temp->next;
                                }
                                temp->next = tempParamList;
                                $$ = $1;
                            }
  
     ; */

FDefBlock: FDefBlock FDef
         | FDef
         ;

FDef: Type ID '(' ParamList ')' '{' LDeclBlock Body '}' 
                                                        {
                                                            defCount++;
                                                            Gtemp = GLookup($2->name);

                                                            if(Gtemp == NULL) {
                                                                yyerror_impl("Function is not declared:", $2->name);
                                                                exit(1);
                                                            }

                                                            if(Gtemp->type != declarationType) {
                                                               yyerror_impl("Function type does not match declaration:", $2->name);
                                                               exit(1);
                                                            }

                                                            argList1 = Phead;
                                                            argList2 = Gtemp->paramlist;

                                                            while(argList1 != NULL && argList2 != NULL) {
                                                                if(argList1->type != argList2->type) {
                                                                    yyerror_impl("Conflict in argument types for function:", $2->name);
                                                                    exit(1);
                                                                }

                                                                if(strcmp(argList1->name, argList2->name)) {
                                                                    yyerror_impl("Conflict in argument names for function:", $2->name);
                                                                    exit(1);
                                                                }

                                                                argList1 = argList1->next;
                                                                argList2 = argList2->next;
                                                            }

                                                            if ((argList1 != NULL) || (argList2 != NULL)) {
                                                                yyerror_impl("Not enough arguments for function:", $2->name);
                                                                exit(1);
                                                            }

                                                             printLSymbolTable();
                                                             printf("print_tree for function %s:\n", $2->name);
                                                             print_tree($8,0);
                                                             printf("Done\n");

                                                             
                                                            
                                                                fprintf(intermediate, "F%d:\n",Gtemp->flabel);
                                                                fprintf(intermediate, "PUSH BP\n");
                                                                fprintf(intermediate, "MOV BP,SP\n");

                                                                Ltemp = Lhead;
                                                                while(Ltemp != NULL) 
                                                                {
                                                                    if(Ltemp->binding > 0)
                                                                        fprintf(intermediate, "PUSH R0\n");
                                                                    Ltemp = Ltemp->next;
                                                                }

                                                                codegen($8);
                                                            

                                                            Phead = NULL;
                                                            Ptail = NULL;
                                                            Lhead = NULL;
                                                            Ltail = NULL;
                                                        }
    ;

ParamList: ParamList ',' Param
         | Param
         | /* epsilon */    {$$ = NULL;}
         
         ;

Param: FType ID {
                    checkAvailability($2->name, 0);
                    PInstall($2->name, FDeclarationType);
                }
        | FType MUL ID  
                {
                    checkAvailability($3->name, 0);
                    PInstall($3->name, TYPE_INT_PTR);
                }
     ;

MainBlock: Type MAIN '(' ')' '{' LDeclBlock Body '}'   {
                                                            if(defCount != declCount) 
                                                            {
                                                                yyerror_impl("All functions declared need to be defined", NULL);
                                                                exit(1);
                                                            }

                                                            if(declarationType != TYPE_INT) 
                                                            {
                                                                yyerror_impl("Main return type should be of integer type", NULL);
                                                                exit(1);
                                                            }

                                                            //printGSymbolTable();
                                                            printLSymbolTable();
                                                            printf("print_tree for main:\n");
                                                            print_tree($7,0);
                                                            printf("Done\n");
                                                            
                                                            
                                                                fprintf(intermediate, "MAIN:\n");
                                                                fprintf(intermediate, "PUSH BP\n");
                                                                fprintf(intermediate, "MOV BP,SP\n");

                                                                Ltemp = Lhead;
                                                                while (Ltemp != NULL)
                                                                {
                                                                    fprintf(intermediate, "PUSH R0\n");
                                                                    Ltemp = Ltemp->next;
                                                                }

                                                                codegen($7);
                                                            

                                                            Lhead = NULL;
                                                            Ltail = NULL;
                                                        }
         ;

LDeclBlock: DECL LDecList ENDDECL   {InstallParamsInLocal();}
          | DECL ENDDECL            {InstallParamsInLocal();}
          |                         {InstallParamsInLocal();}
          ;

LDecList: LDecList LDecl
        | LDecl
        ;

LDecl: FType IdList ';'
     ;

IdList: IdList ',' ID   {
                            checkAvailability($3->name, 0);
                            LInstall($3->name, FDeclarationType);
                        }
      | ID              {
                            checkAvailability($1->name, 0);
                            LInstall($1->name, FDeclarationType);
                        }
      ;

Body: START Slist RetStmt END   {$$ = TreeCreate(TYPE_VOID, NODE_CONNECTOR, NULL, NULL, NULL, $2, $3, NULL);}
    | START RetStmt END         {$$ = $2;}
    ;

RetStmt: RETURN expr ';'    {
                                if(declarationType == $2->type) 
                                {
                                    $$ = TreeCreate(TYPE_VOID, NODE_RET, NULL, NULL, NULL, $2, NULL, NULL);
                                
                                } 
                                else 
                                {
                                    yyerror_impl("Return type mismatch", NULL);
                                    exit(1);
                                }
                            }
       ;

Slist: Slist Stmt       {$$ = TreeCreate(TYPE_VOID, NODE_CONNECTOR, NULL, NULL, NULL, $1, $2, NULL);}
    | Stmt              {$$ = $1;}
    ;

Stmt: InputStmt         {$$ = $1;}
    | OutputStmt        {$$ = $1;}
    | AsgStmt           {$$ = $1;}
    | IfStmt            {$$ = $1;}
    | WhileStmt         {$$ = $1;}
    | BrkStmt           {$$ = $1;}
    | ContStmt          {$$ = $1;}
    | func ';'          {$$ = $1;}
    ;

IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'     {
                                                                typecheck($3->type, TYPE_BOOL, 'e');
                                                                $$ = TreeCreate(TYPE_VOID, NODE_IF_ELSE, NULL, NULL, NULL, $3, $8, $6);
                                                            }
      | IF '(' expr ')' THEN Slist ENDIF ';'                {
                                                                typecheck($3->type, TYPE_BOOL, 'i');
                                                                $$ = TreeCreate(TYPE_VOID, NODE_IF, NULL, NULL, NULL, $3, $6, NULL);
                                                            }
      ;

WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'         {
                                                                typecheck($3->type, TYPE_BOOL, 'w');
                                                                $$ = TreeCreate(TYPE_VOID, NODE_WHILE, NULL, NULL, NULL, $3, $6, NULL);
                                                            }
         ;
BrkStmt: BREAK ';'                  {$$ = TreeCreate(TYPE_VOID, NODE_BREAK, NULL, NULL, NULL, NULL, NULL, NULL);}
       ;

ContStmt: CONT ';'                  {$$ = TreeCreate(TYPE_VOID, NODE_CONT, NULL, NULL, NULL, NULL, NULL, NULL);}
        ;

InputStmt: READ '(' id ')' ';'      {$$ = TreeCreate(TYPE_VOID, NODE_READ, NULL, NULL, NULL, $3, NULL, NULL);}
         ;

OutputStmt: WRITE '(' expr ')' ';'  {$$ = TreeCreate(TYPE_VOID, NODE_WRITE, NULL, NULL, NULL, $3, NULL, NULL);}
          ;

AsgStmt: id ASSGN expr ';'          {
                                        typecheck($1->type, $3->type, '=');
                                        $$ = TreeCreate(TYPE_VOID, NODE_ASSGN, NULL, NULL, NULL, $1, $3, NULL);
                                    }
       ;

ExprList: ExprList ',' expr {
                                $3->arglist = $1;
                                $$ = $3;
                            }
        | expr              {$$ = $1;}
        |                   {$$ = NULL;}
        ;

expr : expr PLUS expr	{
                            typecheck($1->type, $3->type, 'a');
                            $$ = TreeCreate(TYPE_INT, NODE_PLUS, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr MINUS expr  {
                            typecheck($1->type, $3->type, 'a');
                            $$ = TreeCreate(TYPE_INT, NODE_MINUS, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr MUL expr	{
                            typecheck($1->type, $3->type, 'a');
                            $$ = TreeCreate(TYPE_INT, NODE_MUL, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr DIV expr	{
                            typecheck($1->type, $3->type, 'a');
                            $$ = TreeCreate(TYPE_INT, NODE_DIV, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr MOD expr	{
                            typecheck($1->type, $3->type, 'a');
                            $$ = TreeCreate(TYPE_INT, NODE_MOD, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr LT expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = TreeCreate(TYPE_BOOL, NODE_LT, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr GT expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = TreeCreate(TYPE_BOOL, NODE_GT, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr LE expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = TreeCreate(TYPE_BOOL, NODE_LE, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr GE expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = TreeCreate(TYPE_BOOL, NODE_GE, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr NEQ expr    {
                            typecheck($1->type, $3->type, 'b');
                            $$ = TreeCreate(TYPE_BOOL, NODE_NEQ, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr EQ expr     {
                            typecheck($1->type, $3->type, 'b');
                            $$ = TreeCreate(TYPE_BOOL, NODE_EQ, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr AND expr    {
                            typecheck($1->type, $3->type, 'l');
                            $$ = TreeCreate(TYPE_BOOL, NODE_AND, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | expr OR expr     {
                            typecheck($1->type, $3->type, 'l');
                            $$ = TreeCreate(TYPE_BOOL, NODE_OR, NULL, NULL, NULL, $1, $3, NULL);
                        }
     | '(' expr ')'	{$$ = $2;}
     | NUM		{$$ = $1;}
     | MINUS NUM        {
                            $2->value.intval = -1*($2->value.intval);
                            $$ = $2;
                        }
     | STRVAL           {$$ = $1;}
     | id		        {$$ = $1;}
     | func             {$$ = $1;}
     | ADDR id         {
                            if($2->type == TYPE_INT_PTR) 
                            {
                                yyerror_impl("Cannot take address of pointer variable", $2->name);
                                exit(1);
                            }
                            $$ = TreeCreate(TYPE_INT_PTR, NODE_ADDR, NULL, NULL, NULL, $2, NULL, NULL);
                        }
    | Field             {$$ = $1;}
 
     ;

func: ID '(' ExprList ')'   {
                                 assignType($1,1);
                                //checkParamType($1,$3);
                                $1->nodetype = NODE_FUNC;
                                $1->ptr1 = reverseList($3);
                                    if($1==NULL || $3==NULL)
                                    {
                                        printf("Error at 394");
                                        exit(1);
                                    }
                                    struct Gsymbol* temp=GLookup($1->name);
                                    printf("func is :%s\n",temp->name);
                                    struct Paramstruct* temp2=temp->paramlist;
                                    struct ASTNode* right=$1->ptr1;

                                    while(right!=NULL && temp2!=NULL)
                                    {
                                        if(right->type==temp2->type)
                                        {
                                            // printf("hi bro %s %s\n",right->name,temp2->name);
                                            // printf("%d==%d\n",right->type,temp2->type);
                                            right=right->arglist;
                                            temp2=temp2->next;
                                        }
                                        else
                                        {
                                            // printf("hi bro %s %s\n",right->name,temp2->name);
                                            // printf("%d==%d\n",right->type,temp2->type);
                                            printf("mismatch bro in function arguments\n");
                                            exit(1);
                                        }
                                        
                                    }
                                    if(right!=NULL || temp2!=NULL)
                                    {
                                        printf("Error at 422");
                                        if(right==NULL)
                                        {
                                            printf("right is NULL\n");
                                        }
                                        if(temp2==NULL)
                                        {
                                            printf("temp2 is NULL\n");
                                        }
                                        exit(1);
                                    }
                                    $$ = $1;
                                    codegen($$);
                            }

id: ID                  {
                            assignType($1, 0);
                            $$ = $1;
                        }
  | ID '[' expr ']'     {
                            assignType($1, 2);
                            $$ = TreeCreate($1->type, NODE_ARRAY, NULL, NULL, NULL, $1, $3, NULL);
                            $$->Gentry = $1->Gentry;
                            $$->Lentry = $1->Lentry;
                        }
    | MUL ID            {
                            assignType($2, 0);
                            $$ = TreeCreate($2->type, NODE_INT_PTR, $2->name, NULL, NULL, NULL, NULL, NULL);
                            $$->Gentry = $2->Gentry;
                            $$->Lentry = $2->Lentry;
                        }
    /* | ID '.' ID         {
                            struct Gsymbol * temp=GLookup($1->name);
                            if(temp->type!=TYPE_TUPLE_VAR)
                            {
                                printf("Variable %s is not of tuple type\n", $1->name);
                                exit(1);
                            }
                            struct Paramstruct* tempParam=temp->paramlist;
                            int found=0;
                            while(tempParam!=NULL)
                            {
                                if(strcmp(tempParam->name,$3->name)==0)
                                {
                                    found=1;
                                    break;

                                }
                                tempParam=tempParam->next;
                            }
                            if(found==0)
                            {
                                printf("Tuple %s does not have element %s\n", $1->name, $3->name);
                                exit(1);
                            }
                            $$ = TreeCreate(tempParam->type, NODE_TUPLE, NULL, NULL, NULL, $1, $3, NULL);
                            $$->Gentry=temp;

                        }        */

  ;


%%

int yyerror_impl(char const *s, const char *var) 
{
    printf("Error : %s",s);
    if(var != NULL) 
    {
        printf(" '%s'", var);
    }
    printf("\n");
    return 0;
}

// Undefine the macro for the actual implementation
#undef yyerror

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        yyerror_impl("Please provide an input filename", NULL);
        exit(1);
    }
    else 
    {
        fp = fopen(argv[1], "r");
        if (!fp) 
        {
            yyerror_impl("Invalid input file specified:", argv[1]);
            exit(1);
        }
        else 
        {
            yyin = fp;
        }
    }
    yyparse();
    return 0;
}
