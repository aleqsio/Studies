using namespace std;
#include <stdio.h>
#include <iostream>
//a b   wyznacznik = ad-bc wzor la placea
//c d
struct tab{
	int t[10][10];//tablica dosunieta do lewej gornej strony
	int n; //rozmiar tablicy
}
void move(tab &t1,int k,tab &t2)
{
	for(int i=1;i<t1.n)
{
	for(int j=0;j<t1.n;j++)
	{
		t2.t[i-1][j]=t1.t[i][j];
	}
}
for(int i=k+1;i<t2.n-1;i++)
{
	for(int j=0;j<t1.n-1;i++)
	{
		t2.t[i-1][j]=t2.t[i][j];
	}
}
t2.n=t1.n-1;
}
int det(tab t1)
{
	tab t2;
if(t1.n==1)
{
	return t1.t[0][0];
}
int s=0;
znak=1;
for(int i=0;i<t1.n;i++)
{
	move(t1,i,t2)
	s+=t1.t[0][i]*det(t2)*znak
	znak=-znak;
}
}
int main()
{

return 0;
}