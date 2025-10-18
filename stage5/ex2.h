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
#define NODE_RET 24
#define NODE_FUNC 25

#define TYPE_VOID 0
#define TYPE_INT 1
#define TYPE_BOOL 2
#define TYPE_STR 3

union Constant{
    int intval;
    char* strval;
};
struct Gsymbol* Gtemp;
struct Lsymbol* Ltemp;
struct Paramstruct* Ptemp;

struct ASTNode{
    int type;                         //pointer to the type table entry
    int nodetype;                     //node type information,eg : NODETYPE_WHILE,NODETYPE_PLUS,NODETYPE_STMT etc
    char *name;                       //stores the variable/function name in case of variable/function nodes
    union Constant value;             //stores the value of the constant if the node corresponds to a constant
    struct ASTNode *arglist;          //pointer to the expression list given as arguments to a function call
    struct ASTNode *ptr1,*ptr2,*ptr3; //Subtrees of the node. (Maximum Subtrees for IF THEN ELSE)
    struct Gsymbol *Gentry;           //pointer to GST entry for global variables and functions
    struct Lsymbol *Lentry;           //pointer to the function's LST for local variables and arguments
};

struct ASTNode* TreeCreate(
    int type,
    int nodetype,
    char *name,
    union Constant *value,
    struct ASTNode *arglist,
    struct ASTNode *ptr1,
    struct ASTNode *ptr2,
    struct ASTNode *ptr3
);
	
/*To evaluate an expression tree*/
int codegen(struct ASTNode *t);
void initialize();
struct ASTNode* reverseList(struct ASTNode *t);

int declarationType;   // To pass variable type in yacc
int FDeclarationType;  // To pass variable type to functions in yacc
int totalCount = 4096;  // Memory address of next variable
int localBindingStart = 1;
int fLabelCount = 0;

struct Paramstruct {
    char *name;
    int type;
    struct Paramstruct *next;
};

struct Gsymbol{
    char *name;     //name of the variable or function
    int type;       //type of the variable:(Integer / String)
    int size;       //size of an array
    int binding;    //static binding of global variables
    struct Paramstruct *paramlist; //pointer to the head of the formal parameter list in the case of functions
    int flabel;     //a label for identifying the starting address of a function's code
    struct Gsymbol *next;   //points to the next Global Symbol Table entry
};

struct Lsymbol{
    char *name;     //name of the variable
    int type;       //type of the variable:(Integer / String)
    int binding;    //local binding of the variable
    struct Lsymbol *next;   //points to the next Local Symbol Table entry
};

 int yyerror(const char *s);
int checkAvailability(char *name, int global);
void assignType(struct ASTNode* node, int func);
void typecheck(int t1, int t2, char c);
struct Gsymbol* GLookup(char * name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
void GInstall(char *name, int type, int size, struct Paramstruct *paramlist); // Creates a symbol table entry.
struct Gsymbol *Ghead, *Gtail;

struct Lsymbol* LLookup(char *name);
void LInstall(char* name, int type);
struct Lsymbol *Lhead, *Ltail;

void PInstall(char* name, int type);
struct Paramstruct *Phead, *Ptail;

void printLSymbolTable(); // FOR TESTING
void printGSymbolTable(); // FOR TESTING