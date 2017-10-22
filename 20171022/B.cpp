#include <bits/stdc++.h>
using namespace std;
int findRoot(int u, vector<int>& Root){
    if(Root[u] != u)
        Root[u] = findRoot(Root[u],Root);
    return Root[u];
}
void solve(int n_test){
    long long ans = 0;
    int n;
    cin >> n;
    vector<int> R(n),B(n),Root(n);
    vector<pair<int,pair<int,int> > > edges;
    for(auto&u:R) cin >> u;
    for(auto&u:B) cin >> u;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i; j++){
            edges.push_back({R[i]^B[j],{i,j}});
            edges.push_back({B[i]^R[j],{i,j}});
        }
        Root[i] = i;
    }
    sort(edges.begin(),edges.end());
    for(auto&u:edges){
        int x = findRoot(u.second.first, Root);
        int y = findRoot(u.second.second, Root);
        if(x != y){
            ans += u.first;
            Root[x] = y;
        }
    }
    cout << "Case #" << n_test << ": " << ans << "\n";
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
        solve(i);
}

