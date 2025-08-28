struct tnode *makeConstantNode(int type, int val)
{
    struct tnode *new_node = (struct tnode *)malloc(sizeof(struct tnode));
   new_node->val=val;
   new_node->type = type;
   new_node->left=NULL;
   new_node->right=NULL;

   return new_node;

}
FILE* output = NULL;
struct tnode *makeVariableNode(int type, char* varname)
{
    struct tnode *new_node = (struct tnode *)malloc(sizeof(struct tnode));
    new_node->varname = (char *)malloc(sizeof(char) * (strlen(varname) + 1));
    strcpy(new_node->varname, varname);
    new_node->type = type;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct tnode *makeExprNode(int type, char op, struct tnode *left, struct tnode *right)
{
    struct tnode *new_node = (struct tnode *)malloc(sizeof(struct tnode));
    new_node->left = left;
    new_node->right = right;
    new_node->type = type;
    new_node->nodetype = op;
    new_node->op = op;
    return new_node;
}
struct tnode *makeStmtNode(int type, struct tnode *left, struct tnode *right)
{
    struct tnode *new_node = (struct tnode *)malloc(sizeof(struct tnode));
    new_node->left = left;
    new_node->right = right;
    new_node->type = type;
    return new_node;
}
void print_tree(struct tnode *node, int lvl, int isRight)
{
    if (node == NULL) return;

    for (int i = 0; i < lvl; i++) 
    {
        fprintf(output, "    ");
    }

    if (isRight)
    {
        fprintf(output, "R----");
    }
    else 
    {
        fprintf(output, "L----");
    }

    if(node->type==INT_NODE_CONST)
    {
        fprintf(output, "INT: %d\n", node->val);
    }
    else if(node->type==ID_NODE_CONST)
    {
        fprintf(output, "ID: %s\n", node->varname);
    }
    else if(node->type==OP_NODE_CONST)
    {
        fprintf(output, "OP: %c\n", node->op);
    }
    else if(node->type==READ_NODE_CONST)
    {
        fprintf(output, "READ: %s\n", node->varname);
    }
    else if(node->type==WRITE_NODE_CONST)
    {
        fprintf(output, "WRITE: %s\n", node->varname);
    }
    else if(node->type==STATEMENT_NODE_CONST)
    {
        //printf("STATEMENT\n");
        fprintf(output, "OP: %c\n", node->op);

    }
    else if(node->type==ASSIGN_NODE_CONST)
    {
        fprintf(output, "ASSIGN\n");
    }
    else
    {
        fprintf(output, "unknown\n");
    }

    print_tree(node->left, lvl + 1, 1);
    print_tree(node->right, lvl + 1, 0);
}
void preorder(struct tnode *node)
{
    if (node == NULL) return;

    if (node->type == INT_NODE_CONST)
    {
        printf("INT: %d\n", node->val);
    }
    else if(node->type == ID_NODE_CONST)
    {
        printf("ID: %s\n", node->varname);
    }
    else if(node->type == OP_NODE_CONST)
    {
        printf("OP: %c\n", node->nodetype);
    }
    else if(node->type == READ_NODE_CONST)
    {
        printf("READ: %s\n", node->varname);
    }
    else if(node->type == WRITE_NODE_CONST)
    {
        printf("WRITE: %s\n", node->varname);
    }
    else if(node->type == STATEMENT_NODE_CONST)
    {
        printf("STATEMENT\n");
    }
    else if(node->type == ASSIGN_NODE_CONST)
    {
        printf("ASSIGN\n");
    }
    else
    {
        printf("unknown\n");
    }

    preorder(node->left);
    preorder(node->right);
}