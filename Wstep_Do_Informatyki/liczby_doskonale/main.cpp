using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{
	int n,i,s;
	const int l=100000000;
	for(n=1;n<=l;n++)
	{
	i=1;
	s=0;
	while(i*i<n)
	{
		if(n%i==0)
		{
				s+=i;
				if(i!=1)
				{
				s+=(n/i);
		
				}
		}
		i++;
	}
		if(i*i==n)
		{
		s+=i;
		}
		if(n==s)
		{
		cout<<" "<<s;
		}
		}
		return 0;
	}
	
