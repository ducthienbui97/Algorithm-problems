#include <cstdio>
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int const Maxn=1e4+10;
int const r=1e9;
vector<int> toposort;
long long int k[Maxn];
bool q[Maxn];
bool vs[Maxn];
bool to2[Maxn];
vector<int> d[Maxn],red[Maxn];
void dfs1(int u) {
    vs[u]=false;
    for(int i=0; i<red[u].size(); i++) {
        int v=red[u][i];
        if(vs[v])
            dfs1(v);
        }
    }
void dfs2(int u) {
    if(to2[u]) {
        vs[u]=true;
        for(int i=0; i<d[u].size(); i++) {
            int v=d[u][i];
            if(!vs[v])
                dfs2(v);
            }
        //  timetp[u]=toposort.size();
        toposort.push_back(u);
        }
    }
void dfs3(int u) {
    to2[u]=true;
    for(int i=0; i<red[u].size(); i++) {
        int v=red[u][i];
        if(!to2[v]) dfs3(v);
        }
    }
main() {
    int n,m;
    int x,y;
    scanf("%d%d",&n,&m);
    for(int i=1; i<=m; i++) {
        scanf("%d%d",&x,&y);
        d[x].push_back(y);
        red[y].push_back(x);
        }
    dfs3(2);
    dfs2(1);
    int t=0,l;
    for(int i=toposort.size()-1; i>=0; i--) {
        if(vs[toposort[i]]) {
            t++;
            dfs1(toposort[i]);
            }
        }
    if(t<toposort.size()) printf("inf");
    else {
        k[1]=1;
        for(int i=toposort.size()-1; i>=0; i--) {
            l=toposort[i];
            for(int j=0; j<red[l].size(); j++) {
                q[l]=(q[l]||q[red[l][j]]);
                k[l]=(k[l]+k[red[l][j]]);
                if(k[l]>=r) {
                    k[l]=k[l]%r;
                    q[l]=true;
                    }
                }
            }
        if(q[2]) printf("%09d",k[2]%r);
        else printf("%d",k[2]);
        }
    }



