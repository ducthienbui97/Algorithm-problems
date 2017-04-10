#include <bits/stdc++.h>
using namespace std;
const int Maxn = 1e5+20;
int vs[Maxn];
vector<int> d[Maxn];
main(){
    ios_base::sync_with_stdio(false);
    bool impossible  = false;
    queue<int> q;
    int n,m;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x >> y;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    for(int i=1;i<=n;i++) if(!vs[i]){
        q.push(i);
        vs[i] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v:d[u]){
                if(!vs[v]){
                    vs[v] = vs[u]+1;
                    q.push(v);
                }else{

                    impossible |= (vs[u]&1)==(vs[v]&1);
                }
            }
        }
    }
    if(impossible) cout << -1;
    else{
        vector<int> v[2];
        for(int i=1;i<=n;i++)
            v[vs[i]&1].push_back(i);
        cout << v[0].size() << endl;
        for(int u:v[0]) cout << u <<" ";
        cout << endl;
        cout << v[1].size() <<endl;
        for(int u:v[1]) cout << u <<" ";
    }
}
