#include <iostream>

using namespace std;

int n,a,b;

int main()
{
    cin>>n>>a>>b;
    int nra=n/a;
    while((n-nra*a)%b!=0)
    {
        nra--;
    }
    for(int i=1;i<=nra;i++)
    {
        cout<<a<<' ';
    }
    for(int j=1;j<=(n-nra*a)/b;j++)
    {
        cout<<b<<' ';
    }


    return 0;
} 