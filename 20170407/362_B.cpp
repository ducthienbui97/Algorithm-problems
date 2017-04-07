#include <bits/stdc++.h>
using namespace std;
const int Maxn =1e5+20;
int sz[Maxn];
double expected[Maxn];
vector<int> d[Maxn];
int dfs(int u){
    sz[u] = 1;
    for(int v:d[u])
        sz[u] += dfs(v);
    return sz[u];
}
void cal(int u){
    for(int v:d[u]){
        expected[v] = expected[u] + 1 + 0.5*(sz[u] - 1 - sz[v]);
        cal(v);
    }
}
main(){
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i=2;i<=n;i++){
        int x;
        cin >> x;
        d[x].push_back(i);
    }
    dfs(1);
    expected[1] = 1;
    cal(1);
    for(int i=1;i<=n;i++)
        cout << expected[i] <<' ';
}
