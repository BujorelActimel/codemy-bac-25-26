#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("adiacenta.in");
    ofstream fout("adiacenta.out");
    int noduri, muchii;
    fin >> noduri >> muchii;

    int a[noduri+1][noduri+1];

    for (int i = 1; i <= noduri; i++) {
        for (int j = 1; j <= noduri; j++) {
            a[i][j] = 0;
        }
    }
    
    int v1, v2;

    for (int i = 0; i < muchii; i++) {
        fin >> v1 >> v2;
        a[v1][v2] = 1;
        a[v2][v1] = 1;
    }

    for (int i = 1; i <= noduri; i++) {
        for (int j = 1; j <= noduri; j++) {
            fout << a[i][j] << ' ';
        }
        fout << '\n';
    }

    return 0;
}
