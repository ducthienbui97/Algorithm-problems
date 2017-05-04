#include <bits/stdc++.h>
using namespace std;
void solve(int nTest) {
    int n,m;
    vector<double> d;
    cin >> n >> m;
    cout << "Case #"<<nTest<<":"<<endl;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        d.push_back(log(x));
    }
    for(int i=0;i<m;i++){
        int l,r;
        cin >> l >> r;
        double s = 0;
        for(int j=l;j<=r;j++){
            s += d[j];
        }
        s/=(r-l+1);
        cout <<fixed <<setprecision(15)<< exp(s)<<endl;
    }
}
main() {
    freopen("B-small-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}



