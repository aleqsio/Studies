using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{
	long long number=1;
	long long length=0;
	long long power;
	long long sum;
	bool flag;
	long long tmp_number;
	while(true)
	{
		if(number%100000==0)
		{
			cout<<".";
		}
		flag=true;
	if(flag)
	{
	tmp_number=number;
	length=0;
	while(tmp_number>0)
	{
		length++;
		tmp_number/=10;
	}
	tmp_number=number;
	sum=0;
	while(tmp_number>0)
	{
		power=1;
		for(int i=0;i<length;i++)
		{
			power*=tmp_number%10;
		}
		sum+=power;
		tmp_number/=10;
	}
	if(sum==number)
	{
		if(flag)
		{
			cout<<number<<"\n";	
		}
	
	}
	
	}
	number++;
	}
	
	}
