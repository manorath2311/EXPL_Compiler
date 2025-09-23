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



void GInstall(char *name, int type, int size) 
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