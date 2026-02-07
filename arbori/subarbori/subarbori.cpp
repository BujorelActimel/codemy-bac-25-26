#include <fstream>

using namespace std;

ifstream fin("subarbori.in");
ofstream fout("subarbori.out");

int n,p[101];

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
    fin>>n;
    for(int i=1;i<=n;i++)
    {
        fin>>p[i];
    }
    int c=0;
    for(int i=1; i<n; i++){
        for(int j=i+1; j<=n; j++){
            if(parc(i)==parc(j) && parc(i)!=1){
                c++;
            }
        }
    }
    fout<<c;
    fin.close();
    fout.close();
    return 0;
} 

