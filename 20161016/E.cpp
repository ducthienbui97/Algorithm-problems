#include <bits/stdc++.h>
using namespace std;
long long F[55][55][55][55];
int cnt[55][55][55][55];
int a[55];
int t;
vector<int> d;
long long dp(int l,int r,int LL,int RR){
    if(cnt[l][r][LL][RR]==t) return F[l][r][LL][RR];
    if(l==r) return 1LL*d[a[l]]*d[min(LL,RR)];
    if(l>r) return  0;
    cnt[l][r][LL][RR] = t;
    F[l][r][LL][RR] = -1ll<<60;
    for(int i = l; i <= r; i++){
        F[l][r][LL][RR] = max(F[l][r][LL][RR],dp(l,i-1,LL,a[i])+dp(i+1,r,a[i],RR)+1ll*d[a[i]]*d[min(LL,RR)]);
    }
    return F[l][r][LL][RR];
}
void solve(){
    int n;
    cin >> n;
    memset(F,-1,sizeof F);
        d.clear();

    d.push_back(1);
    for(int i=0;i<n;i++){
        cin >> a[i];
        d.push_back(a[i]);
    }
    sort(d.begin(),d.end());
    for(int i = 0; i < n; i++)
        a[i] = lower_bound(d.begin(),d.end(),a[i]) - d.begin();
    cout << dp(0,n-1,0,0) << endl;;

}
main(){
    ios_base::sync_with_stdio(false);
    for(cin >> t; t > 0 ; t--) solve();
}
/*
2
5
3 2 4 9 1
1
100
*/
