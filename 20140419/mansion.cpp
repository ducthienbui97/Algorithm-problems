#include <bits/stdc++.h>
#define mp make_pair
#define elif else if
#define int long long
using namespace std;
const int Max=3e5+30;
vector<pair<int,int> > lis;
vector<pair<int,int> > h[Max],c[Max];
int nh[Max],nc[Max];
priority_queue<pair< int ,pair<int,int> >,vector<pair < int, pair<int,int> > >,greater<pair <int, pair<int,int> > > >pr;
bool light[Max];
int vs[Max][2];
main() {
    ios_base::sync_with_stdio(false);
    int m,n,k;
    cin>>m>>n>>k;
    lis.push_back(mp(1,1));
    for(int i=1; i<=k; i++) {
        int x,y;
        cin>>x>>y;
        lis.push_back(mp(x,y));
        light[i]=true;
        }
    lis.push_back(mp(m,n));
    for(int i=0; i<lis.size(); i++) {
        h[lis[i].first].push_back(mp(lis[i].second,i));
        c[lis[i].second].push_back(mp(lis[i].first,i));
        }
    for(int i=1; i<=max(m,n); i++) {
        sort(h[i].begin(),h[i].end());
        sort(c[i].begin(),c[i].end());
        }
    for(int i=1; i<=max(m,n); i++) {
        for(int j=0; j<h[i].size(); j++) {
            nh[h[i][j].second]=j;
            }
        for(int j=0; j<c[i].size(); j++) {
            nc[c[i][j].second]=j;
            }
        }
    memset(vs,0x3f,sizeof vs);
    pr.push(mp(0,mp(0,0)));

    for(; !pr.empty(); pr.pop()) {
        int w=pr.top().first;
        int k=pr.top().second.first;
        int s=pr.top().second.second;
        if(w>vs[k][s]) continue;
        int y=lis[k].second;
        int x=lis[k].first;
        if(x==m&&y==n) {
            printf("%lld",w);
            return 0;
            }
        int _x,_y,_w,_k;
        if(light[k]&&w+1<vs[k][!s])vs[k][!s]=w+1,pr.push(mp(w+1,mp(k,!s)));
        if(s) {
            if(nc[k]!=0) {
                _k=c[y][nc[k]-1].second;
                _x=lis[_k].first;
                _y=lis[_k].second;
                _w=w+abs(_x-x);
                if(vs[_k][s]>_w) {
                    vs[_k][s]=_w;
                    pr.push(mp(_w,mp(_k,s)));
                    }
                }
            if(nc[k]!=c[y].size()-1) {
                _k=c[y][nc[k]+1].second;
                _x=lis[_k].first;
                _y=lis[_k].second;
                _w=w+abs(_x-x);
                if(vs[_k][s]>_w) {
                    vs[_k][s]=_w;
                    pr.push(mp(_w,mp(_k,s)));
                    }
                }
            }
        else {

            if(nh[k]!=0) {
                _k=h[x][nh[k]-1].second;
                _x=lis[_k].first;
                _y=lis[_k].second;
                _w=w+abs(_y-y);
                if(vs[_k][s]>_w) {
                    vs[_k][s]=_w;
                    pr.push(mp(_w,mp(_k,s)));
                    }
                }
            if(nh[k]!=h[x].size()-1) {
                _k=h[x][nh[k]+1].second;
                _x=lis[_k].first;
                _y=lis[_k].second;
                _w=w+abs(_y-y);
                if(vs[_k][s]>_w) {
                    vs[_k][s]=_w;
                    pr.push(mp(_w,mp(_k,s)));
                    }
                }
            }
        }
        puts("-1");
    }
