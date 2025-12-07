#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

// functie suma elem subarbore
int sumaSubarbore(int tati[], int valori[], int n, int p) {
    int suma = 0;

    queue<int> coada;
    coada.push(p);

    while (!coada.empty()) {
        int elemCurent = coada.front();
        coada.pop();
        suma += valori[elemCurent];

        for (int i = 1; i <= n; i++) {
            if (tati[i] == elemCurent) {
                coada.push(i);
            }
        }
    }

    return suma;
}

int main() {
    ifstream fin("sumsubmax.in");
    ofstream fout("sumsubmax.out");

    int n;
    fin >> n;

    int tati[n+1];
    for (int i = 1; i <= n; i++) {
        fin >> tati[i];
    }
    int valori[n+1];
    for (int i = 1; i <= n; i++) {
        fin >> valori[i];
    }

    int sumaMax = sumaSubarbore(tati, valori, n, 1);    
    for (int nod = 2; nod <= n; nod++) {
        sumaMax = max(sumaMax, sumaSubarbore(tati, valori, n, nod));
    }

    for (int nod = 1; nod <= n; nod++) {
        int suma = sumaSubarbore(tati, valori, n, nod);
        if (suma == sumaMax) {
            fout << nod << ' '; 
        }
    }


    return 0;
}
