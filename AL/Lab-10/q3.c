//Knapsack
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int W, int wt[], int val[], int n, int K[][W + 1]) {
    int i, w;
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

void printTable(int W, int wt[], int n, int K[][W+1]) {
   int i, j;
   printf("Weight vs Item Table:\n");
   printf("   ");
   for (i = 0; i <= W; i++) {
      printf("%2d ", i);
   }
   printf("\n");
   for (i = 0; i <= n; i++) {
      if(i == 0) {
         printf(" 0 ");
      } else {
         printf("%2d ", wt[i-1]);
      }
      for (j = 0; j <= W; j++) {
         printf("%2d ", K[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}


int main() {
    int val[] = {10, 15, 40};
    int wt[] = {1, 2, 3};
    int W = 6;
    int n = sizeof(val) / sizeof(val[0]);
    int K[n + 1][W + 1];
    printf("Maximum value that can be put in a knapsack of capacity %d: %d\n", W, knapSack(W, wt, val, n, K));
    printTable(W, wt, n, K);
    return 0;
}
modify this code such that inputs are taken from user