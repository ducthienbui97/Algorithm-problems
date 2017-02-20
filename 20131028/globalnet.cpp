#include <bits/stdc++.h>
using namespace std;
const int Maxn=10011;
inline void getmin(int& x,const int& v){if(x>v) x=v;}
inline void getmax(int& x,const int& v){if(x<v) x=v;}
typedef pair<int,int> edg;
vector<int> d[Maxn];
int n,m;
int low[Maxn];
int num[Maxn];
int bi[Maxn];
int cntb;
int Max;
int pr[Maxn];
int cnt[Maxn];
int cont;
int vs[Maxn];
stack<pair<int,int> > s;
void dfs(int u){
    int child=0;
    low[u]=num[u]=++cont;
    vs[u]=true;
    for(int i=0;i<d[u].size();i++){
        int v=d[u][i];
        if(v==pr[u]) continue;
        s.push(edg(u,v));
        if(vs[v]) getmin(low[u],num[v]);
        else{
            child++;
            pr[v]=u;
            dfs(v);
            getmin(low[u],low[v]);
            if(low[v]>=num[u]){
                if(!pr[u]) bi[u]=child>1;
                else bi[u]=true;
                int t=0;
                edg tmp;
                cntb++;
                do{
                     tmp=s.top();
                    s.pop();
                    if(cnt[tmp.first]!=cntb) cnt[tmp.first]=cntb,t++;
                    if(cnt[tmp.second]!=cntb) cnt[tmp.second]=cntb,t++;
                }while(tmp!=edg(u,v));
                Max=max(Max,t);
            }
        }
    }
}
main(){
    freopen("globalnet.inp","r",stdin);
    freopen("globalnet.out","w",stdout);
    int x,y;
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    while(m--){
        cin>>x>>y;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
        if(!vs[i]) dfs(i);
    vector<int> ans;
    for(int i=1;i<=n;i++){
        if(bi[i]) ans.push_back(i);
    }
    printf("%d %d",ans.size(),Max);
    for(__typeof(ans.begin())it=ans.begin();it!=ans.end();it++)
        printf("\n%d",*it);
}
