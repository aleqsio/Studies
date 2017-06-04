#include <iostream>

//1zad1 rozwiązać problem plecakowy w wersji dyskretnej //masa i wartość : maksymalnej
//2dwie tablice A[n] i B[n] znaleźć najdłuższy współny podciąg
//3dwie tablice A[n] i B[n] znaleźć najdłuższy wspólny podciąg rosnący
//4zaimplementować algorytm floyda warshalla
//5Korek samochodowy zapisany w tablicy intów n elementowej stoją do bramki wartość to jest długość pojazdu
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

int max(int i, int i1);

int knapsack(int p[], int w[], int n, int T)
{
    int f[n+1][T+1];
    for(int i=0;i<n;i++)
    {
        f[i][0]=0;
        for(int t=0;t<T;t++)
        {
            f[0][t]=0;
        }
    }
    for(int i=1;i<n;i++)
    {
        for(int t=1;t<T;T++)
        {
            if(w[i]>t) f[i][t]=f[i-1][t];
            else
                    f[i][t]=max(f[i-1][t],f[i-1][t-w[i]]+p[i]);
        }
    }
    return f[n][T];
}

int max(int b, int a) {
    b>a ? b : a;
    return 0;
}

int LCS(int A[],int B[],int n,int m)
{
int L[n+1][m+1];
    for(int i=0;i<=n;i++)
    {
        L[i][0]=0;
    }
    for(int i=0;i<=m;i++)
    {
        L[0][i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
        if(A[i]==B[j]) L[i][j]=L[i-1][j-1]+1;
        else{
            L[i][j]=max(L[i][j-1],L[i-1][j]);
        }
        }
    }
    return L[n][m];
}