#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#define mp make_pair
#define elif else if
using namespace std;
const int Maxn=2e3+20;
int n,m;
int A[Maxn],B[Maxn];
long long F[Maxn][Maxn];
int min3(const int& a,const int& b,const int& c){return min(a,min(b,c));}
main(){
    freopen("GAME.inp","r",stdin);
    freopen("GAME.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=n;i>0;i--)
        cin>>A[i],A[i]--;
    for(int i=m;i>0;i--)
        cin>>B[i],B[i]--;
    memset(F,0x1f,sizeof F);
    F[0][0]=0;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++){
        F[i][j]=min3(F[i][j-1],F[i-1][j-1],F[i-1][j])+A[i]*B[j];
    }
    cout<<F[n][m]<<endl;
}
