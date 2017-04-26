using namespace std;
#include <stdio.h>
#include <iostream>
bool skocz(void *t1,int size,int x,int y,int step);
int main()
{
	int x,y,s;
	cout<<"rozmiar:";
	cin>>s;
	cout<<"punkt:";
	cin>>x>>y;
	int t[s][s];
	for(int i=0;i<s*s;i++)
	{
		t[i/s][i%s]=0;
	}
	skocz(&t,s,x,y,1);
	for(int i=0;i<s*s;i++)
	{
		cout<<t[i%s][i/s]<<"  ";
		if(i%s==s-1)
		{
			cout<<endl;
		}
	}
	return 0;
}
bool skocz(void *t1,int size,int x,int y,int step)
{
	
	int (*t)[size][size]=(int (*)[size][size])t1;
	(*t)[x][y]=step;
	if(step==size*size)
	{
		return true;
	}
	int x_m[8]={-2,-2,-1,-1,1,1,2,2};
	int y_m[8]={-1,1,2,-2,2,-2,1,-1};
	bool flag=false;
	for(int i=0;i<8;i++)
		{
			if(x+x_m[i]>=0 and x+x_m[i]<size and y+y_m[i]>=0 and y+y_m[i]<size and (*t)[x+x_m[i]][y+y_m[i]]==0 and !flag)
			{
		flag=skocz(t,size,x+x_m[i],y+y_m[i],step+1);
			}
		}
		if(flag)
		{
			return true;
		}
		(*t)[x][y]=0;
		return false;
}

