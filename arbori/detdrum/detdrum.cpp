#include <fstream>

using namespace std;

ifstream fin("detdrum.in");
ofstream fout("detdrum.out");

int n,k,tati[101],r;

void distanta(int v)
{
    fout<<v<<' ';
    if(v==r)
        return;
    else
        distanta(tati[v]);
}

int main()
{
    fin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        fin>>tati[i];
        if(tati[i]==0)
            r=i;
    }
    distanta(k);
    fin.close();
    fout.close();
    return 0;
} 
