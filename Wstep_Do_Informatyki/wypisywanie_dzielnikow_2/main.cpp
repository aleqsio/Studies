using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{
	int n,i;
	const int l=100;
	for(n=1;n<=l;n++)
	{
	i=1;
	cout<<n<<": ";
	while(i*i<n)
	{
		if(n%i==0)
		{
				cout<<i<<" ";
				if(i!=1)
				{
				cout<<n/i<<" ";
		
				}
		}
		i++;
	}
		if(i*i==n)
		{
		cout<<i<<" ";
		}
cout<<"\n";
		}
		return 0;
	}
	
