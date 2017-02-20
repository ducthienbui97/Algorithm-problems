#include <algorithm>
#include <cstdio>
#include <climits>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
#define elif else if
#define mp make_pair
#define input "nonneg.inp"
#define output "nonneg.out"
void openfile() {
    freopen(input,"r",stdin);
    freopen(output,"w",stdout);
    }
const int Maxn=25005;
vector<pair<int,int> > d[Maxn];
bool vs[Maxn];
int dis[Maxn];
queue<int> q;
main() {
    int n,m,p,s;
    ios_base::sync_with_stdio(false);
#ifndef HYQ
    openfile();
#endif
    memset(dis,0x3f,sizeof dis);
    cin>>n>>m>>p>>s;
    int x,y,z;
    while(m--){
        cin>>x>>y>>z;
        d[x].push_back(mp(y,z));
        d[y].push_back(mp(x,z));
    }
    while(p--){
        cin>>x>>y>>z;
        d[x].push_back(mp(y,z));
    }
    dis[s]=0;
    vs[s]=true;
    q.push(s);
    while(!q.empty()){
        s=q.front();
        q.pop();
        vs[s]=false;
        for(int i=0;i<d[s].size();i++)
        if(dis[s]+d[s][i].second<dis[d[s][i].first]){
            dis[d[s][i].first]=dis[s]+d[s][i].second;
            if(!vs[d[s][i].first]){
                q.push(d[s][i].first);
                vs[d[s][i].first]=true;
            }
        }
    }
    for(int i=1;i<=n;i++)
        if(dis[i]==dis[n+1]) puts("NO PATH");
        else printf("%d\n",dis[i]);
}
/*
6 3 3 4
1 2 5
3 4 5
5 6 10
3 5 -100
4 6 -100
1 3 -10
*/
