#include <vector>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn=1e5+20;
vector<int> d[Maxn],red[Maxn];
vector<int> lis[Maxn],st;
bool rev[Maxn];
int tplt[Maxn];
int F[Maxn];
int r,n,m;
void dfs1(int t){
    rev[t]=true;
    for(int i=0;i<d[t].size();i++)
        if(!rev[d[t][i]]) dfs1(d[t][i]);
    st.push_back(t);
}
void dfs2(int t,int tp){
    rev[t]=true;
    tplt[t]=tp;
    lis[tp].push_back(t);
    for(int i=0;i<red[t].size();i++)
        if(!rev[red[t][i]]) dfs2(red[t][i],tp);
}
void dfs3(int tp){
    F[tp]=lis[tp].size();
    for(int i=0;i<lis[tp].size();i++)
        for(int j=0;j<d[lis[tp][i]].size();j++)
    if(tplt[d[lis[tp][i]][j]]!=tp){
        rev[d[lis[tp][i]][j]]=true;
        dfs3(tplt[d[lis[tp][i]][j]]);
        F[tp]+=F[tplt[d[lis[tp][i]][j]]];
    }
}
int ans=0;
void dfs4(int tp){
    bool ok=(tp!=tplt[r]);
    for(int i=0;i<lis[tp].size();i++){
        int u=lis[tp][i];
        for(int j=0;j<d[u].size();j++){
            int v=d[u][j];
            if(tplt[v]!=tp){
                dfs4(tplt[v]);
              if(rev[u])  ok=false;
            }
        }
    }
    ans+=ok;
}
main() {
    freopen("network.inp","r",stdin);
    freopen("network.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>r;
    int cnt=0;
    int x,y;
    for(int i=1;i<=m;i++){
        cin>>x>>y;
        d[x].push_back(y);
        red[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        if(!rev[i]) dfs1(i);
    reverse(st.begin(),st.end());
    memset(rev,0,sizeof rev);
    for(int i=0;i<n;i++)
    if(!rev[st[i]]){
        dfs2(st[i],cnt);
        ++cnt;
    }
        memset(rev,0,sizeof rev);

    dfs3(tplt[r]);
    for(int  i=1;i<=n;i++)
        printf("%d ",F[tplt[i]]);
    printf("\n");
    dfs4(tplt[r]);
    printf("%d\n",ans);
}
/*
11 12 3
3 2
2 1
2 4
4 5
4 6
6 2
6 7
3 8
8 9
9 10
9 11
10 8
*/
