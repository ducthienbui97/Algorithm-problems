#include <bits/stdc++.h>
using namespace std;
map<string,int> mp;
string ss[3333];
vector<int> d[3333];
int match1[3333],match2[3333];
bool vs[3333];
bool dfs(int v) {
    vs[v] = true;
    if(!match2[v]) return true;
    else {
        int u = match2[v];
        for(int x:d[u])
            if(!vs[x] && x!=v && dfs(x)) {
                match2[x] = u;
                match1[u] = x;
                return true;
            }
    }
    return false;
}
main() {
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    string s1;
    string s2;
    set<int> ms;
    vector<int> l1,l2;
    for(int i=0; i<n; i++) {
        cin >> s1 >> s2;
        int x;
        mp[s1+" "+s2] = mp.size();
        l1.push_back(mp.size());
        x = mp.size();
        s1 = s1.substr(0,3);
        if(mp.find(s1) == mp.end()) {
            mp[s1] = mp.size();
            ss[mp.size()] = s1;
        }
        int y = mp[s1];
        if(ms.find(y) == ms.end()) {
            ms.insert(y);
        } else {
            l2.push_back(y);
        }
        d[x].push_back(y);
        d[y].push_back(x);
        s1 = s1.substr(0,2)+s2[0];
        if(mp.find(s1) == mp.end()) {
            mp[s1] = mp.size();
            ss[mp.size()] = s1;
        }
        y = mp[s1];
        d[x].push_back(y);
        d[y].push_back(x);
        if(!match1[x] && !match2[y]) {
            match1[x] = y;
            match2[y] = x;
        }
    }
    bool ok;
    do {
        memset(vs,0,sizeof vs);
        for(int l:l2) vs[l] = true;
        ok = false;
        for(int u:l1)
            if(!match1[u]) {
                for(int v:d[u])
                    if(!vs[v] && dfs(v)) {
                        match1[u] = v;
                        match2[v] = u;
                        ok = true;
                        break;
                    }
            }
    } while(ok);
    ok = true;
    for(int u:l1)
        if(!match1[u]) ok = false;
    if(ok) {
        cout <<"YES"<<endl;
        for(int u:l1)
            cout << ss[match1[u]] <<endl;
    } else {
        cout <<"NO"<<endl;
    }
}
