using namespace std;
#include <stdio.h>
#include <iostream>

int licz=0;
void nki(int t[10],int n,int s,int p)
{
	cout<<n<<" "<<s<<" "<<p<<endl;
	if(n==1)
	{
		for(int i=p;i<10;i++)
		{
			if(t[i]==s) licz++;
		}
	}else
	{
		for(int i=p;i<10;i++)
		{
			if(s%t[i]==0)
			{
				nki(t,n-1,(s/t[i]),i+1);
			}
		}
	}
}
int main()
{
	int t[10] = {1,2,3,4,5,6,7,8,9,10};
	nki(t,3,60,0);
	cout<<licz;
	return 0;
}
