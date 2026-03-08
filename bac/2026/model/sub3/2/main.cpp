#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a[n+1][n+1];
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            cin>>a[i][j];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=n-i+1; j<=n; j++){
            a[i][j]=a[i][j+1];
        }
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-1; j++){
            cout<<a[i][j]<<' ';
        }
        cout<<'\n';
    }
    return 0;
} 
