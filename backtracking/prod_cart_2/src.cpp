#include <fstream>

using namespace std;

ifstream fin("produscartezian2.in");
ofstream fout("produscartezian2.out");

int n,x[8],v[8];

void afisare()
{
    for(int i=1;i<=n;i++)
        fout<<x[i]<<' ';
    fout<<'\n';
}

void bkt(int i)
{
    for(int j=1;j<=v[i];j++)
    {
        x[i]=j;
        if(i==n)
            afisare();
        else
            bkt(i+1);
    }
}

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
        fin>>v[i];
    bkt(1);
    fin.close();
    fout.close();
    return 0;
} 
