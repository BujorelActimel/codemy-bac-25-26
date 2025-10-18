#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("graf_partial_1.in");
ofstream fout("graf_partial_1.out");

int grad(int a[], int n){
    int suma=0;
    for(int i=1; i<=n; i++){
        suma+=a[i];
    }
    return suma;
}

int main()
{
    int n, v1,v2;
    fin>>n;
    int a[n+1][n+1];

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = 0;
        }
    }

    while(fin>>v1>>v2){
        a[v1][v2]=1;
        a[v2][v1]=1;
    }


    int grade[n+1];
    for(int i=1; i<=n; i++){
        grade[i]=grad(a[i],n);
    }
    int grmax=grade[1], grmin=grade[1];
    for(int i=2; i<=n; i++){
        if(grmax<=grade[i]){
            grmax=grade[i];
        }
        if(grmin>=grade[i]){
            grmin=grade[i];
        }
    }
    int rez=0;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(a[i][j]==1 && ((grade[i]==grmin && grade[j]==grmax)
            ||(grade[i]==grmax && grade[j]==grmin))){
                a[i][j]=0;
                a[j][i]=0;
                rez++;
            }
        }
    }
    fout<<rez<<endl;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            fout<<a[i][j]<<' ';
        }
        fout<<endl;
    }
    fin.close();
    fout.close();
    return 0;
}
