#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> ii;
typedef pair<ii, int> triple;
#define X first
#define Y second

bool minimize(int &a, int b){ if (a>b) a=b; else return false; return true; }
bool maximize(int &a, int b){ if (a<b) a=b; else return false; return true; }

int n, m;
triple parent[23][102309];
int level[102039];
vector<ii> a[102309];

void direct(int u, int lev){
    int i, v;
    level[u]=lev;
    for (i=0; v=a[u][i].Y; i++)
    if (v!=parent[0][u].Y){
        parent[0][v]=triple(ii(a[u][i].X, a[u][i].X), u);
        direct(v, lev+1);
    }
    if (parent[0][u].Y==u)
    parent[0][u]=triple(ii(0x77778888, 0x88887777), u);
}

void lca(){
    for (int k=1; k<=20; k++)
    for (int i=1; i<=n; i++){
        parent[k][i].Y=parent[k-1][parent[k-1][i].Y].Y;
        parent[k][i].X.X=min(parent[k-1][i].X.X, parent[k-1][parent[k-1][i].Y].X.X);
        parent[k][i].X.Y=max(parent[k-1][i].X.Y, parent[k-1][parent[k-1][i].Y].X.Y);
    }
}

int lca(int p, int q){
    for (int k=20; k>=0; k--) if (level[parent[k][p].Y] >= level[q]) p=parent[k][p].Y;
    for (int k=20; k>=0; k--) if (level[parent[k][q].Y] >= level[p]) q=parent[k][q].Y;
    for (int k=20; k>=0; k--) if (parent[k][p].Y != parent[k][q].Y) { p=parent[k][p].Y; q=parent[k][q].Y; }
    while (p!=q) { p=parent[0][p].Y; q=parent[0][q].Y; }
    return p;
}

int lca_min(int p, int q){
    int LCA = lca(p, q);
    int r=0x77778888;
    for (int k=20; k>=0; k--)
    if (level[parent[k][p].Y] >= level[LCA]) {
        minimize(r, parent[k][p].X.X);
        p=parent[k][p].Y;
    }
    for (int k=20; k>=0; k--)
    if (level[parent[k][q].Y] >= level[LCA]) {
        minimize(r, parent[k][q].X.X);
        q=parent[k][q].Y;
    }
    return r;
}

int lca_max(int p, int q){
    int LCA = lca(p, q);
    int r=0x88887777;
    for (int k=20; k>=0; k--)
    if (level[parent[k][p].Y] >= level[LCA]) {
        maximize(r, parent[k][p].X.Y);
        p=parent[k][p].Y;
    }
    for (int k=20; k>=0; k--)
    if (level[parent[k][q].Y] >= level[LCA]) {
        maximize(r, parent[k][q].X.Y);
        q=parent[k][q].Y;
    }
    return r;
}

main(){
	freopen("traffic.inp", "r", stdin);
	freopen("traffic.out", "w", stdout);

    int i, k, p, q, w;
    scanf("%d", &n);
    m=n-1;
    for (i=1; i<=m; i++){
        scanf("%d%d%d", &p, &q, &w);
        a[p].push_back(ii(w, q));
        a[q].push_back(ii(w, p));
    }
    for (i=1; i<=n; i++) a[i].push_back(ii());
    parent[0][1].Y=1;
    direct(1, 1);
    lca();
    scanf("%d", &m);
    for (i=1; i<=m; i++){
        scanf("%d%d", &p, &q);
        printf("%d %d\n", lca_min(p, q), lca_max(p, q));
    }
}


