#include <bits/stdc++.h>
using namespace std;
int cap[555][555];
int X[] = {1,1,1,0,0,-1,-1,-1};
int Y[] = {1,0,-1,1,-1,1,0,-1};
int vs[555][555];
void solve() {
    memset(vs,0x3f,sizeof vs);
    int n,m;
    cin >> n >> m;
    int MAX = -(1<<30);
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) {
            cin >> cap[i][j];
            if(cap[i][j] > MAX)
                MAX = cap[i][j];
        }
    queue<pair<int,int> > bfs;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(cap[i][j] == MAX) {
                bfs.emplace(i,j);
                vs[i][j] = 0;
            }
    while(!bfs.empty()) {
        int x = bfs.front().first;
        int y = bfs.front().second;
        bfs.pop();
        for(int dir = 0; dir < 8; dir++)
            if(x + X[dir] < n && x + X[dir] >= 0 &&  y + Y[dir] < m && y + Y[dir] >= 0)
                if(vs[x][y] + 1 < vs[x + X[dir]][y + Y[dir]]) {
                    vs[x + X[dir]][y + Y[dir]] = vs[x][y] + 1;
                    bfs.emplace(x + X[dir],y + Y[dir]);
                }
    }
    int ans = 0;
    for(int i=0;i < n;i++)
        for(int j=0;j < m;j++)
            ans = max(ans,vs[i][j]);
    cout << ans <<endl;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for(int i=0; i<t; i++) solve();
}
