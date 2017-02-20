#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <algorithm>
#define elif else if
using namespace std;
const int Maxn=1e3+10;
char c[16][Maxn];
int F[16][16];
int n,m,z;
int f[16][1<<15+1];
int done[16][1<<15+1];
int doit(int j,int k){
    if(k==z) return 0;
    if(done[j][k]) return f[j][k];
    done[j][k]=true;
    int x=INT_MAX;
    for(int i=1;i<=m;i++){
        if(!(k&1<<(i-1))) x=min(x,F[j][i]+doit(i,k|(1<<(i-1))));
    }
    f[j][k]=x;
    return x;
}
main(){
    freopen("garlan.inp","r",stdin);
    freopen("garlan.out","w",stdout);
    int k;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        cin>>c[i];
        for(int j=0;j<n;j++){
        F[i][0]+=(c[i][j]=='1');
        }
        F[0][i]=F[i][0];
    }
    z=1<<m;
    z--;
    for(int i=1;i<=m;i++)
        for(int j=1;j<i;j++){
            for(int l=0;l<n;l++)
                F[i][j]+=(c[i][l]!=c[j][l]);
            F[j][i]=F[i][j];
        }
    printf("%d",doit(0,0));

}
