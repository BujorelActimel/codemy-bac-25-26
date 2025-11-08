#include<iostream>
#include <fstream>
#include <queue>

#define inf -1

using namespace std;

int main() {
    ifstream fin("nivele.in");  
    ofstream fout("nivele.out");
    int n;
    fin>>n;
    int a[101][101]={0};
    int radacina;
    int tati[101];
    for(int i=1; i<=n; i++){
        fin>>tati[i];
        a[i][tati[i]]=a[tati[i]][i]=1;
        if(tati[i]==0)
            radacina=i;
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << tati[i] << ' ';
    // }
    // cout << '\n';
    int k;
    fin>>k;
    int dist_nod[101];
    for (int i = 1; i <= n; i++) {
        dist_nod[i]=inf;
    }
    dist_nod[radacina]=0;
    queue<int> coada;
    coada.push(radacina);
    while(!coada.empty()){
        int nod_curent=coada.front();
        coada.pop();
        for(int j=1; j<=n; j++){
            if(a[nod_curent][j]==1 && dist_nod[j]==inf){
                dist_nod[j]=dist_nod[nod_curent]+1;
                coada.push(j);
            }
        }
    }
    
    
    int nod;
    for(int i=1; i<=k; i++){
        fin>>nod;
        fout<<dist_nod[nod]+1<<'\n';
    }
    
    return 0;
}