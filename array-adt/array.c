#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include "array.h"

static void swap(int * i, int * j) {
    if (*i != *j) {
        int temp = *i;
        *i = *j;
        *j = temp;
    }
}

void display(Array arr) {
    if (arr.length == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("----------\nSize = %d\nLength = %d\n", arr.size, arr.length);
    for(int i = 0; i < arr.length; i++)
        printf("%d ", arr.A[i]);

    printf("\n");
}

int get(Array arr, int index) {
    if (index >= arr.length || index < 0) {
        fprintf(stderr, "------------\n| ERROR: This index is not valid.\n------------\n", 52);
        return -1;
    }

    return arr.A[index];
}

void set(Array * pArr, int index, int num) {
    if (index >= pArr->length || index < 0) {
        fprintf(stderr, "------------\n| ERROR: This index is not valid.\n------------\n", 52);
        return;
    } 

    pArr->A[index] = num;
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

void sortedInsert(Array * pArr, int num) {
    if (!isSorted(*pArr)) {
        printf("This array is not sorted.\n");
        return;
    }

    if (pArr->length == pArr->size)
        increaseSize(pArr, 2);
    
    int i = pArr->length - 1;
    
    while(pArr->A[i] > num) {
        pArr->A[i + 1] = pArr->A[i];
        i--;
    }

    pArr->A[i + 1] = num;
    pArr->length++;
}

int delete(Array * pArr, int index) {
    if (index >= pArr->length || index < 0) {
        fprintf(stderr, "------------\n| ERROR: This index is not valid.\n------------\n", 52);
        return 0;
    }

    int element = pArr->A[index];
    for(int i = index; i < pArr->length - 1; i++)
        pArr->A[i] = pArr->A[i + 1];
    
    pArr->length--;

    return element;
}

double avg(Array arr) {
    int sum = 0;

    for(int i = 0; i < arr.length; i++) {
        sum += arr.A[i];
    }

    return (double) sum / arr.length;
}

int max(Array arr) {
    int max = arr.A[0];

    for(int i = 0; i < arr.length; i++) {
        if (arr.A[i] > max)
            max = arr.A[i];
    }

    return max;
}

void increaseSize(Array * pArr, int increase) {
    pArr->size += increase;
    pArr->A = realloc(pArr->A, pArr->size * sizeof(int));
}

// Reverses the array through an array copy
// O(2n)
void reverseCopy(Array * pArr) {
    int * copy;
    int i, j;
    copy = (int *) malloc(pArr->length * sizeof(int));

    for(i = 0, j = pArr->length - 1; i < pArr->length; i++, j--) {
        copy[i] = pArr->A[j];
    }

    for(i = 0; i < pArr->length; i++) {
        pArr->A[i] = copy[i];
    }
}

// Reverses the array through array substitution
// O(log[2]n)
void reverseSub(Array * pArr) {
    int i, j;

    for(i = 0, j = pArr->length - 1; i < j; i++, j--) {
        swap(&pArr->A[i], &pArr->A[j]);
    }
}

void leftShift(Array * pArr, int steps) {
    if(steps <= 0) return;
    for(int i = 0; i < pArr->length; i++) {
        if(i + steps >= pArr->length) {
            pArr->A[i] = 0;
        } else {
            pArr->A[i] = pArr->A[i + steps];
        }
    }
}

void leftRotation(Array * pArr, int steps) {
    if(steps <= 0 || steps % pArr->length == 0) return;

    Array copy = subArray(*pArr, 0, steps - 1);
    display(copy);
    leftShift(pArr, steps);

    for(int i = pArr->length - steps, j = 0; j < steps; i++, j++) {
        pArr->A[i] = copy.A[j];
    }

    free(copy.A);
    copy.A = NULL;
    copy.length = 0;
    copy.size = 0;
}

bool isSorted(Array arr) {
    if(arr.length == 0)
        return true;

    for(int i = 0; i < arr.length - 1; i++)
        if(arr.A[i] > arr.A[i + 1])
            return false;

    return true;
}

// Only for one element
int linearSearch(Array arr, int num) {
    for (int i = 0; i < arr.length; i++)
        if(arr.A[i] == num)
            return i;
            
    return -1;
}

// switches the found item with the previous one to reduce search
int transposedLinearSearch(Array * pArr, int num) {
    for (int i = 0; i < pArr->length; i++) {
        if(pArr->A[i] == num) {
            if (i > 0) {
                int temp = pArr->A[i];
                pArr->A[i] = pArr->A[i - 1]; 
                pArr->A[i - 1] = temp;
            }
            return i;
        }
    }    

    return -1;
}

// switches the found item with the first one to reduce search
int headLinearSearch(Array * pArr, int num) {
    for (int i = 0; i < pArr->length; i++) {
        if(pArr->A[i] == num) {
            if (i > 0) {
                int temp = pArr->A[i];
                pArr->A[i] = pArr->A[0]; 
                pArr->A[0] = temp;
            }
            return i;
        }
    }

    return -1;
}

// only for sorted lists
int binarySearch(Array arr, int num) {
    int low, high, mid;
    low = 0;
    high = arr.length;

    while (low <= high) {
        mid = (int) ceil((double) (high + low) / 2);
        if (num == arr.A[mid])
            return mid;
        else if (num < arr.A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
            
    return -1;
}

// recursive version of binary search
int recursiveBinarySearch(Array arr, int low, int high, int num) {
    if (low <= high) {
        int mid = (int) ceil((double) (high + low) / 2);
        if (num == arr.A[mid])
            return mid;
        else if (num < arr.A[mid])
            recursiveBinarySearch(arr, low, mid - 1, num);
        else
            recursiveBinarySearch(arr, mid + 1, high, num);
    } else    
        return -1;
}

// Creates a sub array
Array subArray(Array arr, int start, int finish) {
    if (start < 0 ||
        start >= arr.length ||
        finish >= arr.length ||
        start > finish) {
        printf("\nSub array could not be created.\n");
        Array nullArr = {NULL, 0, 0};
        return nullArr;
    }

    Array subArr;
    subArr.length = finish - start + 1;
    subArr.size = subArr.length;
    
    // Using memcpy
    // ! To use memcpy you still need to initialize the array in the heap
    subArr.A = (int *) malloc(subArr.size * sizeof(int));
    memcpy(subArr.A, arr.A + start, subArr.size * sizeof(int));

    // Not using memcpy
    // for(int i = start, sub = 0; i <= finish; i++, sub++) {
    //     subArr.A[sub] = arr.A[i];
    // }

    return subArr;
}

void copy(Array * pDestArr, Array srcArr) {
    if (pDestArr != NULL) {
        free(pDestArr->A);
        pDestArr->A = NULL;
    }

    pDestArr->length = srcArr.length;
    pDestArr->size = srcArr.size;
    pDestArr->A = (int *) malloc(srcArr.size * sizeof(int));
    mempcpy(pDestArr->A, srcArr.A, srcArr.size * sizeof(int));
}

bool compare(Array arr1, Array arr2) {
    if (arr1.length != arr2.length)
        return false;

    for(int i = 0; i < arr1.length; i++)
        if (arr1.A[i] != arr2.A[i])
            return false;
    
    return true;
}

void append(Array * pUpdatedArr, Array appendArr);
Array concat(Array pUpdatedArr, Array appendArr);
Array merge(Array pUpdatedArr, Array appendArr);

void rightShift(Array * pArr, int steps);
void rightRotation(Array * pArr, int steps);