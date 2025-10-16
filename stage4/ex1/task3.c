struct LList 
{
    char* name;
    int lineNo;
    struct LList *next;
};
int totalCount=4096;
struct LList *labels = NULL;

void Lappend(char* Lname, int lineNo) 
{
    struct LList *label = (struct LList*)malloc(sizeof(struct LList));
    label->name = Lname;
    label->lineNo = lineNo;
    label->next = labels;
    labels = label;
}

int LLookup(char *Lname) 
{
    struct LList *head = labels;
    while(head != NULL) 
    {
        if(strcmp(head->name, Lname) == 0)
            return head->lineNo;
        head = head->next;
    }
    return -1;
}
void typecheck(int t1, int t2, char c) 
{
    switch(c)
    {
        case 'w':
            if(t1 != t2)
            {
                perror("Expected Boolean in WHILE check\n");
                exit(1);
            }
            break;
        case 'e':
            if(t1 != t2)
            {
                perror("Expected Boolean in IF ELSE check\n");
                exit(1);
            }
            break;
        case 'i':
            if(t1 != t2)
            {
                perror("Expected Boolean in IF check\n");
                exit(1);
            }
            break;
        case 'a':
            if(t1 != TYPE_INT || t2 != TYPE_INT)
            {
                perror("Invalid type for arithmetic operation\n");
                exit(1);
            }
            break;
        case 'b':
            if(t1 != TYPE_INT || t2 != TYPE_INT)
            {
                perror("Invalid type for comparing (<, >, <=..) operation\n");
                exit(1);
            }
            break;
        case '=':
            if(t1 != t2)
            {
                perror("Invalid type for assignment operation\n");
                exit(1);
            }
            break;
    }
}
struct Gsymbol* GLookup(char * name) 
{
    struct Gsymbol *temp = Ghead;

    while (temp != NULL && (strcmp(temp->name, name) != 0)) 
    {
        temp = temp->next;
    }

    return temp;
}



void GInstall(char *name, int type, int size,int is2D, int arrleft_index, int arrright_index) 
{
    struct Gsymbol* temp;

    temp = GLookup(name);
    if (temp != NULL) 
    {
        perror("Variable re-initialized");
        printf("\"%s\"\n", name);
        exit(1);
    } 
    else if(size < 1) 
    {
        perror("Invalid array size");
        exit(1);
    }

    temp = (struct Gsymbol *)malloc(sizeof(struct Gsymbol));
    temp->name = (char*)malloc(sizeof(name));
    strcpy(temp->name, name);
    temp->type = type;
    temp->size = size;
    temp->binding = totalCount;
    totalCount = totalCount + temp->size;
    temp->next = NULL;
    temp->is2D = is2D;
    temp->arrleft_index = arrleft_index;
    temp->arrright_index = arrright_index;

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

void printSymbolTable() 
{
    struct Gsymbol* temp = Ghead;
    while (temp != NULL) 
    {
        printf("%s---%d---%d---%d\n", temp->name, temp->type,temp->size, temp->binding);
        temp = temp->next;
        
    }
}

void print_tree(struct tnode* root) 
{
    if (root == NULL) 
        return;

    printf("Node Type: %d ", root->nodetype);
    if (root->nodetype == NODE_NUM) 
    {
        printf("Value: %d\n", root->val);
    } 
    else if (root->nodetype == NODE_ID) 
    {
        printf("Variable Name: %s\n", root->varname);
    } 
    else if (root->nodetype == NODE_STRVAL) 
    {
        printf("String Value: %s\n", root->varname);
    } 
    else 
    {
        printf("\n");
    }

    print_tree(root->left);
    print_tree(root->middle);
    print_tree(root->right);
}

struct tnode* createTree(int type, int val, int nodetype, char* name, struct tnode *l, struct tnode *r, struct tnode *mid,struct Gsymbol *g) 
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    temp->type = type;
    temp->nodetype = nodetype;
    if (name != NULL) {
        temp->varname = (char *)malloc(sizeof(name));
        strcpy(temp->varname, name);
    }
    temp->left = l;
    temp->right = r;
    temp->middle = mid;
    temp->Gentry = g;
    return temp;
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
    printf("Out of Registers");
    exit(1);
}
int freeReg() {
    if(counter >= 0)
        counter--;
}

int getMemoryAddress(struct tnode* t) 
{
    int r;
    if(t->nodetype == NODE_ID) 
    {
        r = getReg();
        fprintf(intermediate, "MOV R%d, %d\n", r, t->Gentry->binding);
        return r;
    }
    if(t->nodetype == NODE_ARRAY) 
    {
        r = getReg();
        int indexReg = codegen(t->right);
        fprintf(intermediate, "MOV R%d, %d\n", r, t->Gentry->binding);
        fprintf(intermediate, "ADD R%d, R%d\n", r, indexReg);
        //freeReg();
        return r;
    }

    if(t->nodetype == NODE_2D_ARRAY) 
    {
        r = getReg();
        int rowReg = codegen(t->middle);
        int colReg = codegen(t->right);
        int numRows = t->Gentry->arrright_index;
        int numCols = t->Gentry->arrleft_index ;
        fprintf(intermediate, "MUL R%d, %d\n", rowReg, numCols);
        fprintf(intermediate, "ADD R%d, R%d\n", rowReg, colReg);
        fprintf(intermediate, "MOV R%d, %d\n", r, t->Gentry->binding);
        fprintf(intermediate, "ADD R%d, R%d\n", r, rowReg);
        //freeReg();
        //freeReg();
        return r;
    }
    else
    {
        return -1;
    }
}

