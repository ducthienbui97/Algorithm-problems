#include <algorithm>
#include <cstdio>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;
#define elif else if
#define mp make_pair
#define pb push_back
#define input "deputation.inp"
#define output "deputation.out"
void openfile() {
    freopen(input,"r",stdin);
    freopen(output,"w",stdout);
    }
int n,m;
const int Maxn=1011;
int vs[Maxn][2];
vector<pair<int,bool> > d[Maxn][2];
int cnt;
bool dfs(int x1,bool y1,int x2,bool y2) {
    vs[x1][y1]=cnt;
    if(x1==x2&&y1==y2) return true;
    for(int i=0; i<d[x1][y1].size(); i++) {
        if(vs[d[x1][y1][i].first][d[x1][y1][i].second]!=cnt&&dfs(d[x1][y1][i].first,d[x1][y1][i].second,x2,y2))
            return true;
        }
        return false;
    }
int ans[Maxn];
main() {
    ios_base::sync_with_stdio(false);
#ifndef HYQ
    openfile();
#endif
    int x,y,z,t;
    char c1[20],c2[20];
    cin>>n>>m;
    while(m--) {
        cin>>x>>c1>>y>>c2;
        z=(c1[0]=='Y');
        t=(c2[0]=='Y');
        d[x][!z].pb(mp(y,t));
        d[y][!t].pb(mp(x,z));
        }
    for(int i=1;i<=n;i++){
        bool vs1,vs2;
        ++cnt;
        vs1=dfs(i,0,i,1);
        ++cnt;
        vs2=dfs(i,1,i,0);
        if(vs1&&vs2){
            puts("IMPOSSIBLE");
            return 0;
        }
        if(!vs1&&vs2) ans[i]=1;
        if(vs1&&!vs2) ans[i]=-1;
    }
    for(int i=1;i<=n;i++)
        if(ans[i]==-1) putchar('Y');
        elif(ans[i]==1) putchar('N');
        else putchar('?');
}
    /*
    3 4
    1 Y 2 N
    1 N 2 N
    1 Y 3 Y
    1 Y 2 Y
    */
