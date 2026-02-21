#include <bits/stdc++.h>

using namespace std;

ifstream fin("concert.in");
ofstream fout("concert.out");

string before(string s, char c){
    return s.substr(0, s.find(c));
}

string after(string s, char c) {
    return s.substr(s.find(c)+1);
}

int main() {
    int n, t;

    vector<pair<int, int>> durate;
    fin >> n >> t;

    for(int i=1; i<=n; i++) {
        string line;
        fin >> line;
        int m = stoi(before(line, ':'));
        int s = stoi(after(line, ':'));
        
        durate.push_back(pair<int, int>(i, m * 60 + s));
    }

    sort(durate.begin(), durate.end(), [](const pair<int,int>& a, const pair<int,int>& b) {
        return a.second < b.second;
    });

    int i = 0;
    int cnt = 0;
    int rezultat[101];

    while (i < durate.size() && t - durate[i].second >= 0) {
        rezultat[cnt++] = durate[i].first;
        t -= durate[i].second;
        i++;
    }

    fout << cnt << '\n';
    sort(rezultat, rezultat + cnt);
    for (int i = 0; i < cnt; i++) {
        fout << rezultat[i] << ' ';
    }

    fin.close();
    fout.close();
    return 0;
}
