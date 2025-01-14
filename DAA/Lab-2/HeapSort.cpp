#include <iostream>
#include <vector>
using namespace std;

// To heapify a subtree rooted with node i which is an index in arr[]. n is size of heap
void heapify(vector<int> &arr, int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(vector<int> &arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* A utility function to print array of size n */
void printArray(const vector<int> &arr) {
    for (int i : arr)
        cout << i << " ";
    cout << "\n";
}

// Function to handle input
void input(vector<int> &arr) {
    int l;
    cout << "Enter Size of array: ";
    cin >> l;

    arr.resize(l);
    cout << "Enter Array Elements: ";
    for (int i = 0; i < l; i++) {
        cout << "A[" << i << "] ";
        cin >> arr[i];
    }
}

// Driver program
int main() {
    vector<int> arr;

    input(arr);

    heapSort(arr);

    cout << "Sorted array is \n";
    printArray(arr);

    return 0;
}
