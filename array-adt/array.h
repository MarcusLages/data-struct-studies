#ifndef ARRAY_C_
#define ARRAY_C_

typedef struct Array Array;

struct Array {
    int * A;
    int size;
    int length;
};

void display(Array arr);
void add(Array * arr, int num);
void insert(Array * arr, int index, int num);
void increaseSize(Array * arr, int increase);

#endif //ARRAY_C_