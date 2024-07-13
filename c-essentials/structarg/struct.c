#include <stdio.h>

// * ARRAYS CAN BE PASSED AS STRUCTURES
struct Test{
    int A[2];   //sizeof() = sizeof(int) * 2
    int n;
};

int sum(struct Test s);

int main() {
    struct Test testStruct = {{0, 1}, 1};
    printf("%d", sum(testStruct));
    return 0;
}

int sum(struct Test s) {
    int sum = 0;
    for(int i = 0; i < s.n; i++) {
        sum += (s.A[0] + s.A[1]);
    }
    return sum;
}
