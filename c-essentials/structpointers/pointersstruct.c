#include <stdio.h>
#include <stdlib.h>

struct Rectangle {
    int length;
    int height;
};

int main() {
    struct Rectangle r = {5, 10};
    struct Rectangle *pR;
    pR = &r;

    r.length = 2;
    (*pR).length = 3;
    // or
    pR->length = 5; // arrow notation for accessing the structure pointer attribute

    // HEAP STRUCTURE POINTER
    struct Rectangle *pHR;
    pHR = (struct Rectangle *) malloc(sizeof(struct Rectangle));

    free(pHR);
}