#ifndef EX1_H
#define EX1_H
typedef struct tnode{
 int val; //value of the expression tree
 char *op; //indicates the opertor
 struct tnode *left,*right; //left and right branches
 }tnode;
	
struct tnode* makeLeafNode(int n);
struct tnode* makeOperatorNode(char c,struct tnode *l,struct tnode *r);
int evaluate(struct tnode *t);
void printprefix(struct tnode *t);
void printpostfix(struct tnode *t);
#endif