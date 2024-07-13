#include <stdio.h>

// Space: 0(n)
// Time: 0(n)
int sumUntil(int n) {
    if (n == 0) return 0;
    
    return n + sumUntil(n - 1);
}

// // Space: 0(1)
// // Time: 0(1)
// int sumUntil(int n) {
//     return n * (n + 1) / 2;
// }

int main() {
    printf("%d", sumUntil(4));
    return 0;
}