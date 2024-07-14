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
void add(Array * pArr, int num);
void insert(Array * pArr, int index, int num);
int delete(Array * pArr, int index);
void increaseSize(Array * pArr, int increase);
int linearSearch(Array arr, int num);
int transposedLinearSearch(Array * pArr, int num);
int headLinearSearch(Array * pArr, int num);
int binarySearch(Array arr, int num);
int recursiveBinarySearch(Array arr, int low, int high, int num);

#endif //ARRAY_C_