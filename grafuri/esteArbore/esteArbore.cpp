#include <fstream>
#include <iostream>
#include <queue>
#define size 100

using namespace std;

bool esteArbore(int n, int m, int adj[][size]) {
    if (m != n - 1) {
        return false;
    }
    
    int visited[n];
    for (int i = 0; i < n; i++) {
        visited[i] = 0;
    }

    queue<int> q;
    q.push(0);
    visited[0] = 1;
    
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        
        for (int vecin = 0; vecin < n; vecin++) {
            if (adj[node][vecin] && !visited[vecin]) {
                q.push(vecin);
                visited[vecin] = 1;
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            return false;
        }
    }

    return true;
}

int main() {
    ifstream fin("estearbore.in");
    ofstream fout("estearbore.out");

    int n, m = 0;
    fin >> n;
    int adj[size][size];
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            adj[i][j] = 0;
        }
    }

    int x, y;
    while (fin >> x >> y) {
        x--;
        y--;
        if (!adj[x][y]) {
            m++;
        }

        adj[x][y] = 1;
        adj[y][x] = 1;
    }

    fout << (esteArbore(n, m, adj) ? "DA\n" : "NU\n");

    return 0;
}
