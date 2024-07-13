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
    arr.size = 3;
    arr.length = 3;
    arr.A = (int *) malloc(arr.size * sizeof(int));
    arr.A[0] = 1;
    arr.A[1] = 2;
    arr.A[2] = 3;
    display(arr);
    
    // add(&arr, 4);
    // display(arr);

    insert(&arr, 0, 7);
    insert(&arr, 0, 7);
    insert(&arr, 0, 7);
    display(arr);

    return 0;
}