#include <fstream>
#include <iostream>

using namespace std;

int n, m;

int memo[1001][1001];

int countPaths(int x, int y) {
    if (x > n || y > m) {
        return 0;
    }

    if (x == n && y == m) {
        return 1;
    }

    if (memo[x][y] != -1) {
        return memo[x][y];
    }

    memo[x][y] = (countPaths(x+1, y) % 9901 + countPaths(x, y+1) % 9901) % 9901;

    return memo[x][y];
}

int main() {
    ifstream fin("cladire.in");
    ofstream fout("cladire.out");

    fin >> n >> m;

    memo[1][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            memo[i][j] = -1;
        }
    }

    fout << countPaths(1, 1) % 9901;

    return 0;
}
