using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{
	long long a,b;
	const long long limit=4000000;
	a=1;
	long long sum=0;
	b=1;
	cout<<a;
	while (a+b<limit)
	{
		if(b%2==0)
		{
			sum+=b;
			if(b%20000==0)
		{
			cout<<".";
		}
		}
		b=a+b;
		a=b-a;
	}
	cout<<sum;
}
