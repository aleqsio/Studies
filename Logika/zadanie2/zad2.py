#Aleksander Mikucki zad. 2

#Implementacja zera i jedynki
n0 = lambda f: lambda x:x #n0 to funkcja która niezależnie od funkcji f zachowuje się jak funkcja tożsamościowa - nie wywołuje tej funkcji
n1 = lambda f: lambda x:f(x)

#test prawidłowości implementacji
test0=n0(len)
test1=n1(len)
print(test0("test")+ "\n" + str(test1("test"))) # zero zwraca napis test (zerowe złożenie funkcji length, jeden zwraca 4 - długość napisu (jednokrotne złożenie)

#liczebniki od 2-5
n2 = lambda f: lambda x:f(f(x))
n3 = lambda f: lambda x:f(f(f(x)))
n4 = lambda f: lambda x:f(f(f(f(x))))
n5 = lambda f: lambda x:f(f(f(f(f(x)))))
 
#wartosci logiczne
true = lambda a:lambda b:a
false = lambda a:lambda b:b

#funkcja pomocnicza zamieniająca churcha na inta - dla sprawdzania wyników
churchtoint = lambda ch: ch(lambda x:x+1)(0) #korzystamy z cechy że wywołanie liczebnika churcha jest tak
#  naprawdę n krotnym zastosowaniem funkcji podanej w argumencie na zwracanych wartościach
# podanie funkcji increment powoduje inkrementację na każdym stopniu zagnieżdzenia
print(str(churchtoint(n0)))
print(str(churchtoint(n5)))

#funkcja pomocnicza zamieniająca boolean funkcyjny na standardowy
churchtobool = lambda ch: ch(True)(False)
print(str(churchtobool(true)))
print(str(churchtobool(false)))

#DEFINIOWANIE OPERACJI
power = lambda a:lambda b:b(a) #potęga wynika z prostej własności złożenia
print(str(churchtoint(power(n5)(n3))))

base = lambda f:power(f)(n0) #zwraca funkcję bazową f dowolnego złożenia
print(str(churchtoint(base(n5)))) #zwraca 1

succ = lambda a: lambda f: lambda x: f(a(f)(x)) #incrementuje
print(str(churchtoint(succ(n5))))
lambda a: lambda f: lambda x: f(a(f)(x)) #incrementuje

pred = lambda a: lambda b: lambda x: a (lambda f: lambda g: g (f (b))) (lambda i:x) (lambda o:o)

add = lambda a: lambda b:lambda f: lambda x: a(f)(b(f)(x))
print(str(churchtoint(add(n5)(n3))))

sub = lambda a: lambda b: b(pred)(a)

multiply = lambda a: lambda b: lambda x: (a(b(x)))
print(str(churchtoint(multiply(n5)(n3))))

power = lambda a:lambda b:b(a)
print(str(churchtoint(power(n5)(n3))))

#OPERACJE LOGICZNE
_and = lambda a:lambda b: a(b(true)(false))(false)
print(str(churchtobool(_and(true)(true)))); print(str(churchtobool(_and(false)(true))));print(str(churchtobool(_and(true)(false))));print(str(churchtobool(_and(false)(false))))

_or = lambda a:lambda b: a(true)(b(true)(false))
print(str(churchtobool(_or(true)(true)))); print(str(churchtobool(_or(false)(true))));print(str(churchtobool(_or(true)(false))));print(str(churchtobool(_or(false)(false))))

_not = lambda a: a(false)(true)
print(str(churchtobool(_not(true)))); print(str(churchtobool(_not(false))));



_if = lambda s: lambda a: lambda b: s(a)(b)

print("always true")
print(_if(true)("Yes")("No"))

print("1==0, 0==0")
_iszero = lambda f: f(lambda x: false)(true)

print(_if(_iszero(n1))("Yes")("No"))
print(_if(_iszero(n0))("Yes")("No"))

_lessoreq = lambda a: lambda b: _iszero(sub(a)(b))

print("5 lower then 3")
print(_if(_lessoreq(n5)(n3))("Yes")("No"))

_mod2 = lambda f: lambda a: lambda b: _if(_lessoreq(b)(a))(lambda e: f(f)(sub(a)(b))(b)(e))(a)
_mod = lambda a: lambda b: _mod2(_mod2)(a)(b)
print(str(churchtoint(_mod(n5)(n2))))
#PROGRAM ZWRACA SUMĘ ELEMENTÓW
def sum(n):
    #print(str(churchtoint(n)))
    return (((_if(_iszero(n)))(n1)((((lambda z=n: add(sum(pred(z)))(z)))))))(n)
print(str(churchtoint(sum(multiply(n2)(n5)))))



#PROGRAM ZWRACA SUMĘ ELEMENTÓW PODZIELNYCH PRZEZ 5
def sumdiv5(n):
   print(str(churchtoint(n)))
   return (_if(_iszero(n)))(n1)(lambda z=n: add(sumdiv5(pred(z)))((_if(_iszero(_mod(z)(n5)))(z)(n0))))(n)

print(str(churchtoint(sumdiv5(multiply(n2)(n5)))))

