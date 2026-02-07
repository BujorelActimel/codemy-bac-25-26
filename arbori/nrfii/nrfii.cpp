#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("nrfii.in");
ofstream fout("nrfii.out");

int n, tati[101], nrfii[101];

void parcurgere(){
    for(int i=1; i<=n; i++){
        nrfii[tati[i]]++;
    }
} 

int main()
{
    fin>>n;
    for(int i=1; i<=n; i++){
        fin>>tati[i];
    }
    parcurgere();
    int max_fii=0;
    for(int i=1; i<=n; i++){
        if(nrfii[i]>max_fii)
            max_fii=nrfii[i];
    }
    for(int i=1; i<=n; i++){
        if(nrfii[i]==max_fii){
            fout<<i<<' ';
        }
    }
    return 0;
} 
