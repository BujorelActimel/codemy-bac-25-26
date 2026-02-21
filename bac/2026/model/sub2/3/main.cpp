#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char tI[21]="(+1)2121234567",pN[21]="";
    char tL[21];
    if(strlen(pN)>0)
       strcpy(tL,pN);
    strcpy(tL+strlen(pN),strchr(tI,')')+1);
    cout<<tL;
    return 0;
} 
