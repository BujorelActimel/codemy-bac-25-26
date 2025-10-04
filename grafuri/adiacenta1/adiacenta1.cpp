#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("adiacenta1.in");
    ofstream fout("adiacenta1.out");

    int a[101][101] = {0};
    
    int v1, v2;
    int noduri = 0;

    while (fin >> v1 >> v2) {
        a[v1][v2] = 1;
        a[v2][v1] = 1;
        noduri = max(noduri, max(v1, v2));
    }

    for (int i = 1; i <= noduri; i++) {
        for (int j = 1; j <= noduri; j++) {
            fout << a[i][j] << ' ';
        }
        fout << '\n';
    }

    return 0;
}
