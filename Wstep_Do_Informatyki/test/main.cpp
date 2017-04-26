#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
int* p;
int i[10];
i[0]=5;
i[1]=10;
p=i;
cout<<*(p+1);
}
