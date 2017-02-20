#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <iterator>
#include <algorithm>
#include <time.h>

using namespace std;

int n,m,k,t;
int a[222][222];

int main(){
    srand(time(0));
    freopen("36.inp","w",stdout);
    int i,j,u,v;
    while (true){
        n=rand()%200+1;
        m=rand()%200+1;
        if (n<=2) continue;
        if (m<=2) continue;
        if (n*m>=10) break;
    }
    k=rand()%6+1;
    t=rand()%k+1;
    n=200;
    m=200;
    k=6;
    t=6;
    cout<<m<<" "<<n<<" "<<k<<" "<<t<<"\n";
    memset(a,0,sizeof(a));
    for (i=1;i<=k;i++)
        while (true){
            u=rand()%m+1;
            v=rand()%n+1;
            if (a[u][v]==0){
                a[u][v]=i;
                cout<<u<<" "<<v<<" ";
                break;
            }
        }
    cout<<"\n";
    for (i=1;i<=m;i++){
        for (j=1;j<=n;j++){
            v=rand()%30000+1;
            v=1000000000;
            cout<<v<<" ";
        }
        cout<<"\n";
    }
}
