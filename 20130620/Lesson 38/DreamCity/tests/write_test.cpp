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

#define maxn 111111

using namespace std;

int n;
int a[maxn];
int b[maxn];

int main(){
    srand(time(0));
    freopen("2.inp","w",stdout);
    cout<<20<<"\n";
    int i,j,u,v,t;
    for (i=1;i<=20;i++){
        while (true){
            n=rand()%100000+1;
            if (n>=2) break;
        }
        if (i>=19) n=100000;
        cout<<n<<"\n";
        for (j=2;j<=n;j++){
            v=rand()%(j-1)+1;
            a[j-1]=j;
            b[j-1]=v;
        }
        for (j=1;j<=100000;j++){
            u=rand()%(n-1)+1;
            v=rand()%(n-1)+1;
            swap(a[u],a[v]);
            swap(b[u],b[v]);
        }
        for (j=1;j<n;j++){
            t=rand()%2;
            if (t==0) cout<<a[j]<<" "<<b[j]<<"\n"; else
                cout<<b[j]<<" "<<a[j]<<"\n";
        }
    }
}
