using namespace std;
#include <iostream>

int main() {
    for(int i=1;i<=100000;i++)
        if(i%3 && i%5) cout<<i<<"\n";
        else cout<<((i%3)?"":"Fizz")<<((i%5)?"":"Buzz")<<"\n";
    return 0;
}