#include <fstream>
#include <iostream>
#include <queue>

using namespace std;

void initializeaza(int a[], int n) {
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
    }
}

int main() {
    ifstream fin("input.txt");
    int n;
    fin >> n;
    int a[n+1][n+1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            fin >> a[i][j];
        }
    }

    int nod1, nod2;
    cin >> nod1 >> nod2;

    queue<int> coada;
    int vizitat[n+1];
    initializeaza(vizitat, n);

    coada.push(nod1);
    vizitat[nod1] = 1;
    while (!coada.empty()) {
        int nodCurent = coada.front();
        coada.pop();
        if (nodCurent == nod2) {
            cout << "DA\n";
            return 0;
        }
        for (int j = 1; j <= n; j++) {
            if (a[nodCurent][j] && !vizitat[j]) {
                coada.push(j);
                vizitat[j] = 1;
            }
        }
    }
    cout << "NU\n";

    return 0;
}
