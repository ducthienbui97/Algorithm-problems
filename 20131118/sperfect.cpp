//THIEN GAY
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#define elif else if
using namespace std;
const int Maxn=2e5+20;
typedef pair<int,int> pii;
int n,m,cnt;
bool vs[Maxn];
bool ok[Maxn];
vector<int> lis[Maxn],d[Maxn],red[Maxn];
vector<int> topo,retopo;
int tplt[Maxn],root[Maxn];
void dfs1(int u){
    vs[u]=true;
    for(int i=0;i<d[u].size();i++)
        if(!vs[d[u][i]]) dfs1(d[u][i]);
    topo.push_back(u);
}
void dfs2(int u,int t){
    vs[u]=true;
    for(int i=0;i<red[u].size();i++)
        if(!vs[red[u][i]]) dfs2(red[u][i],t);
    lis[t].push_back(u);
    tplt[u]=t;
}
void dfs3(int u,vector<int>& TP){
    vs[u]=true;
    for(int i=0;i<lis[u].size();i++){
        int t=lis[u][i];
        for(int j=0;j<d[t].size();j++)
            if(!vs[tplt[d[t][j]]]) dfs3(tplt[d[t][j]],TP);
    }
    TP.push_back(u);
}

void Clr(){
    for(int i=1;i<=n;i++) root[i]=i,d[i].clear(),lis[i].clear(),red[i].clear();
    memset(vs,0,sizeof vs);
    memset(ok,0,sizeof ok);
    memset(tplt,0,sizeof tplt);
    cnt=0;
    topo.clear();
    retopo.clear();
}
int findroot(int u){
    if(root[u]!=u) return root[u]=findroot(root[u]);
    return u;
}
void doit(){
    int x,y;
    cin>>n>>m;
    Clr();
     while(m--){
        cin>>x>>y;
        d[x].push_back(y);
        red[y].push_back(x);
        ok[x]=ok[y]=true;
        root[findroot(x)]=findroot(y);
    }
    int dem=0;
    for(int i=1;i<=n;i++)
    if(ok[i]){
            if(!vs[i]) dfs1(i);
            dem+=(root[i]==i);
    }
    if(dem>1){
        puts("NO");
        return ;
    }
    reverse(topo.begin(),topo.end());
    memset(vs,0,sizeof vs);
    for(int i=0;i<topo.size();i++)
        if(!vs[topo[i]]){
            dfs2(topo[i],++cnt);
        }
    memset(vs,0,sizeof vs);
    topo.clear();
    for(int i=1;i<=cnt;i++)
       if(!vs[i]) dfs3(i,topo);
    memset(vs,0,sizeof vs);
    for(int i=0;i<=n;i++)
        if(ok[i]) reverse(d[i].begin(),d[i].end());
    for(int i=cnt;i>0;i--)
       if(!vs[i]) dfs3(i,retopo);
    puts(topo!=retopo?"NO":"YES");

}
main() {
    freopen("SPERFECT.INP","r",stdin);
    freopen("SPERFECT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--) doit();
}
