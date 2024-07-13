#include <stdio.h>

struct Rectangle {
    int length;
    int height;
};

void initialize(struct Rectangle *pR, int length, int height);

double area(struct Rectangle R);

void changeLength(struct Rectangle *pR, int length);

int main() {
    struct Rectangle r;

    initialize(&r, 2, 2);
    
    double area1 = area(r);
    printf("%lf", area1);
    
    changeLength(&r, 4);
    
    area1 = area(r);
    printf("%lf", area1);

    return 0;
}

void initialize(struct Rectangle *pR, int length, int height) {
    pR->height = height;
    pR->length = length;
}

double area(struct Rectangle R) {
    return (double) R.height * R.length;
}

void changeLength(struct Rectangle *pR, int length) {
    pR->length = length;
}
