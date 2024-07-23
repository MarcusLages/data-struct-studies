#include <stdio.h>
#include <stdlib.h>
#include "array.h"

void inputArray(Array * arr);
void display(Array arr);

void inputArray(Array * arr) {
    int number;

    printf("Please enter the size of the array: ");
    scanf("%d", &arr->size);

    arr->A = (int *) malloc(arr->size * sizeof(int));

    do {
        printf("How many numbers are you going to enter? ");
        scanf("%d", &number);
    } while(number > arr->size);

    arr->length = number;
    
    for(int i = 0; i < arr->length; i++) {
        printf("Please input the number %d: ", i + 1);
        scanf("%d", &arr->A[i]);
    }

}

int main (int argc, char *argv[]) {
    Array arr;

    // inputArray(&arr);
    arr.size = 6;
    arr.length = 6;
    arr.A = (int *) malloc(arr.size * sizeof(int));
    arr.A[0] = 1;
    arr.A[1] = 2;
    arr.A[2] = 3;
    arr.A[3] = 4;
    arr.A[4] = 5;
    arr.A[5] = 6;
    display(arr);
    
    // add(&arr, 4);
    // display(arr);

    // insert(&arr, 10, 7);
    // insert(&arr, 0, 7);
    // insert(&arr, 0, 7);
    // display(arr);

    // int x = delete(&arr, 0);
    // x = delete(&arr, 10);
    // display(arr);

    // printf("\n3 is in index: %d\n", linearSearch(&arr, 3));
    // display(arr);

    // printf("\n3 is in index: %d\n", transposedLinearSearch(&arr, 3));
    // display(arr);

    // printf("\n3 is in index: %d\n", headLinearSearch(&arr, 3));
    // display(arr);

    // printf("\n5 is in index: %d\n", binarySearch(&arr, 5));
    // display(arr);
    
    // printf("\n2 is in index: %d\n", recursiveBinarySearch(&arr, 0, arr.length, 2));
    // display(arr);

    // printf("\n12 is in index: %d\n", recursiveBinarySearch(&arr, 0, arr.length, 12));
    // display(arr);

    // printf("Element at index 3: %d", get(arr, 3));

    // set(&arr, 2, 13);
    // display(arr);

    // printf("The average of the items in the array is: %.2lf", avg(arr));
    // printf("The max of the items in the array is: %d", max(arr));

    // printf("Array sorted? %d\n", isSorted(arr));

    // sortedInsert(&arr, 7);
    // display(arr);

    // reverseCopy(&arr);
    // reverseSub(&arr);
    // display(arr);

    // leftShift(&arr, 3);
    // display(arr);

    // Array sub = subArray(arr, 2, 4);
    // display(sub);

    // leftRotation(&arr, 5);
    // display(arr);

    // printf("Array sorted? %d\n", isSorted(arr));

    Array copiedArray;
    copy(&copiedArray, arr);
    printf("Original array:\n");
    display(arr);
    printf("Copied array:\n");
    display(copiedArray);

    return 0;
}