#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct LList 
{
    char* name;
    int lineNo;
    struct LList *next;
};
int totalCount=4096;
struct LList *labels = NULL;

// Forward declarations for global symbol table
struct Gsymbol *Ghead = NULL;
struct Gsymbol *Gtail = NULL;

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
        if(temp->is2D == 1)
            printf("%s---%d---%d---%d---%d---%d\n", temp->name, temp->type,temp->size, temp->binding, temp->arrleft_index, temp->arrright_index);
        else
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



int counter = -1, j, label=0;
int whileStart = -1, whileEnd = -1;
extern int i;
int declaration_type;
extern FILE *intermediate;

int getlabel() {
    return ++label;
}
int getReg() 
{
    if(counter < 20)
      {
        return ++counter;
      }  
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
        fprintf(intermediate, "MOV R%d,%d\n", r, t->Gentry->binding);
        return r;
    }
    if(t->nodetype == NODE_ARRAY) 
    {
        r = getReg();
        int indexReg = codegen(t->right);
        fprintf(intermediate, "MOV R%d,%d\n", r, t->Gentry->binding);
        fprintf(intermediate, "ADD R%d,R%d\n", r, indexReg);
        freeReg();
        return r;
    }

    if(t->nodetype == NODE_2D_ARRAY) 
    {
        r = getReg();
        int rowReg = codegen(t->middle);
        int colReg = codegen(t->right);
        int numRows = t->Gentry->arrright_index;
        int numCols = t->Gentry->arrleft_index ;
        fprintf(intermediate, "MUL R%d,%d\n", rowReg, numCols);
        fprintf(intermediate, "ADD R%d,R%d\n", rowReg, colReg);
        fprintf(intermediate, "MOV R%d,%d\n", r, t->Gentry->binding);
        fprintf(intermediate, "ADD R%d,R%d\n", r, rowReg);

        printf("%d %d %d\n", numRows, numCols, t->Gentry->binding);
        printf("%d %d %d\n", rowReg, colReg, r);
        freeReg();
        freeReg();
        return r;
    }
    if(t->nodetype == NODE_ADDRESS) 
    {
        r = getReg();
        struct Gsymbol *g = t->Gentry;
        int addr=g->binding;
        fprintf(intermediate, "MOV R%d,%d\n", r, addr);
        //freeReg();
        return r;
    }
    if(t->nodetype == NODE_INT_PTR) 
    {

        int addr=t->Gentry->binding;
        r = getReg();
        fprintf(intermediate, "MOV R%d,%d\n", r, addr);
        fprintf(intermediate, "MOV R%d,[R%d]\n", r, r);

        return r;
    }
    else
    {
        return -1;
    }
}

// int counter = -1, i, j, label=0;
// int whileStart = -1, whileEnd = -1;
// extern FILE *intermediate;

// int getlabel() {
//     return ++label;
// }
// int getReg() {
//     if(counter < 20)
//         return ++counter;
//     printf("Out of Registers");
//     exit(1);
// }
// int freeReg() {
//     if(counter >= 0)
//         counter--;
// }

// int getMemoryAddress(struct tnode* t) {
//     int r;
//     if(t->nodetype == NODE_ID) {
//         r = getReg();
//         fprintf(intermediate, "MOV R%d, %d\n", r, t->Gentry->binding);
//         return r;
//     } else if(t->nodetype == NODE_ARRAY) {
//         r = codegen(t->right);
//         fprintf(intermediate, "ADD R%d, %d\n", r, t->left->Gentry->binding);
//         return r;
//     } else {
//         return -1;
//     }
// }

