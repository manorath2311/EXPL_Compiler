extern FILE *intermediate;

void initialize() 
{
    intermediate = fopen("machinecode.xsm", "w");
    fprintf(intermediate, "0\n2056\n0\n0\n0\n0\n0\n0\n");
    fprintf(intermediate, "ADD SP, 26\n");
    fprintf(intermediate, "CALL MAIN\n");
    fprintf(intermediate, "MOV R0, 10\nPUSH R0\nINT 10\n");
}
FILE *stream;
int count = 0;
char* findKey(struct tnode*);
void typecheck(int t1, int t2, char c) 
{
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
char* num_to_char(int num) 
{
    int length = snprintf(NULL, 0, "%d", num);
    char *str = malloc(length + 1);
    snprintf(str, length + 1, "%d", num);
    return str;
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
            key=num_to_char(head->val);
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
struct tnode* createTree(int type, int val, int nodetype, char* name, struct tnode *l, struct tnode *r, struct tnode *mid) {
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