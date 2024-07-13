#include <stdio.h>
#include "numlist.h"

int main() {
    node *list = createList(5);
    
    printNodes(list);
    // printf("\nSize: %d", size(list));
    // printf("\n----------------\nValor do ultimo nodo: %d", getLastNode(list)->value);
    addNode(list, 45);
    addNode(list, 35);
    printNodes(list);
    // printf("\nSize: %d", size(list));
    // removeNode(list, 0);
    printNodes(list);
    // printf("\nSize: %d", size(list));

    return 0;
}