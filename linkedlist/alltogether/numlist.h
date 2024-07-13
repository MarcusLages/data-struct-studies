#ifndef NUMLIST_H
#define NUMLIST_H

typedef struct node {
    int value;
    struct node *next;
} node;

node* createList(int initialValue);
node* getLastNode(node *head);
int size(node *head);
void printNodes(node *head);
void addNode(node *head, int value);
// void removeNode(node *head, int index);
// void freeAll(node *head);
#endif