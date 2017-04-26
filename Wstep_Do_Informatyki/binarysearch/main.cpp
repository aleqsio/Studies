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
	for(long i=0;i<n;i++)
	{
		cin>>num[i];
	}
	for(long i=0;i<k;i++)
	{
		cin>>currnum;
		currend=n-1;
		currstart=0;
		while(currend-currstart>1)
		{
			middleindex=(currend+currstart)/2;
			if(num[middleindex]<currnum)
			{
				currstart=middleindex;
			}else
			{
				currend=middleindex;
			}
		
		}
		if(num[currstart]==currnum)
		{
			cout<<currstart+1;
		}else if(num[currend]==currnum)
		{
			cout<<currend+1;
		}else
		{
			cout<<-1;
		}
        cout<<" ";
	}
	
	return 0;
}
