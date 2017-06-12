#include<bits/stdc++.h>
using namespace std;
bool cnt[2555];
vector<int> v[2555];
void solve(){
    int n,k;
    cin >> n >> k;
    for(int i=0;i<n;i++){
        int l;
        cin >> l;
        v[i].resize(l);
        for(auto&u:v[i]) cin >> u;
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        memset(cnt,0,sizeof cnt);
        for(auto&u:v[i]) cnt[u] =true;
        int s1 = v[i].size();
        for(int j=i+1;j<n;j++){
            int s2 = 0;
            for(auto&u:v[j]) if(!cnt[u]) s2 ++;
            if(s1 + s2 == k) ans ++;
        }
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

