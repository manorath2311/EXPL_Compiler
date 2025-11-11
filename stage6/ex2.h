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
#define NODE_FIELD 26
#define NODE_NULL 27
#define NODE_ALLOC 28
#define NODE_FREE 29
#define NODE_INIT 30

union Constant{
    int intval;
    char* strval;
};

struct Typetable{
    char *name;                 //type name
    int size;                   //size of the type
    struct Fieldlist *fields;   //pointer to the head of fields list
    struct Typetable *next;     // pointer to the next type table entry
};

struct Fieldlist{
    char *name;              //name of the field
    int fieldIndex;          //the position of the field in the field list
    struct Typetable *type;  //pointer to type table entry of the field's type
    struct Fieldlist *next;  //pointer to the next field
};

struct Paramstruct {
    char *name;
    struct Typetable *type;       //type of the variable:(Integer / String)
    struct Paramstruct *next;
};

struct Gsymbol{
    char *name;     //name of the variable or function
    struct Typetable *type;       //type of the variable:(Integer / String)
    int size;       //size of an array
    int binding;    //static binding of global variables
    struct Paramstruct *paramlist; //pointer to the head of the formal parameter list in the case of functions
    int flabel;     //a label for identifying the starting address of a function's code
    struct Gsymbol *next;   //points to the next Global Symbol Table entry
};

struct Lsymbol{
    char *name;     //name of the variable
    struct Typetable *type;       //type of the variable:(Integer / String)
    int binding;    //local binding of the variable
    struct Lsymbol *next;   //points to the next Local Symbol Table entry
};

struct ASTNode{
    struct Typetable *type;                         //pointer to the type table entry
    int nodetype;                     //node type information,eg : NODETYPE_WHILE,NODETYPE_PLUS,NODETYPE_STMT etc
    char *name;                       //stores the variable/function name in case of variable/function nodes
    union Constant value;             //stores the value of the constant if the node corresponds to a constant
    struct ASTNode *arglist;          //pointer to the expression list given as arguments to a function call
    struct ASTNode *ptr1,*ptr2,*ptr3; //Subtrees of the node. (Maximum Subtrees for IF THEN ELSE)
    struct Gsymbol *Gentry;           //pointer to GST entry for global variables and functions
    struct Lsymbol *Lentry;           //pointer to the function's LST for local variables and arguements
};

extern struct Gsymbol* Gtemp;
extern struct Lsymbol* Ltemp;
extern struct Paramstruct* Ptemp;

int checkAvailability(char *name, int global);
void assignType(struct ASTNode* node, int func);
void assignTypeField(struct ASTNode* node, struct Fieldlist *fields);
void typecheck(struct Typetable *t1,struct Typetable *t2, char c);

void error(const char *s,const char *var);
void yyerror(char const *s);
struct ASTNode* TreeCreate(
    struct Typetable *type,
    int nodetype,
    char *name,
    union Constant *value,
    struct ASTNode *arglist,
    struct ASTNode *ptr1,
    struct ASTNode *ptr2,
    struct ASTNode *ptr3
);

int codegen(struct ASTNode *t);
void initialize();
char* findKey(struct ASTNode*);
struct ASTNode* reverseList(struct ASTNode *t);
struct ASTNode* insertFieldId(struct ASTNode *field, struct ASTNode *id);
extern struct ASTNode* tempASTNode;

extern int totalCount;  // Memory address of next variable
extern int localBindingStart;
extern int fLabelCount;

struct Typetable *TLookup(char *name);
void TInstall(char *name, struct Fieldlist *fields);
extern struct Typetable *Thead, *Ttail;
extern struct Typetable *declarationType;   // To pass variable type in yacc
extern struct Typetable *FDeclarationType;  // To pass variable type to functions in yacc

struct Fieldlist *FLookup(char *name, struct Fieldlist *list);
void FInstall(char *name, struct Typetable *type);
extern struct Fieldlist *Fhead, *Ftail;

void PInstall(char* name, struct Typetable *type);
extern struct Paramstruct *Phead, *Ptail;

struct Gsymbol* GLookup(char * name); // Returns a pointer to the symbol table entry for the variable, returns NULL otherwise.
void GInstall(char *name, struct Typetable *type, int size, struct Paramstruct *paramlist); // Creates a symbol table entry.
extern struct Gsymbol *Ghead, *Gtail;

struct Lsymbol* LLookup(char *name);
void LInstall(char* name, struct Typetable *type);
extern struct Lsymbol *Lhead, *Ltail;


void printLSymbolTable(char* name);   // FOR TESTING
void printGSymbolTable();   // FOR TESTING
void printTypeTable();      // FOR TESTING