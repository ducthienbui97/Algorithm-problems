#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
#include <climits>
#include <utility>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
const int Maxn=1e6+10;
const int Mn=3000+10;
pair<int,int> p[Maxn];
int D[Mn][Mn];
int vs[Mn][Mn];

main(){
    int x=0,y=0;
    int now=0;
    memset(D,-1,sizeof D);
    int a[6];
    a[5]=0;
    p[0]=make_pair(0,0);
    D[1500][1500]=0;
    for(int i=1;i<=1e6;i++){
       if(a[5]==now){
            now++;
            for(int j=0;j<6;j++)
                a[j]=0;
            a[0]=0;
            x++;
            y=0;
        }
        p[i]=make_pair(x,y);
        D[x+1500][y+1500]=i;
        if(a[4]==now){
            a[5]++;
            x++;
            y--;
        }
        else if(a[3]==now){
            a[4]++;
            x++;
        }
        else if(a[2]==now){
            a[3]++;
            y++;
        }
        else if(a[1]==now){
            a[2]++;
            x--;
            y++;
        }
        else if(a[0]==now){
            a[1]++;
            x--;
        }
        else{
            y--;
            a[0]++;
        }

    }
    queue<pair<int,pair<int,int> > > bfs;
    int ax,bx,z;
    int xi[]={1,1,0,0,-1,-1};
    int yi[]={0,-1,1,-1,0,1};
    scanf("%d%d",&ax,&bx);
    int rep=0;
    bfs.push(make_pair(0,make_pair(p[ax].first+1500,p[ax].second+1500)));
    vs[p[ax].first+1500][p[ax].second+1500]=1;
    while(!bfs.empty()){
        z=bfs.front().first;
        x=bfs.front().second.first;
        y=bfs.front().second.second;
        bfs.pop();
        if(D[x][y]==bx){
            cout<<z;
            return 0;
        }
        for(int i=0;i<6;i++){
            if(x+xi[i]<0) continue;
            if(y+yi[i]<0) continue;
            if(x+xi[i]>3000) continue;
            if(y+yi[i]>3000) continue;
            if(!vs[x+xi[i]][y+yi[i]]){
                vs[x+xi[i]][y+yi[i]]=true;
                bfs.push(make_pair(z+1,make_pair(x+xi[i],y+yi[i])));
            }
        }
    }
}

