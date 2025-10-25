#include <fstream>

using namespace std;

int main() {
    ifstream fin("graf_complet.in");
    ofstream fout("graf_complet.out");
    int g;
    fin >> g;
    while (g--) {
        int n;
        fin >> n;
        int a[n][n];
        int count0 = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                fin >> a[i][i];
                if (!a[i][i]) {
                    count0++;
                }
            }
        }
        fout << (count0 == n ? "DA\n" : "NU\n");
    }
    
    fin.close();
    fout.close();
    return 0;
}
