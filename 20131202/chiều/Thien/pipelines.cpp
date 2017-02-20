#include <iostream>
#include <cstdio>
#include <cstring>
#define mp make_pair
#include <string>
#include <vector>
#include <algorithm>
#include  <queue>
#define elif else if
#define int long long
#define mp make_pair
#define W first
#define N second.first
#define K second.second
using namespace std;
int D[10011][22];
typedef pair<int,int> edg;
typedef pair<int,edg> par;
int n,m,k;
vector<edg> d[10011];
priority_queue<par,vector<par>, greater<par> > pr;
main() {
    freopen("pipelines.inp","r",stdin);
    freopen("pipelines.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k;
    memset(D,0x3f,sizeof D);
    int x,y,z;
    while(m--) {
        cin>>x>>y>>z;
        d[x].push_back(mp(y,z));
        d[y].push_back(mp(x,z));
        }
    D[1][k]=0;
    pr.push(mp(0,mp(1,k)));
    int ans=1ll<<60;
    while(!pr.empty()) {
        par t=pr.top();
        pr.pop();
        if(t.W>D[t.N][t.K]) continue;
        if(t.N==n) ans=min(ans,t.W);
        for(int i=0; i<d[t.N].size(); i++) {
            if(t.K) {
                if(t.W<D[d[t.N][i].first][t.K-1]) {
                    D[d[t.N][i].first][t.K-1]=t.W;
                    pr.push(mp(t.W,mp(d[t.N][i].first,t.K-1)));
                    }
            }
            if(t.W+d[t.N][i].second<D[d[t.N][i].first][t.K]) {
                D[d[t.N][i].first][t.K]=t.W+d[t.N][i].second;
                pr.push(mp(t.W+d[t.N][i].second,mp(d[t.N][i].first,t.K)));
                }
            }
        }
        cout<<ans<<endl;
    }
