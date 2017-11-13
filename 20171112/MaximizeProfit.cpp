#include <bits/stdc++.h>
using namespace std;
main(){
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin >> n >> m >> k;
    int ans = m*k;
    vector<int> v(n);
    for(auto&u:v) cin >> u;
    for(int i = 0; i < n; i++){
        int t;
        cin >> t;
        ans = max(ans,t*m*v[i]);
    }
    cout << ans;
}
