#include <iostream>
// #include <conio.h>
#include <stdio.h>

using namespace std;

int main()
{
    FILE *fp;
    int i;
    float D, S, a, b, c, d, P;
    fp = fopen("sim.xls", "w+");
    cout << "\nEnter the value of Demand price(dp) a: ";
    cin >> a;
    cout<< "\nEnter the value of Demand slope(ds) b: ";
    cin >> b;

    cout << "\nEnter the value of supply price(sp) c: ";
    cin >> c;

    cout << "\nEnter the value of supply slpoe)(ss) d: ";
    cin >> d;

    cout << "\nEnter the value of initial price(P): ";
    cin >> P;

    for (i = 0; i <= 10; i++)
    {
            D = a - (b * P);
            S = c + (d * P);
            P++;

            fprintf(fp, "%f\t%f\t\n", D, S);
            if (D == S)
            {
                cout << "\nEquilitrium Price is =%f"<< P;
            }
    }
    fclose(fp);

    return 0;
}