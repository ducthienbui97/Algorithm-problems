#include <bits/stdc++.h>
using namespace std;
vector<string> S;
vector<string> F;
int d1[222],d2[222],r[222],c[222];
vector<int> d[222];
int p1[222],p2[222];
bool vs[222];
const int INF = 1<<30;
vector<int> dlist;
bool dfs(int u) {
    if(!u) return true;
    vs[u] = true;
    for(int v:d[u]) if(!vs[p2[v]]&&dfs(p2[v])){
        p2[v] = u;
        p1[u] = v;
        return true;
    }
    return false;
}
void solve(int numTest) {
    memset(d1,0,sizeof d1);
    memset(d2,0,sizeof d2);
    memset(r,0,sizeof r);
    memset(c,0,sizeof c);
    memset(p1,0,sizeof p1);
    memset(p2,0,sizeof p2);
    int n,m;
    cin >> n >> m;
    S = vector<string>(n,string(n,' '));
    F = vector<string>(n,string(n,' '));
    for(int i=2; i<=2*n; i++)
        d[i].clear();
    dlist.clear();
    for(int i=0; i<m; i++) {
        int x,y;
        char cc;
        cin >> cc >> x >>y;
        S[x-1][y-1] = cc;
        F[x-1][y-1] = cc;
        if(cc=='+'||cc=='o') {
            d1[x+y]=1;
            d2[x-y+100]=1;
        }
        if(cc=='x'||cc=='o') {
            r[x] = 1;
            c[y] = 1;
        }
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++){
            if(!d1[i+j]&&!d2[i-j+100]) {
                dlist.push_back(i+j);
                d[i+j].push_back(i-j+100);
            }
            if(!r[i]&&!c[j]){
                F[i-1][j-1] = F[i-1][j-1]=='+'?'o':'x';
                r[i] = 1;
                c[j] = 1;
            }
        }

    bool done;
    sort(dlist.begin(),dlist.end());
    dlist.resize(unique(dlist.begin(),dlist.end())-dlist.begin());
    do {
        memset(vs,0,sizeof vs);
        done = false;
        for(int i1:dlist)
            if(!vs[i1] && !p1[i1] && dfs(i1)) {
                done  = true;
            }
    } while(done);
    for(int sum:dlist)if(p1[sum]){
        int sub = p1[sum] - 100;
        int x = (sum+sub)/2;
        int y = (sum-sub)/2;
        F[x-1][y-1] = F[x-1][y-1] =='x'?'o':'+';
    }

    int ans1=0,ans2=0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)if(F[i][j]!=' ') {
                ans1 += (F[i][j]!='x')+(F[i][j]!='+');
                ans2 += (F[i][j]!=S[i][j]);
            }
    cout << "Case #" <<numTest <<": "<<ans1<<" "<<ans2<<endl;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)if(F[i][j]!=S[i][j]) {
                cout<<F[i][j] << " " << i + 1 <<" "<<j + 1<<endl;
            }
}
int main() {
     freopen("D-large.in","r",stdin);
      freopen("out.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i=1; i<=t; i++) solve(i);
}
