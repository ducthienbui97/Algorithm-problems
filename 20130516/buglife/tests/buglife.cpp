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
bool check;
int n,m;
vector<int> d[Maxn];
int vs[Maxn];
bool dfs(int k,int t){
    if(vs[k]==-1){
        vs[k]=t;
        for(int i=0;i<d[k].size();i++){
            if(vs[d[k][i]]==t) check=false;
            elif(vs[d[k][i]]==-1) dfs(d[k][i],!t);
        }

    }
    return check;
}
void doit(int xx){
    scanf("%d%d",&n,&m);
    for(int i=0;i<=n;i++){
        d[i].clear();
        vs[i]=-1;
    }
    int x,y;
    check=true;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&x,&y);
        d[x].pb(y);
        d[y].pb(x);
    }
    for(int i=1;i<=n;i++)
    if(vs[i]==-1)check=dfs(i,0);
    if(check) printf("Scenario #%d:\nNo suspicious bugs found!\n",xx);
    else printf("Scenario #%d:\nSuspicious bugs found!\n",xx);
}
main(){
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
        doit(i);
}
