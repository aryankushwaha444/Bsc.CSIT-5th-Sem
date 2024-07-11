#include <stdio.h>

// A recursive binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;

        // If the element is present at the middle
        if (arr[mid] == x)
            return mid;

        // If element is smaller than mid, it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        // Else the element can only be present in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }

    // We reach here when the element is not present in array
    return -1;
}

// Function to handle input
void input(int *arr, int *l, int *x) {
    printf("Enter Size of array: ");
    scanf("%d", l);

    printf("Enter Array Elements: ");
    for (int i = 0; i < *l; i++) {
        printf("A[%d] ",i);
        scanf("%d", &arr[i]);
    }

    printf("Which number do you want to search: ");
    scanf("%d", x);
}

int main(void) {
    int arr[25], l, x;

    input(arr, &l, &x);

    int result = binarySearch(arr, 0, l - 1, x);

    if (result == -1) {
        printf("Element is not present in array\n");
    } else {
        printf("Element is present at index %d\n", result);
    }

    return 0;
}
