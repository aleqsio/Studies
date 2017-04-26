using namespace std;
#include <stdio.h>
#include <iostream>

int power(int n,int p)
{
	int s=1;
	for(int i=0;i<p;i++)
	{
		s*=n;
	}
	return s;
}

int main()
{
	int length =6;
		char a[length]="ABCDEF";
	for(int i=0;i<power(length,length);i++)
	{
		for(int k=length-1;k>=0;k--)
	{
		char l=a[i/power(length,k)%length];
			cout<<l;
		
		
	}
	cout<<"\n";
	}
}


