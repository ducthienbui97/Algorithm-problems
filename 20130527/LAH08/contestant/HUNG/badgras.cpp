#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <iterator>

#define maxn 111111

using namespace std;

int n,m;
int a[111][111];
int front,rear;
pair<int,int> queue[maxn];
bool fr[111][111];
int DX[]={0,0,-1,1,1,-1,1,-1};
int DY[]={-1,1,0,0,1,-1,-1,1};
int res;

void push(int u,int v){
    rear++;
    queue[rear]=make_pair(u,v);
    fr[u][v]=false;
}

bool BFS(int x,int y){
    int u,v,t;
    bool ok;
    rear=0;
    front=0;
    push(x,y);
    ok=true;
    while (rear!=front){
        front++;
        x=queue[front].first;
        y=queue[front].second;
        if ((x!=0)||(y!=0)) ok=false;
        for (t=0;t<8;t++){
            u=x+DX[t];
            v=y+DY[t];
            if ((u>=1)&&(u<=n)&&(v>=1)&&(v<=m))
                if (fr[u][v])
                   if(a[u][v]==0) push(u,v);
        }
    }
    return ok;
}

void process(){
    int i,j;
    memset(fr,true,sizeof(fr));
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
            if ((fr[i][j])&&(a[i][j]==0))
                if (!BFS(i,j)){
                    res++;
                }
}


void input(){
    int i,j;
    cin>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++){
            scanf("%d",&a[i][j]);
        }
}



int main(){
    freopen("badgras.inp","r",stdin);
    freopen("badgras.out","w",stdout);
    input();
    process();
    cout<<res;
}
