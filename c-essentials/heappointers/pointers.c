#include <stdio.h>
#include <stdlib.h>

int main() {
    // array in the stack
    int A[5] = {0, 1, 2, 3, 4};
    int *pA;

    // declaring pointers to arrays
    pA = A;
    // or
    pA = &A[0];

    // for (int i = 0; i < sizeof(A) / sizeof(int); i++) {
    //     printf("%d ", pA[i]);   // dereferencing
    // }

    // USING HEAP FOR AN ARRAY
    int *pB;
    pB = (int *) malloc(5 * sizeof(int));
    pB[4] = 0;
    pB[3] = 1;
    pB[2] = 2;
    pB[1] = 3;
    pB[0] = 4;

    // you shouldnt use sizeof(pB) since you are using the size of the pointer
    // not the size of the array itself
    for (int i = 0; i < sizeof(pB) / sizeof(int); i++) {
        printf("%d ", pB[i]);   // dereferencing a heap array
    }

    free(pB);

    return 0;
}