int codegen(struct tnode* t) 
{
    int r1, r2, r3, l1, l2, number, status=0;
    int prevWhileStart, prevWhileEnd;

    if(t == NULL) {
        printf("reached0 st\n");
        return -1;
    } else if(t->nodetype == NODE_CONNECTOR) {
        printf("reached_connector st\n");
        codegen(t->left);
        codegen(t->right);
        return -1;
    }

    switch(t->nodetype) {
        case NODE_NUM:
            printf("reached1 st\n");
            r1 = getReg();
            fprintf(intermediate, "MOV R%d, %d\n", r1, t->val);
            return r1;
        case NODE_STRVAL:
            printf("reached2 st\n");
            r1 = getReg();
            fprintf(intermediate, "MOV R%d, %s\n", r1, t->varname);
            return r1;
        case NODE_ID:
            printf("reached3 st\n");
            r1 = getMemoryAddress(t);
            fprintf(intermediate, "MOV R%d, [R%d]\n", r1, r1);
            return r1;
        case NODE_ARRAY:
            printf("reached4 st\n");
            r1 = getMemoryAddress(t);
            fprintf(intermediate, "MOV R%d, [R%d]\n", r1, r1);
            return r1;
        case NODE_PLUS:
            printf("reached5 st\n");
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "ADD R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_MINUS:
            printf("reached6 st\n");
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "SUB R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_MUL:
            printf("reached7 st\n");
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "MUL R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_DIV:
            printf("reached8 st\n");
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "DIV R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_MOD:
            printf("reached9 st\n");
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "MOD R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_LT:
            printf("reached10 st\n");
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "LT R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_GT:
            printf("reached11 st\n");
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "GT R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_LE:
            printf("reached12 st\n");
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "LE R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_GE:
            printf("reached13 st\n");
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "GE R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_EQ:
            printf("reached14 st\n");
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "EQ R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_NEQ:
            printf("reached15 st\n");
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "NE R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_ASSGN:
            printf("reached16 st\n");
            r1 = getMemoryAddress(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "MOV [R%d], R%d\n", r1, r2);
            freeReg();
            freeReg();
            return 0;
        case NODE_WRITE:
            printf("reached17 st\n");
            for (i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status = counter;

            fprintf(intermediate, "MOV R0,\"Write\"\n");
            fprintf(intermediate, "PUSH R0\n"); // function code "Write"
            fprintf(intermediate, "MOV R0,-2\n");
            fprintf(intermediate, "PUSH R0\n"); //Argument 1

            r1 = codegen(t->left);
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
            printf("reached18 st\n");
            for (i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status = counter;

            fprintf(intermediate, "MOV R0,\"Read\"\n");
            fprintf(intermediate, "PUSH R0\n"); // function code "Write"
            fprintf(intermediate, "MOV R0,-1\n");
            fprintf(intermediate, "PUSH R0\n"); //Argument 1

            r1 = getMemoryAddress(t->left);
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
            printf("reached19 st\n");
            r1 = codegen(t->left); 
            l1 = getlabel();
            fprintf(intermediate, "JZ R%d,L%d\n", r1, l1);
            number = codegen(t->right);
            fprintf(intermediate, "L%d:\n", l1);
            freeReg();
            break;
        case NODE_IF_ELSE:
            printf("reached20 st\n");
            r1 = codegen(t->left);
            l1 = getlabel();
            l2 = getlabel();
            fprintf(intermediate, "JZ R%d,L%d\n", r1, l1);
            freeReg();
            number = codegen(t->middle);
            fprintf(intermediate, "JMP L%d\n", l2);
            fprintf(intermediate, "L%d:\n", l1);
            number = codegen(t->right);
            fprintf(intermediate, "L%d:\n", l2);
            break;
        case NODE_WHILE:
            printf("reached21 st\n");
            l1 = getlabel();
            l2 = getlabel();

            // Store old while start and end
            prevWhileStart = whileStart;
            prevWhileEnd = whileEnd;
            // Change to new start and end labels
            whileStart = l1;
            whileEnd = l2;

            fprintf(intermediate, "L%d:\n", l1);
            r1 = codegen(t->left);
            fprintf(intermediate, "JZ R%d,L%d\n", r1, l2);
            freeReg();
            number = codegen(t->right);
            fprintf(intermediate, "JMP L%d\n", l1);
            fprintf(intermediate, "L%d:\n", l2);

            // Restore while start and end labels
            whileStart = prevWhileStart;
            whileEnd = prevWhileEnd;
            break;
        case NODE_BREAK:
            printf("reached22\n");
            if(whileEnd != -1)
                fprintf(intermediate, "JMP L%d\n", whileEnd);
            break;
        case NODE_CONT:
            printf("reached23\n");
            if(whileStart != -1)
                fprintf(intermediate, "JMP L%d\n", whileStart);
            break;
        default:
            printf("reached_default\n");
            break;
    }
}