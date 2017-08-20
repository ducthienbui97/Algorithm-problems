#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n,k,x,d;
    cin >> n >> k >> x >> d;
    d*=100;
    k*=100;
    int fee = 0;
    for(int i=0;i < n;i ++){
        int p;
        cin >> p;
        fee += max(k,p*x);
    }
    if(fee <= d) cout << "fee\n";
    else cout << "upfront\n";
}
main(){
    int t;
    for(cin >> t; t > 0; t--) solve();
}
