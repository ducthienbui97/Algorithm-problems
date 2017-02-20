#include<cstdio>
#include<vector>
#include<algorithm>
#define X   first
#define Y   second
using namespace std;
typedef pair<int, int> ii;
#define TR(v, i) for(__typeof((v).begin())i=(v).begin(); i!=(v).end(); i++)
const int N = 1e5+4;
vector<ii> edge[N];
int n, h[N], par[N][18], low[N][18], high[N][18];

void dfs(int u) {
    TR(edge[u], i) {
        int v=i->X, w=i->Y;
        if (v!=par[u][0]) {
            par[v][0]=u;
            low[v][0]=w;
            high[v][0]=w;
            h[v]=h[u]+1;
            dfs(v);
        }
    }
}

void make_lca() {
    int i, j;
    for (j=1; j<=17; j++)
    for (i=1; i<=n; i++) {
        high[i][j]=max(high[i][j-1], high[par[i][j-1]][j-1]);
        low[i][j]=min(low[i][j-1], low[par[i][j-1]][j-1]);
        par[i][j]=par[par[i][j-1]][j-1];
    }
}

int min(int a, int b, int c) {
    return min(a, min(b, c));
}

int max(int a, int b, int c) {
    return max(a, max(b, c));
}

ii query(int u, int v) {
    if (h[u]<h[v]) swap(u, v);
    int i, ll=1e9, rr=0;
    for (i=17; i>=0; i--) {
        if (h[par[u][i]]>=h[v]) {
            ll=min(ll, low[u][i]);
            rr=max(rr, high[u][i]);
            u=par[u][i];
        }
    }
    if (u==v) return ii(ll, rr);
    for (i=17; i>=0; i--) {
        if (par[u][i]!=par[v][i]) {
            ll=min(ll, low[u][i], low[v][i]);
            rr=max(rr, high[u][i], high[v][i]);
            u=par[u][i];
            v=par[v][i];
        }
    }
    ll=min(ll, low[u][0], low[v][0]);
    rr=max(rr, high[u][0], high[v][0]);
    return ii(ll, rr);
}
main() {
    freopen("traffic.inp", "r", stdin);
    freopen("traffic.out", "w", stdout);
    int i, q;
    scanf("%d", &n);
    for (i=0; i<n-1; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        edge[u].push_back(ii(v, w));
        edge[v].push_back(ii(u, w));
    }
    h[1]=1;
    dfs(1);
    make_lca();
    scanf("%d", &q);
    for (; q--;) {
        int u, v;
        scanf("%d%d", &u, &v);
        ii ans=query(u, v);
        printf("%d %d\n", ans.X, ans.Y);
    }
}
