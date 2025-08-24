typedef struct tnode 
{ 
	int val;	// value of a number for NUM nodes.
	int type;	//type of variable
	char* varname;	//name of a variable for ID nodes  
	int nodetype;  // information about non-leaf nodes - read/write/connector/+/* etc.  
	struct tnode *left,*right;	//left and right branches   
	char op;
}tnode;

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
