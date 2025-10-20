#include "label.h"

lnode* head = NULL;
fnode* head2 = NULL;

lnode* createLabel(char* label, int addr){
    lnode* node = (lnode*)malloc(sizeof(lnode));

    node->label = label;
    node->address = addr;

    node->next = head;
    head = node;
    return node;
}

int getLabelAddr(char* label)
{
    lnode* temp = head;

    while(temp != NULL)
    {
        if(strcmp(temp->label, label) == 0)
        {
            return temp->address;
        }
        temp = temp->next;
    }
    return -1;
}
fnode* createLabel_func(char* label, int addr)
{
    fnode* node = (fnode*)malloc(sizeof(fnode));

    node->label = label;
    node->address = addr;

    node->next = head2;
    head2 = node;
    return node;
}
int getLabelAddr_func(char *label)
{
    fnode* temp = head2;

    while(temp != NULL)
    {
        if(strcmp(temp->label, label) == 0)
        {
            return temp->address;
        }
        temp = temp->next;
    }
    return -1;
}