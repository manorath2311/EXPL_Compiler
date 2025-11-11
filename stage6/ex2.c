// Global variable definitions
struct Gsymbol* Gtemp = NULL;
struct Lsymbol* Ltemp = NULL;
struct Paramstruct* Ptemp = NULL;
struct ASTNode* tempASTNode = NULL;
int totalCount = 4096;
int localBindingStart = 1;
int fLabelCount = 0;
struct Typetable *Thead = NULL, *Ttail = NULL;
struct Typetable *declarationType = NULL;
struct Typetable *FDeclarationType = NULL;
struct Fieldlist *Fhead = NULL, *Ftail = NULL;
struct Paramstruct *Phead = NULL, *Ptail = NULL;
struct Gsymbol *Ghead = NULL, *Gtail = NULL;
struct Lsymbol *Lhead = NULL, *Ltail = NULL;

// extern FILE *intermediate;
int counter = -1, j, label=0;
int whileStart = -1, whileEnd = -1;
struct Lsymbol* Ltemp;
extern FILE *intermediate;

int getlabel() {
    return ++label;
}
int getReg() {
    if(counter < 20)
        return ++counter;
    error("Out of Registers", NULL);
    exit(1);
}
int freeReg() {
    if(counter >= 0)
        counter--;
}
int freeAllReg() {
    counter = -1;
}

int pushArguments(struct ASTNode *t) {
    int r;
    while(t != NULL) {
        r = codegen(t);
        fprintf(intermediate, "PUSH R%d\n", r);
        freeReg();
        t = t->arglist;
    }
}

int popArguments(struct ASTNode *t) {
    int r = getReg();
    while(t != NULL) {
        fprintf(intermediate, "POP R%d\n", r);
        t = t->arglist;
    }
    freeReg();
}

int getMemoryAddress(struct ASTNode* t) {
    int r;
    if(t->nodetype == NODE_FIELD) {
        r = getReg();
        struct Fieldlist* ftemp;
        if(t->ptr1->Gentry != NULL) {
            fprintf(intermediate, "MOV R%d, %d\n", r, t->ptr1->Gentry->binding);
        } else {
            fprintf(intermediate, "MOV R%d,BP\n", r);
            fprintf(intermediate, "ADD R%d,%d\n", r, t->ptr1->Lentry->binding);
        }

        while(t->ptr2->nodetype == NODE_FIELD) {
            ftemp = FLookup(t->ptr2->ptr1->name, t->ptr1->type->fields); 
            fprintf(intermediate, "MOV R%d, [R%d]\n", r, r);
            fprintf(intermediate, "ADD R%d, %d\n", r, ftemp->fieldIndex);
            t = t->ptr2;
        }

        ftemp = FLookup(t->ptr2->name, t->ptr1->type->fields); 
        fprintf(intermediate, "MOV R%d, [R%d]\n", r, r);
        fprintf(intermediate, "ADD R%d, %d\n", r, ftemp->fieldIndex);
        return r;
    } else if(t->nodetype == NODE_ID) {
        if(t->Gentry != NULL) {
            r = getReg();
            fprintf(intermediate, "MOV R%d, %d\n", r, t->Gentry->binding);
            return r;
        } else {
            r = getReg();
            fprintf(intermediate, "MOV R%d,BP\n", r);
            fprintf(intermediate, "ADD R%d,%d\n", r, t->Lentry->binding);
            return r;
        }
    } else if(t->nodetype == NODE_ARRAY) {
        r = codegen(t->ptr2);
        fprintf(intermediate, "ADD R%d, %d\n", r, t->ptr1->Gentry->binding);
        return r;
    } else {
        printf("Cannot find memory address of nodetype %d", t->nodetype);
        exit(1);
    }
    return -1;
}

