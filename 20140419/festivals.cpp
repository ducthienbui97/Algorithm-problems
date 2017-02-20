#include <bits/stdc++.h>
#define mp make_pair
#define elif else if
//#define int long long
using namespace std;
const int Max=2e5+20;
int n,m,k,q;
vector<pair<int,pair<int,int> > > edg;
vector<int> d[Max];
set<pair<pair<int,int>,int > > ms;
int vs[Max];
int ans[Max];
int nz[Max],root[Max];
vector<pair<int,int> > qr[Max];
priority_queue<pair<int,int>,vector<pair<int,int> > ,greater<pair<int,int> > > pr;
int findroot(int x){
    if(root[x]==x) return x;
    return root[x]=findroot(root[x]);
}
main() {
    ios_base::sync_with_stdio(false);
    cin>>n>>m>>k>>q;
    for(int i=0;i<m;i++){
        int x,y,w;
        cin>>x>>y>>w;
        d[x].push_back(edg.size());
        d[y].push_back(edg.size());
        edg.push_back(mp(w,mp(x,y)));
    }
    memset(vs,0x3f,sizeof vs);
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        vs[x]=0;
        pr.push(mp(0,x));
    }
    for(;!pr.empty();pr.pop()){
        int x=pr.top().second;
        int w=pr.top().first;
        int y;
        if(vs[x]<w) continue;
        for(int i=0;i<d[x].size();i++){
            if(x==edg[d[x][i]].second.first) y=edg[d[x][i]].second.second;
            else y=edg[d[x][i]].second.first;
            if(w+edg[d[x][i]].first<vs[y]){
                vs[y]=w+edg[d[x][i]].first;
                pr.push(mp(vs[y],y));
            }
        }
    }
    for(int i=0;i<edg.size();i++){
        int x=edg[i].second.first;
        int y=edg[i].second.second;
        edg[i].first=min(vs[x],vs[y]);
    }
    sort(edg.begin(),edg.end());
    reverse(edg.begin(),edg.end());
    int x,y,z;
    for(int i=1;i<=q;i++){
        cin>>x>>y;
        qr[x].push_back(mp(y,i));
        qr[y].push_back(mp(x,i));
    }
    for(int i=1;i<=n;i++)
        root[i]=i;
    for(int i=0;i<edg.size();i++){
        int x=findroot(edg[i].second.second);
        int y=findroot(edg[i].second.first);
        if(findroot(x)!=findroot(y)){
            if(qr[x].size()>qr[y].size()) swap(x,y);
            for(;qr[x].size();qr[x].pop_back()){
                int z=findroot(qr[x].back().first);
                if(z==x) continue;
                if(z==y){
                    ans[qr[x].back().second]=edg[i].first;
                    continue;
                }
                qr[y].push_back(qr[x].back());
            }
            root[x]=y;
        }
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]);
}
