#include <algorithm>
#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <climits>
#include <utility>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
const int Maxn=60,Maxx=1e6+10;
int d[Maxn][Maxn];
char c[Maxn][Maxn];
int mx,mn;
vector<int> lower,upper;
int cnt,sx,sy;
bool low[Maxx],up[Maxx];
int n;
int vs[Maxn][Maxn];
int now;
int xi[]={-1,-1,-1,1,1,1,0,0};
int yi[]={-1,1,0,1,-1,0,1,-1};
queue<pair<int,int> > bfs;
bool dfs(int minn,int maxx){
    bfs.push(make_pair(sx,sy));
    int x,y;
    int cx=0;
    vs[sx][sy]=now;
    while(!bfs.empty()){
        x=bfs.front().first;
        y=bfs.front().second;
        bfs.pop();
        if(c[x][y]=='K') ++cx;
        for(int i=0;i<8;i++){
            if(x+xi[i]<0) continue;
            if(y+yi[i]<0) continue;
            if(y+yi[i]>=n) continue;
            if(x+xi[i]>=n) continue;
            if(vs[x+xi[i]][y+yi[i]]==now) continue;
            if(d[x+xi[i]][y+yi[i]]>maxx) continue;
            if(d[x+xi[i]][y+yi[i]]<minn) continue;
            vs[x+xi[i]][y+yi[i]]=now;
            bfs.push(make_pair(x+xi[i],y+yi[i]));
        }
    };
    return (cx==cnt);
}

main(){
    now=0;
    mx=INT_MIN;
    mn=INT_MAX;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%s",&c[i]);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            scanf("%d",&d[i][j]);
            if(c[i][j]=='P'||c[i][j]=='K'){
                if(c[i][j]=='P') sx=i,sy=j;
                else cnt++;
                mx=max(mx,d[i][j]);
                mn=min(mn,d[i][j]);
            }
        }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(d[i][j]<=mn) if(!low[d[i][j]]) lower.push_back(d[i][j]),low[d[i][j]]=true;
            if(d[i][j]>=mx) if(!up[d[i][j]] ) upper.push_back(d[i][j]),up[d[i][j]] =true;
        }
    sort(upper.begin(),upper.end());
    int ans=INT_MAX;
    int l,r,mid;
    for(int i=0;i<(int) lower.size();i++){
        l=0;
        r=(int) upper.size()-1;
         while(l<=r){
            mid=(l+r)/2;
            ++now;
            if(dfs(lower[i],upper[mid])) r=mid-1,ans=min(ans,upper[mid]-lower[i]);
            else l=mid+1;
        }
    }
    printf("%d",ans);
}
