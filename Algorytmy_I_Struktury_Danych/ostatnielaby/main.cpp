#include <iostream>

/*
 * Zadanie 1
 * Mamy dany zbiór zadań T, t1,t2,t3,t4
 * Chcemy wykonać część z tych zadań zabiera 1s
 * Zadania mają cechy g(t) - zysk pieniędzy z zdania
 *                    d(t) - termin wykonania
 *
 * Zadanie 2
 * pokrycie zbioru przedziałami jednostkowymi
 * zbiór liczb rzeczywistych
 * Zadanie 3
 * kolorowanie grafu funkcja ze zbioru krawędzi na zbiór liczb naturalnych kolorujemy krawędzie
 * D+1 kolorów, gdzie d to maksymalny stopień w grafie G
 * Zadanie 4
 * Ciągły problem plecakowy możemy przeciąć przedmiot i wziąć kawałek
 * Zadanie 5
 * Pojazd typu czołg
 * d -pojemność litrów
 * spalanie stałe 1 l/km
 * podróż z A do B i(n-2) wiele stacji
 * a) dojechać do B i zminimalizować liczbę postojów
 * b) ceny paliwa na stacjach
 */
struct block {
    double price;
    double weight;
    double density;
};

double ContinouBagProblem(int n, block A[], int T) {
    for (int i = 0; i < n; i++) {
        A[i].density = A[i].price / A[i].weight;
    }
    //  QSByDensity(n,A);
    int i = 0;
    while (i < n and T > A[i].density) {

    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    int x;

    return 0;
}

