#include<bits/stdc++.h>
using namespace std;
vector<int> v;
void solve(){
    int n;
    cin >> n;
    v.resize(n);
    for(auto&u:v) cin >> u;
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    long long cur = 0;
    int cnt = 0;
    long long ans = 0;
    for(int&u:v){
        if((cur + u)*(cnt+1) > cur*cnt + u){
            cur += u;
            cnt ++;
        }
        else{
            ans += cur*cnt;
            cur = u;
            cnt = 1;
        }
    }
    ans += cur*cnt;
    cout << ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++) solve();
}
