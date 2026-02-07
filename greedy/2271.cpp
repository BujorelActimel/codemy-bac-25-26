#include <iostream>
#define MAX 1000000


using namespace std;

int main() {
    long long n;
    cin >> n;

    long long Min = MAX, Min2 = MAX, Max = -MAX, Max2 = -MAX;

    for (long long i = 0; i < n; i++) {
        long long numar;
        cin >> numar;

        if (numar < Min) {
            Min2 = Min;
            Min = numar;
        }
        else if (numar < Min2) {
            Min2 = numar;
        }

        if (numar > Max) {
            Max2 = Max;
            Max = numar;
        }
        else if (numar > Max2) {
            Max2 = numar;
        }
    }
    
    cout << max(Min2*Min, Max2*Max) << '\n';

    return 0;
}
