#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
vector<int> d[20022][2];
int vs[20022];
int def[20022];
vector<int> done;
void dfs(int u,int t,vector<int>&trace) {
    vs[u] = 1;
    for(int v:d[u][t])
        if(!vs[v]) dfs(v,t,trace);
    trace.push_back(u);
}
void solve(int nTest) {
    int n;
    bool ans = true;
    done.clear();
    mp.clear();
    cin >> n;
    string s;
    memset(def,0,sizeof def);
    for(int i=1; i<=n; i++) {
        cin >> s;
        replace(s.begin(),s.end(),'=',' ');
        replace(s.begin(),s.end(),',',' ');
        replace(s.begin(),s.end(),')',' ');
        replace(s.begin(),s.end(),'(',' ');
        stringstream ss(s);
        ss >> s;
        int u;
        if(mp.find(s)==mp.end()) {
            u = mp.size();
            mp[s] = u;
            d[u][0].clear();
            d[u][1].clear();
        } else {
            u = mp[s];
        }
        def[u] = true;
        ss >> s;
        while(ss >> s) {
            int v;
            if(mp.find(s)==mp.end()) {
                v = mp.size();
                mp[s] = v;
                d[v][0].clear();
                d[v][1].clear();
            } else {
                v = mp[s];
            }
            d[u][0].push_back(v);
            d[v][1].push_back(u);
            if(v == u) ans = false;
        }
    }

    memset(vs,0,sizeof vs);
    for(int i=0; i<mp.size(); i++){
        if(!vs[i]) dfs(i,0,done);
        if(!def[i]) ans = false;
    }
    reverse(done.begin(),done.end());
    memset(vs,0,sizeof vs);
    for(int u:done)if(!vs[u]) {
            vector<int> ls;
            dfs(u,1,ls);
            if(ls.size()>1) ans = false;
        }
    cout <<"Case #"<<nTest<<": "<<(ans?"GOOD":"BAD")<<endl;
}
main() {
    freopen("C-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++)solve(i);
}


