#ifndef ARRAY_C_
#define ARRAY_C_

typedef struct Array Array;

struct Array {
    int * A;
    int size;
    int length;
};

void display(Array arr);

#endif //ARRAY_C_