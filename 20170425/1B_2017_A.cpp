#include <bits/stdc++.h>
using namespace std;

void solve(int nTest){
    double ans;
    int k,d,s,n;
    vector<double> Time;
    cin >> d >> n;
    for(int i=1;i<=n;i++){
        cin >> k >> s;
        Time.push_back(1.*(d-k)/s);
    }
    sort(Time.begin(),Time.end());
    ans = d/Time.back();
    cout << "Case #"<<nTest<<": "<<fixed <<setprecision(9)<<ans<<endl;
}
main(){
    freopen("A-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}
