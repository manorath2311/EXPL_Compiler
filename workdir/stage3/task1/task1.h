typedef struct tnode 
{ 
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	struct tnode *left,*right,*middle;	//left and right branches   
	char op;
}tnode;

//struct tnode* createTree(int val, int type, char* c, struct tnode *l, struct tnode *r);

struct tnode *makeConstantNode(int type, int val);
struct tnode *makeVariableNode(int type, char* varname);
struct tnode *makeExprNode(int type, char op, struct tnode *left, struct tnode *right);
struct tnode *makeStmtNode(int type, struct tnode *left, struct tnode *right);
struct tnode* createTree(int type, int val, int nodetype, char* name, struct tnode *l, struct tnode *r, struct tnode *mid) ;
void print_tree(struct tnode *, int lvl, int isRight);

#define ID_NODE_CONST 1
#define INT_NODE_CONST 2
#define OP_NODE_CONST 3
#define READ_NODE_CONST 4
#define WRITE_NODE_CONST 5
#define STATEMENT_NODE_CONST 6
#define ASSIGN_NODE_CONST 7

#define PLUS_NODE_CONST 8
#define MINUS_NODE_CONST 9
#define MUL_NODE_CONST 10
#define DIV_NODE_CONST 11

#define TYPE_INT_NODE_CONST 12
#define TYPE_BOOL_NODE_CONST 13
#define TYPE_VOID_NODE_CONST 24
#define TYPE_VOID 24

#define IF_NODE_CONST 14
#define WHILE_NODE_CONST 15
#define ELSE_NODE_CONST 16
#define IF_ELSE_NODE_CONST 17

#define LT_NODE_CONST 18
#define GT_NODE_CONST 19
#define LE_NODE_CONST 20
#define GE_NODE_CONST 21
#define NE_NODE_CONST 22
#define EQ_NODE_CONST 23

#define NODE_CONNECTOR 25