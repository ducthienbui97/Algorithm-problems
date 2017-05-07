#include <bits/stdc++.h>
using namespace std;
const int Maxn = 11111;
const int Mod = 1e9+7;
int v[Maxn];
long long pw[Maxn];
void solve(int nTest){
    int n;
    long long ans=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> v[i];
        for(int j=1;j<i;j++){
            ans = (ans + pw[i-j-1]*(v[i] - v[j]))%Mod;
        }
    }
    cout << "Case #"<<nTest<<": "<<ans<<endl;
}
int main(){
    pw[0] = 1;
    for(int i=1;i<Maxn;i++)
        pw[i] = (pw[i-1]<<1)%Mod;
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}
