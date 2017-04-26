using namespace std;
#include <stdio.h>
#include <iostream>
void factorise(int number,int base);
int main()
{
int n,k;
cin>>n>>k;
factorise(n,k);
return 0;
}
void factorise(int number,int base)
{
	if(number<base)
	{
		cout<<number;
	}else
	{
		factorise(number/base,base);
		cout<<number%base;
}
}