#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
vector<long long> v[3];
void solve(){
    int n[3];
    for(int i=0;i<3;i++){
        cin >> n[i];
        v[i].resize(n[i]);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<n[i];j++)
            cin >> v[i][j];
        sort(v[i].begin(),v[i].end());
    }
    int i = 0,j = 0;
    long long ans = 0,s1 = 0,s2 = 0;
    for(auto&u:v[1]){
        while(i < n[0] && v[0][i] <= u) s1 = (s1 + v[0][i++])%mod;
        while(j < n[2] && v[2][j] <= u) s2 = (s2 + v[2][j++])%mod;
        //cout << u <<" "<<i <<" "<<j<<" "<<s1 <<" "<<s2 <<endl;
        ans = (ans + ((u*i%mod + s1)%mod)*((u*j%mod + s2)%mod)%mod)%mod;
    }
    cout << ans <<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i=0;i<t;i++) solve();
}
