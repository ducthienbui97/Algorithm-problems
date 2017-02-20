#include <iostream>
#include <cstdio>
#include <queue>
#include <string>
#include <cstring>
#include <climits>
#include <vector>
#define input "traffic.inp"
#define output "traffic.out"
#define elif else if
using namespace std;
inline void openfile(){
    freopen(input,"r",stdin);
    freopen(output,"w",stdout);
}
const int Maxn=100011;
int n;
int H[Maxn];
int Max[Maxn][20];
int Min[Maxn][20];
int P[Maxn][20];
vector<pair<int,int> > d[Maxn];
int Log;
int Maxh;
inline void lca(int& x,int& y) {
    if(x==y) {
        printf("0 0\n");
        return ;
        }
    int Mn=INT_MAX,Mx=INT_MIN;
    if(H[x]<H[y]) swap(x,y);
    for(int k=Log; k>=0; k--)
        if(H[P[x][k]]>=H[y]) Mn=min(Mn,Min[x][k]),Mx=max(Mx,Max[x][k]),x=P[x][k];
    if(x==y) {
        printf("%d %d\n",Mn,Mx);
        return ;
        }
    for(int k=Log; k>=0; k--)
        if(P[x][k]!=P[y][k]) {
            Mn=min(Mn,Min[x][k]),Mx=max(Mx,Max[x][k]),x=P[x][k];
            Mn=min(Mn,Min[y][k]),Mx=max(Mx,Max[y][k]),y=P[y][k];
            }
    Mn=min(Mn,Min[x][0]),Mx=max(Mx,Max[x][0]);
    Mn=min(Mn,Min[y][0]),Mx=max(Mx,Max[y][0]);
    printf("%d %d\n",Mn,Mx);
    }
queue<int> Q;
void bfs(int t) {
    Q.push(t);
    while(!Q.empty()) {
        t=Q.front();
        Maxh=H[t];
        Q.pop();
        for(int i=0; i<d[t].size(); i++)
            if(!H[d[t][i].first]) {
                P[d[t][i].first][0]=t;
                Max[d[t][i].first][0]=Min[d[t][i].first][0]=d[t][i].second;
                H[d[t][i].first]=H[t]+1;
                Q.push(d[t][i].first);
                }
        }
    }
main() {
    openfile();
    ios_base::sync_with_stdio(false);
    cin>>n;
    int x,y,z;
    for(int i=1; i<n; i++) {
        cin>>x>>y>>z;
        d[x].push_back(make_pair(y,z));
        d[y].push_back(make_pair(x,z));
        }
    H[1]=1;
    Maxh=INT_MAX;
    bfs(1);
    for( Log=0;(1<<Log)<=Maxh ;Log++ ) ;
    Log--;
    for(int i=1; i<=Log; i++)
        for(int j=1; j<=n; j++) {
            P[j][i]=P[P[j][i-1]][i-1];
            Max[j][i]=max(Max[j][i-1],Max[P[j][i-1]][i-1]);
            Min[j][i]=min(Min[j][i-1],Min[P[j][i-1]][i-1]);
            }
    int q;
    cin>>q;
    while(q--) {
        cin>>x>>y;
        lca(x,y);
        }
    }




