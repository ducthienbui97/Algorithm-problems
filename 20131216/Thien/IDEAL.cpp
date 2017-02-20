#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#define mp make_pair
#define elif else if
using namespace std;
const int Maxn=1e5+20;
vector<int> d[Maxn];
vector<int> a,b,c;
int n,m;
int ans[Maxn],Mmin[Maxn];
int dis[Maxn];
int vs[Maxn];
queue<int> q;
main(){
    freopen("IDEAL.inp","r",stdin);
    freopen("IDEAL.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    a.resize(m);
    b.resize(m);
    c.resize(m);
    for(int i=0;i<m;i++){
        cin>>a[i]>>b[i]>>c[i];
        d[a[i]].push_back(i);
        d[b[i]].push_back(i);
    }
    memset(ans,0x3f,sizeof ans);
    dis[n]=1;
    q.push(n);
    while(!q.empty()){
        int u=q.front(),v;
        q.pop();
        for(int i=0;i<d[u].size();i++){
            v=u==a[d[u][i]]?b[d[u][i]]:a[d[u][i]];
            if(!dis[v]){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    vs[1]=1;
    ans[1]=0;
    q.push(1);
    while(!q.empty()){
        int u=q.front(),v;
        q.pop();
        if(ans[vs[u]]==Mmin[u])
        for(int i=0;i<d[u].size();i++){
            v=u==a[d[u][i]]?b[d[u][i]]:a[d[u][i]];
            if(vs[u]+dis[v]==dis[1]){
                ans[vs[u]+1]=min(ans[vs[u]+1],c[d[u][i]]);
                if(!vs[v]){
                    q.push(v);
                    vs[v]=vs[u]+1;
                    Mmin[v]=c[d[u][i]];
                }else Mmin[v]=min(Mmin[v],c[d[u][i]]);
            }
        }
    }
    printf("%d\n",dis[1]-1);
    for(int i=2;i<=dis[1];i++)
        printf("%d ",ans[i]);
}
