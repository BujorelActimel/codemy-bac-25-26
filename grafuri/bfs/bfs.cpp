#include <iostream>
#include <queue>

using namespace std;

void initializeaza(int a[], int n) {
    for (int i = 0; i < n; i++) {
        a[i] = 0;
    }
}

int main() {
    int n;
    cin >> n;
    int a[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // parcurgerea in latime (BFS)
    cout << "Parcurgere BFS:\n";
    queue<int> coada;
    int vizitat[n];
    initializeaza(vizitat, n);

    coada.push(0);
    vizitat[0] = 1;
    while (!coada.empty()) {
        int i = coada.front();
        coada.pop();
        cout << i+1 << ' ';

        for (int j = 0; j < n; j++) {
            if (a[i][j] && !vizitat[j]) {
                coada.push(j);
                vizitat[j] = 1;
            }
        }
    }

    return 0;
}
