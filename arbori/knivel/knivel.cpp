#include <fstream>

using namespace std;

ifstream fin("knivel.in");
ofstream fout("knivel.out");

int n,tati[101],k,niv[101];

void nivel(int v,int niv_curent)
{
    niv[v]=niv_curent;
    for(int i=1;i<=n;i++)
    {
        if(tati[i]==v)
            nivel(i,niv_curent+1);
    }
}

int main() {
    fin>>n>>k;
    int r;
    for(int i=1;i<=n;i++)
    {
        fin>>tati[i];
        if(tati[i]==0)
            r=i;
    }
    nivel(r,1);
    for(int i=1;i<=n;i++)
    {
        if(niv[i]==k)
            fout<<i<<' ';
    }
    fin.close();
    fout.close();
    return 0;
}
