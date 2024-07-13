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

void add(Array * arr, int num) {
    if (arr->length < arr->size) {
        arr->length++;
        arr->A[arr->length - 1] = num;
    } else {
        increaseSize(arr, 2);
        arr->length++;
        arr->A[arr->length - 1] = num;
    }
}

void increaseSize(Array * arr, int increase) {
    arr->size += increase;
    arr = realloc(arr->A, arr->size * sizeof(int));
}