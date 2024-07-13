#include <stdio.h>

int fib(int n) {
    if (n <= 1) return n;

    return fib(n - 2) + fib(n - 1);
} 

int main (int argc, char *argv[]) {
    int n = 4;
    printf("%d", fib(n));
    return 0;
}