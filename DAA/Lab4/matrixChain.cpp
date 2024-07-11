#include<iostream>
using namespace std;

// Function to compute the minimum number of scalar multiplications
int MatrixChainOrder(int p[], int n) {
    int m[n][n]; // Declare the 2D array to store the minimum multiplication costs
    int i, j, k, L, q;

    // Initialize the cost for single matrix multiplication as zero
    for (i = 1; i < n; i++)
        m[i][i] = 0;

    // Loop to calculate the minimum cost of matrix chain multiplication
    for (L = 2; L < n; L++) { // L is the chain length
        for (i = 1; i < n - L + 1; i++) {
            j = i + L - 1;
            m[i][j] = INT_MAX; // Initialize with a large value
            for (k = i; k <= j - 1; k++) {
                // Calculate the cost/scalar multiplications
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) 
                    m[i][j] = q;
            }
        }
    }
    return m[1][n - 1];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int p[n + 1];
    cout << "Enter the dimensions of the matrices: ";
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    int size = n + 1;
    cout << "Minimum number of multiplications is " << MatrixChainOrder(p, size);

    return 0;
}
