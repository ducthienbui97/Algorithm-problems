#include <bits/stdc++.h>
using namespace std;
void solve(int nTest) {
    double ans = 0;
    double l = 0;
    double r = 1;
    double u;
    vector<double> p;
    int n,k;
    cin >> n >> k >> u;
    p.resize(n);
    for(auto&c:p) cin >> c;
    for(int i=0;i<100;i++){
        double m = (l+r)/2;
        double s = 0;
        for(auto c:p) s+= max(0.,m-c);
        if(s <= u){
            l = m;
            ans = 1.;
            for(auto c:p) ans*=max(c,m);
        }
        else r = m;
    }
    cout << "Case #"<<nTest<<": "<<fixed<<setprecision(15)<<ans<<endl;
}
main() {
    freopen("C-small-practice-1.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}

/*
1
2 0
900 1260
180 540
*/

