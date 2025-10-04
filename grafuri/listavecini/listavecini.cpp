#include <iostream>
#include <fstream>

using namespace std;

int suma(int a[], int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += a[i];
    }
    return s;
}

int main() {
    ifstream fin("listavecini.in");
    ofstream fout("listavecini.out");

    int n;
    fin >> n;

    int a[n+1][n+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = 0;
        }
    }

    int v1, v2;
    while (fin >> v1 >> v2) {
        a[v1][v2] = 1;
        a[v2][v1] = 1;
    }

    for (int i = 1; i <= n; i++) {
        fout << suma(a[i], n) << ' ';
        for (int j = 1; j <= n; j++) {
            if (a[i][j]) {
                fout << j << ' '; 
            }
        }
        fout << '\n';
    }

    return 0;
}
