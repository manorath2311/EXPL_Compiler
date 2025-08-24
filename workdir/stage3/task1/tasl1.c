struct tnode *makeConstantNode(int type, int val)
{
    struct tnode *new_node = (struct tnode *)malloc(sizeof(struct tnode));
   new_node->val=val;
   new_node->type = type;
   new_node->left=NULL;
   new_node->right=NULL;

   return new_node;

}

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
        printf("    ");
    }

    if (isRight)
    {
        printf("R----");
    }
    else 
    {
        printf("L----");
    }

    if(node->type==INT_NODE_CONST)
    {
        printf("INT: %d\n", node->val);
    }
    else if(node->type==ID_NODE_CONST)
    {
        printf("ID: %s\n", node->varname);
    }
    else if(node->type==OP_NODE_CONST)
    {
        printf("OP: %c\n", node->op);
    }
    else if(node->type==READ_NODE_CONST)
    {
        printf("READ: %s\n", node->varname);
    }
    else if(node->type==WRITE_NODE_CONST)
    {
        printf("WRITE: %s\n", node->varname);
    }
    else if(node->type==STATEMENT_NODE_CONST)
    {
        //printf("STATEMENT\n");
        printf("OP: %c\n", node->op);

    }
    else if(node->type==ASSIGN_NODE_CONST)
    {
        printf("ASSIGN\n");
    }
    else
    {
        printf("unknown\n");
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
struct tnode* createTree(int type, int val, int nodetype, char* name, struct tnode *l, struct tnode *r, struct tnode *mid) 
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
    return temp;
}

FILE *stream;
int count = 0;
char* findKey(struct tnode*);

void print_dot_aux(struct tnode* node) 
{
    static int nullcount = 0;
    count += 1;
    int temp = count;

    if (node->left) {
        fprintf(stream, "    \"%d.%s\" -> \"%d.%s\";\n", temp, findKey(node), count + 1, findKey(node->left));
        print_dot_aux(node->left);
    }

    if (node->middle) {
        fprintf(stream, "    \"%d.%s\" -> \"%d.%s\";\n", temp, findKey(node), count + 1, findKey(node->middle));
        print_dot_aux(node->middle);
    }

    if (node->right) {
        fprintf(stream, "    \"%d.%s\" -> \"%d.%s\";\n", temp, findKey(node), count + 1, findKey(node->right));
        print_dot_aux(node->right);
    }
}

void print_dot(struct tnode* tree) 
{
    stream = fopen("temp.dot", "w");
    fprintf(stream, "digraph BST {\n");
    fprintf(stream, "    node [fontname=\"Arial\"];\n");

    if (!tree)
        fprintf(stream, "\n");
    else if (!tree->right && !tree->left)
        fprintf(stream, "    %s;\n", findKey(tree));
    else
        print_dot_aux(tree);
    fprintf(stream, "}\n");

    fclose(stream);
}

char* findKey(struct tnode* head) 
{
    char *key = malloc(10);
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
            strcpy(key, head->varname);
            break;
        case NODE_NUM:
            strcpy(key, head->val);
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
    }
    return key;        
}