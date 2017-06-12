#include<bits/stdc++.h>
using namespace std;
void solve(){
    int u,v;
    cin >> u >> v;
    int S = u + v + 1;
    long long all = 1ll*S*(S+1)/2;
    cout << all - v <<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++) solve();
}
