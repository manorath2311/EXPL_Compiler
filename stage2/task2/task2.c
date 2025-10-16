#include <string.h>
// FILE *code_xsm = NULL;
// struct tnode *makeConstantNode(int type, int val)
// {
//     struct tnode *new_node = (struct tnode *)malloc(sizeof(struct tnode));
//    new_node->val=val;
//    new_node->type = type;
//    new_node->left=NULL;
//    new_node->right=NULL;

//    return new_node;

// }
// int counter=-1;
// int number;
// int getReg() 
// {
//     if(counter < 20)
//     {
//         counter++;
//         return counter;
//     }
//     fprintf(code_xsm, "Out of Registers");
//     exit(1);
// }
// void freeReg() 
// {
//     if(counter >= 0)
//         counter--;
// }

// struct tnode *makeVariableNode(int type, char* varname)
// {
//     struct tnode *new_node = (struct tnode *)malloc(sizeof(struct tnode));
//     new_node->varname = (char *)malloc(sizeof(char) * (strlen(varname) + 1));
//     strcpy(new_node->varname, varname);
//     new_node->type = type;
//     new_node->left = NULL;
//     new_node->right = NULL;
//     return new_node;
// }

// struct tnode *makeExprNode(int type, char op, struct tnode *left, struct tnode *right)
// {
//     struct tnode *new_node = (struct tnode *)malloc(sizeof(struct tnode));
//     new_node->left = left;
//     new_node->right = right;
//     new_node->type = type;
//     new_node->nodetype = op;
//     new_node->op = op;
//     return new_node;
// }
// struct tnode *makeStmtNode(int type, struct tnode *left, struct tnode *right)
// {
//     struct tnode *new_node = (struct tnode *)malloc(sizeof(struct tnode));
//     new_node->left = left;
//     new_node->right = right;
//     new_node->type = type;
//     return new_node;
// }
// void print_tree(struct tnode *node, int lvl, int isRight)
// {
//     if (node == NULL) return;

//     for (int i = 0; i < lvl; i++) 
//     {
//         printf("    ");
//     }

//     if (isRight)
//     {
//         printf("R----");
//     }
//     else 
//     {
//         printf("L----");
//     }

//     if(node->type==INT_NODE_CONST)
//     {
//         printf("INT: %d\n", node->val);
//     }
//     else if(node->type==ID_NODE_CONST)
//     {
//         printf("ID: %s\n", node->varname);
//     }
//     else if(node->type==OP_NODE_CONST)
//     {
//         printf("OP: %c\n", node->op);
//     }
//     else if(node->type==READ_NODE_CONST)
//     {
//         printf("READ: %s\n", node->varname);
//     }
//     else if(node->type==WRITE_NODE_CONST)
//     {
//         printf("WRITE: %s\n", node->varname);
//     }
//     else if(node->type==STATEMENT_NODE_CONST)
//     {
//         //printf("STATEMENT\n");
//         printf("OP: %c\n", node->op);

//     }
//     else if(node->type==ASSIGN_NODE_CONST)
//     {
//         printf("ASSIGN\n");
//     }
//     else
//     {
//         printf("unknown\n");
//     }

//     print_tree(node->left, lvl + 1, 1);
//     print_tree(node->right, lvl + 1, 0);
// }

// void preorder(struct tnode *node)
// {
//     if (node == NULL) return;

//     if (node->type == INT_NODE_CONST)
//     {
//         printf("INT: %d\n", node->val);
//     }
//     else if(node->type == ID_NODE_CONST)
//     {
//         printf("ID: %s\n", node->varname);
//     }
//     else if(node->type == OP_NODE_CONST)
//     {
//         printf("OP: %c\n", node->nodetype);
//     }
//     else if(node->type == READ_NODE_CONST)
//     {
//         printf("READ: %s\n", node->varname);
//     }
//     else if(node->type == WRITE_NODE_CONST)
//     {
//         printf("WRITE: %s\n", node->varname);
//     }
//     else if(node->type == STATEMENT_NODE_CONST)
//     {
//         printf("STATEMENT\n");
//     }
//     else if(node->type == ASSIGN_NODE_CONST)
//     {
//         printf("ASSIGN\n");
//     }
//     else
//     {
//         printf("unknown\n");
//     }

//     preorder(node->left);
//     preorder(node->right);
// }
// int evaluate(tnode* root)
// {
//     if (root == NULL) return 0;

//     int left = evaluate(root->left);
//     int right = evaluate(root->right);

//     switch (root->type)
//     {
//         case INT_NODE_CONST:
//             return root->val;
//         case ID_NODE_CONST:
//             // For simplicity, assume variable 'a' is stored in a global variable
//             if (strcmp(root->varname, "a") == 0)
//                 return number; // 'number' holds the value of 'a'
//             return 0;
//         case OP_NODE_CONST:
//             switch (root->op)
//             {
//                 case '+': return left + right;
//                 case '-': return left - right;
//                 case '*': return left * right;
//                 case '/': return left / right;
//                 default: return 0;
//             }
//         case ASSIGN_NODE_CONST:
//             // Only handles 'a = <expr>' assignment
//             if (root->left && root->left->type == ID_NODE_CONST && strcmp(root->left->varname, "a") == 0)
//                 number = evaluate(root->right);
//             return number;
//         case READ_NODE_CONST:
//             // Simulate read by setting 'a' to a fixed value (e.g., 2)
//             if (root->left && root->left->type == ID_NODE_CONST && strcmp(root->left->varname, "a") == 0)
//                 number = 2;
//             return number;
//         case WRITE_NODE_CONST:
//             // Print the value of 'a'
//             if (root->left)
//                 printf("%d\n", evaluate(root->left));
//             else if (root->varname && strcmp(root->varname, "a") == 0)
//                 printf("%d\n", number);
//             return 0;
//         default:
//             return 0;
//     }
// }

