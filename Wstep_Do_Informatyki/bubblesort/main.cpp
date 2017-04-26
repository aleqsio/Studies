#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	int size;
	long b=0;
	cin>>size;
	long val[size];
	for(int i=0;i<size;i++)
	{
		cin>>val[i];
	}
	for(int i=1;i<size;i++)
	{
		for(int j=size-1;j>=i;j--)
		{
			if(val[j]<val[j-1])
			{
				b=val[j];
				val[j]=val[j-1];
				val[j-1]=b;
			}
		}
		cout<<val[i-1]<<" ";
	}
	cout<<val[size-1];
	return 0;
}

