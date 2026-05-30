#include <fstream>

using namespace std;

ifstream fin("sumtri.in");
ofstream fout("sumtri.out");

int n,v[101][101],s[101][101];

int main()
{
    fin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            fin>>v[i][j];
    
    s[1][1]=v[1][1];
    for(int i=2;i<=n;i++)
        for(int j=1;j<=i;j++) {
            // verif vecinii de sus
            s[i][j]=max(s[i-1][j],s[i-1][j-1])+v[i][j];
        }
    int mx=0;
    for(int j=1;j<=n;j++)
        if(s[n][j]>=mx)
            mx=s[n][j];
    fout<<mx;
    fin.close();
    fout.close();
    return 0;
} 
