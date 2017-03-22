#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5+20;
vector<int> d[MAX];
bool vs[MAX];
vector<int> euler;
void dfs(int u) {
    vs[u] = true;
    euler.push_back(u);
    for(int v:d[u])
        if(!vs[v]) {
            dfs(v);
            euler.push_back(u);
        }
}
int main() {
    ios_base::sync_with_stdio(false);
    int n,m,k;
    cin >> n >>m >> k;
    for(int i=0; i<m; i++) {
        int x,y;
        cin >> x >> y;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    for(int i=1; i<=n; i++)
        if(!vs[i]) dfs(i);
    int v = (euler.size())/k + 1;

    for(int i=0; i<k; i++) {
        int fr = min(i*v,(int)euler.size()-1);
        int to = min((i+1)*v,(int)euler.size());
        cout << to - fr;
        while(fr < to) cout << " "<< euler[fr++];
        cout << endl;
    }
}
