#ifndef LABEL_HEADER_FILE
#define LABEL_HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct lnode {
    char* label;
    int address;
    struct lnode* next;
} lnode;

typedef struct fnode {
    char* label;
    int address;
    struct fnode* next;
} fnode;

lnode* createLabel(char* label, int addr);
fnode* createLabel_func(char *label,int addr);

int getLabelAddr(char* label);
int getLabelAddr_func(char* label);

#endif