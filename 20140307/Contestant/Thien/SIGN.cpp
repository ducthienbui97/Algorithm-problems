#include <bits/stdc++.h>
#define elif else if
using namespace std;
int n,m;
int a[111][555];
int vs[111][555];
typedef pair<int,int> room;
typedef pair<int,room> pp;
priority_queue<pp,vector<pp>,greater<pp> > pq;
int ok(int x,int y,int w){
    if(x>n||!x||y>m||!y||a[x][y]+w>=vs[x][y]) return false;
    return true;
}
room next[]={room(1,0),room(0,-1),room(0,1)};
main(){
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    memset(vs,0x3f,sizeof vs);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        cin>>a[i][j];
    for(int i=1;i<=m;i++){
        vs[1][i]=a[1][i];
        pq.push(pp(vs[1][i],room(1,i)));
    }
    while(!pq.empty()){
        pp tmp=pq.top();
       int x=tmp.second.first;
       int y=tmp.second.second;
       int w=tmp.first;
        pq.pop();
        if(vs[x][y]<w) continue;
        if(x==n){
            printf("%d\n",w);
            return 0;
        }
        for(int i=0;i<3;i++)
        if(ok(x+next[i].first,y+next[i].second,w)){
            vs[x+next[i].first][y+next[i].second]=w+a[x+next[i].first][y+next[i].second];
            pq.push(pp(vs[x+next[i].first][y+next[i].second],room(x+next[i].first,y+next[i].second)));
        }
    }
}

