using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{
	int n,i,s_main,s_curr;
	const int l=100000;
	for(n=1;n<=l;n++)
	{
		//wyliczanie sumy dzielników (s_main) liczby n
		i=1;
		s_main=0;
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
		//koniec wyliczania
		for(int k=1;k<n;k++)
	{
			//wyliczanie sumy dzielników (s_curr) liczby k (każdej kolejnej mniejszej od n)
		i=1;
		s_curr=0;
		while(i*i<k)
		{
		if(k%i==0)
		{
			s_curr+=i;
				if(i!=1)
				{
				s_curr+=k/i;
				}
		}
		i++;
		}
		if(i*i==k)
		{
		s_curr+=i;
		}
		//koniec wyliczania
		if(s_curr==n&&s_main==k)
		{
			cout<<"P:"<<s_curr<<" "<<s_main<<"\n";
		}
	}
		
		}
		return 0;
	}
	
