#include <bits/stdc++.h>
using namespace std;
# define M_PI         3.141592653589793238462643383279502884L /* pi */
void solve(int nTest){
    long long ans = 0;
    int n,k;
    vector<pair<int,int> > v;
    cin >> n >> k;
    v.resize(n);
    for(auto&c:v){
        cin >> c.first >> c.second;
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i=0;i<n;i++){
        long long rep = 1ll*v[i].first*v[i].first + 2ll*v[i].first*v[i].second;
        priority_queue<long long,vector<long long>,greater<long long> > pr;
        for(int j=i+1;j<n;j++)
            pr.push(2ll*v[j].second*v[j].first);
        while(pr.size() >= k) pr.pop();
        while(!pr.empty()){
            rep += pr.top();
            pr.pop();
        }
        ans = max(ans,rep);
    }
    cout << "Case #"<<nTest<<": "<<fixed<<setprecision(15)<<M_PI*ans<<endl;
}
main(){
    freopen("A-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}
