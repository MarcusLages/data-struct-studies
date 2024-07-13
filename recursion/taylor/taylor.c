#include <stdio.h>

int factorial(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return n * factorial(n - 1);
}

int powExp(int n, int exp) {
    if (exp == 0) return 1;

    return n * powExp(n, exp - 1);
}

double e(int power, int reps) {
    if(reps == 0) return 1;

    return ((double) powExp(power, reps) / factorial(reps)) + e(power, reps - 1);
}

int main (int argc, char *argv[]) {
    int p = 2;
    int r = 10;
    printf("%lf", e(p, r));
    return 0;
}