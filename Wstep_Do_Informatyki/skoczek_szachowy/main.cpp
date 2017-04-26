using namespace std;
#include <stdio.h>
#include <iostream>
bool skocz(int t[][8],int skok,int x,int y);
bool flag=false;
int main()
{
	int x,y;
	cin>>x>>y;
	int t[8][8];
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			t[i][j]=0;
		}
	}
	skocz(t,1,x,y);
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<8;j++)
		{
			cout<<t[i][j]<<" ";
			if(t[i][j]<10) cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}
bool skocz(int t[][8],int skok,int x, int y)
{
	if(skok==64 or flag)
	{
		flag=true;
		t[x][y]=64;
		return true;
	}
	int x_move[8]={-2,-2,-1,-1,1,1,2,2};
	int y_move[8]={1,-1,2,-2,2,-2,1,-1};
	t[x][y]=skok;
	bool f=false;
	for(int i=0;i<8;i++)
	{
		if(x+x_move[i]>=0 and x+x_move[i]<8 and y+y_move[i]>=0 and y+y_move[i]<8 and t[x+x_move[i]][y+y_move[i]]==0)
		{
			if(skocz(t,skok+1,x+x_move[i],y+y_move[i]))
			{
				f=true;
			}
		}
	}
	if(!f and !flag)
	{
		t[x][y]=0;
		return false;
	}
}
