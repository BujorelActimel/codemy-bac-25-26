#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

vector <int> find_sons(vector <int> parinti, int p[], int n) {
    vector <int> rezultat;
    for(int i=1;i<=n;i++) {
        for(int j=0;j<parinti.size();j++) {
            if(p[i]==parinti[j])
                rezultat.push_back(i);
        }
    }
    return rezultat;
}

int main() {
    ifstream fin("nivele11.in");
    ofstream fout("nivele11.out");
    int p[101],n,rad;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>p[i];
        if(p[i]==0)
            rad=i;
    }
    vector <int> parinti,fii;
    fout<<rad<<endl;
    parinti.push_back(rad);
    fii=find_sons(parinti,p,n);
    while(!fii.empty()) {
        for(int i=0;i<fii.size();i++)
            fout << fii[i] << ' ';
        fout << '\n';
        parinti=fii;
        fii=find_sons(parinti,p,n);
    }
    fin.close();
    fout.close();
    return 0;
}
