using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{
	int n=100;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j*j<=n*n-i*i;j++)
		{
			for(int k=1;k*k<=i*i+j*j;k++)
			{
				if(i*i+j*j==k*k && i<=n &j<=n&k<=n)
				{
					cout<<i<<" "<<j<<" "<<k<<endl;
				}
			}
		}
	}
}

