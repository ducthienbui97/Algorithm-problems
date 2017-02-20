#include <bits/stdc++.h>
using namespace std;
bool mp[100001][5];
int n[5];
void solve() {
    memset(mp,0,sizeof(mp));
    for(int i=0; i<5; i++){
        cin >> n[i];
    }
    for(int i=0; i<5; i++) {
        for(int j=0; j<n[i]; j++) {
            int x;
            cin >> x;
            mp[x][i] = true;
        }
    }
    int ans = 0;
    for(int i=1;i<=100000;i++){
        int t = 0;
        for(int j=0;j<5;j++)
            t+=mp[i][j];
        ans += t >= 3;
    }
    cout << ans <<endl;
}
main() {
    ios_base::sync_with_stdio(false);
    int t;
    for(cin>>t; t>0; t--) solve();

}
