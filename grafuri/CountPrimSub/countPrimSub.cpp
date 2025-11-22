#include <iostream>
#include <fstream>

using namespace std;

int st[1000], dr[1000], val[1000];

int prim(int nr) {
    if (nr < 2) {
        return 0;
    }
    if (nr == 2) {
        return 1;
    }
    if (nr % 2 == 0) {
        return 0;
    }
    for (int d = 3; d * d <= nr; d += 2) {
        if (nr % d == 0) {
            return 0;
        }
    }
    return 1;
}

int nrPrime(int r) {
    if (r == 0) {
        return 0;
    }
    int suma = prim(val[r]);
    suma += nrPrime(st[r]);
    suma += nrPrime(dr[r]);
    return suma;
}

int main() {
    ifstream fin("countprimsub.in");
    ofstream fout("countprimsub.out");

    int n;
    fin>>n;
    for(int i=1;i<=n;i++){
        fin>>val[i]>>st[i]>>dr[i];
    }

    int k;
    fin >> k;
    for (int i = 1; i <= k; i++) {
        int r;
        fin >> r;
        fout << nrPrime(r) << '\n';
    }

    return 0;
}
