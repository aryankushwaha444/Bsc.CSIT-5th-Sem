// A Dynamic Programming based solution for 0-1 Knapsack problem
#include <iostream>
#include <vector>
using namespace std;

// A utility function that returns the maximum of two integers
int max(int a, int b) { return (a > b) ? a : b; }

// Returns the maximum value that can be put in a knapsack of capacity W
int knapSack(int W, vector<int>& wt, vector<int>& val, int n) {
    vector<vector<int> > K(n + 1, vector<int>(W + 1)); // Add space between the angle brackets

    // Build table K[][] in bottom up manner
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
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
    int n, W;
    
    // Read the number of items
    cout << "Enter the number of items: ";
    cin >> n;
    
    vector<int> val(n), wt(n);
    
    // Read the values of the items
    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    
    // Read the weights of the items
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    
    // Read the capacity of the knapsack
    cout << "Enter the capacity of the knapsack: ";
    cin >> W;
    
    // Calculate and print the maximum value
    cout << "The maximum value that can be put in the knapsack is " << knapSack(W, wt, val, n) << endl;
    
    return 0;
}
