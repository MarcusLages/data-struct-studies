#ifndef ARRAY_C_
#define ARRAY_C_

#include <stdbool.h>

typedef struct Array Array;

struct Array {
    int * A;
    int size;
    int length;
};

// Display
void display(Array arr);

// Item handling
int get(Array arr, int index);
void set(Array * pArr, int index, int num);
void add(Array * pArr, int num);
void insert(Array * pArr, int index, int num);
void sortedInsert(Array * pArr, int num);
int delete(Array * pArr, int index);

// Return item properties
double avg(Array arr);
int max(Array arr);

// List handling
void increaseSize(Array * pArr, int increase);
void reverseCopy(Array * pArr);
void reverseSub(Array * pArr);
void leftShift(Array * pArr, int steps);
void leftRotation(Array * pArr, int steps);
void rightShift(Array * pArr, int steps);
void rightRotation(Array * pArr, int steps);
void negNumOnLeft(Array * pArr);

// Sorting
bool isSorted(Array arr);

// Searching
int linearSearch(Array arr, int num);
int transposedLinearSearch(Array * pArr, int num);
int headLinearSearch(Array * pArr, int num);
int binarySearch(Array arr, int num);
int recursiveBinarySearch(Array arr, int low, int high, int num);

// Binary or subarray operations
Array subArray(Array arr, int start, int finish);
void copy(Array * pArr, Array copiedArray);
bool compare(Array arr1, Array arr2);
void append(Array * pUpdatedArr, Array appendArr);
Array concat(Array pUpdatedArr, Array appendArr);
Array merge(Array pUpdatedArr, Array appendArr);

#endif //ARRAY_C_