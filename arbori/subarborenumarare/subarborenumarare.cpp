#include <fstream>

using namespace std;

ifstream fin("subarborenumarare.in");
ofstream fout("subarborenumarare.out");

int n,k,p[101];

int parc(int v)
{
    int s=0;
    for(int i=1;i<=n;i++)
    {
        if(p[i]==v)
        {
            s=s+parc(i);
        }
    }
    return s+1;
}

int main()
{
    fin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        fin>>p[i];
    }
    fout<<parc(k);

    fin.close();
    fout.close();

    return 0;
}
