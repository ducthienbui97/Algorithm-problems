#include <bits/stdc++.h>
#define elif else if
using namespace std;
const int Maxn=250;
bool vs[Maxn];
int f,s;
bool c[Maxn][Maxn];
vector<int> d[Maxn];
bool dfs(int t){
    if(t==f) return false;
    vs[t]=true;
    for(int i=0;i<d[t].size();i++)
    if(!vs[d[t][i]] && !dfs(d[t][i]))
        return false;
    return true;
}
main(){
    int cnt=0;
    int n,m;
    freopen("STOCK.IN","r",stdin);
    freopen("STOCK.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    while(m--){
        memset(vs,0,sizeof vs);
        cin>>f>>s;
        if(c[f][s]) continue;
        if(!c[s][f]&&dfs(s)) d[f].push_back(s),c[f][s]=true;
        else cnt++;
    }
    printf("%d",cnt);
}
