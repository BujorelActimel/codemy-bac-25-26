#include <iostream>
#include <queue>
#define INF -1

int max(int a[], int n);

int main() {
    int n, m, k;
    std::cin >> n >> m >> k;
    int a[101][101] = {0};

    for (int i = 0; i < m; i++) {
        int n1, n2;
        std::cin >> n1 >> n2;
        a[n1][n2] = 1;
        a[n2][n1] = 1;
    }

    int dist[n+1];
    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }
    dist[k] = 0;

    std::queue<int> coada;
    coada.push(k);
    while (!coada.empty()) {
        int nodCurent = coada.front();
        coada.pop();
        for (int j = 1; j <= n; j++) {
            if (a[nodCurent][j] && dist[j] == INF) {
                dist[j] = dist[nodCurent]+1;
                coada.push(j);
            }
        }
    }

    int distMax = max(dist, n);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == distMax) {
            std::cout << i << ' ';
        }
    }
    std::cout << '\n';

    return 0;
}

int max(int a[], int n) {
    int res = a[1];
    for (int i = 2; i <= n; i++) {
        if (a[i] > res) {
            res = a[i];
        }
    }
    return res;
}
