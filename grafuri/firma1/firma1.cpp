#include <fstream>
using namespace std;

int venituri(int angajat, int ierarhie[], int salarii[], int n) {
    bool areSubalterni = 0;
    for (int i = 1; i <= n; i++) {
        if (ierarhie[i] == angajat) {
            areSubalterni = 1;
            break;
        }
    }

    if (!areSubalterni) {
        return salarii[angajat];
    }

    int suma = 0;
    int contor = 0;
    for (int i = 1; i <= n; i++) {
        if (ierarhie[i] == angajat) {
            suma += venituri(i, ierarhie, salarii, n);
            contor++;
        }
    }

    int media = suma/contor + (suma % contor > 0 ? 1 : 0);

    return salarii[angajat] + media;
}

int main() {
    ifstream fin("firma1.in");
    ofstream fout("firma1.out");

    int n;
    fin >> n;
    int ierarhie[n+1], salarii[n+1];
    int director_general;

    for (int i = 1; i <= n; i++) {
        fin >> ierarhie[i];
        if (ierarhie[i] == 0) {
            director_general = i;
        }
    }
    for (int i = 1; i <= n; i++) {
        fin >> salarii[i];
    }

    fout << venituri(director_general, ierarhie, salarii, n) << '\n';
    return 0;
}
