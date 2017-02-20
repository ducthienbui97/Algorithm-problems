#include <algorithm>
#include <cstdio>
#include <climits>
#include <cstring>
#include <iostream>
using namespace std;
#define elif else if
#define input "gridp.inp"
#define output "gridp.out"
void openfile() {
    freopen(input,"r",stdin);
    freopen(output,"w",stdout);
    }
int n,m,r,c;
int Mx[20][20];
int a[20][20];
int f[20][20];
inline int cal(int x1,int y1,int x2,int y2) {
    return a[x2][y2]-a[x1-1][y2]-a[x2][y1-1]+a[x1-1][y1-1];
    }
int ans=INT_MAX;
int ax[20];
void test() {
    memset(Mx,0,sizeof Mx);
    memset(f,0x3f,sizeof f);
    for(int i=1; i<=m; i++)
        for(int j=1; j<=i; j++) {
            Mx[j][i]=cal(1,j,ax[0],i);
            for(int l=0; l<r; l++) {
                Mx[j][i]=max(Mx[j][i],cal(ax[l]+1,j,ax[l+1],i));
                }
            }
    for(int i=1; i<=m; i++)
        f[0][i]=Mx[1][i];
    for(int i=1; i<=c; i++)
        for(int j=2; j<=m; j++)
            for(int l=1; l<j; l++) {
                    f[i][j]=min(f[i][j],max(f[i-1][l],Mx[l+1][j]));
                }
    ans=min(ans,f[c][m]);
    }
void bt(int k,int deep) {
    if(deep>=r) test();
    else {
        for(; k<=n-r+deep; k++) {
            ax[deep]=k;
            bt(k+1,deep+1);
            }
        }
    }
main() {
    ios_base::sync_with_stdio(false);
#ifndef HYQ
    openfile();
#endif
    int x;
    cin>>n>>m>>r>>c;
    ax[r]=n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++) {
            cin>>x;
            a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+x;
            }
    bt(1,0);
    cout<<ans;
    }

/*
 7 8 2 1
0 0 2 6 1 1 0 0
1 4 4 4 4 4 3 0
2 4 4 4 4 4 3 0
1 4 4 4 8 4 3 0
0 3 4 4 4 4 4 3
0 1 1 3 4 4 3 0
0 0 0 1 2 1 2 0
*/
