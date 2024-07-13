#include <stdio.h>

int pow(int n, int exp) {
    if (exp == 0) return 1;

    return n * pow(n, exp - 1);
}

int main (int argc, char *argv[]) {
    int n = 10;
    printf("%d", pow(n, 5));

    return 0;
}