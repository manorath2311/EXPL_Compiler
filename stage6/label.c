#include "label.h"

lnode* head = NULL;
fnode* head2 = NULL;

lnode* createLabel(char* label, int addr)
{
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
void printLabels()
{
    lnode* temp = head;
    printf("Labels:\n");
    while(temp != NULL)
    {
        printf("Label: %s, Address: %d\n", temp->label, temp->address);
        temp = temp->next;
    }

    fnode* temp2 = head2;
    printf("Function Labels:\n");
    while(temp2 != NULL)
    {
        printf("Label: %s, Address: %d\n", temp2->label, temp2->address);
        temp2 = temp2->next;
    }
}