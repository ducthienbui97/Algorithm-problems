#include <bits/stdc++.h>
using namespace std;
vector<int> c,d;
vector<int> dif;
void solve(){
    int n,m,e;
    cin >> n >> m >> e;
    c.resize(n);
    d.resize(m);
    dif.clear();
    for(int i=0;i<n;i++)
        cin >> c[i];
    for(int i=0;i<m;i++)
        cin >> d[i];
    sort(c.begin(),c.end());
    sort(d.begin(),d.end());
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++){
        dif.push_back(d[j] - c[i]);
        dif.push_back(d[j] - c[i] + e);
        dif.push_back(d[j] - c[i] - e);
    }
    dif.push_back(0);
    int ans = 0;
    for(int differ : dif){
        int x = 0;
        int y = 0;
        int cnt = 0;
        while(x < n && y < m){
            if(abs(d[y] - (c[x] + differ)) <= e){
                cnt ++;
                x ++;
                y ++;
            }else if(c[x] + differ < d[y]){
                x++;
            }else
                y++;
        }
        if(cnt > ans) ans = cnt;
    }
    cout << ans <<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=0;i<t;i++) solve();
}
