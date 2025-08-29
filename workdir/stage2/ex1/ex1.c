#include <string.h>

int counter = -1, i, j;
extern FILE *intermediate;

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
int codegen(struct tnode* t) 
{
    int r1, r2, r3, number, status=0;

    if(t == NULL) {
        return -1;
    } else if(t->nodetype == NODE_CONNECTOR) {
        codegen(t->left);
        codegen(t->right);
    }

    switch(t->nodetype) {
        case NODE_NUM:
            r1 = getReg();
            fprintf(intermediate, "MOV R%d, %d\n", r1, t->val);
            return r1;
        case NODE_ID:
            r1 = getReg();
            number = 4096 + t->varname[0] - 'a';
            fprintf(intermediate, "MOV R%d, [%d]\n", r1, number);
            return r1;
        case NODE_PLUS:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "ADD R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_MINUS:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "SUB R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_MUL:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "MUL R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_DIV:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "DIV R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_ASSGN:
            number = 4096 + t->left->varname[0] - 'a';
            r2 = codegen(t->right);
            fprintf(intermediate, "MOV [%d], R%d\n", number, r2);
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
            number = 4096 + t->left->varname[0] - 'a';
            for (i = 0; i <= counter; i++)
                fprintf(intermediate, "PUSH R%d\n", i);
            status = counter;

            fprintf(intermediate, "MOV R0,\"Read\"\n");
            fprintf(intermediate, "PUSH R0\n"); 
            fprintf(intermediate, "MOV R0,-1\n");
            fprintf(intermediate, "PUSH R0\n"); 
            fprintf(intermediate, "MOV R0,%d\n", number);
            fprintf(intermediate, "PUSH R0\n"); 
            fprintf(intermediate, "ADD SP,2\n");
            fprintf(intermediate, "CALL 0\n");
            fprintf(intermediate, "SUB SP,5\n");

            for (i = status; i >= 0; i--)
                fprintf(intermediate, "POP R%d\n", i);
            counter = status;
            break;
    }
}
struct tnode* createTree(int type, int val, int nodetype, char* name, struct tnode *l, struct tnode *r) 
{
    struct tnode *temp;
    temp = (struct tnode*)malloc(sizeof(struct tnode));
    temp->val = val;
    temp->type = type;
    temp->nodetype = nodetype;
    if (name != NULL) 
    {
        temp->varname = (char *)malloc(sizeof(name));
        strcpy(temp->varname, name);
    }
    temp->left = l;
    temp->right = r;
    return temp;
}
extern FILE *intermediate;

void initialize() 
{
    intermediate = fopen("intermediate.xsm", "w");
    fprintf(intermediate, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(intermediate, "ADD SP, 26\n");
}
int arr[52];

int getAddr(char *c) 
{
    if(iscapital(c))
    {
        return *c - 'A' + 26;
    }
    
    return *c - 'a';
}

int iscapital(char *c)
{
    if(*c >= 'A' && *c <= 'Z')
    {
        return 1;
    }
    return 0;
}

int evaluate(struct tnode *t) 
{
    int addr, p, q;

    if (t == NULL) {
        return 0;
    }

    switch (t->nodetype) 
    {

        case NODE_NUM:
            return t->val;

        case NODE_ID:
            addr = getAddr(t->varname);
            return arr[addr];

        case NODE_PLUS:
            return evaluate(t->left) + evaluate(t->right);

        case NODE_MINUS:
            return evaluate(t->left) - evaluate(t->right);

        case NODE_MUL:
            return evaluate(t->left) * evaluate(t->right);

        case NODE_DIV:
            return evaluate(t->left) / evaluate(t->right);

        case NODE_ASSGN:
            if (t->left && t->left->nodetype == NODE_ID) 
            {
                addr = getAddr(t->left->varname);
                arr[addr] = evaluate(t->right);
            }
            return -1;

        case NODE_READ:
            if (t->left && t->left->nodetype == NODE_ID) 
            {
                addr = getAddr(t->left->varname);
                // For actual input, use scanf. Example:
                // printf("Enter value for %c: ", t->left->varname);
                scanf("%d", &arr[addr]);
            }
            return -1;

        case NODE_WRITE:
            if (t->left) 
            {
                printf("%d\n", evaluate(t->left));
            }
            return -1;

        case NODE_CONNECTOR:
            evaluate(t->left);
            evaluate(t->right);
            return -1;

        default:
            return 0;
    }
}
