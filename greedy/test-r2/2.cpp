#include <iostream>

using namespace std;

int n,a[101];
int f[101];

int findf(int x[101],int nr)
{
    for(int j=1;j<=nr;j++)
    {
        if(x[j]==0)
            return j;
    }
    return 0;
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int c=0;
    int i=findf(f,n);
    int ultu=i;
    f[i]=1;
    while(i!=0)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(a[j]>a[ultu] && f[j]==0)
            {
                ultu=j;
                f[j]=1;
            }
        }
        for (int j = 1; j <= n; j++) {
            cout << f[j] << ' ';
        }
        cout << '\n';
        cout << "i = " << i << '\n';
        i=findf(f,n);
        f[i] = 1;
        ultu = i;
        c++;
    }
    cout<<c;

    return 0;
} 
