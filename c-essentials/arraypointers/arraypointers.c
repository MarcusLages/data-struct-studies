#include <stdio.h>
#include <stdlib.h>

int* fill(int, int);

int main() {
    int *pA;
    pA = fill(5, 8);

    for (int i = 0; i < 5; i++)
        printf("%d ", pA[4]);

    free(pA);

    return 0;
}

int* fill(int size, int number) {
    int *pArray;
    pArray = (int *) malloc(size * sizeof(int));

    for(int i = 0; i < size; i++) {
        pArray[i] = number;
    }

    return pArray;
}