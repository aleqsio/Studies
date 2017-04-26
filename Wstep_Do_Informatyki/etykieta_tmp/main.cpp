using namespace std;
#include <stdio.h>
#include <iostream>
int main(int argc, char **argv)
{
	bool i;
etykieta: 
cin>>i;
// instrukcje 
if (i)
{ 
cout<<"pętla";
goto etykieta; 
}
cout<<"poza";
goto etykieta; 

}
