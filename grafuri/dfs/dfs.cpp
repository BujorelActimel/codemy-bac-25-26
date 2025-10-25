#include <iostream>
#include <stack>

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

    // parcurgerea in adancime (DFS)
    cout << "Parcurgere DFS:\n";
    stack<int> stiva;
    int vizitat[n];
    initializeaza(vizitat, n);

    stiva.push(0);
    vizitat[0] = 1;
    while (!stiva.empty()) {
        int i = stiva.top();
        stiva.pop();
        cout << i+1 << ' ';

        for (int j = 0; j < n; j++) {
            if (a[i][j] && !vizitat[j]) {
                stiva.push(j);
                vizitat[j] = 1;
            }
        }
    }

    return 0;
}
