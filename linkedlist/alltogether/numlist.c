#include <stdio.h>
#include <stdlib.h>
#include "numlist.h"

node* createList(int initialValue) {
    node *head = (node *) malloc(sizeof(node));
    head->value = initialValue;
    head->next = NULL;
    return head;
};

node* getLastNode(node *head) {
    if(head == NULL) return NULL;

    node *current = head;

    while(current->next != NULL) {
        current = current->next;
    }

    return current;
}

int size(node *head) {
    if(head == NULL) return 0;
    
    node *current = head;
    int size = 1;

    while(current->next != NULL) {
        current = current->next;
        size++;
    }

    return size;
}

void printNodes(node *head) {
    if(head == NULL) printf("The list is empty");

    node *current = head;
    printf("\n-------------");
    
    while (current->next != NULL) {
        printf("\nNumber: %d\nAddress: %p", current->value, current);
        current = current->next;
    }

    printf("\nNumber: %d\nAddress: %p\n-------------\n", current->value, current);
}

void addNode(node *head, int value) {
    if(head == NULL) return;

    // * The asterisk is related to the var, so for every new var
    // * an asterisk is necessary
    node *last, *newNode;
    last = getLastNode(head);
    newNode = (node *) malloc(sizeof(node));

    newNode->value = value;
    newNode->next = NULL;

    last->next = newNode;
}

// void removeNode(node *head, int index) {
//     if(head == NULL) return;

//     int curIndex = 0;
//     node *current, *previous;
//     current = head;
//     previous = NULL;

//     while (current->next != NULL && curIndex < index) {
//         previous = current;
//         current = current->next;
//         curIndex++;
//     }

//     if(current->next == NULL && curIndex < index) {
//         printf("Index out of bounds.");
//         return;
//     } else {
//         if (previous != NULL) {
//             previous->next = current->next;
//         }
//         free(current);
//         current = NULL;
//     }
// }

// void freeAll(node *head) {
//     if(head == NULL) return;
    
//     node *current, *previous;
//     current = head;
//     previous = NULL;
    
//     while(current->next != NULL) {
//         previous = current;
//         current = current->next;
//         free(previous);
//         previous = NULL;
//     }

//     free(current);
//     current = NULL;
// }