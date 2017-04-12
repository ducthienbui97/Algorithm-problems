#include <bits/stdc++.h>
using namespace std;
map<string,int> m1,m2;
vector<int> d[1111];
int p1[1111],p2[1111];
bool vs[1111];
vector<pair<int,int> > ls;
bool dfs(int u){
    if(u<0) return true;
    if(vs[u]) return  false;
    vs[u] = true;
    for(int v:d[u]) if(dfs(p2[v])){
        p2[v] = u;
        p1[u] = v;
        return true;
    }
    return false;
}
void solve(int nTest){
    memset(p1,-1,sizeof p1);
    memset(p2,-1,sizeof p2);
    m1.clear();
    m2.clear();
    ls.clear();
    int n;
    cin >> n;
    for(int i=0;i<=n;i++)
        d[i].clear();
    for(int i=0;i<n;i++){
        string s1,s2;
        cin >> s1 >> s2;
        if(m1.find(s1)==m1.end()) m1[s1] = m1.size();
        if(m2.find(s2)==m2.end()) m2[s2] = m2.size();
        int l = m1[s1];
        int r = m2[s2];
        d[l].push_back(r);
        if(p1[l] < 0 && p2[r] < 0) p1[l] = r,p2[r]=l;
        ls.push_back(make_pair(l,r));
    }
    bool done;
    do{
        done = false;
        for(int i=1;i<=m1.size();i++) vs[i] = false;
        for(int i=1;i<=m1.size();i++) if(p1[i] < 0 && dfs(i)) done = true;
    }while(done);
    int ans = m1.size();
    for(int i=1;i<=m2.size();i++) if(p2[i] < 0) ans ++;
    cout <<"Case #"<<nTest<<": "<<n - ans<<endl;;
}
main(){
    freopen("C-large-practice.in","r",stdin);
    freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1;i<=t;i++) solve(i);
}

