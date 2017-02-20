#include <bits/stdc++.h>
using namespace std;
vector<int> r;
vector<int> s;
vector<bool> v;
int findroot(int p){
    if(r[p] == p) return r[p];
    return r[p] = findroot(r[p]);
}
main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    r.resize(n),s.resize(n),v.resize(n);
    for(int i=0;i<n;i++){
        r[i] = i;
        s[i] = 1;
        v[i] = true;
    }
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x>>y;
        x = findroot(x-1);
        y = findroot(y-1);
        if(x != y){
            r[x] = y;
            s[y] += s[x];
        }
    }
    cin >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >>y;
        x = findroot(x-1);
        y = findroot(y-1);
        if(x == y) v[x] = false;
    }
    int ans = 0;
    for(int i=0;i<n;i++)
        if(v[findroot(i)]) ans=max(ans,s[findroot(i)]);
    cout << ans;
}
