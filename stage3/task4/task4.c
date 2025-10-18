int counter = -1, i, j, label=0;
int whileStart = -1, whileEnd = -1;
extern FILE *intermediate;
extern FILE *intermediate2;

FILE *stream;
int count = 0;
int getlabel() 
{
    return ++label;
}
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

char* findKey(struct tnode*);
char * convert_to_char(int n) 
{
    char *str = (char *)malloc(10);
    sprintf(str, "%d", n);
    return str;
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

char* findKey(struct tnode* head) 
{
    char *key = malloc(10);
    switch(head->nodetype) 
    {
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
            key = convert_to_char(head->val);
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

struct tnode* createTree(int type, int val, int nodetype, char* name, struct tnode *l, struct tnode *r, struct tnode *mid) 
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
    temp->middle = mid;
    return temp;
}

void print_tree(struct tnode *root,int lvl,int position)
{
    if(root==NULL)
    {
        return;
    }
    for(int i=0;i<lvl;i++)
    {
        fprintf(stream," ");
    }
    if(position==-1)
    {
        fprintf(stream,"%d ",lvl);
        fprintf(stream,"L : ");
    }
    else if(position==0)
    {
        fprintf(stream,"%d ",lvl);
        fprintf(stream,"M : ");
    }
    else
    {
        fprintf(stream,"%d ",lvl);
        fprintf(stream,"R : ");
    }
    if(root->type==NODE_CONNECTOR)
    {
        print_tree(root->left,lvl+1,-1);
        print_tree(root->right,lvl+1,1);
        return;
    }
    if(root->type==NODE_IF_ELSE)
    {
        fprintf(stream," %s\n",findKey(root));
        print_tree(root->left,lvl+1,-1);
        print_tree(root->middle,lvl+1,0);
        print_tree(root->right,lvl+1,1);
        return;
    }
    fprintf(stream,"%s\n",findKey(root));
    print_tree(root->left,lvl+1,-1);
    print_tree(root->right,lvl+1,1);

    return;
}

int codegen(struct tnode* t) 
{
    int r1, r2, r3, l1, l2, number, status=0;
    int prevWhileStart, prevWhileEnd;

    if(t == NULL)
    {
        return -1;
    }
    else if(t->nodetype == NODE_CONNECTOR) 
    {
        codegen(t->left);
        codegen(t->right);
        return -1;
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
        case NODE_LT:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "LT R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_GT:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "GT R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_LE:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "LE R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_GE:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "GE R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_EQ:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "EQ R%d, R%d\n", r1, r2);
            freeReg();
            return r1;
        case NODE_NEQ:
            r1 = codegen(t->left);
            r2 = codegen(t->right);
            fprintf(intermediate, "NE R%d, R%d\n", r1, r2);
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
            {
                fprintf(intermediate, "PUSH R%d\n", i);
            }
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
            {
                fprintf(intermediate, "POP R%d\n", i);
            }
            counter = status;
            break;
        case NODE_READ:
            number = 4096 + t->left->varname[0] - 'a';
            for (i = 0; i <= counter; i++)
            {
                fprintf(intermediate, "PUSH R%d\n", i);
            }
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
            {
                fprintf(intermediate, "POP R%d\n", i);
            }
            counter = status;
            break;
        case NODE_WHILE:
            l1 = getlabel();
            l2 = getlabel();

            prevWhileStart = whileStart;
            prevWhileEnd = whileEnd;

            whileStart = l1;
            whileEnd = l2;
                     // Store old while start and end
            fprintf(intermediate, "L%d:\n", l1);
            r1 = codegen(t->left);
            fprintf(intermediate, "JZ R%d,L%d\n", r1, l2);
            freeReg();
            number = codegen(t->right);
            fprintf(intermediate, "JMP L%d\n", l1);
            fprintf(intermediate, "L%d:\n", l2);


            whileStart = prevWhileStart;
            whileEnd = prevWhileEnd;
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
        case NODE_BREAK:
            if(whileEnd != -1)
                fprintf(intermediate, "JMP L%d\n", whileEnd);
            break;
        case NODE_CONT:
            if(whileStart != -1)
                fprintf(intermediate, "JMP L%d\n", whileStart);
            break;
        case NODE_DOWHILE:
            r1 = codegen(t->right); 
            l1 = getlabel();
            l2 = getlabel();

       
            prevWhileStart = whileStart;
            prevWhileEnd = whileEnd;
     
            whileStart = l1;
            whileEnd = l2;

            fprintf(intermediate, "L%d:\n", l1);
            r1 = codegen(t->left);
            fprintf(intermediate, "JZ R%d,L%d\n", r1, l2);
            freeReg();
            number = codegen(t->right);
            fprintf(intermediate, "JMP L%d\n", l1);
            fprintf(intermediate, "L%d:\n", l2);

        
            whileStart = prevWhileStart;
            whileEnd = prevWhileEnd;
            freeReg();
            break;
        case NODE_REPEATUNTIL:
            r1 = codegen(t->right); 
            l1 = getlabel();
            l2 = getlabel();

       
            prevWhileStart = whileStart;
            prevWhileEnd = whileEnd;
     
            whileStart = l1;
            whileEnd = l2;

            fprintf(intermediate, "L%d:\n", l1);
            r1 = codegen(t->left);
            //fprintf(intermediate, "NOT R%d\n", r1);
            fprintf(intermediate, "JNZ R%d,L%d\n", r1, l2);
            freeReg();
            number = codegen(t->right);
            printf("hi\n");
            //fprintf(intermediate, "NOT R%d\n", r1);
            fprintf(intermediate,"JZ R%d,L%d\n",r1,l2);
            fprintf(intermediate, "JMP L%d\n", l1);
            fprintf(intermediate, "L%d:\n", l2);

        
            whileStart = prevWhileStart;
            whileEnd = prevWhileEnd;
            freeReg();
            break;
    }
}
int arr[52] = {0};
int iscapital(char *c) 
{
    return (*c >= 'A' && *c <= 'Z');
}

int getAddr(char *c) 
{
    if(iscapital(c))
    {
        return *c - 'A' + 26;
    }
    
    return *c - 'a';
}
int evaluate(struct tnode *t) 
{
    int addr, p, q;

    if (t == NULL) 
    {
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
        case NODE_LT:
            return evaluate(t->left) < evaluate(t->right);
        case NODE_GT:
            return evaluate(t->left) > evaluate(t->right);
        case NODE_LE:
            return evaluate(t->left) <= evaluate(t->right);
        case NODE_GE:
            return evaluate(t->left) >= evaluate(t->right);
        case NODE_EQ:
            return evaluate(t->left) == evaluate(t->right);
        case NODE_NEQ:
            return evaluate(t->left) != evaluate(t->right);
        case NODE_IF:
            p = evaluate(t->left);
            if (p) 
            {
                evaluate(t->right);
            }
            return -1;
        case NODE_IF_ELSE:
            p = evaluate(t->left);
            if (p) 
            {
                evaluate(t->middle);
            }
            else
            {
                evaluate(t->right);
            }
            return -1;
        case NODE_WHILE:
            p = evaluate(t->left);
            while (p) 
            {
                evaluate(t->right);
                p = evaluate(t->left);
            }
        
            return -1;
        default:
            return 0;
    }
}

int labels[100]={0};
int labcount = 0;
void changeLabels(FILE *fp) 
{
    char ch;
    int line = 1;
    
    //rewind(fp); 
    int cnt=0;
    while(ch=fgetc(fp)!=EOF)
    {
        cnt++;
    }
    printf("%d",cnt);
    // while ((ch = fgetc(fp)) != EOF) 
    // {
    //     if(ch=='L')
    //     {
    //         fprintf(intermediate2, "L");
    //     }
    //     if (ch == 'L') 
    //     {
    //         int label = 0;
    //         ch = fgetc(fp);
    //         while (isdigit(ch)) 
    //         {
    //             int num = ch - '0';
    //             label = label * 10 + num;
    //             ch = fgetc(fp);
    //         }
    //         if (ch == ':') 
    //         {
    //             labels[label] = 2 * (line - 1) + 2048;
    //             fprintf(intermediate2, "L%d:\n", labels[label]);
    //         }
    //     }
    //     if (ch == '\n')
    //     {
    //         line++;
    //     }
    // }
    fprintf(intermediate2, "done\n");
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