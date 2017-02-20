#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <climits>
#include <algorithm>
#define elif else if
using namespace std;
struct TH{
    int x,y,tt,c;
};
int m,n;
char c[55][55];
int x[3],y[3];
int v[55][55][5][5];
queue<pair<int,TH> > bfs;
int yy[]={0,0,-1,1};
int xx[]={-1,1,0,0};
int d[4][3]={
    {1,2,3},
    {0,2,3},
    {1,0,3},
    {0,2,1},
};
void doit(){
    TH a;
    int tt;
    int now;
    a.x=x[0];
    a.y=y[0];
    a.tt=a.c=0;
    bfs.push(make_pair(0,a));
    a.c=1;
    bfs.push(make_pair(0,a));
    a.c=2;
    bfs.push(make_pair(0,a));
    a.c=3;
    bfs.push(make_pair(0,a));
    v[a.x][a.y][a.tt][0]=v[a.x][a.y][a.tt][1]=v[a.x][a.y][a.tt][2]=v[a.x][a.y][a.tt][3]=1;
    while(!bfs.empty()){
        a=bfs.front().second;
        tt=a.tt;
        now=bfs.front().first;
        bfs.pop();
        if((tt==1&&a.x==x[2]&&a.y==y[2])||(tt==2&&a.x==x[1]&&a.y==y[1])) {
            printf("%d",now);
            return;
        }
        if(a.x==x[2]&&a.y==y[2]) tt=tt|(1<<1);
        if(a.x==x[1]&&a.y==y[1]) tt=tt|1;
        for(int i=0;i<3;i++){
            TH b;
            b.c=d[a.c][i];
            b.x=a.x+xx[b.c];
            b.y=a.y+yy[b.c];
            b.tt=tt;
            if(c[b.x][b.y]=='#') continue;
            if(b.x>=m) continue;
            if(b.y>=n) continue;
            if(b.x<0) continue;
            if(b.y<0) continue;
            if(v[b.x][b.y][b.tt][b.c]) continue;
            v[b.x][b.y][b.tt][b.c]=1;
            bfs.push(make_pair(now+1,b));

        }
    }
    cout<<-1;
    return;
}
main(){
   // freopen("DELIVER.IN","r",stdin);
   // freopen("DELIVER.OUT","w",stdout);
    int cnt=0;
    while(scanf("%s",c[cnt++])!=EOF);
    m=cnt;
    n=strlen(c[0]);
    cnt=0;
    for(int i=0;i<m;i++)
        for(int j=0;j<n;j++){
        if(c[i][j]=='S') x[0]=i,y[0]=j;
        else if(c[i][j]=='C') x[++cnt]=i,y[cnt]=j;
    }
    doit();
}
