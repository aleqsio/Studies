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
# podanie funkcji incremenent powoduje inkrementację na każdym stopniu zagnieżdzenia
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

_if = lambda s: lambda a:lambda b: s(a)(b)
print(_if(true)("Yes")("No"))

_iszero = (lambda f: (f(lambda x: false))(f(lambda x: true)))
print(_if(_iszero(n1))("Yes")("No"))

#PROGRAM ZWRACA SUMĘ ELEMENTÓW
def sum(n):
    print(str(churchtoint(n)))
    x=(((lambda z=n: add(sum(pred(z)))(z))))
    return _if(_iszero(n))(n0)(x)(n)
print(str(churchtoint(sum(multiply(n5)(n2)))))