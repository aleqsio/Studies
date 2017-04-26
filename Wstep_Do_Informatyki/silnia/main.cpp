using namespace std;
#include <stdio.h>
#include <iostream>
int power(int n,int p)
{
	long s=1;
	for(int i=0;i<p;i++)
	{
		s*=n;
	}
	return s;
}
int main()
{
	long long tmp_number=1;
	long long value=1;//=1
	int length=1;//=1
	int digit=1;
	int tmpd=0;
	while(true)
	{
		for(long i=power(10,length-1);i<power(10,length);i++)
		{
			tmp_number=i;
				while(tmp_number%1000==0)
		{
			tmp_number/=1000;
			digit+=3;
		}
		while(tmp_number%10==0)
		{
			tmp_number/=10;
			digit++;
		}
		tmpd=tmp_number%10;
		while(tmp_number>9)
		{
			tmp_number/=10;
			digit++;
		}
		tmp_number=tmpd;
		while(value%1000==0)
		{
			value/=1000;
			digit+=3;
		}
		while(value%10==0)
		{
			value/=10;
				digit++;
		}
			tmpd=value%10;
		while(value>9)
		{
			value/=10;
			digit++;
		}
		value=tmpd;
		value=value*tmp_number;
			while(value%10==0)
		{
			value/=10;
			digit++;
		}
			tmpd=value%10;
		while(value>9)
		{
			value/=10;
			digit++;
		}
		value=tmpd;
		cout<<i<<":"<<value%10<<":"<<digit<<endl;
		}
		length++;
	}
}
