#define NODE_CONNECTOR 0
#define NODE_PLUS 1
#define NODE_MINUS 2
#define NODE_MUL 3
#define NODE_DIV 4
#define NODE_MOD 23
#define NODE_ID 5
#define NODE_NUM 6
#define NODE_ASSGN 7
#define NODE_READ 8
#define NODE_WRITE 9
#define NODE_IF 10
#define NODE_IF_ELSE 11
#define NODE_WHILE 12
#define NODE_LT 13
#define NODE_GT 14
#define NODE_LE 15
#define NODE_GE 16
#define NODE_EQ 17
#define NODE_NEQ 18
#define NODE_BREAK 19
#define NODE_CONT 20
#define NODE_STRVAL 21
#define NODE_ARRAY 22

#define TYPE_VOID 0
#define TYPE_INT 1
#define TYPE_BOOL 2
#define TYPE_STR 3

struct tnode
{
    int val;
    int type;
    char* varname;
    int nodetype;
    struct Gsymbol *Gentry;
    struct tnode *left, *middle, *right;
};

struct tnode* createTree(int type, int val, int nodetype, char* name, struct tnode *l, struct tnode *r, struct tnode *mid);

int codegen(struct tnode *t);
void initialize();

int declaration_type;
//int totalCount = 4096;

struct Gsymbol
{
    char* name;
    int type;
    int size;
    int binding;
    struct Gsymbol *next;
};

struct Gsymbol* GLookup(char * name);
void GInstall(char *name, int type, int size);
void printSymbolTable();
struct Gsymbol *Ghead, *Gtail;
