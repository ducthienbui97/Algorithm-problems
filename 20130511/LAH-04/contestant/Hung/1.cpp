#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>

#define INF 1111111111

using namespace std;

int n;
vector< pair<int,int> > adj[11111];

void input(){
    int i;
    int u,v;
    scanf("%d",&n);
    for (i=1;i<=n;i++) adj[i].clear();
    for (i=1;i<=n;i++){
            scanf ("%d%d",&u,&v);
            adj[u].push_back(make_pair(v,1));
    }
}

int main(){
    freopen("1.inp","r",stdin);
    freopen("1.out","w",stdout);
    input();
    while (1){
            int s,f;
            scanf("%d%d",&s,&f);
            if (s==0&&f==0) break;
            else{
                int i,u,v;
                int d[1111];
            bool stop;
            for (v=1;v<=n;v++) d[v]=INF;
            d[s]=0;
            while (true){
                stop=true;
                for (u=1;u<=n;u++)
                    for (i=0;i<adj[u].size();i++){
                        v=adj[u][i].first;
                        if (d[v]>d[u]+adj[u][i].second){
                            d[v]=d[u]+adj[u][i].second;
                            stop=false;
                        }
                    }
                if (stop) break;
            }
            if (d[f]==INF) printf("No");
            if (d[f]!=INF) printf("Yes %d", d[f]-1);
            }
    }
}
