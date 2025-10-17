

// Provide a stub for initialize
struct ASTNode* TreeCreate(
    int type,
    int nodetype,
    char *name,
    union Constant *value,
    struct ASTNode *arglist,
    struct ASTNode *ptr1,
    struct ASTNode *ptr2,
    struct ASTNode *ptr3
) {
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

struct ASTNode* reverseList(struct ASTNode* head) {
    struct ASTNode *prev = NULL, *current;

    while(head != NULL) {
        current = head->arglist;
        head->arglist = prev;
        prev = head;
        head = current;
    }

    return prev;
}

int counter = -1, i, j, label=0;
int whileStart = -1, whileEnd = -1;
extern FILE *intermediate;

int getlabel() {
    return ++label;
}
int getReg() {
    if(counter < 20)
        return ++counter;
    yyerror("Out of Registers");
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
    if(t->nodetype == NODE_ID && t->Gentry != NULL) {
        r = getReg();
        fprintf(intermediate, "MOV R%d, %d\n", r, t->Gentry->binding);
        return r;
    } else if(t->nodetype == NODE_ID) {
        r = getReg();
        fprintf(intermediate, "MOV R%d,BP\n", r);
        fprintf(intermediate, "ADD R%d,%d\n", r, t->Lentry->binding);
        return r;
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
            for (i = 0; i <= counter; i++)
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

            for (i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;
            break;
        case NODE_READ:
            for (i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status = counter;

            fprintf(intermediate, "MOV R0,\"Read\"\n");
            fprintf(intermediate, "PUSH R0\n"); // function code "Write"
            fprintf(intermediate, "MOV R0,-1\n");
            fprintf(intermediate, "PUSH R0\n"); //Argument 1

            r1 = getMemoryAddress(t->ptr1);
            fprintf(intermediate, "PUSH R%d\n", r1); //Argument 2
            freeReg();

            fprintf(intermediate, "ADD SP,2\n");
            fprintf(intermediate, "CALL 0\n");
            fprintf(intermediate, "SUB SP,5\n");

            for (i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;
            break;
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
            for (i = 0; i <= counter; i++)
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

            for (i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;
            r1 = getReg();
            return r1;
            break;
        default:
            printf("%d: This shouldn't have happened", t->nodetype);
            exit(1);
    }
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

void GInstall(char *name, int type, int size, struct Paramstruct *paramlist) {
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

void LInstall(char *name, int type) {
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

void PInstall(char *name, int type) {
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

void printGSymbolTable() {
    struct Gsymbol* temp = Ghead;
    printf("\nGlobal Variables:\n");
    while (temp != NULL) {
        printf("%s --- %d --- %d\n", temp->name, temp->type, temp->binding);
        temp = temp->next;
    }
}

void printLSymbolTable() {
    struct Lsymbol* temp = Lhead;
    printf("\nLocal Variables:\n");
    while (temp != NULL) {
        printf("%s --- %d --- %d\n", temp->name, temp->type, temp->binding);
        temp = temp->next;
    }
}

int checkAvailability(char *name, int global) {
    if(global) {
        Gtemp = GLookup(name);
        if(Gtemp != NULL) {
            {
                char buf[128];
                snprintf(buf, sizeof(buf), "Re-initialization of variable/function '%s'\n", name);
                yyerror(buf);
            }
            exit(1);
        }
    } else {
        Ltemp = LLookup(name);
        Ptemp = PLookup(name);
        if(Ptemp != NULL || Ltemp != NULL) {
            {
                char buf[128];
                snprintf(buf, sizeof(buf), "Re-initialization of variable '%s'\n", name);
                yyerror(buf);
            }
            exit(1);
        }
    }

    return 1;
}

void assignType(struct ASTNode* node, int code) {
    // Code 0 - Local or Global Variable
    // Code 1 - Function
    // Code 2 - Array
    
    Ltemp = LLookup(node->name);
    if(Ltemp != NULL && code == 0) {
        node->Lentry = Ltemp;
        node->type = Ltemp->type;
    } else {
        Gtemp = GLookup(node->name);
        if(Gtemp != NULL) {
            node->Gentry = Gtemp;
            node->type = Gtemp->type;

            if(code == 1 && Gtemp->size != -1) {
                yyerror("conflict in ID NodeType : Expected Function \n");
                printf("%s\n", node->name);
                exit(1);
            }
        } else {
            if(code == 1)
                {
                    char buf[128];
                    snprintf(buf, sizeof(buf), "Function '%s' not declared!", node->name);
                    yyerror(buf);
                }
            else
                {
                    char buf[128];
                    snprintf(buf, sizeof(buf), "Variable '%s' not declared!", node->name);
                    yyerror(buf);
                }
            exit(1);
        }
    }

    return;
}

void typecheck(int t1, int t2, char c) {
    switch(c) {
        case 'w': if(t1 != t2) {
                      yyerror("Expected Boolean in WHILE check\n");
                      exit(1);
                  }
                  break;
        case 'e': if(t1 != t2) {
                      yyerror("Expected Boolean in IF ELSE check\n");
                      exit(1);
                  }
                  break;
        case 'i': if(t1 != t2) {
                      yyerror("Expected Boolean in IF check\n");
                      exit(1);
                  }
                  break;
        case 'a': if(t1 != TYPE_INT || t2 != TYPE_INT) {
                      yyerror("Invalid type for arithmetic operation\n");
                      exit(1);
                  }
                  break;
        case 'b': if(t1 != TYPE_INT || t2 != TYPE_INT) {
                      yyerror("Invalid type for comparing (<, >, <=..) operation\n");
                      exit(1);
                  }
                  break;
        case '=': if(t1 != t2) {
                      yyerror("Invalid type for assignment operation\n");
                      exit(1);
                  }
                  break;
    }
}
