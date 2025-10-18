#include <fstream>
#include <queue>

using namespace std;

ifstream fin("componenteconexe2.in");
ofstream fout("componenteconexe2.out");

bool visitedAll(int v[], int n) {
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0) {
            return false;
        }
    }
    return true;
}

int visit(int v[], int n) {
    for (int i = 1; i <= n; i++) {
        if (v[i] == 0) {
            return i;
        }
    }
    return 0;
}

int nrMuchii(int a[][101], int n) {
    int rez = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            rez += a[i][j];
        }
    }
    return rez/2;
}

int main() {
    int n, v1,v2;
    fin>>n;
    int a[101][101]={0};
    while(fin>>v1>>v2) {
        a[v1][v2]=1;
        a[v2][v1]=1;
    }

    queue<int> c;
    int v[101]={0},cc=1;
    while (!visitedAll(v, n)) {
        int toVisit = visit(v, n);
        c.push(toVisit);
        v[toVisit] = cc;
        while(!c.empty()) {
            for(int i=1;i<=n;i++)
            {
                if(v[i]==0 && a[c.front()][i]==1){
                    v[i]=cc;
                    c.push(i);
                }
            }
            c.pop();
        }
        cc++;
    }
    
    int rez = nrMuchii(a, n);

    for (int i = 1; i < cc; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            count += (v[j] == i);
        }
        rez -= (count-1);
    }

    fout << rez << '\n';

    fin.close();
    fout.close();

    return 0;
} 
