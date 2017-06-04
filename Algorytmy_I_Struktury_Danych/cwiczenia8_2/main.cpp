#include <iostream>

struct ngh {
    int index;
    ngh *next;
};

void DFS(ngh *G[], int n, int i, bool visited[]) {
    ngh *tmp = G[i];
    while (tmp != NULL) {
        if(!visited[tmp->index])
        {
            DFS(G,n,tmp->index,visited);
        }
        tmp=tmp->next;
    }
}
int Skladowe(ngh *G[], int n) {
    int quantity = 0;
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++) {
        visited[i] = false;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(G, n, i, visited);
            quantity++;
        }
    }
    return quantity;
}


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
//mamy nowoczesny budynek chcemy ustawić camerę
//szukanie cyklu eulera