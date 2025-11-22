#include <fstream>

using namespace std;

int n,s[1001],d[1001],niv[1001];

void parc(int r,int niv_curent) {
    if(r!=0) {
        niv[niv_curent]++;
        parc(s[r],niv_curent+1);
        parc(d[r],niv_curent+1);
    }
}

int main() {
    ifstream fin("nivelebin.in");
    ofstream fout("nivelebin.out");
    fin>>n;
    int v,r=0,p[1001]={0};
    for(int i=1;i<=n;i++){
        fin>>v>>s[i]>>d[i];
        p[s[i]]=p[d[i]]=1;
    }
    for(int i=1;i<=n;i++)
        if(p[i]==0)
            r=i;
    parc(r,niv[r]);
    int poz=0;
    for(int i=1;i<=n;i++)
        if(niv[i]==0){
            poz=i-1;
            break;
        }
    fout<<poz+1<<endl;
    for(int i=0;i<=poz;i++)
        fout<<niv[i]<<' ';
    fin.close();
    fout.close();
    return 0;
}
