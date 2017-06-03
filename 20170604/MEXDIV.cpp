#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
const int maxn= 555000;
int v[maxn];
int cnt[maxn];
int past[maxn];
long long sum[maxn];
long long F[maxn];
set<int> ms;
void solve(){
    int n,k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> v[i];
    int l = 1;
    int current = 0;
    v[0] = 1<<30;
    for(int i=0;i<=n;i++) ms.insert(i);
    for(int r = 1; r <= n; r++){
        if(v[r] <= n){
            cnt[v[r]] ++;
            if(cnt[v[r]] == 1) ms.erase(v[r]);
        }
        current = *ms.begin();
        while(current > k){
            if(v[l] <= n){
                cnt[v[l]] --;
                if(!cnt[v[l]]) {
                    current = min(current,v[l]);
                    ms.insert(v[l]);
                }
            }
            l++;
        }
        past[r] = l;
        //cout <<"("<<l<<","<<r<<")"<<endl;
    }
    F[0] = 1;
    sum[0] = 1;
    //F[1] = 1;
    //sum[1] = 1;
    for(int i = 1;i<=n;i++){
        int l = past[i];
        F[i] = ((F[l-1] + sum[i-1] - sum[l-1])%mod+ mod)%mod;
        sum[i] = (sum[i-1] + F[i])%mod;
        //cout << F[i] <<"->"<<sum[i] <<endl;
    }
    cout << F[n] <<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int t = 1;
    //cin >> t;
    for(int i=0;i<t;i++) solve();
}


