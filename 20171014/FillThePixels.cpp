#include <bits/stdc++.h>
using namespace std;
vector<string> s;
int X[] = {1,-1,0,0,1,-1,-1,1};
int Y[] = {0,0,1,-1,1,-1,1,-1};
int n,m;
bool vs[1111][1111];
void dfs(int x,int y,int fr,int to){
    if(x >=  n || y >= m || x < 0 || y < 0 || s[x][y] == '0'||vs[x][y])
        return;
    vs[x][y] = true;
    for(int i = fr; i < to; i++)
        dfs(x + X[i],y + Y[i],fr,to);
}
void solve(){

    cin >> n >> m;
    swap(n,m);
    s.resize(n);
    for(auto&u:s)
        cin >> u;
    memset(vs,0,sizeof vs);
    int cnt = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)if(s[i][j] == '1' && !vs[i][j]){
        dfs(i,j,0,4);
        cnt++;
    }
    cout << cnt << ' ';
    memset(vs,0,sizeof vs);
    cnt = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)if(s[i][j] == '1' && !vs[i][j]){
        dfs(i,j,4,8);
        cnt++;
    }
    cout << cnt << ' ';
    memset(vs,0,sizeof vs);
    cnt = 0;
    for(int i = 0; i < n; i++)
    for(int j = 0; j < m; j++)if(s[i][j] == '1' && !vs[i][j]){
        dfs(i,j,0,8);
        cnt++;
    }
    cout << cnt << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}

