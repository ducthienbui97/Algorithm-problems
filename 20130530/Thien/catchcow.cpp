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
#include <climits>
#include <algorithm>
#include <utility>
#define elif else if
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pi;
queue<pi> bfs;
bool vs[211111];
main(){
    freopen("catchcow.inp","r",stdin);
    freopen("catchcow.out","w",stdout);
    int n,k;
    int x,y;
    scanf("%d%d",&n,&k);
    bfs.push(pi(0,n));
    vs[n]=true;
    while(!bfs.empty()){
        x=bfs.front().X;
        y=bfs.front().Y;
        bfs.pop();
        //cout<<x<<" "<<y<<endl;
            if(y==k) {
                printf("%d",x);
                break;}
            if(y>0)if(!vs[y-1]) vs[y-1]=true,bfs.push(pi(x+1,y-1));
            if(y<100000)if(!vs[y+1]) vs[y+1]=true,bfs.push(pi(x+1,y+1));
            if(2*y<=100000) if(!vs[2*y]) vs[2*y]=true,bfs.push(pi(x+1,2*y));
        }
    }

