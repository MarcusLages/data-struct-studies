#include <stdio.h>
#include "array.h"

void display(Array arr) {
    for(int i = 0; i < arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
}