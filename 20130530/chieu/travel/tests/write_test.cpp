#include <iostream>
#include <fstream>
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

int main(){
    srand(time(0));
    freopen("20.inp","w",stdout);
    int n,m,k,i,u,v,c1,c2;
    n=rand()%2000+1;
    m=rand()%10001;
    while (true){
        k=rand()%7+1;
        if (k<=n) break;
    }
    n=2000;
    m=10000;
    k=7;
    cout<<n<<" "<<m<<" "<<k<<"\n";
    for (i=1;i<=m;i++){
        while (true){
            u=rand()%n+1;
            v=rand()%n+1;
            if (u!=v) break;
        }
        c1=rand()%1000+1;
        c2=rand()%1000+1;
        cout<<u<<" "<<v<<" "<<c1<<" "<<c2<<"\n";
    }
    bool fr[2012];
    memset(fr,true,sizeof(fr));
    for (i=1;i<=k;i++)
        while (true){
            v=rand()%n+1;
            if (fr[v]){
                cout<<v<<" ";
                fr[v]=false;
                break;
            }
        }
}
