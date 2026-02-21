// citeste m,n
// #  (numere naturale, 1<m<n)
// repeta
//     x<-m; y<-n; n<-n-1
//     repeta
//         daca x>y atunci x<-x-y
//             altfel y<-y-x
//         sf
//     pana cand y=0
// pana cand x!=1
// scrie n+1

#include <iostream>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    int x, y;
    do {
        x = m;
        y = n;
        n--;
        do {
            if (x > y) {
                x -= y;
            }
            else {
                y -= x;
            }
        } while (y);
    } while (x == 1);
    cout << n + 1;
    return 0;
}
