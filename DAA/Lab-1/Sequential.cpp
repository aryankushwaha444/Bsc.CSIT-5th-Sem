#include <iostream>
#include <string.h>
using namespace std;
int search(int arr[], int n, int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            return i;

    return -1;
}

int main(void)

{
    int arr[] = {12, 43, 44, 120, 4};
    int x = 43;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout<<"\nThe Given Array [ ] = { ";
    for (int i = 0; i < n; i++)
    {
        if (i == n - 1)
        {
            cout << arr[i] << " }";
        }
        else
        {
            cout << arr[i] << " ,";
        }
    }

    int result = search(arr, n, x);
    (result == -1) ? cout << "\n\nElement is not present in array" : cout << "\n\nElement is present at index " << result;

    return 0;
}