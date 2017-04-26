using namespace std;
#include <stdio.h>
#include <iostream>
void generuj(int a,int b,int c);
int main()
{
generuj(0,0,1);	
}
void generuj(int num,int poz,int max)
{
		if(!(poz<4))
		{
		cout<<num<<" ";
		}else{
	for(int i=1;i<=max+1;i++)
	{
		num*=10;
		num+=i;
		generuj(num,poz+1,max+1);
		}
		}
}
