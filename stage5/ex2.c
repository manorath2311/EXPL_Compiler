// Global variable definitions
int declarationType = 0;
int FDeclarationType = 0;
int totalCount = 4096;
int localBindingStart = 1;
int fLabelCount = 0;
struct Gsymbol* Gtemp = NULL;
struct Lsymbol* Ltemp = NULL;
struct Paramstruct* Ptemp = NULL;
struct Gsymbol *Ghead = NULL, *Gtail = NULL;
struct Lsymbol *Lhead = NULL, *Ltail = NULL;
struct Paramstruct *Phead = NULL, *Ptail = NULL;

FILE *stream;
int count = 0;


extern FILE *intermediate;
struct ASTNode* TreeCreate(int type,int nodetype,char *name,union Constant *value,struct ASTNode *arglist,struct ASTNode *ptr1,struct ASTNode *ptr2,struct ASTNode *ptr3) 
{
    struct ASTNode* temp;
    temp = (struct ASTNode*)malloc(sizeof(struct ASTNode));

    if(value != NULL) 
        temp->value = *value;

    temp->type = type;
    temp->nodetype = nodetype;
    temp->name = name;
    temp->ptr1 = ptr1;
    temp->ptr2 = ptr2;
    temp->ptr3 = ptr3;
    temp->arglist = arglist;
    return temp;
}

struct ASTNode* reverseList(struct ASTNode* head) 
{
    struct ASTNode *prev = NULL, *current;

    while(head != NULL) {
        current = head->arglist;
        head->arglist = prev;
        prev = head;
        head = current;
    }

    return prev;
}

