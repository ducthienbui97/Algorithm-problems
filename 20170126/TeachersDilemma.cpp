#include <bits/stdc++.h>
using namespace std;
vector<int> r;
vector<int> s;
int findroot(int p){
    if(r[p] == p) return r[p];
    return r[p] = findroot(r[p]);
}
const int base = 1e9+7;
main(){
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    r.resize(n),s.resize(n);
    for(int i=0;i<n;i++){
        r[i] = i;
        s[i] = 1;
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
    long long ans = 1;
    for(int i=0;i<n;i++)
    if(i == findroot(i)){
        ans= (ans*s[i])%base;
    }
    cout << ans ;
}
