#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int main() {
string p="*#include <stdio.h>$#include <iostream>$#include <string.h>$using namespace std;$int main() {$string p=%@%;$char a;$for(int i=0;i<p.length();i++)${$a=p[i];$if(a==64)${$cout<<p;$}else if(a==36)${$cout<<endl;$}else if(a==37)${$cout<<a-3;$}else if(a==42)${$a=a-8;$cout<<a;$a=a+8;$cout<<a;$}else${$cout<<a;$}$}$}*";
char a;
for(int i=0;i<p.length();i++)
{
a=p[i];
if(a==64)
{
cout<<p;
}else if(a==36)
{
cout<<endl;
}else if(a==37)
{
cout<<a-3;
}else if(a==42)
{
	//a=a-8;
	
cout<<a;
//a=a+8;
cout<<a;
}else
{
cout<<a;
}
}
}