int codegen(struct ASTNode* t) {
    int r1, r2, r3, l1, l2, number, status=0;
    int prevWhileStart, prevWhileEnd;

    if(t == NULL) {
        return -1;
    } else if(t->nodetype == NODE_CONNECTOR) {
        codegen(t->ptr1);
        codegen(t->ptr2);
        return -1;
    }

    switch(t->nodetype) {
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
        case NODE_FIELD:
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
            for (int i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status = counter;

            fprintf(intermediate, "MOV R0,\"Write\"\n");
            fprintf(intermediate, "PUSH R0\n"); // function code "Write"
            fprintf(intermediate, "MOV R0,-2\n");
            fprintf(intermediate, "PUSH R0\n"); //Argument 1

            r1 = codegen(t->ptr1);
            fprintf(intermediate, "PUSH R%d\n", r1); //Argument 2
            freeReg();
            fprintf(intermediate, "ADD SP,2\n");
            fprintf(intermediate, "CALL 0\n");
            fprintf(intermediate, "SUB SP,5\n");

            for (int i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;
            break;
        case NODE_READ:
            for (int i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status = counter;

            fprintf(intermediate, "MOV R0,\"Read\"\n");
            fprintf(intermediate, "PUSH R0\n"); // function code "Read"
            fprintf(intermediate, "MOV R0,-1\n");
            fprintf(intermediate, "PUSH R0\n"); //Argument 1

            r1 = getMemoryAddress(t->ptr1);
            fprintf(intermediate, "PUSH R%d\n", r1); //Argument 2
            freeReg();

            fprintf(intermediate, "ADD SP,2\n");
            fprintf(intermediate, "CALL 0\n");
            fprintf(intermediate, "SUB SP,5\n");

            for (int i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;
            break;
        case NODE_FREE:
            for (int i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status = counter;

            fprintf(intermediate, "MOV R0,\"Free\"\n");
            fprintf(intermediate, "PUSH R0\n");

            r1 = codegen(t->ptr1);
            fprintf(intermediate, "PUSH R%d\n", r1); //Argument 1
            freeReg();

            fprintf(intermediate, "ADD SP,3\n");
            fprintf(intermediate, "CALL 0\n");
            fprintf(intermediate, "SUB SP,5\n");

            for (int i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;
            break;
        case NODE_INIT:
            for (int i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status = counter;

            fprintf(intermediate, "MOV R0,\"Heapset\"\n");
            fprintf(intermediate, "PUSH R0\n");
            fprintf(intermediate, "ADD SP,4\n");
            fprintf(intermediate, "CALL 0\n");
            fprintf(intermediate, "SUB SP,5\n");

            for (int i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;
            break;
        case NODE_ALLOC:
            for (int i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status = counter;

            fprintf(intermediate, "MOV R0,\"Alloc\"\n");
            fprintf(intermediate, "PUSH R0\n");
            fprintf(intermediate, "ADD SP,4\n");
            fprintf(intermediate, "CALL 0\n");

            r1 = status + 1;
            fprintf(intermediate, "POP R%d\n", r1); // for return value
            
            fprintf(intermediate, "SUB SP,4\n");

            for (int i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;
            r1 = getReg();
            return r1;
        case NODE_IF:
            r1 = codegen(t->ptr1); 
            l1 = getlabel();
            fprintf(intermediate, "JZ R%d,L%d\n", r1, l1);
            number = codegen(t->ptr2);
            fprintf(intermediate, "L%d:\n", l1);
            freeReg();
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
            while(Ltemp != NULL) {
                if(Ltemp->binding > 0)
                    fprintf(intermediate, "POP R0\n");
                Ltemp = Ltemp->next;
            }

            fprintf(intermediate, "POP BP\n");
            fprintf(intermediate, "RET\n");
            break;
        case NODE_FUNC:
            for (int i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status = counter;
            freeAllReg();

            pushArguments(t->ptr1); //Push Arguments
            fprintf(intermediate, "PUSH R0\n"); //Space for return value
            fprintf(intermediate, "CALL F%d\n", t->Gentry->flabel); //Space for return value

            r1 = status + 1;
            fprintf(intermediate, "POP R%d\n", r1); // for return value
            if (status == -1)
                r2 = getReg();

            popArguments(t->ptr1); // Pop Arguments

            if (status == -1)
                freeReg();

            for ( int i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;
            r1 = getReg();
            return r1;
        case NODE_NULL:
            r1 = getReg();
            fprintf(intermediate, "MOV R%d,-1\n", r1);
            return r1;
            break;
        default:
            printf("%d: This shouldn't have happened", t->nodetype);
            exit(1);
    }
}

void initialize() {
    intermediate = fopen("machinecode.xsm", "w");
    fprintf(intermediate, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(intermediate, "MOV SP, %d\n", totalCount-1);
    fprintf(intermediate, "PUSH R0\n");
    fprintf(intermediate, "CALL MAIN\n");
    fprintf(intermediate, "MOV R0, 10\nPUSH R0\nINT 10\n");
}
FILE *stream;
int count = 0;


void print_dot_aux(struct ASTNode* node) {
    
}

void print_dot(struct ASTNode* tree, char* name) {
   
}

char* findKey(struct ASTNode* head) {
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
        case NODE_FIELD:
            strcpy(key, "field");
            break;
        case NODE_NULL:
            strcpy(key, "NULL");
            break;
        case NODE_ALLOC:
            strcpy(key, "alloc()");
            break;
        case NODE_FREE:
            strcpy(key, "free()");
            break;
        case NODE_INIT:
            strcpy(key, "initialize()");
            break;
        default: 
            printf("Graphviz: No Node found");
            exit(1);
    }
    return key;        
}

struct Gsymbol* GLookup(char *name) {
    struct Gsymbol *temp = Ghead;

    while (temp != NULL && (strcmp(temp->name, name) != 0)) {
        temp = temp->next;
    }

    return temp;
}

struct Lsymbol* LLookup(char *name) {
    struct Lsymbol *temp = Lhead;

    while (temp != NULL && (strcmp(temp->name, name) != 0)) {
        temp = temp->next;
    }

    return temp;
}

struct Paramstruct* PLookup(char *name) {
    struct Paramstruct *temp = Phead;

    while (temp != NULL && (strcmp(temp->name, name) != 0)) {
        temp = temp->next;
    }

    return temp;
}

struct Typetable *TLookup(char *name) {
    struct Typetable *temp = Thead;
    while(temp != NULL && strcmp(temp->name, name) != 0) {
        temp = temp->next;
    }

    return temp;
}

struct Fieldlist *FLookup(char *name, struct Fieldlist *list) {
    while(list != NULL && strcmp(list->name, name) != 0) {
        list = list->next;
    }

    return list;
}

void FInstall(char *name, struct Typetable *type) {
    struct Fieldlist *ftemp;
    ftemp = (struct Fieldlist*)malloc(sizeof(struct Fieldlist));

    ftemp->name = (char*)malloc(sizeof(name));
    strcpy(ftemp->name, name);
    ftemp->type = type;
    ftemp->next = NULL;

    if(Fhead == NULL) {
        Fhead = ftemp;
        Ftail = ftemp;
    } else {
        Ftail->next = ftemp;
        Ftail = ftemp;
    }

    return;
}

void TInstall(char *name, struct Fieldlist *fields) {
    struct Typetable *temp;
    struct Fieldlist *ftemp;
    int counter = 0;
    temp = (struct Typetable *)malloc(sizeof(struct Typetable));

    temp->name = (char*)malloc(sizeof(name));
    strcpy(temp->name, name);
    temp->next = NULL;

    if(Thead == NULL) {
        Thead = temp;
        Ttail = temp;
    } else {
        Ttail->next = temp;
        Ttail = temp;
    }

    ftemp = fields;
    while(ftemp != NULL) {
        if (ftemp->type == TLookup("dummy")) {
            ftemp->type = TLookup(name);
        }

        ftemp->fieldIndex = ++counter;
        ftemp = ftemp->next;
    }

    temp->fields = fields;
    temp->size = counter;

    if(counter >= 8) {
        error("Too many member fields", NULL);
        exit(1);
    }

    Fhead = NULL;
    Ftail = NULL;
    return;
}

void GInstall(char *name, struct Typetable *type, int size, struct Paramstruct *paramlist) {
    struct Gsymbol* temp;
    temp = (struct Gsymbol *)malloc(sizeof(struct Gsymbol));
    temp->name = (char*)malloc(sizeof(name));
    strcpy(temp->name, name);
    temp->type = type;
    temp->size = size;
    temp->next = NULL;

    if(paramlist != NULL)
        temp->paramlist = paramlist;

    if(size != -1) {
        temp->binding = totalCount;
        totalCount = totalCount + temp->size;
    } else {
        temp->flabel = fLabelCount;
        fLabelCount++;
    }

    if (Ghead != NULL) {
        Gtail->next = temp;
        Gtail = temp;
    } else {
        Ghead = temp;
        Gtail = temp;
    }

    return;
}

void LInstall(char *name, struct Typetable *type) {
    struct Lsymbol *temp;
    temp = (struct Lsymbol *)malloc(sizeof(struct Lsymbol));
    temp->name = (char*)malloc(sizeof(name));
    strcpy(temp->name, name);
    temp->type = type;
    temp->binding = localBindingStart;
    localBindingStart++;

    if (Lhead != NULL) {
        Ltail->next = temp;
        Ltail = temp;
    } else {
        Lhead = temp;
        Ltail = temp;
    }

    return;
}

void InstallParamsInLocal() {
    struct Paramstruct *temp = Phead;
    int count = 0;

    while(temp != NULL) {
        count++;
        temp = temp->next;
    }

    localBindingStart = -1*count - 2;
    temp = Phead;
    while(temp != NULL) {
        LInstall(temp->name, temp->type);
        temp = temp->next;
    }

    localBindingStart = 1;
    return;
}

void PInstall(char *name, struct Typetable *type) {
    struct Paramstruct *temp;
    temp = (struct Paramstruct*)malloc(sizeof(struct Paramstruct));
    temp->name = (char*)malloc(sizeof(name));
    strcpy(temp->name, name);
    temp->type = type;

    if (Phead != NULL) {
        Ptail->next = temp;
        Ptail = temp;
    } else {
        Phead = temp;
        Ptail = temp;
    }

    return;
}

void printGSymbolTable() 
{
    struct Gsymbol* temp = Ghead;
    printf("-----Global Variables-----\n");
    while (temp != NULL) {
        printf("%s --- %s --- %d\n", temp->name, temp->type->name, temp->binding);
        temp = temp->next;
    }
    printf("\n");
}

void printLSymbolTable(char* funcName) 
{
    struct Lsymbol* temp = Lhead;
    printf("-----Local Variables (%s)-----\n", funcName);
    while (temp != NULL) {
        printf("%s --- %s --- %d\n", temp->name, temp->type->name, temp->binding);
        temp = temp->next;
    }
    printf("\n");
}

void printTypeTable() 
{
    printf("-----TYPE TABLE-----\n");
    struct Typetable *temp = Thead;
    struct Fieldlist *ftemp;
    while(temp != NULL) {
        printf("%s\t%d\n", temp->name, temp->size);
        ftemp = temp->fields;
        while(ftemp != NULL) {
            printf("\t%d\t%s\t%s\n", ftemp->fieldIndex, ftemp->name, ftemp->type->name);
            ftemp = ftemp->next;
        }
        temp = temp->next;
    }
    printf("\n");
}
int checkAvailability(char *name, int global) 
{
    if(global) {
        Gtemp = GLookup(name);
        if(Gtemp != NULL) {
            error("Re-initialization of variable/function '%s'\n", name);
            exit(1);
        }
    } else {
        Ltemp = LLookup(name);
        Ptemp = PLookup(name);
        if(Ptemp != NULL || Ltemp != NULL) {
            error("Re-initialization of variable '%s'\n", name);
            exit(1);
        }
    }

    return 1;
}

void assignTypeField(struct ASTNode* node, struct Fieldlist *fields) {
    struct Fieldlist *temp = FLookup(node->name, fields);
    if(temp == NULL) {
        error("No member field named '%s'", node->name);
        exit(1);
    }
    node->type = temp->type;
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
    }
    else 
    {
        Gtemp = GLookup(node->name);
        if(Gtemp != NULL) {
            node->Gentry = Gtemp;
            node->type = Gtemp->type;

            if(code == 1 && Gtemp->size != -1) {
                error("conflict in ID NodeType : Expected Function \n",NULL);
                printf("%s\n", node->name);
                exit(1);
            }
        }
        else 
         {
            if(code == 1)
                error("Function '%s' not declared!", node->name);
            else
                error("Variable '%s' not declared!", node->name);
            exit(1);
        }
    }

    return;
}

void typecheck(struct Typetable *t1, struct Typetable *t2, char c) {
    switch(c) {
        case 'w': if(t1 != t2) {
                      error("Expected Boolean in WHILE check\n", NULL);
                      exit(1);
                  }
                  break;
        case 'e': if(t1 != t2) {
                      error("Expected Boolean in IF ELSE check\n", NULL);
                      exit(1);
                  }
                  break;
        case 'i': if(t1 != t2) {
                      error("Expected Boolean in IF check\n", NULL);
                      exit(1);
                  }
                  break;
        case 'a': if(t1 != TLookup("integer") || t2 != TLookup("integer")) {
                      error("Invalid type for arithmetic operation\n", NULL);
                      exit(1);
                  }
                  break;
        case 'b': if(t1 != TLookup("integer") || t2 != TLookup("integer")) {
                      error("Invalid type for comparing (<, >, <=..) operation\n", NULL);
                      exit(1);
                  }
                  break;
        case '=': if(t1 != t2) {
                      error("Invalid type for assignment operation\n", NULL);
                      exit(1);
                  }
                  break;
        case '!': if (t1 == TLookup("string") || t1 == TLookup("integer")) {
                      error("Interger or String cannot be compared with NULL\n", NULL);
                      exit(1);
                  }
                  break;
    }
}

struct ASTNode* TreeCreate(
    struct Typetable *type,
    int nodetype,
    char *name,
    union Constant *value,
    struct ASTNode *arglist,
    struct ASTNode *ptr1,
    struct ASTNode *ptr2,
    struct ASTNode *ptr3
) {
    struct ASTNode *temp = (struct ASTNode*)malloc(sizeof(struct ASTNode));
    temp->type = type;
    temp->nodetype = nodetype;
    temp->name = name;
    if(value != NULL)
        temp->value = *value;
    temp->arglist = arglist;
    temp->ptr1 = ptr1;
    temp->ptr2 = ptr2;
    temp->ptr3 = ptr3;
    temp->Gentry = NULL;
    temp->Lentry = NULL;
    return temp;
}

struct ASTNode* reverseList(struct ASTNode *t) {
    struct ASTNode *prev = NULL, *current = t, *next = NULL;
    while(current != NULL) {
        next = current->arglist;
        current->arglist = prev;
        prev = current;
        current = next;
    }
    return prev;
}

struct ASTNode* insertFieldId(struct ASTNode *field, struct ASTNode *id) {
    struct ASTNode *temp = field;
    while(temp->ptr2->nodetype == NODE_FIELD) {
        temp = temp->ptr2;
    }
    assignTypeField(id, temp->ptr2->type->fields);
    temp->ptr2 = TreeCreate(id->type, NODE_FIELD, NULL, NULL, NULL, temp->ptr2, id, NULL);
    return field;
}

// void yyerror(char const *s) {
//     printf("yyerror: %s at line %d\n", s, lineno);
// }

// void error(const char *s, const char *var) {
//     fprintf(stderr, "Error: ");
//     fprintf(stderr, s, var);
//     fprintf(stderr, " at line number %d\n", lineno);
//     errorFlag = 1;
// }