// 5 8 3 7 7 
// 1 1 4 5 1 
// 5 8 9 1 7 
// 5 8 6 6 9 

// 5  8  3  7  7
// 9  9  12 12 8
// 14 20 21 13 19
// 25 29 27 27 28

#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("comori.in");
ofstream fout("comori.out");

int main()
{
    int n,m,a[201][201];
    fin>>n>>m;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            fin>>a[i][j];
        }
    }

    int s[201][201];
    for(int j=1;j<=m;j++) {
        s[1][j]=a[1][j];
    }

    for(int i=2;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            s[i][j] += a[i][j];

            if (j == 1) {
                s[i][j] += max(s[i-1][j], s[i-1][j+1]);
            }
            else if (j == m) {
                s[i][j] += max(s[i-1][j], s[i-1][j-1]);
            }
            else {
                s[i][j] += max(s[i-1][j-1], max(s[i-1][j], s[i-1][j+1]));
            }
        }
    }

    int mx=0;
    for(int i=1;i<=m;i++) {
        if(mx<s[n][i]) {
            mx=s[n][i];
        }
    }

    fout<<mx;
    fin.close();
    fout.close();
    return 0;
} 
