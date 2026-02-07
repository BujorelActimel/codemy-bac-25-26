#include <bits/stdc++.h>

using namespace std;

struct obiect {
    int greutate; 
    int valoare;
} a[1005];

int n, gmax;

bool comp(obiect A, obiect B) {
    return A.valoare * B.greutate > A.greutate * B.valoare;
}

void solve() {
    cin >> n >> gmax;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i].greutate >> a[i].valoare;
    }
    sort(a + 1 , a + n + 1, comp);
    int g = 0 , i = 1;
    double rez = 0;
    while (i <= n) {
        if (g + a[i].greutate <= gmax) {
            g += a[i].greutate;
            rez += a[i].valoare;
            i++;
        }
        else if (gmax - g > 0) {
            double factor = 1.0 * (gmax - g) / a[i].greutate;
            g = gmax;
            rez += factor * a[i].valoare;
            i++;
        }
        else {
            //i = n + 1;
            break;
        }
    }
    cout << rez;
}

int main() {
    solve();
    return 0;
}
