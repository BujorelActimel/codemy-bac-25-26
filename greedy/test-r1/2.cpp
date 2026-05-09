#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int l = 0, r = 1;

    int s = a[l] + a[r];

    while (s % n != 0) {
        for (int i = l - 1; i >= 0; i--) {
            s += a[i];
            if (s % n == 0) {
                cout << i+1 << ' ' << r+1 << '\n';
                return 0;
            }
        }
        l++;
        r++;
        s = a[l] + a[r];
    }

    cout << l+1 << ' ' << r+1 << '\n';

    return 0;
}
