#include<iostream>

using namespace std;
void swap(int *xp, int *yp)
{
int temp = *xp;
*xp = *yp;
*yp = temp;
}
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
int i, j;
for (i = 0; i < n-1; i++)
// Last i elements are already in place
for (j = 0; j < n-i-1; j++)
if (arr[j] > arr[j+1])
swap(&arr[j], &arr[j+1]);

}
/* Function to print an array */
void printArray(int arr[], int size)
{
int i;
for (i = 0; i < size; i++)
cout << arr[i] << " ";
cout << endl;

}
// Driver code
int main()
{
int arr[] = {45, 53, 55, 152, 24, 19, 80};
int n = sizeof(arr)/sizeof(arr[0]);
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
bubbleSort(arr, n);
cout<<"\n\nSorted array: \n";
printArray(arr, n);
return 0;
}