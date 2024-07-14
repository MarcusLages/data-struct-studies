#ifndef ARRAY_C_
#define ARRAY_C_

typedef struct Array Array;

struct Array {
    int * A;
    int size;
    int length;
};

void display(Array arr);
void add(Array * pArr, int num);
void insert(Array * pArr, int index, int num);
int delete(Array * pArr, int index);
void increaseSize(Array * pArr, int increase);
int linearSearch(Array * pArr, int num);
int transposedLinearSearch(Array * pArr, int num);
int headLinearSearch(Array * pArr, int num);

#endif //ARRAY_C_