void initialize() 
{
    intermediate = fopen("machinecode.xsm", "w");
    fprintf(intermediate, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(intermediate, "MOV SP, %d\n", totalCount-1);
    fprintf(intermediate, "PUSH R0\n");
    fprintf(intermediate, "CALL MAIN\n");
    fprintf(intermediate, "MOV R0, 10\nPUSH R0\nINT 10\n");
}

// void print_tree(struct ASTNode* node) 
// {
//     static int nullcount = 0;
//     count += 1;
//     int temp = count;

//     if (node->ptr1) 
//     {
//         fprintf(stream, "    \"%d.%s\" -> \"%d.%s\";\n", temp, findKey(node), count + 1, findKey(node->ptr1));
//         print_tree(node->ptr1);
//     }

//     if (node->ptr2) 
//     {
//         fprintf(stream, "    \"%d.%s\" -> \"%d.%s\";\n", temp, findKey(node), count + 1, findKey(node->ptr2));
//         print_tree(node->ptr2);
//     }

//     if (node->ptr3) 
//     {
//         fprintf(stream, "    \"%d.%s\" -> \"%d.%s\";\n", temp, findKey(node), count + 1, findKey(node->ptr3));
//         print_tree(node->ptr3);
//     }

//     if (node->arglist) 
//     {
//         fprintf(stream, "    \"%d.%s\":e -> \"%d.%s\":w;\n", temp, findKey(node), count + 1, findKey(node->arglist));
//         print_tree(node->arglist);
//    }
// }



char* findKey(struct ASTNode* head) 
{
    char *key = malloc(20);
    switch(head->nodetype) {
        case NODE_CONNECTOR:
            strcpy(key, "_");
            break;
        case NODE_PLUS:
            strcpy(key, "+");
            break;
        case NODE_MINUS:
            strcpy(key, "-");
            break;
        case NODE_MUL:
            strcpy(key, "*");
            break;
        case NODE_DIV:
            strcpy(key, "/");
            break;
        case NODE_ID:
            strcpy(key, head->name);
            break;
        case NODE_FUNC:
            sprintf(key, "%s()", head->name);
            break;
        case NODE_NUM:
            sprintf(key, "%d", head->value.intval);
            break;
        case NODE_ASSGN:
            strcpy(key, "=");
            break;
        case NODE_READ:
            strcpy(key, "read");
            break;
        case NODE_WRITE:
            strcpy(key, "write");
            break;
        case NODE_IF:
            strcpy(key, "if");
            break;
        case NODE_IF_ELSE:
            strcpy(key, "if else");
            break;
        case NODE_WHILE:
            strcpy(key, "while");
            break;
        case NODE_LT:
            strcpy(key, "<");
            break;
        case NODE_GT:
            strcpy(key, ">");
            break;
        case NODE_LE:
            strcpy(key, "<=");
            break;
        case NODE_GE:
            strcpy(key, ">=");
            break;
        case NODE_EQ:
            strcpy(key, "==");
            break;
        case NODE_NEQ:
            strcpy(key, "!=");
            break;
        case NODE_BREAK:
            strcpy(key, "break");
            break;
        case NODE_CONT:
            strcpy(key, "continue");
            break;
        case NODE_STRVAL:
            strcpy(key, head->value.strval+1);
            key[strlen(key)-1] = '\0';
            break;
        case NODE_ARRAY:
            strcpy(key, "array");
            break;
        case NODE_RET:
            strcpy(key, "return");
            break;
        case NODE_INT_PTR:
            sprintf(key, "*%s", head->name);
            break;
        case NODE_TUPLE :
            sprintf(key,"<%s>", head->name);

    }
    return key;        
}

void print_tree(struct ASTNode* node,int level)
{
    if(node == NULL)
        return;
    for(int i=0; i<level; i++)
        printf("--");
    printf("%s\n", findKey(node));
    print_tree(node->ptr1, level + 1);
    print_tree(node->ptr2, level + 1);
    print_tree(node->ptr3, level + 1);
}

struct Gsymbol* GLookup(char *name) 
{
    struct Gsymbol *temp = Ghead;

    while (temp != NULL && (strcmp(temp->name, name) != 0)) {
        temp = temp->next;
    }

    return temp;
}

struct Lsymbol* LLookup(char *name) 
{
    struct Lsymbol *temp = Lhead;

    while (temp != NULL && (strcmp(temp->name, name) != 0)) 
    {
        temp = temp->next;
    }

    return temp;
}

struct Paramstruct* PLookup(char *name) 
{
    struct Paramstruct *temp = Phead;

    while (temp != NULL && (strcmp(temp->name, name) != 0)) 
    {
        temp = temp->next;
    }

    return temp;
}

void GInstall(char *name, int type, int size, struct Paramstruct *paramlist) 
{
    struct Gsymbol* temp;
    temp = (struct Gsymbol *)malloc(sizeof(struct Gsymbol));
    temp->name = (char*)malloc(sizeof(name));
    strcpy(temp->name, name);
    temp->type = type;
    temp->size = size;
    temp->next = NULL;

    if(paramlist != NULL)
        temp->paramlist = paramlist;

    if(size != -1) 
    {
        temp->binding = totalCount;
        totalCount = totalCount + temp->size;
    }
    else 
    {
        temp->flabel = fLabelCount;
        fLabelCount++;
    }

    if (Ghead != NULL) 
    {
        Gtail->next = temp;
        Gtail = temp;
    }
    else 
    {
        Ghead = temp;
        Gtail = temp;
    }

    return;
}

void LInstall(char *name, int type) 
{
    struct Lsymbol *temp;
    temp = (struct Lsymbol *)malloc(sizeof(struct Lsymbol));
    temp->name = (char*)malloc(sizeof(name));
    strcpy(temp->name, name);
    temp->type = type;
    temp->binding = localBindingStart;
    localBindingStart++;

    if (Lhead != NULL) 
    {
        Ltail->next = temp;
        Ltail = temp;
    }
    else 
    {
        Lhead = temp;
        Ltail = temp;
    }

    return;
}

void InstallParamsInLocal() 
{
    struct Paramstruct *temp = Phead;
    int count = 0;

    // Count parameters
    while(temp != NULL) 
    {
        count++;
        temp = temp->next;
    }

    // Parameters are at negative offsets below BP
    // First param is at BP - (3 + count - 1), last is at BP - 3
    temp = Phead;
    while(temp != NULL) 
    {
        localBindingStart = -(3 + count - 1);
        LInstall(temp->name, temp->type);
        count--;
        temp = temp->next;
    }

    // Local variables start at BP+1
    localBindingStart = 1;
    return;
}

void PInstall(char *name, int type) 
{
    struct Paramstruct *temp;
    temp = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
    temp->name = (char*)malloc(sizeof(name));
    strcpy(temp->name, name);
    temp->type = type;

    if (Phead != NULL) 
    {
        Ptail->next = temp;
        Ptail = temp;
    }
    else 
    {
        Phead = temp;
        Ptail = temp;
    }

    return;
}

void printGSymbolTable() 
{
    struct Gsymbol* temp = Ghead;
    printf("\nGlobal Variables:\n");
    if(temp==NULL)
    {
        printf("NO Global variables\n");
    }
    while (temp != NULL) 
    {
        printf("%s --- %d --- %d\n", temp->name, temp->type, temp->binding);
        temp = temp->next;
    }
}

void printLSymbolTable() 
{
    struct Lsymbol* temp = Lhead;
    printf("\nLocal Variables:\n");
    if(temp == NULL) 
    {
        printf("No local variables.\n");
        return;
    }
    while (temp != NULL) 
    {
        printf("%s --- %d --- %d\n", temp->name, temp->type, temp->binding);
        temp = temp->next;
    }
}

int checkAvailability(char *name, int global) 
{
    if(global) 
    {
        Gtemp = GLookup(name);
        if(Gtemp != NULL) 
        {
            yyerror_impl("Re-initialization of variable/function:", name);
            exit(1);
        }
    }
    else 
    {
        Ltemp = LLookup(name);
        Ptemp = PLookup(name);
        if(Ptemp != NULL || Ltemp != NULL) 
        {
            yyerror_impl("Re-initialization of variable:", name);
            exit(1);
        }
    }

    return 1;
}

void assignType(struct ASTNode* node, int code) 
{
    // Code 0 - Local or Global Variable
    // Code 1 - Function
    // Code 2 - Array
    
    Ltemp = LLookup(node->name);
    if(Ltemp != NULL && code == 0) 
    {
        node->Lentry = Ltemp;
        node->type = Ltemp->type;
        
        // If this is a pointer dereference, the type should be the base type
        if(node->nodetype == NODE_INT_PTR) 
        {
            node->type = TYPE_INT;
        }
    }
    else 
    {
        Gtemp = GLookup(node->name);
        
        if(Gtemp != NULL) 
        {
            node->Gentry = Gtemp;
            node->type = Gtemp->type;
            
            // If this is a pointer dereference, the type should be the base type
            if(node->nodetype == NODE_INT_PTR) 
            {
                node->type = TYPE_INT;
            }

            if(code == 1 && Gtemp->size != -1) 
            {
                yyerror_impl("conflict in ID NodeType : Expected Function:", node->name);
                exit(1);
            }
        }
        else 
        {
            if(code == 1)
                yyerror_impl("Function not declared:", node->name);
            else
                yyerror_impl("Variable not declared:", node->name);
            exit(1);
        }
    }

    return;
}

void typecheck(int t1, int t2, char c) 
{
    switch(c) {
        case 'w': if(t1 != t2) {
                      yyerror_impl("Expected Boolean in WHILE check", NULL);
                      exit(1);
                  }
                  break;
        case 'e': if(t1 != t2) {
                      yyerror_impl("Expected Boolean in IF ELSE check", NULL);
                      exit(1);
                  }
                  break;
        case 'i': if(t1 != t2) {
                      yyerror_impl("Expected Boolean in IF check", NULL);
                      exit(1);
                  }
                  break;
        case 'a': 
                    if(t1 == TYPE_INT_PTR && t2 == TYPE_INT) {
                        break;
                    }
                    if(t1 == TYPE_INT && t2 == TYPE_INT_PTR) {
                        break;
                    }
                    if(t1 != TYPE_INT || t2 != TYPE_INT) {
                      yyerror_impl("Invalid type for arithmetic operation", NULL);
                      exit(1);
                  }
                  break;
         case 'b': //if(t1 != TYPE_INT || t2 != TYPE_INT) {
        //               yyerror_impl("Invalid type for comparing (<, >, <=..) operation", NULL);
        //               exit(1);
        //           }
                  break;
        case 'l': if(t1 != TYPE_BOOL || t2 != TYPE_BOOL) {
                      yyerror_impl("Invalid type for logical AND/OR operation", NULL);
                      exit(1);
                  }
                  break;
        case '=': 
                    // Allow assignment if types match, no special handling needed
                    // Dereferencing is handled in codegen
                    if(t1==TYPE_INT_PTR && t2==TYPE_INT)
                    {
                        break;
                    }
                    if(t1 != t2) 
                    {
                      yyerror_impl("Invalid type for assignment operation", NULL);
                      exit(1);
                    }
                  break;
    }
}

static int counter = -1, i, j, label=0;
int whileStart = -1, whileEnd = -1;
extern FILE *intermediate;

int getlabel() 
{
    return ++label;
}
int getReg() 
{
    if(counter < 20)
        return ++counter;
    yyerror_impl("Out of Registers", NULL);
    exit(1);
}
int freeReg() 
{
    if(counter >= 0)
        counter--;
}
int freeAllReg() 
{
    counter = -1;
}

int pushArguments(struct ASTNode *t) 
{
    int r;
    while(t != NULL) 
    {
        r = codegen(t);
        fprintf(intermediate, "PUSH R%d\n", r);
        freeReg();
        t = t->arglist;
    }
}

int popArguments(struct ASTNode *t) 
{
    int r = getReg();
    while(t != NULL) 
    {
        fprintf(intermediate, "POP R%d\n", r);
        t = t->arglist;
    }
    freeReg();
}

int getMemoryAddress(struct ASTNode* t) 
{
    int r;
    if(t->nodetype == NODE_ID && t->Gentry != NULL) 
    {
        r = getReg();
        fprintf(intermediate, "MOV R%d, %d\n", r, t->Gentry->binding);
        return r;
    }
    else if(t->nodetype == NODE_ID) 
    {
        r = getReg();
        fprintf(intermediate, "MOV R%d,BP\n", r);
        fprintf(intermediate, "ADD R%d,%d\n", r, t->Lentry->binding);
        return r;
    }
    else if(t->nodetype == NODE_ARRAY) 
    {
        r = codegen(t->ptr2);
        if(t->Gentry != NULL) 
        {
            fprintf(intermediate, "ADD R%d, %d\n", r, t->Gentry->binding);
        }
        else 
        {
            int r2 = getReg();
            fprintf(intermediate, "MOV R%d, BP\n", r2);
            fprintf(intermediate, "ADD R%d, %d\n", r2, t->Lentry->binding);
            fprintf(intermediate, "ADD R%d, R%d\n", r, r2);
            freeReg();
        }
        return r;
    }
    else if(t->nodetype == NODE_INT_PTR) 
    {
        // Get the address stored in the pointer variable
        r = getReg();
        if(t->Gentry != NULL)
        {
            fprintf(intermediate, "MOV R%d, %d\n", r, t->Gentry->binding);
            
            printf("Pointer variable found in Global symbol table: %s\n", t->name);
        }
        else if(t->Lentry != NULL)
        {
            fprintf(intermediate, "MOV R%d, BP\n", r);
            fprintf(intermediate, "ADD R%d, %d\n", r, t->Lentry->binding);
    
            printf("Pointer variable found in local symbol table: %s\n", t->name);
        }
        else
        {
            printf("Error: Pointer variable not found in symbol table: %s\n", t->name);
            exit(1);
        }
        return r;
    }
    else if(t->nodetype == NODE_ADDR) 
    {
        // Get the address of the variable
        r = getMemoryAddress(t->ptr1);
        return r;
    }
    else if(t->nodetype == NODE_TUPLE)
    {
        r=getReg();
        if(t->ptr1==NULL)
        {
            printf("ptr1 is null \n");
            exit(1);
        }
        else
        {
            printf("ptr1 is not null\n");
        }
        if(t->Gentry==NULL)
        {
            printf("TUPLE Gentry is NULL\n");
            exit(1);
        }
        else
        {
            printf("TUPLE Gentry is NOT NULL\n");

        }
        int baseAddress=t->Gentry->binding;
        printf("Base Address of TUPLE %s is %d\n",t->name,baseAddress);
        struct Paramstruct* tempParamList=t->Gentry->paramlist;
        int offset=0;
        if(tempParamList==NULL)
        {
            printf("tempParamList is NULL\n");
        }
        else
        {
            printf("tempParamList is not NULL\n");
        }
        while(tempParamList)
        {
            if(strcmp(tempParamList->name,t->ptr2->name)==0)
            {
                printf("found %s %s\n",tempParamList->name,t->ptr2->name);
                break;
            }
            offset++;
            tempParamList=tempParamList->next;
        }
        
        printf("Offset of TUPLE %s is %d\n",t->name,offset);
        // offset=0;
        
        int addr=baseAddress+offset;
        fprintf(intermediate, "MOV R%d, %d\n", r,addr);
        //fprintf(intermediate, "MOV R%d, %d\n", r,addr);
        return r;

    }
    else 
    {
        printf("Cannot find memory address of nodetype %d", t->nodetype);
        exit(1);
    }
    return -1;
}

int codegen(struct ASTNode* t) 
{
    int r1, r2, r3, l1, l2, number, status=0;
    int prevWhileStart, prevWhileEnd;

    if(t == NULL) 
    {
        return -1;
    } 
    else if(t->nodetype == NODE_CONNECTOR) 
    {
        codegen(t->ptr1);
        codegen(t->ptr2);
        return -1;
    }

    switch(t->nodetype) 
    {
        case NODE_NUM:
            r1 = getReg();
            fprintf(intermediate, "MOV R%d, %d\n", r1, t->value.intval);
            return r1;
        case NODE_STRVAL:
            r1 = getReg();
            fprintf(intermediate, "MOV R%d, %s\n", r1, t->value.strval);
            return r1;
        case NODE_ID:
            r1 = getMemoryAddress(t);
            fprintf(intermediate, "MOV R%d, [R%d]\n", r1, r1);
            return r1;
        case NODE_ARRAY:
            r1 = getMemoryAddress(t);
            fprintf(intermediate, "MOV R%d, [R%d]\n", r1, r1);
            return r1;
        case NODE_PLUS:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "ADD R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_MINUS:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "SUB R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_MUL:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "MUL R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_DIV:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "DIV R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_MOD:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "MOD R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_LT:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "LT R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_GT:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "GT R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_LE:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "LE R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_GE:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "GE R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_EQ:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "EQ R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_NEQ:
            r1 = codegen(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "NE R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_ASSGN:
            r1 = getMemoryAddress(t->ptr1);
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "MOV [R%d], R%d\n", r1, r2);
            freeReg();
            freeReg();
            return 0;
        case NODE_WRITE:
            

            fprintf(intermediate, "MOV R0,\"Write\"\n");
            fprintf(intermediate, "PUSH R0\n"); 
            fprintf(intermediate, "MOV R0,-2\n");
            fprintf(intermediate, "PUSH R0\n"); 

            r1 = codegen(t->ptr1);
            fprintf(intermediate, "PUSH R%d\n", r1);
            freeReg();
            fprintf(intermediate, "ADD SP,2\n");
            fprintf(intermediate, "CALL 0\n");
            fprintf(intermediate, "SUB SP,5\n");

           
            break;
        case NODE_READ:
            

            fprintf(intermediate, "MOV R0,\"Read\"\n");
            fprintf(intermediate, "PUSH R0\n"); 
            fprintf(intermediate, "MOV R0,-1\n");
            fprintf(intermediate, "PUSH R0\n"); 

            r1 = getMemoryAddress(t->ptr1);
            fprintf(intermediate, "PUSH R%d\n", r1); 
            freeReg();

            fprintf(intermediate, "ADD SP,2\n");
            fprintf(intermediate, "CALL 0\n");
            fprintf(intermediate, "SUB SP,5\n");

            
            break;
        case NODE_IF:
            r1 = codegen(t->ptr1); 
            l1 = getlabel();
            fprintf(intermediate, "JZ R%d,L%d\n", r1, l1);
            number = codegen(t->ptr2);
            fprintf(intermediate, "L%d:\n", l1);
            freeReg();
            break;
        case NODE_AND:
            l1 = getlabel();
            r1 = codegen(t->ptr1);
            fprintf(intermediate, "JZ R%d,L%d\n", r1, l1);
            freeReg();
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "JZ R%d,L%d\n", r2, l1);
            freeReg();
            r3 = getReg();
            fprintf(intermediate, "MOV R%d, 1\n", r3);
            l2 = getlabel();
            fprintf(intermediate, "JMP L%d\n", l2);
            fprintf(intermediate, "L%d:\n", l1);
            fprintf(intermediate, "MOV R%d, 0\n", r3);
            fprintf(intermediate, "L%d:\n", l2);
            return r3;
            break;
        case NODE_OR:
            l1 = getlabel();
            r1 = codegen(t->ptr1);
            fprintf(intermediate, "JNZ R%d,L%d\n", r1, l1);
            freeReg();
            r2 = codegen(t->ptr2);
            fprintf(intermediate, "JNZ R%d,L%d\n", r2, l1);
            freeReg();
            r3 = getReg();
            fprintf(intermediate, "MOV R%d, 0\n", r3);
            l2 = getlabel();
            fprintf(intermediate, "JMP L%d\n", l2);
            fprintf(intermediate, "L%d:\n", l1);
            fprintf(intermediate, "MOV R%d, 1\n", r3);
            fprintf(intermediate, "L%d:\n", l2);
            return r3;
            break;
        case NODE_IF_ELSE:
            r1 = codegen(t->ptr1);
            l1 = getlabel();
            l2 = getlabel();
            fprintf(intermediate, "JZ R%d,L%d\n", r1, l1);
            freeReg();
            number = codegen(t->ptr3);
            fprintf(intermediate, "JMP L%d\n", l2);
            fprintf(intermediate, "L%d:\n", l1);
            number = codegen(t->ptr2);
            fprintf(intermediate, "L%d:\n", l2);
            break;
        case NODE_WHILE:
            l1 = getlabel();
            l2 = getlabel();

            // Store old while start and end
            prevWhileStart = whileStart;
            prevWhileEnd = whileEnd;
            // Change to new start and end labels
            whileStart = l1;
            whileEnd = l2;

            fprintf(intermediate, "L%d:\n", l1);
            r1 = codegen(t->ptr1);
            fprintf(intermediate, "JZ R%d,L%d\n", r1, l2);
            freeReg();
            number = codegen(t->ptr2);
            fprintf(intermediate, "JMP L%d\n", l1);
            fprintf(intermediate, "L%d:\n", l2);

            // Restore while start and end labels
            whileStart = prevWhileStart;
            whileEnd = prevWhileEnd;
            break;
        case NODE_BREAK:
            if(whileEnd != -1)
                fprintf(intermediate, "JMP L%d\n", whileEnd);
            break;
        case NODE_CONT:
            if(whileStart != -1)
                fprintf(intermediate, "JMP L%d\n", whileStart);
            break;
        case NODE_RET:
            r1 = getReg();
            r2 = codegen(t->ptr1);
            fprintf(intermediate, "MOV R%d,BP\n", r1);
            fprintf(intermediate, "ADD R%d,%d\n", r1, -2);
            fprintf(intermediate, "MOV [R%d], R%d\n", r1, r2);
            freeReg();
            freeReg();

            Ltemp = Lhead;
            while(Ltemp != NULL) 
            {
                if(Ltemp->binding > 0)
                    fprintf(intermediate, "POP R0\n");
                Ltemp = Ltemp->next;
            }

            fprintf(intermediate, "POP BP\n");
            fprintf(intermediate, "RET\n");
            break;
        case NODE_FUNC:
            for (i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status = counter;
            freeAllReg();

            pushArguments(t->ptr1); //Push Arguments
            fprintf(intermediate, "PUSH R0\n"); //Space for return value
            fprintf(intermediate, "CALL F%d\n", t->Gentry->flabel); 

            r1 = status + 1;
            fprintf(intermediate, "POP R%d\n", r1); // for return value
            if (status == -1)
                r2 = getReg();

            popArguments(t->ptr1); // Pop Arguments

            if (status == -1)
                freeReg();

            for (i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;
            r1 = getReg();
            return r1;
            break;
        case NODE_INT_PTR:
            r1 = getMemoryAddress(t);
            fprintf(intermediate, "MOV R%d,[R%d]\n", r1, r1);
            return r1;
            break;
        case NODE_ADDR:
            r1 = getMemoryAddress(t->ptr1);
            fprintf(intermediate, "MOV R%d,[R%d]\n", r1, r1);
            return r1;
            break;
        case NODE_TUPLE:
            r1 = getMemoryAddress(t);
            fprintf(intermediate, "MOV R%d,[R%d]\n", r1, r1);
            return r1;

        default:
            printf("%d: This shouldn't have happened", t->nodetype);
            exit(1);
    }
}

void print_header() 
{
    intermediate = fopen("machinecode.xsm", "w");
    fprintf(intermediate, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(intermediate, "MOV SP, %d\n", totalCount-1);
    fprintf(intermediate, "PUSH R0\n");
    fprintf(intermediate, "CALL MAIN\n");
    fprintf(intermediate, "MOV R0, 10\nPUSH R0\nINT 10\n");
}
