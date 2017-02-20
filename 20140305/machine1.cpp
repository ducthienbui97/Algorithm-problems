#include <bits/stdc++.h>
#define elif else if
#define int long long
using namespace std;
const int Max=333;
struct edge{
    int fr,to,alw,cost,used;
    edge(int _fr=0,int _to=0,int _alw=0,int _cost=0){
        fr=_fr,to=_to,alw=_alw,cost=_cost,used=0;
    }
    int left(){
        return alw-used;
    }
};
vector<pair<int,int> > query;
vector<edge> lis;
vector<int> d[Max];
vector<int> com;
int dis[Max];
int n;
int p[Max];
bool vs[Max];
void addedge(int fr,int to,int alw,int cost){
    d[fr].push_back(lis.size());
    lis.push_back(edge(fr,to,alw,cost));
    d[to].push_back(lis.size());
    lis.push_back(edge(to,fr,0,-cost));

}
int ans=0;
queue<int> q;
int ford(int fr,int to){
    memset(dis,-1,sizeof dis);
    memset(p,-1,sizeof p);
    dis[fr]=0;
    vs[fr]=true;
    q.push(fr);
    while(!q.empty()){
        int u=q.front();
        q.pop();
        vs[u]=false;
        for(int i=0;i<d[u].size();i++){
            edge tmp=lis[d[u][i]];
            if(tmp.left()>0&&dis[tmp.to]<dis[u]+tmp.cost){
                dis[tmp.to]=dis[u]+tmp.cost;
                p[tmp.to]=d[u][i];
                if(!vs[tmp.to]) vs[tmp.to]=true,q.push(tmp.to);
            }
        }
    }
    if(p[to]<0) return -1;
    int M=(1<<30);
    for(int v=to;v!=fr;v=lis[p[v]].fr){
        M=min(lis[p[v]].left(),M);
    }
    int rep=0;
    for(int v=to;v!=fr;v=lis[p[v]].fr){
        rep+=lis[p[v]].cost;
        lis[p[v]].used+=M;
        lis[p[v]^1].used-=M;
    }
    return rep*M;
}
main(){
    ios_base::sync_with_stdio(false);
    cin>>n;
    query.resize(n);
    for(int i=0;i<n;i++)
        cin>>query[i].first>>query[i].second,com.push_back(query[i].first),com.push_back(query[i].second);
    sort(com.begin(),com.end());
    com.resize(unique(com.begin(),com.end())-com.begin());
    for(int i=0;i<n;i++){
        int x=query[i].first;
        int y=query[i].second;
        int xx=upper_bound(com.begin(),com.end(),x)-com.begin();
        int yy=upper_bound(com.begin(),com.end(),y)-com.begin();
        addedge(xx,yy+1,1,y-x+1);
    }
    for(int i=0;i<=com.size()+1;i++){
        addedge(i,i+1,2,0);
    }
    int ans=0;
    while(1){
     int t=ford(0,com.size()+2);
     if(t==-1) break;
    ans+=t;
    }
    cout<<ans;
}
