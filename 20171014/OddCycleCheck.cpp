#include <bits/stdc++.h>

using namespace std;

const int maxN = 1e4+10;
int vs[maxN];
vector<int> d[maxN];
vector<int> cn;
bool dfs(int v,int pr){
    //cout << v<< " " <<pr << endl;
    vs[v] = vs[pr] + 1;
    for(auto&u:d[v])if(u!=pr){
        if(vs[u]){
            if((vs[u] - vs[v])%2 == 0)
                return 0;
        }
        else{
            if(!dfs(u,v))
                return 0;
        }
    }
    return 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(bool conti = 1; conti; cout << conti << endl) {
        int x,y;
        cin >> x >> y;
        d[x].push_back(y);
        d[y].push_back(x);
        memset(vs,0,sizeof vs);
        conti &= dfs(x,0);
    }
}

