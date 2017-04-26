using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{
	int a;
	int n=1;
	cin>>a;
	while(n*n<a)
	{
		n++;
	}
	if(n*n==a)
	{
		cout<<n;
	}else
	{
		cout<<"NIE";
	}
	return 0;
}
