#include <fstream>
#include <iostream>

using namespace std;

int main() {
    // rand 1 si 2
    ifstream fin("input.txt");
    int n;
    fin >> n;
    int a[n][n];

    cout << "Noduri terminale:\n";
    for (int i = 0; i < n; i++) {
        int grad = 0;
        for (int j = 0; j < n; j++) {
            fin >> a[i][j];
            grad += a[i][j];
        }
        if (grad == 1) {
            cout << i+1 << '\n';
        }
    }
    cout << "\nNoduri izolate:\n";
    for (int i = 0; i < n; i++) {
        int grad = 0;
        for (int j = 0; j < n; j++) {
            grad += a[i][j];
        }
        if (grad == 0) {
            cout << i+1 << '\n';
        }
    }

    return 0;
}
