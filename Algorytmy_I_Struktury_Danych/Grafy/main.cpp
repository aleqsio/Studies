#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
class Queue
{
public: void push(int x);
public: int pop()
    {

    }
public: bool isEmpty()
    {
        return true;
    }
};
bool Port(int** a,int m,int n,int T)
{
    bool visited[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            visited[i][j]=false;
        }
    }
    visited[0][0]=true;
    Queue q;
    q.push(0);
    q.push(0);
    while(!q.isEmpty())
    {
        int x=q.pop();
        int y=q.pop();
        if(x==m-1 and y==n-1)
        {
            return true;
        }
        if(x<m-1 and A[x+1][y]>T and !visited[x+1][y])
        {
            q.push(x+1);
            q.push(y);
            visited[x+1][y]=true;
        }
        if(y<n-1 and A[x][y+1]>T and !visited[x][y+1])
        {
            q.push(x+1);
            q.push(y);
            visited[x+1][y]=true;
        }
        // missing two cases
    }
return false;

    /*
     * N zbiorów rozłącznych pokazać że po operacjach union najgorszy przypadek
     * taki przypadek że n operacji find jest ograniczony przez n O(n)
     *
     * Mamy strukturę zbiorów rozłącznych w której mamy łączenie rangi ale nie mamy kompresji ścieżki
     * ciąg rzędu n operacji który nas w sumie będzie kosztował o(nlogn)
     */
}