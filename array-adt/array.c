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

    pArr->length++;
    pArr->A[pArr->length - 1] = num;
}

void insert(Array * pArr, int index, int num) {
    if (index >= pArr->length && index < 0) {
        fprintf(stderr, "This index is not valid.\n", 25);
        return;
    }

    if (pArr->length == pArr->size)
        increaseSize(pArr, 2);
    
    pArr->length++;
    for(int i = pArr->length - 2; i >= index; i--)
        pArr->A[i + 1] = pArr->A[i];
    pArr->A[index] = num;
}

void increaseSize(Array * pArr, int increase) {
    pArr->size += increase;
    pArr->A = realloc(pArr->A, pArr->size * sizeof(int));
}