#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
long long pw[100011];
const long long div2 = 500000004;
void solve(){
    long long ans=0 , sum=0;
    int n;
    cin >> n;
    long long v;
    cin >> v;
    sum = 1ll*v*pw[n-1]%mod;
    for(int i=1;i<n;i++){
        cin >> v;
        sum = sum*div2%mod;
        ans  = (ans + sum)%mod;
        sum = (sum*v%mod + v*pw[n-2]%mod)%mod;
    }
    cout << (ans + sum)%mod <<endl;
}
int main(){
    pw[0] = 1;
    for(int i=1;i<100011;i++)
        pw[i] = pw[i-1]*2%mod;
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=0;i<t;i++) solve();
}

