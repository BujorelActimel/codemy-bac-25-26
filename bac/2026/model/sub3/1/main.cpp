#include <iostream>
using namespace std;

int len(int n) {
    int result = 0;
    while (n > 0) {
        result++;
        n /= 10;
    }
    return result;
}

void Plus(int &n) {
    int lungime = len(n);
    int numar[lungime+1];
    for (int i = lungime; i >= 1; i--) {
        numar[i] = n % 10;
        n /= 10;
    }

    n = 0;
    for (int i = 1; i <= lungime; i++) {
        if (i > 1 && numar[i-1] == 2 && numar[i] == 5) {
            n = n * 10 + 6;
        }
        else {
            n = n * 10 + numar[i];
        }
    }
}

int main() {
    int n = 202535250;
    Plus(n);
    cout << n << '\n';
    return 0;
}
