using namespace std;
#include <stdio.h>
#include <iostream>

int main()
{
	long n,k;
    cin>>n;
	long num[n];
	cin>>k;
	long currnum;
	long currstart;
	long currend;
	long middleindex;
	long min;
	long tmp;
	long minindex=0;
	cin>>num[0];
	for(long i=1;i<n;i++)
	{
		cin>>num[i];
		if(num[i-1]>num[i])
		{
			minindex=i;
		}
	}
	for(long i=0;i<k;i++)
	{
		cin>>currnum;
		currend=n-1;
		currstart=0;
		while(true)
		{
			if(currend<currstart)
			{
				cout<<-1;
				break;
			}
			middleindex=(currend+currstart)/2;
			if(num[(middleindex+minindex)%n]<currnum)
			{
				currstart=middleindex+1;
				continue;
			}else if(num[(middleindex+minindex)%n]>currnum)
			{
				currend=middleindex-1;
				continue;
			}
        cout<<(middleindex+minindex)%n+1;
		break;
		}
		cout<<" ";
	}
	return 0;
}
