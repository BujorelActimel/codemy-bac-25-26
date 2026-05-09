#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // sort(a, a+n);

    // cout << max(a[0] * a[1], a[n-2] * a[n-1]);

    int min1 = a[0], min2 = a[0];
    int max1 = a[0], max2 = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] < min1) {
            min2 = min1;
            min1 = a[i];
        }
        else if (a[i] < min2) {
            min2 = a[i];
        }
        else if (a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        }
        else if (a[i] > max2) {
            max2 = a[i];
        }
    }

    cout << max(min1*min2, max1*max2);

    return 0;
}
