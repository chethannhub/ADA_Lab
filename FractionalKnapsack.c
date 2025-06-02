#include <stdio.h>

typedef struct {
    int value;
    int weight;
} Item;

// Function to find the maximum of two floats
float max(float a, float b) {
    return (a > b) ? a : b;
}

// Function to sort items by value-to-weight ratio in descending order
void sortItemsByRatio(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            float r1 = (float)items[j].value / items[j].weight;
            float r2 = (float)items[j + 1].value / items[j + 1].weight;
            if (r1 < r2) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

// Fractional Knapsack function
float fractionalKnapsack(int capacity, Item items[], int n) {
    sortItemsByRatio(items, n);

    float totalValue = 0.0;
    int currWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currWeight + items[i].weight <= capacity) {
            // Take the whole item
            currWeight += items[i].weight;
            totalValue += items[i].value;
        } else {
            // Take the fraction of the remaining capacity
            int remain = capacity - currWeight;
            totalValue += ((float)items[i].value / items[i].weight) * remain;
            break;
        }
    }
    return totalValue;
}

// Driver code
int main() {
    int n = 3;
    Item items[] = {{60, 10}, {100, 20}, {120, 30}};
    int capacity = 50;

    float maxValue = fractionalKnapsack(capacity, items, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}
