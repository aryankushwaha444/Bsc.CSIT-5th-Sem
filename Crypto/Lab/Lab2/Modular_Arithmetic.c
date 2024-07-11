#include <stdio.h>

// Function prototypes
int gcd(int a, int b);
int mod_inverse_add(int a, int m);
int mod_inverse_mult(int a, int m);
int extended_gcd(int a, int b, int *x, int *y);
void find_additive_inverse();
void find_multiplicative_inverse();
void check_relatively_prime();

int main()
{
    int choice;

    do
    {
        printf("\nMenu:\n");
        printf("1. Find Additive Inverse\n");
        printf("2. Find Multiplicative Inverse (Extended Euclidean Algorithm)\n");
        printf("3. Check if Two Numbers are Relatively Prime\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            find_additive_inverse();
            break;
        case 2:
            find_multiplicative_inverse();
            break;
        case 3:
            check_relatively_prime();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to find the gcd of two numbers (recursive)
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Function to find the additive inverse of 'a' under modulo 'm'
int mod_inverse_add(int a, int m)
{
    return (m - a % m) % m;
}

// Function to find the multiplicative inverse using the Extended Euclidean Algorithm
int mod_inverse_mult(int a, int m)
{
    int x, y;
    int g = extended_gcd(a, m, &x, &y);
    if (g != 1)
    {
        return -1; // Inverse doesn't exist
    }
    else
    {
        int res = (x % m + m) % m;
        return res;
    }
}

// Extended Euclidean Algorithm
int extended_gcd(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int gcd = extended_gcd(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gcd;
}

// Function to check if two numbers are relatively prime
void check_relatively_prime()
{
    int a, b;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);

    if (gcd(a, b) == 1)
    {
        printf("%d and %d are relatively prime.\n", a, b);
    }
    else
    {
        printf("%d and %d are not relatively prime.\n", a, b);
    }
}

// Function to find the additive inverse of a number under a modulo
void find_additive_inverse()
{
    int a, m;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Enter the modulo: ");
    scanf("%d", &m);
    int inverse = mod_inverse_add(a, m);
    printf("The additive inverse of %d under modulo %d is: %d\n", a, m, inverse);
}

// Function to find the multiplicative inverse of a number under a modulo
void find_multiplicative_inverse()
{
    int a, m;
    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Enter the modulo: ");
    scanf("%d", &m);
    int inverse = mod_inverse_mult(a, m);
    if (inverse == -1)
    {
        printf("Multiplicative inverse doesn't exist for %d under modulo %d\n\n", a, m);
    }
    else
    {
        printf("The multiplicative inverse of %d under modulo %d is: %d\n", a, m, inverse);
    }
}
