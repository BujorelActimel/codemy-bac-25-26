#include <iostream>
using namespace std;

int n, x[15], folosit[15];

void back(int k) {
    if (k > n) {
        for (int i = 1; i <= n; i++)
            cout << x[i] << " ";
        cout << "\n";
    } else {
        for (int i = 1; i <= n; i++) {
            if (!folosit[i]) {
                x[k] = i;
                folosit[i] = 1;
                back(k + 1);
                folosit[i] = 0;
            }
        }
    }
}

int main() {
    cin >> n;
    back(1);
    return 0;
}
