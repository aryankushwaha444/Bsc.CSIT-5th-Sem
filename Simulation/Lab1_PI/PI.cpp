#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

int main()
{
    int m ,n = 0 ,i,r;
    float x,y,f,pie,error,e1;

    cout<<"\nEnter No. of Experiment :";
    cin>>m;

        cout<<"\nEnter No. of Radius :";
    cin>>r;

    for (i = 0; i <= m; i++)
    {
        x = rand()%r;
        y=rand()%r;
        f=pow(x,2) + pow(y,2) -pow(r,2);

        if (f<=0)
        {
            n++;
        }
        
    }

    pie = 4*(float)n / (float)m;

    cout<<"\n The value of pie is "<<pie;
    e1 = ((3.14 - pie)/3.14)*100;
    cout<<"\n Error percentage"<<e1;
    return 0;
    


}