#include <iostream>
#include <climits>
#include <cstdlib>
using namespace std;

int randomPartition(int arr[], int l, int r);

// This function returns k'th smallest element in arr[l..r] using
// QuickSort based method. ASSUMPTION: ELEMENTS IN ARR[] ARE DISTINCT
int kthSmallest(int arr[], int l, int r, int k) {
    // If k is smaller than number of elements in array
    if (k > 0 && k <= r - l + 1) {
        // Partition the array around a random element and
        // get position of pivot element in sorted array
        int pos = randomPartition(arr, l, r);

        // If position is same as k
        if (pos - l == k - 1)
            return arr[pos];
        if (pos - l > k - 1) // If position is more, recur for left subarray
            return kthSmallest(arr, l, pos - 1, k);

        // Else recur for right subarray
        return kthSmallest(arr, pos + 1, r, k - pos + l - 1);
    }

    // If k is more than the number of elements in the array
    return INT_MAX;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Standard partition process of QuickSort(). It considers the last
// element as pivot and moves all smaller element to left of it and
// greater elements to right. This function is used by randomPartition()
int partition(int arr[], int l, int r) {
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[r]);
    return i;
}

// Picks a random pivot element between l and r and partitions
// arr[l..r] around the randomly picked element using partition()
int randomPartition(int arr[], int l, int r) {
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);
    return partition(arr, l, r);
}

// Function to handle input
void input(int*& arr, int& size, int& k) {
    cout << "Enter Size of array: ";
    cin >> size;

    arr = new int[size];

    cout << "Enter Array Elements: ";
    for (int i = 0; i < size; i++) {
        cout << "A[" << i << "]: ";
        cin >> arr[i];
    }

    cout << "Enter k (1-based index of the smallest element to find): ";
    cin >> k;
}

// Driver program to test above methods
int main() {
    int* arr;
    int size, k;

    input(arr, size, k);

    int result = kthSmallest(arr, 0, size - 1, k);
    if (result != INT_MAX) {
        cout << "K'th smallest element is " << result << endl;
    } else {
        cout << "K is out of bounds" << endl;
    }

    delete[] arr; // Free the allocated memory
    return 0;
}
