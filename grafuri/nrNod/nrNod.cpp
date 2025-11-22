#include <fstream>

using namespace std;

ifstream fin("nrnod.in");
ofstream fout("nrnod.out");

int n,st[1001],dr[1001];

int parc(int v) {
    if(v!=0) {
        int nr=0,x,y,nr1=0,nr2=0;
        fin>>x;
        if(x!=0) {
            nr1=parc(x);
            nr++;
        }
        fin>>y;
        if(y!=0) {
            nr2=parc(y);
            nr++;
        }
        return nr1+nr2+(nr==1);
    }
    else
        return 0;
}
int main() {
    int v;
    fin>>v;
    fout<<parc(v);
    fin.close();
    fout.close();
    return 0;
}