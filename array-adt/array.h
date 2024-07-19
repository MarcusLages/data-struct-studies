#ifndef ARRAY_C_
#define ARRAY_C_

typedef struct Array Array;

struct Array {
    int * A;
    int size;
    int length;
};

void display(Array arr);
int get(Array arr, int index);
void set(Array * pArr, int index, int num);
void add(Array * pArr, int num);
void insert(Array * pArr, int index, int num);
int delete(Array * pArr, int index);
double avg(Array arr);
int max(Array arr);
void increaseSize(Array * pArr, int increase);
int linearSearch(Array arr, int num);
int transposedLinearSearch(Array * pArr, int num);
int headLinearSearch(Array * pArr, int num);
int binarySearch(Array arr, int num);
int recursiveBinarySearch(Array arr, int low, int high, int num);
void reverseCopy(Array * pArr);
void reverseSub(Array * pArr);
void leftShift(Array * pArr, int steps);
void leftRotation(Array * pArr, int steps);
void rightShift(Array * pArr, int steps);
void rightRotation(Array * pArr, int steps);


#endif //ARRAY_C_