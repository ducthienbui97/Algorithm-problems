#include <bits/stdc++.h>

using namespace std;
const int Maxn = 222;
vector<int> d[Maxn];
int par[Maxn];
int rev[Maxn];
bool vs[Maxn];
bool dfs(int i){
    if(i < 0) return true;
    if(vs[i]) return false;
    vs[i] =true;
    for(int u:d[i]) if(dfs(rev[u])){
        par[i] = u;
        rev[u] = i;
        return true;
    }
    return false;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s;
    getline(cin,s);
    for(int i = 0; i < n ;i++){
        getline(cin,s);
        stringstream ss(s);
        vector<int> mk(n,1);
        mk[i] = 0;
        int x;
        while(ss >> x)
            mk[x] = 0;
        for(int x = 0; x < n; x++)
            if(mk[x])
                d[i].push_back(x);
    }
    memset(par,-1,sizeof par);
    memset(rev,-1,sizeof rev);
    for(bool ok = true; ok; ){
        ok = false;
        memset(vs,0,sizeof vs);
        for(int i = 0; i < n; i++)
        if(par[i] < 0){
            ok |= dfs(i);
        }
    }
    int ans = 0;
    for(int i = 0 ; i < n; i++)
        ans += (par[i] < 0);
    cout << ans;
}



