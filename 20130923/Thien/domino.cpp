#include <iostream>
#include <cstdio>
using namespace std;
#define input "domino.inp"
#define output "domino.out"
void openfile() {
    freopen(input,"r",stdin);
    freopen(output,"w",stdout);
    }
const int Maxn=12;
int n,m,k;
long long F[2][1<<Maxn][1<<Maxn];
int st[1<<Maxn];
main() {
#ifndef HYQ
    openfile();
#endif // HYQ
    ios_base::sync_with_stdio(false);
    int n,m,k,x,y;
    cin>>n>>m>>k;
    while(k--) {
        cin>>x>>y;
        x--;y--;
        st[x]|=1<<y;
        }
    F[0][st[0]][st[1]]=1LL;
    int all=(1<<m)-1;
    for(int cnt=0,i=0; cnt<n; cnt++) {
        i=cnt&1;
        for(int j=0; j<=all; j++)
            for(int l=0; l<=all; l++)
                F[!i][j][l]=0;
        for(int j=0; j<=all; j++)
            for(int l=0; l<=all; l++)
                if(j==all) F[!i][l][st[cnt+2]]+=F[i][j][l];
                else {
                    int tmp=~j;
                    tmp=tmp&-tmp;
                    if((tmp<<1)<=all&&!(j&(tmp<<1)))   F[i][j|tmp|(tmp<<1)][l]+=F[i][j][l];
                    if(!(l&tmp)) F[i][j|tmp][l|tmp]+=F[i][j][l];
                    }
        }
    cout<<F[n&1][0][0];
    }
