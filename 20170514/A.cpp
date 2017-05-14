#include <bits/stdc++.h>
using namespace std;
void solve(int nTest){
    int n,p;
    cin >> n >> p;
    int cnt[5] = {0,0,0,0,0};
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        cnt[x%p] ++;
    }
    int ans = cnt[0];
    for(int i=1;i<p;i++){
        int t = min(cnt[i],cnt[p-i]);
        if(i == p - i){
            ans += t/2;
            cnt[i]%=2;
        }else{
            ans += t;
            cnt[i] -= t;
            cnt[p-i] -= t;
        }
        ans += cnt[i]/p;
        cnt[i] %= p;
    }
    //cout << ans <<endl;
    if(p == 4 && cnt[2] == 1){
        if(cnt[3] >= 2){
            cnt[3] -= 2;
            cnt[2] --;
            ans ++;
        }
        else if(cnt[1] >= 2){
            cnt[1] -= 2;
            cnt[2] --;
            ans ++;
        }
    }
    for(int i=1;i<p;i++)
    if(cnt[i]) {
        ans ++;
        break;
    }
    cout <<"Case #"<<nTest<<": "<<ans<<endl;;
}
main(){
    //freopen("A-large.in","r",stdin);
    //freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}
