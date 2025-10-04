#include <iostream>
#include <fstream>

using namespace std;

int grad(int a[], int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += a[i];
    }
    return s;
}

void elimina(int a[][101], int n, int nod) {
    for (int i = 1; i <= n; i++) {
        a[nod][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        a[i][nod] = 0;
    }
}

int main() {
    ifstream fin("subgraf1.in");
    ofstream fout("subgraf1.out");

    int n;
    fin >> n;

    int a[101][101] = {0};

    int v1, v2;
    while (fin >> v1 >> v2) {
        a[v1][v2] = 1;
        a[v2][v1] = 1;
    }

    int gradMinim = grad(a[1], n);
    for (int i = 2; i <= n; i++) {
        gradMinim = min(gradMinim, grad(a[i], n));
    }

    for (int i = 1; i <= n; i++) {
        int g = grad(a[i], n);
        if (g == gradMinim) {
            elimina(a, n, i);
        }
    }

    int muchiiRamase = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            muchiiRamase += a[i][j];
        }
    }

    muchiiRamase /= 2;

    fout << muchiiRamase << '\n';

    return 0;
}
