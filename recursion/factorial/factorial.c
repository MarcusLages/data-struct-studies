#include <stdio.h>

int factorial(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return n * factorial(n - 1);
}

int main (int argc, char *argv[]) {
    int n = 12;
    printf("%d", factorial(n));

    return 0;
}