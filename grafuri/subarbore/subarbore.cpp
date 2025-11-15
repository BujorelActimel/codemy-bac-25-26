#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("subarbore.in");
    ofstream fout("subarbore.out");

    int n,k,p[101];
    vector<int>v;
    fin>>n>>k;
    for(int i=1;i<=n;i++) {
        fin>>p[i];
    }

    int viz[101]={0};
    queue<int> c;
    c.push(k);
    viz[k]=1;
    while(!c.empty()) {
        int elemCurent = c.front();
        c.pop();
        for(int i=1;i<=n;i++) {
            if(viz[i]==0 && p[i]==elemCurent){
                c.push(i);
                viz[i]=1;
                v.push_back(i);
            }
        }
    }
    v.push_back(k);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++) {
        fout<<v[i]<<' ';
    }

    fin.close();
    fout.close();

    return 0;
} 
