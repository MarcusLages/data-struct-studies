#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void display(Array arr) {
    printf("----------\nSize = %d\nLength = %d\n", arr.size, arr.length);
    for(int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
    printf("\n");
}

void add(Array * pArr, int num) {
    if (pArr->length == pArr->size)
        increaseSize(pArr, 2);

    pArr->A[pArr->length] = num;
    pArr->length++;
}

void insert(Array * pArr, int index, int num) {
    if (index >= pArr->length || index < 0) {
        fprintf(stderr, "------------\n| ERROR: This index is not valid.\n------------\n", 52);
        return;
    }

    if (pArr->length == pArr->size)
        increaseSize(pArr, 2);
    
    for(int i = pArr->length - 1; i >= index; i--)
        pArr->A[i + 1] = pArr->A[i];
    pArr->A[index] = num;
    pArr->length++;
}

int delete(Array * pArr, int index) {
    if (index >= pArr->length || index < 0) {
        fprintf(stderr, "------------\n| ERROR: This index is not valid.\n------------\n", 52);
        return 0;
    }

    int element = pArr->A[index];
    for(int i = index; i < pArr->length - 1; i++) {
        pArr->A[i] = pArr->A[i + 1];
    }
    
    pArr->length--;

    return element;
}

void increaseSize(Array * pArr, int increase) {
    pArr->size += increase;
    pArr->A = realloc(pArr->A, pArr->size * sizeof(int));
}

// Only for one element
int linearSearch(Array * pArr, int num) {
    for (int i = 0; i < pArr->length; i++)
        if(pArr->A[i] == num)
            return i;
            
    return -1;
}

int transposedLinearSearch(Array * pArr, int num) {
    for (int i = 0; i < pArr->length; i++)
        if(pArr->A[i] == num) {
            if (i > 0) {
                int temp = pArr->A[i];
                pArr->A[i] = pArr->A[i - 1]; 
                pArr->A[i - 1] = temp;
            }
            return i;
        }
            
    return -1;
}