#include <iostream>

using namespace std;

int a,b,x[11];

int cond(int i)
{
    for(int j=1;j<i;j++)
    {
        if(x[i]==x[j])
            return 0;
    }
    return 1;
}

void afisare()
{
    for(int j=1;j<=b-a+1;j++)
    {
        cout<<x[j]<<' ';
    }
    cout<<'\n';
}

int main()
{
    cin>>a>>b;
    int i=1;
    x[i]=a-1;
    while(i>=1)
    {
        if(x[i]<b)
        {
            x[i]++;
            if(cond(i))
                if(i==b-a+1)
                    afisare();
                else
                {
                    i++;
                    x[i]=a-1;
                }
        }
        else
            i--;
    }

    return 0;
} 
