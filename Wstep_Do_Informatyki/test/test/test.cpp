// test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
const int MAX = 10;
struct stos {
int t[MAX];
int
size
;
stos();
void
push
(
int
el
);
int
pop();
bool
empty
();
};
stos::stos
() {
	size = 0; std::cout << "constr";
}
void
stos::
push
(
int
el
) { t[
size
++
]=el
; }   
// bez kontroli
int
stos::pop
() { return t[
--
size
]; }       
// bez kontroli
bool
stos::
empty
() { return (size==0); }
int
main
() {
stos s; 
// konstruktor wywo³any automatycznie
for (
int
i=0; i<10; i++) 
s.push
(
i*i
); 
while
(!
s.empty
()) 
cout<<s.pop()<<endl
; 
}