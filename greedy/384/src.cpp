#include <bits/stdc++.h>
using namespace std;

struct point {
    int x, y;
};

vector<point> getNextPositions(int a[][101], int n, int m, point pct) {
    vector<point> pos;

    int di[]= {-2,-2,-1,-1,+1,+1,+2,+2};
    int dj[]= {1,-1,2,-2,2,-2,1,-1}; 

    point newPos = pct;

    for (int i = 0; i < 8; i++) {
        newPos.x = pct.x + di[i];
        newPos.y = pct.y + dj[i];

        if (
            newPos.x > 0 && 
            newPos.x <= n &&
            newPos.y > 0 &&
            newPos.y <= m &&
            a[newPos.x][newPos.y] == 0
        ) {
            pos.push_back(newPos);
        } 
    }

    return pos;
}

int main() {
    ifstream fin("saritura_calului1.in");
    ofstream fout("saritura_calului1.out");

    int n, m;
    point curent;
    fin >> n >> m >> curent.x >> curent.y;

    int a[101][101];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            a[i][j] = 0;
        }
    }
    a[curent.x][curent.y] = 1;

    int pas = 2;
    auto nextPos = getNextPositions(a, n, m, curent);

    while (nextPos.size() != 0) {
        int min = INT_MAX;
        for (auto pos : nextPos) {
            int choices = getNextPositions(a, n, m, pos).size();
            if (choices < min) {
                min = choices;
                curent = pos;
            }
        }
        a[curent.x][curent.y] = pas++;
        nextPos = getNextPositions(a, n, m, curent);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            fout << a[i][j] << ' ';
        }
        fout << '\n';
    }

    return 0;
}


// 1 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0
// 0 0 0 0 0