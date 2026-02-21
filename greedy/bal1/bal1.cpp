#include <fstream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("bal.in");
ofstream fout("bal.out");

int main() {
    int n,m;
    vector<int> f;
    vector<int> b;
    fin>>n>>m;
    for(int i=1; i<=n; i++) {
        int nr;
        fin >> nr;
        f.push_back(nr);
    }
    for(int i=1; i<=m; i++) {
        int nr;
        fin >> nr;
        b.push_back(nr);
    }

    sort(f.begin(), f.end());
    sort(b.begin(), b.end());

    int i=0,j=0,c=0;
    while(i<n && j<m)
    {
        if(f[i]<=b[j])
        {
            c++;
            i++;
            j++;
        }
        else
            j++;
    }
    fout<<c;

    fin.close();
    fout.close();

    return 0;
}
