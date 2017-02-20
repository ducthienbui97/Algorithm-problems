#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <algorithm>
#include <map>
#include <utility>
#include <set>
#include <deque>
#define elif else if
using namespace std;
int xi[]={-1,1,0,0};
int yi[]={0,0,1,-1};
int n,m;
char c[111][111];
int vs[111][111][22];
int x1,y1;
int tt,w;
int tmp;
queue<pair<pair<int,int>,pair<int,int> > > bfss;
int dfs(int x,int y,int ss){
    while(!bfss.empty()) bfss.pop();
    bfss.push(make_pair(make_pair(0,0),make_pair(x,y)));
    vs[x][y][0]=ss;
    while(!bfss.empty()){
        x1=bfss.front().second.first;
        y1=bfss.front().second.second;
        tt=bfss.front().first.second;
        w=bfss.front().first.first;
        bfss.pop();
        if(c[x1][y1]=='X') return w;
        for(int i=0;i<4;i++){
            if(x1+xi[i]>=n) continue;
            if(x1+xi[i]<0) continue;
            if(y1+yi[i]>=m) continue;
            if(y1+yi[i]<0) continue;
            if(c[x1+xi[i]][y1+yi[i]]=='#') continue;
            if(c[x1+xi[i]][y1+yi[i]]=='B'&&!(tt&1<<0)) continue;
            if(c[x1+xi[i]][y1+yi[i]]=='Y'&&!(tt&1<<1)) continue;
            if(c[x1+xi[i]][y1+yi[i]]=='R'&&!(tt&1<<2)) continue;
            if(c[x1+xi[i]][y1+yi[i]]=='G'&&!(tt&1<<3)) continue;
            tmp=tt;
            if(c[x1+xi[i]][y1+yi[i]]=='b') tmp=(tt|1<<0) ;
            elif(c[x1+xi[i]][y1+yi[i]]=='y') tmp=(tt|1<<1) ;
            elif(c[x1+xi[i]][y1+yi[i]]=='r') tmp=(tt|1<<2) ;
            elif(c[x1+xi[i]][y1+yi[i]]=='g') tmp=(tt|1<<3) ;
            if(vs[x1+xi[i]][y1+yi[i]][tmp]==ss) continue;
            bfss.push(make_pair(make_pair(w+1,tmp),make_pair(x1+xi[i],y1+yi[i])));
            vs[x1+xi[i]][y1+yi[i]][tmp]=ss;

        }
    }
    return -1;
}
void doit(int ss){
    int x,y;
    for(int i=0;i<n;i++){
        scanf("%s",c[i]);
        for(int j=0;j<m;j++)
            if(c[i][j]=='*') x=i,y=j;
    }
    int a=dfs(x,y,ss);
    if(a!=-1){
            printf("Escape possible in %d steps.",a);
        return ;
    }
    printf("The poor student is trapped!");
    return ;
}
main(){
    freopen("MAZE.IN","r",stdin);
    freopen("MAZE.OUT","w",stdout);

    int j=0;
    while(scanf("%d%d",&n,&m)!=EOF&&n&&m)
        doit(++j),putchar('\n');
    return 0;
}
