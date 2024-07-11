#include<iostream>
#include<iomanip>
using namespace std;
class chisquare
{
private:
int n, observed[20],i,N,Expected;
float CalculaGon[20],final,criGcal;
public:
chisquare() //constructor to iniGalize values
{
N=0;
final=0.00;
}
void getdata() //gePng observed frequency
{
cout<<"How many numbers:?"<<endl;
cin>>n;
cout<<"Enter the observed frequency:"<<endl;
for(i=0;i<n;i++)
{
cout<<"Enter "<<i+1<<"th number: "<<endl;
cin>>observed[i];
}
}

void calculaGon() //calculaGon of N(total frequency), CalculaGon(((Oi-Ei)^2/Ei)),final(?)

{
for(i=0;i<n;i++)
{
N=N+observed[i];
}
Expected=N/n;
for(i=0;i<n;i++)
{

CalculaGon[i]=(float)((observed[i]-Expected)*(observed[i]-

Expected))/Expected;

final=final+CalculaGon[i];
}
}
void display() //display in tabulated format
{
cout<<setw(5)<<"S.No";
cout<<setw(5)<<"Oi";
cout<<setw(5)<<"Ei";
cout<<setw(22)<<"((Oi-Ei)*(Oi-Ei))/Ei"<<endl;
for(i=0;i<n;i++)
{
cout<<setw(5)<<i+1;
cout<<setw(5)<<observed[i];
cout<<setw(5)<<Expected;
cout<<setw(10)<<setprecision(2)<<CalculaGon[i]<<endl;
}
cout<<"-------------------------------------------------------"<<endl;
cout<<setw(10)<<N;
cout<<setw(15)<<final;
cout<<endl;
}

void conclusion() //compare tabulated and calculated value and conclude if Ho is accepted.
{
cout<<endl;
cout<<"Enter the criGcal value:"<<endl;
cin>>criGcal;
if(final<criGcal)
{
cout<<"The test is accepted"<<endl;
}
else
{
cout<<"The test is rejected"<<endl;
}
}

};
int main()

{
chisquare c;
c.getdata();
c.calculaGon();
c.display();
c.conclusion();
return(0);
}