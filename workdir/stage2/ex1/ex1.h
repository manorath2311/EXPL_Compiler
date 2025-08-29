
/*Create a node tnode*/
//struct tnode* createTree(int val, int type, char* c, struct tnode *l, struct tnode *r);

struct tnode *makeConstantNode(int type, int val);
struct tnode *makeVariableNode(int type, char* varname);
struct tnode *makeExprNode(int type, char op, struct tnode *left, struct tnode *right);
struct tnode *makeStmtNode(int type, struct tnode *left, struct tnode *right);

void print_tree(struct tnode *, int lvl, int isRight);

#define ID_NODE_CONST 1
#define INT_NODE_CONST 2
#define OP_NODE_CONST 3
#define READ_NODE_CONST 4
#define WRITE_NODE_CONST 5
#define STATEMENT_NODE_CONST 6
#define ASSIGN_NODE_CONST 7

int getreg();
void freereg();
//int counter=-1;
#define NODE_CONNECTOR 0
#define NODE_PLUS 1
#define NODE_MINUS 2
#define NODE_MUL 3
#define NODE_DIV 4
#define NODE_ID 5
#define NODE_NUM 6
#define NODE_ASSGN 7
#define NODE_READ 8
#define NODE_WRITE 9

typedef struct tnode{
    int val; //value of the expression tree
    int type; //type of variable
    char* varname; //Name of variable for ID names
    int nodetype; //Information of non-leaf nodes. Ex NODE_PLUS
    struct tnode *left,*right; //left and right branches
}tnode;
	
/*Create a node tnode*/
struct tnode* createTree(int type, int val, int nodetype, char* name, struct tnode *l, struct tnode *r);
	
/*To evaluate an expression tree*/
//int evaluate(struct tnode *t);
int codegen(struct tnode *t);
void initialize();
int iscapital(char *c);