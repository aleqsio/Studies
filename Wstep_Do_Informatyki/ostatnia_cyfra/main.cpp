using namespace std;
#include <stdio.h>
#include <iostream>
int main(int argc, char **argv)
{
	int a,b;
	cin>>a>>b;
	a=a+b;
	bool flag=true;
	while(a>0)
	{
		b=a%10;
		a/=10;
		if(b<=a%10)
		{
			flag=false;
			a=0;
		}
	}
	cout<<flag;
	return 0;
}
