#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "array.h"

void display(Array arr) {
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

void increaseSize(Array * pArr, int increase) {
    pArr->size += increase;
    pArr->A = realloc(pArr->A, pArr->size * sizeof(int));
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