// int generate_xsm(tnode *root)
// {
//     if (root == NULL)
//     {
//         return -1;
//     } 
//     int r1,r2,addr;
//     switch (root->type)
//     {
//         case INT_NODE_CONST:
//             r1 = getReg();
//             fprintf(code_xsm, "MOV R%d, %d\n", r1, root->val);
//             return r1;
//             break;
//         case ID_NODE_CONST:
//             addr=4096 + root->varname[0] - 'a';
//             r1=getReg();
//             fprintf(code_xsm, "MOV R%d, [%d]\n", r1, addr);
//             return r1;
//             break;
        
//         case STATEMENT_NODE_CONST:
//             r1=generate_xsm(root->left);
//             r2=generate_xsm(root->right);
//             if(root->op=='+')
//             {
//                 fprintf(code_xsm, "ADD R%d R%d\n", r1, r2);
//             }
//             else if(root->op=='-')
//             {
//                 fprintf(code_xsm, "SUB R%d R%d\n", r1, r2);
//             }
//             else if(root->op=='*')
//             {
//                 fprintf(code_xsm, "MUL R%d R%d\n", r1, r2);
//             }
//             else if(root->op=='/')
//             {
//                 fprintf(code_xsm, "DIV R%d R%d\n", r1, r2);
//             }
//             else
//             {
//                 fprintf(code_xsm, "Unknown operator %c\n", root->op);
//                 exit(1);
//             }
//             freeReg(r2);
//             return r1;
//             break;
//         case READ_NODE_CONST:
//             fprintf(code_xsm, "READ\n");
//               number = 4096 + root->left->varname[0] - 'a';

//             fprintf(code_xsm, "MOV R0,\"Read\"\n");
//             fprintf(code_xsm, "PUSH R0\n"); // function code "Read"
//             fprintf(code_xsm, "MOV R0,-1\n");
//             fprintf(code_xsm, "PUSH R0\n"); // Argument 1
//             fprintf(code_xsm, "MOV R0,%d\n", number);
//             fprintf(code_xsm, "PUSH R0\n"); // Argument 2
//             fprintf(code_xsm, "ADD SP,2\n");
//             fprintf(code_xsm, "CALL 0\n");
//             fprintf(code_xsm, "SUB SP,5\n");

//             return r1;

//             break;
//         case WRITE_NODE_CONST:

//                 fprintf(code_xsm, "WRITE\n");

//                 fprintf(code_xsm, "MOV R0,\"Write\"\n");
//                 fprintf(code_xsm, "PUSH R0\n");
//                 fprintf(code_xsm, "MOV R0,-2\n");
//                 fprintf(code_xsm, "PUSH R0\n");

//                 if(root->left != NULL) 
//                 {
//                     r1 = generate_xsm(root->left);
//                     fprintf(code_xsm, "PUSH R%d\n", r1);
//                     freeReg();
//                 } 
//                 else if(root->varname != NULL) 
//                 {
//                     int addr = 4096 + root->varname[0] - 'a';
//                     r1 = getReg();
//                     fprintf(code_xsm, "MOV R%d,[%d]\n", r1, addr);
//                     fprintf(code_xsm, "PUSH R%d\n", r1);
//                     freeReg();
//                 } 

//                 fprintf(code_xsm, "ADD SP,2\n");
//                 fprintf(code_xsm, "CALL 0\n");
//                 fprintf(code_xsm, "SUB SP,5\n");
//                 return r1;
//                 break;


        
//         case ASSIGN_NODE_CONST:
//             fprintf(code_xsm, "ASSIGN\n");
//             return r1;

//             break;
//         default:
//             fprintf(code_xsm, "unknown\n");
//             return r1;
//             break;
//     }

//     generate_xsm(root->left);
//     generate_xsm(root->right);
// }
int counter = -1, i, j;
extern FILE *intermediate;

int getReg() 
{
    if(counter < 20)
        return ++counter;
    printf("Out of Registers");
    exit(1);
}
int freeReg() 
{
    if(counter >= 0)
        counter--;
}
int codegen(struct tnode* t) 
{
    int r1, r2, r3, number, status=0;

    if(t == NULL) 
    {
        return -1;
    } 
    else if(t->nodetype == NODE_CONNECTOR) 
    {
        codegen(t->left);
        codegen(t->right);
    }

    switch(t->nodetype) 
    {
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
            fprintf(intermediate, "PUSH R0\n"); // function code "Write"
            fprintf(intermediate, "MOV R0,-1\n");
            fprintf(intermediate, "PUSH R0\n"); //Argument 1
            fprintf(intermediate, "MOV R0,%d\n", number);
            fprintf(intermediate, "PUSH R0\n"); //Argument 1
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
    if (name != NULL) {
        temp->varname = (char *)malloc(sizeof(name));
        strcpy(temp->varname, name);
    }
    temp->left = l;
    temp->right = r;
    return temp;
}
extern FILE *intermediate;

void initialize() {
    intermediate = fopen("intermediate.xsm", "w");
    fprintf(intermediate, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(intermediate, "ADD SP, 26\n");
}