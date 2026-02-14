#include <iostream>

using namespace std;

int main()
{
    int n,m,v1,v2,c,a[101][101]={0};
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>v1>>v2>>c;
        a[v1][v2]=a[v2][v1]=c;
    }
    int mn=-1,vf;
    for(int i=1;i<=n;i++)
    {
        float ma=0;
        int nr_term=0;
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]!=0)
            {
                ma+=a[i][j];
                nr_term++;
            }
        }
        ma=ma/(nr_term*1.0);
        if(mn==-1 || mn>ma)
            mn=ma,vf=i;
    }
    cout<<vf;
    return 0;
} 
