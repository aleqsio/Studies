using namespace std;
#include <iostream>

//The following is not a part of this magical journey
//Skip this class you fools!
class Helper {
public:
    static const int defaultarraysize = 10;
    static void Swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }
    static int *getRandomArray(int length = defaultarraysize, int min = 0, int max = 100) {
        int *arr = new int[length];
        for (int i = 0; i < length; i++) {
            arr[i] = rand() % (max - min + 1) + min;
        }
        return arr;
    }

    static void printArray(string s, int *a, int length = defaultarraysize) {
        std::cout << "\n" << s << "\n";
        for (int i = 0; i < length - 1; i++) {
            cout << a[i] << ",";
        }
        cout << a[length - 1];
    }

    static void print(string s) { cout << "\n" << s << "\n"; }
};




//THE LORD OF THE ASD
//This is a journey through time and algorithms.
// By J.R.R. Cormen and the Fellowship of D17

//ROZDZIAL 1: ALGORYTMY SORTUJĄCE
class Sorting {

public:
    class QuickSortOnArray {
    public:
        static void QuickSort(int A[], int p, int r) {
            if (p < r) {
                int q = Partition(A, p, r);
                QuickSort(A, p, q - 1);
                QuickSort(A, q + 1, r);
            }
        }

        static int Partition(int A[], int p, int r) {
            int x = A[r];
            int i, j;
            i = p - 1;
            for (j = p; j < r; j++) {
                if (A[j] <= x) {
                    i++;
                    Helper::Swap(A[i], A[j]);
                }
            }
            Helper::Swap(A[i + 1], A[r]);
            return i + 1;
        }



        static void Test() {
            int *a = Helper::getRandomArray();
            QuickSort(a, 0, Helper::defaultarraysize - 1);
            Helper::printArray("QUICKSORT ON ARRAY", a);
        }
    };
    class QuickSortOnList {
    public:
        static void Test(){
            //THIS FUNCTION ISN'T HERE, LITTLE FRODO
        }
    };
    class QuickerSortOnArray {
    public:
        static void Test(){
            //THIS FUNCTION ISN'T HERE, LITTLE FRODO
        }
    };
    class QuickerSortOnList {
    public:
        static void Test(){
            //THIS FUNCTION ISN'T HERE, LITTLE FRODO
        }
    };
    class MergeSortOnArray {
    public:
        static void Test(){
            //THIS FUNCTION ISN'T HERE, LITTLE FRODO
        }
    };
    class HeapSortOnArray {
    public:
        static void Test(){
            //THIS FUNCTION ISN'T HERE, LITTLE FRODO
        }
    };
};

int main() {
    std::cout << "Welcome to the journey!" << std::endl;
    Sorting::QuickSortOnArray::Test();
    Sorting::QuickSortOnList::Test();

    return 0;
}
