#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

void solve(int nTest) {
    int r,c;
    cin >> r >> c;
    if(r>c) swap(r,c);
    int ans;
    if(r<=2) ans = r*c-r*(c/3);
    else ans = r*c - r*c/3;
    cout << "Case #"<<nTest<<": " << ans <<endl;
    //cerr <<nTest<<endl;

}
main() {
    freopen("B-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}


