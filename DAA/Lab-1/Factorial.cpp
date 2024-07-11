#include <iostream>
using namespace std;

unsigned long long factorial(int n)
{
    unsigned long long fact = 1;
    int i;

    // Check if n is negative
    if (n < 0)
    {
        cout<<"Factorial is not defined for negative numbers.\n";
        return 0;
    }

    // Calculate factorial iteratively
    for (i = 1; i <= n; ++i)
    {
        fact *= i;
    }

    return fact;
}

int main()
{
    int num;
    cout << "Enter a number: ";
    cin >> num;

    unsigned long long fact = factorial(num);
    cout << "factorial of " << num << " = " << fact;

    return 0;
}
