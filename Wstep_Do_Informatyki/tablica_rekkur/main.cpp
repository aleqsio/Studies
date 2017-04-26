using namespace std;
#include <stdio.h>
#include <iostream>
int sum(int t[],int n,int s,int acc)
{
	
	acc+=t[n];
	if(n==s-1)
	{
		return acc;
	}
	return sum(t,n+1,s,acc);
}
int main()
{	
	int s=2000;
	int tab[s];
	for(int i=0;i<s;i++)
	{
		tab[i]=5;
	}
	cout<<sum(tab,0,s,0);
	return 0;
}

