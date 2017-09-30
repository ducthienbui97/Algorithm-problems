#include <bits/stdc++.h>
using namespace std;
bool F[1111][1111][2];
void solve() {
    int n;
    cin >> n;
    vector<string> inp(n);
    int win = false;
    vector<pair<int,int> > P;
    for(auto&u:inp) cin >> u;
    F[0][0][0] = 1;
    F[0][0][1] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++) {
            if(!i && !j) continue;

            F[i][j][0] = 0;
            F[i][j][1] = 0;
            if(inp[i][j] == 'X') continue;
            if(i) {
                F[i][j][0] |= F[i - 1][j][1];
                F[i][j][1] |= F[i - 1][j][0];
            }
            if(j) {
                F[i][j][0] |= F[i][j - 1][1];
                F[i][j][1] |= F[i][j - 1][0];
            }
            if(i && j) {
                F[i][j][0] |= F[i - 1][j - 1][1];
                F[i][j][1] |= F[i - 1][j - 1][0];
            }
            if(inp[i][j] == 'K')
                if(F[i][j][0] && F[i][j][1])
                    P.emplace_back(i,j);
                else if(F[i][j][1])
                    win = !win;
        }
    int cnt = 0;
    if(P.size() > 1)
        cout <<"LOSE\n";
    else if(P.size() == 1) {
        int x = P[0].first;
        int y = P[0].second;
        if(x && !win == F[x - 1][y][0] && win == F[x - 1][y][1])
            ++cnt;
        if(y && !win == F[x][y - 1][0] && win == F[x][y - 1][1])
            ++cnt;
        if(x && y && !win == F[x - 1][y - 1][0] && win == F[x - 1][y - 1][1])
            ++cnt;
        if(cnt)
            cout << "WIN " << cnt <<'\n';
        else
            cout << "LOSE\n";
    } else {
        if(!win)
            cout << "LOSE\n";
        else {
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++) {
                    if(inp[i][j] != 'K') continue;
                    if(i && (F[i - 1][j][0] || F[i - 1][j][1])) cnt ++;
                    if(j && (F[i][j - 1][0] || F[i][j - 1][1])) cnt ++;
                    if(i && j && (F[i - 1][j - 1][0] || F[i - 1][j - 1][1])) cnt ++;
                }
            if(cnt)
                cout <<"WIN "<<cnt<<'\n';
            else
                cout << "LOSE\n";
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    while(q-->0)
        solve();
    return 0;
}
