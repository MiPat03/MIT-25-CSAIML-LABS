#include <stdio.h>

#define MAX_N 100
#define MAX_W 1000

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n) {
    int i, w, K[MAX_N + 1][MAX_W + 1];
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (wt[i - 1] <= w)
                K[i][w] = max(val[i - 1] + K[i - 1][w - wt[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }
    return K[n][W];
}

int main() {
    int val[MAX_N], wt[MAX_N], W, n, i;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weights and values of the %d items:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d %d", &wt[i], &val[i]);
    }
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &W);
    printf("Maximum value that can be put in a knapsack of capacity %d: %d\n", W, knapSack(W, wt, val, n));
    return 0;
}
