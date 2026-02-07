#include <fstream>

using namespace std;

ifstream fin("detdrum3.in");
ofstream fout("detdrum3.out");

int n,p[101],inf[101],fr[101];

int suma(int v)
{
    if(p[v]!=0)
        return inf[v]+suma(p[v]);
    return inf[v];
}
void print(int v)
{
    if(p[v]!=0)
        print(p[v]);
    fout<<v<<' ';
}

int main()
{
    int r;
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>p[i];
        if(p[i]==0)
            r=i;
        fr[p[i]]=1;
    }
    for(int i=1;i<=n;i++)
    {
        fin>>inf[i];
    }
    int maxim=0;
    for(int i=1;i<=n;i++)
    {
        if(fr[i]==0)
            if(suma(i)>maxim)
                maxim=suma(i);
    }
    fout<<maxim<<endl;
    for(int i=1;i<=n;i++)
    {
        if(fr[i]==0)
            if(suma(i)==maxim)
            {
                print(i);
                break;
            }
    }

    fin.close();
    fout.close();

    return 0;
}
