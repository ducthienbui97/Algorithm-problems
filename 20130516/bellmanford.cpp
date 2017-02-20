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
#include <deque>
#define elif else if
#define pb push_back
#define mp make_pair
#include <utility>
const int  Maxn = 1e6+11;
using namespace std;
queue <int> q;
int s,f,n,m;
bool inqueue[Maxn];
vector<pair<int,int> > d[Maxn];
int k[Maxn];
int pop(){
    int x=q.front();
    inqueue[x]=false;
    q.pop();
    return x;
}
void push(int i){
if(!inqueue[i]) {q.push(i);
    inqueue[i]=true;
    }
}
void bmf(){
    push(s);
    memset(k,0x5f,sizeof k);
    k[s]=0;
    int x,y;
    while(!q.empty()){
            x=pop();
        for(int i=0;i<d[x].size();i++){
           // cout<<d[x][i].first<<" "<<k[x]<<" "<<d[x][i].second<<endl;
            if(k[d[x][i].first]>k[x]+d[x][i].second){
                k[d[x][i].first]=k[x]+d[x][i].second;
                push(d[x][i].first);}
        }
    }
    printf("%d",k[f]);
}
void read(){
    int x,y,z;
   scanf("%d%d%d%d",&n,&m,&s,&f);
   for(int i=1;i<=m;i++){
    scanf("%d%d%d",&x,&y,&z);
    d[x].pb(mp(y,z));
    d[y].pb(mp(x,z));
   }
}
main(){
    read();
    bmf();
}
