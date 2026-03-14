#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("bac.in");

int main()
{
    int minz,minp;
    fin>>minz>>minp;
    int i=1,j=1,sc=0,af=0;
    int x;
    while(fin>>x)
    {
        if(x>=minz)
        {
            sc=sc+x;
        }
        else
        {
            if(sc>=minp && j-i>=2)
            {
                cout<<i<<' '<<j-1<<' '<<sc<<endl;
                af++;
            }
            i=j+1;
            sc = 0;
        }
        j++;
    }

    if(sc>=minp && j-i>=2)
    {
        cout<<i<<' '<<j-1<<' '<<sc<<endl;
        af++;
    }

    if(af==0)
        cout<<"nu exista";

    fin.close();

    return 0;
} 
