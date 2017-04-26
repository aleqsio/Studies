using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{
	int n,i;
	const int l=100000;
	int sum_table[l];
	for(n=1;n<=l;n++)
	{
		int i=1;
		int s_main=0;
		while(i*i<n)
		{
		if(n%i==0)
		{
			s_main+=i;
				if(i!=1)
				{
				s_main+=n/i;
				}
		}
		i++;
		}
		if(i*i==n)
		{
		s_main+=i;
		}
		sum_table[n-1]=s_main;
	}
	cout<<"table generated\n";
		for(n=1;n<=l;n++)
	{
			for(int k=1;k<=l;k++)
	{
		if(sum_table[n-1]==k&&sum_table[k-1]==n)
		{
				cout<<"P:"<<k<<" "<<n<<"\n";
		}
	}
	}
		return 0;
	}
	