int codegen(struct tnode* t) {
    int r1, r2, r3, l1, l2, number, status=0;
    int prevWhileStart, prevWhileEnd;

    if(t == NULL) {
        return -1;
    } else if(t->nodetype == NODE_CONNECTOR) {
        codegen(t->left);
        codegen(t->right);
        return -1;
    }

    switch(t->nodetype) {
        case NODE_NUM:
            r1 = getReg();
            fprintf(intermediate, "MOV R%d,%d\n", r1, t->val);
            return r1;
        case NODE_STRVAL:
            r1 = getReg();
            fprintf(intermediate, "MOV R%d,%s\n", r1, t->varname);
            return r1;
        case NODE_ID:
            r1 = getMemoryAddress(t);
            fprintf(intermediate, "MOV R%d,[R%d]\n", r1, r1);
            return r1;
        case NODE_ARRAY:
            r1 = getMemoryAddress(t);
            fprintf(intermediate, "MOV R%d,[R%d]\n", r1, r1);
            return r1;
        case NODE_PLUS:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "ADD R%d,R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_MINUS:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "SUB R%d,R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_MUL:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "MUL R%d,R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_DIV:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "DIV R%d,R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_MOD:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "MOD R%d,R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_LT:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "LT R%d,R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_GT:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "GT R%d,R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_LE:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "LE R%d,R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_GE:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "GE R%d,R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_EQ:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "EQ R%d,R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_NEQ:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "NE R%d,R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_ASSGN:
            r1 = getMemoryAddress(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "MOV [R%d],R%d\n", r1, r2);
            freeReg();
            freeReg();
            return 0;
        case NODE_WRITE:

            r2 = getReg();
            fprintf(intermediate, "MOV R%d,\"Write\"\n", r2);
            fprintf(intermediate, "PUSH R%d\n", r2); // function code "Write"
            fprintf(intermediate, "MOV R%d,-2\n", r2);
            fprintf(intermediate, "PUSH R%d\n", r2); //Argument 1

            r1 = codegen(t->left);
            fprintf(intermediate, "PUSH R%d\n", r1); //Argument 2
            freeReg();
            fprintf(intermediate, "ADD SP,2\n");
            fprintf(intermediate, "CALL 0\n");
            fprintf(intermediate, "SUB SP,5\n");
            freeReg();

    
            break;
        case NODE_READ:

            r2 = getReg();
            fprintf(intermediate, "MOV R%d,\"Read\"\n", r2);
            fprintf(intermediate, "PUSH R%d\n", r2); // function code "Read"
            fprintf(intermediate, "MOV R%d,-1\n", r2);
            fprintf(intermediate, "PUSH R%d\n", r2); //Argument 1

            r1 = getMemoryAddress(t->left);
            fprintf(intermediate, "PUSH R%d\n", r1); //Argument 2
            freeReg();

            fprintf(intermediate, "ADD SP,2\n");
            fprintf(intermediate, "CALL 0\n");
            fprintf(intermediate, "SUB SP,5\n");

 
            break;
        case NODE_IF:
            r1 = codegen(t->left); 
            l1 = getlabel();
            fprintf(intermediate, "JZ R%d,L%d\n", r1, l1);
            number = codegen(t->right);
            fprintf(intermediate, "L%d:\n", l1);
            freeReg();
            break;
        case NODE_IF_ELSE:
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
        case NODE_2D_ARRAY :
            r1 = getMemoryAddress(t);
            fprintf(intermediate, "MOV R%d,[R%d]\n", r1, r1);
            return r1;
           break;
        case NODE_BREAK:
            if(whileEnd != -1)
                fprintf(intermediate, "JMP L%d\n", whileEnd);
            break;
        case NODE_CONT:
            if(whileStart != -1)
                fprintf(intermediate, "JMP L%d\n", whileStart);
            break;
        case NODE_INT_PTR:
            r1 = getMemoryAddress(t);
            fprintf(intermediate, "MOV R%d,[R%d]\n", r1, r1);
            return r1;
            break;
        case NODE_ADDRESS:
            r1 = getMemoryAddress(t->left);
            return r1;
            break;
        default:
            printf("Unknown node type: %d\n", t->nodetype);
            exit(1);
    }
}
void print_header() 
{
    fprintf(intermediate,"0");
    fprintf(intermediate,"\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(intermediate,"ADD SP,200\n");
  
}
void print_footer() 
{

    fprintf(intermediate, "MOV R0, \"Exit\"\nPUSH R0\n");
    fprintf(intermediate, "PUSH R0\nPUSH R0\nPUSH R0\nPUSH R0\n");
    fprintf(intermediate, "CALL 0\n");
    fprintf(intermediate, "POP R0\nPOP R0\nPOP R0\nPOP R0\nPOP R0\n");
}
