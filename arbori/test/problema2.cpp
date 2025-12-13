#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void ascendenti(int tati[], int root, int nod, vector<int>& rezultat) {
    if (nod == root) {
        return;
    }

    if (root == tati[nod]) {
        rezultat.push_back(root);
        return;
    }

    rezultat.push_back(tati[nod]);
    ascendenti(tati, root, tati[nod], rezultat);
}

int ascComun(int tati[], int root, int nod1, int nod2) {
    vector<int> asc1;
    vector<int> asc2;

    ascendenti(tati, root, nod1, asc1);
    ascendenti(tati, root, nod2, asc2);

    for (int i1: asc1) {
        for (int i2: asc2) {
            if (i1 == i2) {
                return i1;
            }
        }
    }
}

int main() {
    ifstream fin("input_sd.txt");
    int n;
    fin >> n;

    int tati[n+1];
    for (int i = 1; i <= n; i++) {
        tati[i] = 0;
    }

    int valori[n+1];
    int root;

    for (int i = 1; i <= n; i++) {
        int nod, st, dr, val;
        fin >> nod >> st >> dr >> val;
        tati[st] = nod;
        tati[dr] = nod;
        valori[nod] = val;
    }
    for (int i = 1; i <= n; i++) {
        if (!tati[i]) {
            root = i;
        }
    }

    // a
    int nod;
    vector<int> asc;
    cin >> nod;
    cout << "Ascendentii lui " << nod << ": ";
    ascendenti(tati, root, nod, asc);
    for (int i: asc) {
        cout << i << ' ';
    }
    cout << '\n';

    // b
    // int nod1, nod2;
    // cin >> nod1 >> nod2;
    
    // int asc << ascComun(tati, root, nod1, nod2);

    // int nodCurent = nod1;
    // while (nodCurent != )

    return 0;
}
