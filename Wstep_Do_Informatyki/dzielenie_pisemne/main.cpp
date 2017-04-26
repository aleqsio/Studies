#include "stdafx.h"
#include <stdio.h>
#include <iostream>

using namespace std;
int main()
{
	int n=1;
	const long size=100000;
	long t[size][2];
	long len;
		int mult=0;
	bool zero;
	for(int i=0;i<size;i++)
	{
		t[i][0]=0;
		t[i][1]=0;
	}
	t[0][0]=1;
	while(true)
	{
		len=0;
			mult=0;
			cout<<n+1<<"! length:";
			n++;
			zero=false;
			
				for(int p=0;p<size-1;p++)
				{
			mult=t[p][0]*n;
			t[p][0]=(mult+t[p][1])%10;
			t[p+1][1]=(mult+t[p][1])/10;
			}
			for(int i=size-1;i>=0;i--)
			{
				if(t[i][0]!=0)
				{
					zero=true;
				}
				if(zero)
				{
					len++;
				}
			}
			cout<<len;
			cout<<endl;

	}
}
