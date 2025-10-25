#include <fstream>
#include <iostream>

using namespace std;

void initializeaza(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
}

int main() {
    ifstream fin("input.txt");
    int n;
    fin >> n;
    int a[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fin >> a[i][j];
        }
    }

    int m;
    cin >> m;
    // verif lant elementar (sa nu se repete noduri)
    int vizitat[n];
    initializeaza(vizitat, n);

    int nodCurent;
    int elementar = true;
    cin >> nodCurent;
    nodCurent--;
    vizitat[nodCurent] = 1;
    m--;
    while (m--) {
        int nodUrmator;
        cin >> nodUrmator;
        nodUrmator--;

        if (
            a[nodCurent][nodUrmator] &&
            !vizitat[nodUrmator]
        ) {
            nodCurent = nodUrmator;
            vizitat[nodCurent] = 1;
        }
        else {
            elementar = false;
        }
    }

    if (elementar) {
        cout << "Lantul este elementar\n";
    }
    else {
        cout << "Lantul NU este elementar\n";
    }
    // pentru lant simplu, schimb vectorul vizitat cu o matrice pentru a verifica muchiile
    return 0;
}
