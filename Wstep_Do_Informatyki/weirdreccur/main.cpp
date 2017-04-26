using namespace std;
#include <stdio.h>
#include <iostream>
void mystery(int a,int b,int l)
{
	if(l<300 and a<b)
	{
	int m=(a+b)/2;
	mystery(a,m,l+1);
	cout<<m<<endl;
	mystery(m,b,l+1);
	}
	
}
int main()
{
	mystery(0,8,0);
	return 0;
}

