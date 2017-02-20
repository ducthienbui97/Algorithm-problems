#include <bits/stdc++.h>
#define elif else if
using namespace std;
const int Max=5e3+30;
int n;
int dis;
bool vs[Max];
queue<int> q[2];
vector<int> d[Max];
vector<int> lis[Max];
void bfs(int t){
    q[0].push(t);
    vs[t]=true;
    for(dis=0;!q[dis&1].empty();++dis){
        lis[dis].push_back(q[dis&1].size());
        while(!q[dis&1].empty()){
            int u=q[dis&1].front();
            q[dis&1].pop();
            for(int i=0;i<d[u].size();i++)
            if(!vs[d[u][i]]){
                vs[d[u][i]]=true;
                q[!(dis&1)].push(d[u][i]);
            }
        }
    }
}
main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    long long ans=0;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        d[x].push_back(y);
        d[y].push_back(x);
    }
    for(int i=1;i<=n;i++){
        memset(vs,0,sizeof vs);
        vs[i]=true;
        int Maxd=0;
        for(int j=0;j<d[i].size();j++)
            bfs(d[i][j]),Maxd=max(Maxd,dis);
        for(dis=0;dis<Maxd;++dis){
            long long t=0;
            long long s=0;
            for(int j=0;j<lis[dis].size();j++){
                ans+=t*lis[dis][j];
                t+=s*lis[dis][j];
                s+=lis[dis][j];
            }
            lis[dis].clear();
        }
    }
    cout<<ans;
}
