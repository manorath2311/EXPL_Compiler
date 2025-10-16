#include <stdio.h>
#include <stdlib.h>
#include "ex2.h"

#define MAX_REGS 20
static int reg_used[MAX_REGS];

void initializeRegs()
{
    for(int i=0;i<MAX_REGS;i++)
    {
        reg_used[i]=0;
    }
}

int getReg(void)
{
    for(int i=0;i<MAX_REGS;i++)
    {
        if(reg_used[i]==0)
        {
            reg_used[i]=1;
            return i;
        }
    }
    fprintf(stderr,"Out of registers\n");
    exit(1);
}

void freeReg(void)
{
    for(int i=MAX_REGS-1;i>=0;i--)
    {
        if(reg_used[i]==1)
        {
            reg_used[i]=0;
            return;
        }
    }
    return;
}

tnode* makeLeafNode(int n)
{
    tnode *temp = (tnode*)malloc(sizeof(tnode));
    if(!temp) { perror("malloc"); exit(1); }
    temp->op = '\0';
    temp->val = n;
    temp->left = temp->right = NULL;
    return temp;
}

tnode* makeOperatorNode(char c, tnode *l, tnode *r)
{
    tnode *temp = (tnode*)malloc(sizeof(tnode));
    if(!temp) { perror("malloc"); exit(1); }
    temp->op = c;
    temp->left = l;
    temp->right = r;
    return temp;
}
int generateCode(struct tnode *node, FILE *outFile)
{
    if (node->left == NULL && node->right == NULL) 
    {
        int regIndex = getReg();
        fprintf(outFile, "MOV R%d, %d\n", regIndex, node->val);
        return regIndex;
    }

    int leftReg  = generateCode(node->left, outFile);
    int rightReg = generateCode(node->right, outFile);

    switch (node->op) 
    {
        case '+':
            fprintf(outFile, "ADD R%d, R%d\n", leftReg, rightReg);
            break;
        case '-':
            fprintf(outFile, "SUB R%d, R%d\n", leftReg, rightReg);
            break;
        case '*':
            fprintf(outFile, "MUL R%d, R%d\n", leftReg, rightReg);
            break;
        case '/':
            fprintf(outFile, "DIV R%d, R%d\n", leftReg, rightReg);
            break;
        default:
            fprintf(stderr, "Error: Unsupported operator '%c'\n", node->op);
            exit(1);
    }

    freeReg();
    return leftReg;
}
