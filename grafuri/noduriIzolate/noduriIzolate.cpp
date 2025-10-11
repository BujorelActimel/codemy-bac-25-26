#include <iostream>

using namespace std;

long long max(long long first, long long second) {
    if (first > second) {
        return first;
    }
    return second;
}

int main() {
    long long n, m;
    cin >> n >> m;

    long long k = 1;
    while (k*(k-1)/2 < m) {
        k++;
    }

    int a = max(0, n-2*m);

    cout << a << ' ' << n - k << '\n';
    return 0;
}
