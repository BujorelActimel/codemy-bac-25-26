#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

// 1 - cate frunze cu informatii pare
// frunza = nod fara fii

// 2 - inaltimea arborelui
// inalitmea = cel mai lung lant de la radacina la o frunza

// 3 - pt un nivel, daca are numar maxim de noduri
// parcurgere pe nivele = bfs

int dist(int tati[], int root, int nod) {
    int nivel = 0;

    while (nod != root) {
        nod = tati[nod];
        nivel++;
    }

    return nivel;
}

bool areNivelMaxim(int tati[], int n, int root, int nivel) {
    queue<int> coada;
    coada.push(root);
    int nivelCurent = 0;

    int nrNoduriMax = 0;
    int nivelMax = 0;

    while (!coada.empty()) {
        cout << "nivel " << nivelCurent << '\n';

        int nrNoduri = coada.size();

        if (nrNoduri > nrNoduriMax) {
            nrNoduriMax = nrNoduri;
            nivelMax = nivelCurent;
        }

        nivelCurent++;

        for (int i = 0; i < nrNoduri; i++) {
            int nodCurent = coada.front();
            cout << nodCurent << ' ';
            coada.pop();
            for (int i = 1; i <= n; i++) {
                if (tati[i] == nodCurent) {
                    coada.push(i);
                }
            }
        }   
        cout << "\n\n";
    }

    return nivel == nivelMax;
}

int main(int argc, char** argv) {
    if (string(argv[1]) == "sd") {
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

        // bis ca mai jos

        return 0;
    } else {
        ifstream fin("input.txt");
        int n;
        fin >> n;
        int tati[n+1];
        int valori[n+1];

        int root;

        for (int i = 1; i <= n; i++) {
            fin >> tati[i];
            if (tati[i] == 0) {
                root = i;
            }
        }
        for (int i = 1; i <= n; i++) {
            fin >> valori[i];
        }

        // 1
        int frunze[n+1];
        for (int i = 1; i <= n; i++) {
            frunze[i] = 1;
        }

        for (int i = 1; i <= n; i++) {
            frunze[tati[i]] = 0;
        }

        int contor = 0;
        for (int i = 1; i <= n; i++) {
            if (frunze[i] && valori[i] % 2 == 0) {
                contor++;
            }
        }
        cout << contor << '\n';

        // 2
        int inaltime = 0;
        for (int i = 1; i <= n; i++) {
            if (frunze[i]) {
                inaltime = max(inaltime, dist(tati, root, i));
            }
        }
        cout << inaltime << '\n';

        // 3
        cout << areNivelMaxim(tati, n, root, 2);


        return 0;
    }
}
