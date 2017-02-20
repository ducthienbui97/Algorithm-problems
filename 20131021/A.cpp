#include <bits/stdc++.h>
#define elif else if
#define FOR(i,d) for(__typeof(d.begin()) i=d.begin();i!=d.end();i++)
using namespace std;
vector<int> d[555];
int vs[555];
int pr[555];
queue <int> q;
int bfs(int t) {
    q.push(t);
    vs[t]=1;
    int rep=1<<30;
    while(!q.empty()) {
        int u=q.front();
        q.pop();
        FOR(i,d[u]) if((*i)!=pr[u])
                        if(!vs[*i]) q.push(*i),vs[*i]=vs[u]+1,pr[*i]=u;
                        else rep=min(rep,vs[u]+vs[*i]-1);
        }
    return rep;
    }
void doit() {
    int n,m;
    cin>>n>>m;
    int x,y;
    for(int i=0; i<n; i++) d[i].clear();
    while(m--) {
        cin>>x>>y;
        d[x].push_back(y);
        d[y].push_back(x);
        }
    int ans=1<<30;
    for(int i=0; i<n; i++) {
        memset(vs,0,sizeof vs);
        memset(pr,-1,sizeof pr);
        q=queue<int>();
        ans=min(ans,bfs(i));
        if(ans==3) break;
        }
    if(ans==(1<<30)) puts("impossible");
    else printf("%d\n",ans);
    }
main() {
    ios_base::sync_with_stdio(false);
    int t;
    int cnt=0;
    cin>>t;
    while(t--) printf("Case %d: ",++cnt) ,doit();
    }
