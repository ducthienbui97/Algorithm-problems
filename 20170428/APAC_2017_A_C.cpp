#include <bits/stdc++.h>
using namespace std;
void solve(int nTest){
    long double ans;
    long double l = 0;
    long double r = 2;
    int n;
    cin >> n;
    vector<int>v(n+1);
    for(int&x:v)cin >>x;
    v[0] = -v[0];
    reverse(v.begin(),v.end());
    for(int it=0;it<10000;it++){
        long double mid = (l+r)/2;
        long double rate = 1;
        long double sum = 0;
        for(int x:v){
            sum += x*rate;
            rate*=mid;
        }
        if(sum < 0) r = mid;
        else l = mid;
    }
    ans = (l+r)/2 - 1;
    cout <<"Case #"<<nTest<<": "<<fixed<<setprecision(15)<<ans<<endl;
}
main(){
    freopen("C-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++)solve(i);
}

