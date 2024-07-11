//Generating random numbers using LCG
#include<iostream>
// #include<conio.h>
#include<math.h>
using namespace std;
int main()
{
	int x[10],n,a,c,m,i,j,p;
	float r[10];
	cout<<"\n1.Mixed LCM\n2.Multiplicative LCM\n3.Additive LCM\n4.Arithmetic LCM:\n5.Exit";
	do{
	cout<<"\n\nSelect an option:";
	cin>>p;
	switch(p)
	{
		case 1:
			cout<<"Enter the number of random numbers to generate , seed x0 , a ,c,m:";
		cin>>n>>x[0]>>a>>c>>m;
		cout<<"Random numbers are:\n";
		for(i=0;i<n;i++)
		{
			x[i+1]=(a*x[i]+c)%m;
			r[i+1]=(float)x[i+1]/m;
			cout<<r[i+1] <<"\t";		
		}
		break;
		case 2:
		cout<<"Enter the number of random numbers to generate , seed x0 , a ,m:";
		cin>>n>>x[0]>>a>>m;
		cout<<"Random numbers are:\n";
		for(i=0;i<n;i++)
		{
			x[i+1]=(a*x[i])%m;
			r[i+1]=(float)x[i+1]/m;
			cout<<r[i+1]	<<"\t";		
		}
		break;
		
		case 3:
			cout<<"Enter the number of random numbers to generate , seed x0 ,c,m:";
		cin>>n>>x[0]>>c>>m;
		cout<<"Random numbers are:\n";
		for(i=0;i<n;i++)
		{
			x[i+1]=(x[i]+c)%m;
			r[i+1]=(float)x[i+1]/m;
			cout<<r[i+1]	<<"\t";		
		}
		break;
		
		case 4:
			
			cout<<"Enter the number of random numbers to generate , x0,x1,m:";
			cin>>n>>x[0]>>x[1]>>m;
			cout<<"Random numbers are:\n";
			
				for(i=0;i<n;i++)
		{
			x[i+2]=(x[i]+x[i+1])%m;
			r[i+2]=(float)x[i+2]/m;
			cout<<r[i+2]	<<"\t";		
		}
		break;
		case 5:
			exit(0);
			break;
		default:
			cout<<"Error input selection!!";
	}
}while(p<=4);

	return 0;
}
