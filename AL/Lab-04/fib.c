#include <stdio.h>

int OpCount = 0;

int fibonacci(int n) {
    OpCount++;
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);
    int result = fibonacci(n);
    printf("Fibonacci(%d) = %d\n", n, result);
    printf("Total number of operations: %d\n", OpCount);
    return 0;
}
