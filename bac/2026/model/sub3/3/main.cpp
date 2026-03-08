// 26^p : 1*2*..*n


// 10! = 1 * 2 * 3 * (2*2) * 5 * (2*3)


// 26 = 2 * 13


// 26^p : n!

// for (int i = 1; i <= n: ) {

// }

// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28

#include <iostream>

using namespace std;

int cati_13(int n) {
    int cnt = 0;
    while (n % 13 == 0) {
        n /= 13;
        cnt++;
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;

    int contor_13 = 0;

    for (int i = 1; i <= n; i++) {
        contor_13 += cati_13(i);
    }

    cout << contor_13 << '\n';

    return 0;
}
