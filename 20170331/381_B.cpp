#include <bits/stdc++.h>
using namespace std;
const int Maxn = 2e5+20;
int a[Maxn],ans[Maxn];
int p[Maxn],w[Maxn];
vector<pair<long long,int> >  dis;
vector<int> d[Maxn];
void dfs(int u,long long dist){
    dis.push_back(make_pair(dist,u));
    int t = lower_bound(dis.begin(),dis.end(),make_pair(dist - a[u],0))->second;
    ans[p[t]] --;
    ans[p[u]] ++;
    for(int v:d[u]){
        dfs(v,dist+w[v]);
        ans[u] += ans[v];
    }
    dis.pop_back();
}
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=2;i<=n;i++){
        cin >> p[i] >> w[i];
        d[p[i]].push_back(i);
    }
    dfs(1,0);
    for(int i=1;i<=n;i++)
        cout << ans[i] <<" ";

}
