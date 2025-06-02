#include <stdio.h>


int max(int a, int b) {
    return (a > b) ? a : b;
}


int knapsack(int W, int weights[], int values[], int n) {
    
    int dp[n+1][W+1];

        for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            }
             else if (weights[i-1] <= w) {
                  dp[i][w] = max(dp[i-1][w], values[i-1] + dp[i-1][w-weights[i-1]]);
            }
            else {
                dp[i][w] = dp[i-1][w];
            }
        }
    }

   return dp[n][W];
}

int main() {
    int n, W;

    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);

    int values[n], weights[n];

    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &values[i]);
    }

    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    int result = knapsack(W, weights, values, n);
    printf("Maximum value in Knapsack = %d\n", result);

    return 0;
}
