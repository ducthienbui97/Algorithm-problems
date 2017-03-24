#include <bits/stdc++.h>
using namespace std;
int n;
int m[2];
int a[2][7777];
int t[2][7777];
int d[2][7777];
queue<pair<int,int> > q;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0; i<2; i++) {
        cin >> m[i];
        for(int j=0; j<m[i]; j++)
            cin >> a[i][j];
    }
    for(int i=1; i<n; i++)
        for(int j=0; j<2; j++)
            t[j][i]=m[j];
    d[0][0]=1;
    d[1][0]=1;
    q.push(make_pair(1,0));
    q.push(make_pair(0,0));
    while(!q.empty()) {
        int p = q.front().first;
        int l = q.front().second;
        q.pop();
        for(int i=0; i<m[!p]; i++) {
            int v = (l + n - a[!p][i])%n;
            if(!d[!p][v]) {
                if(d[p][l] == 1) {
                    d[!p][v] = 2;
                    q.emplace(!p,v);
                } else if(!(--t[!p][v])) {
                    d[!p][v] = 1;
                    q.emplace(!p,v);
                }
            }
        }
    }
    for(int i=0;i<2;i++){
        for(int j=1;j<n;j++)
            if(!d[i][j]) cout << "Loop ";
            else if(d[i][j] == 1) cout <<"Lose ";
            else cout << "Win ";
        cout <<endl;
    }
}
