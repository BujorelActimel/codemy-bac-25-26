#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("frunze.in");
    ofstream fout("frunze.out");

    int n;
    fin >> n;
    int tati[101];
    int frunze[101] = {0};

    int radacina;
    for (int i = 1; i <= n; i++) {
        fin >> tati[i];
        if (tati[i] == 0) {
            radacina = i;
        }
        frunze[tati[i]] = 1;
    }

    fout << radacina << '\n';
    int nrFrunze = 0;
    for (int i = 1; i <= n; i++) {
        if (frunze[i] == 0) {
            nrFrunze++;
        }
    }
    fout << nrFrunze << '\n';
    for (int i = 1; i <= n; i++) {
        if (frunze[i] == 0) {
            fout << i << ' ';
        }
    }

    return 0;
}
