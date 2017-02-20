#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;

#define TR(v,i) for(typeof((v).begin())i=(v).begin();i!=(v).end();++i)
const int N = 1e5 + 2, LOGN = 17 + 2;
int P[N][LOGN], L[N], Wmin[N][LOGN], Wmax[N][LOGN], n;
vector<vector<pair<int, int> > > g;

void dfs(int u) {
	TR(g[u], it) {
		int v = it->first, w = it->second;
		if(v != P[u][0]) {
			P[v][0] = u; L[v] = L[u] + 1;
			Wmin[v][0] = Wmax[v][0] = w;
			dfs(v);
		}
	}
}

void init() {
	memset(P, -1, sizeof P);
	dfs(0);
	for(int j = 1; 1 << j < n; ++j)
		for(int u = 0; u < n; ++u)
			if(P[u][j-1] != -1) {
				P[u][j] = P[P[u][j-1]][j-1];
				Wmin[u][j] = min(Wmin[u][j-1], Wmin[P[u][j-1]][j-1]);
				Wmax[u][j] = max(Wmax[u][j-1], Wmax[P[u][j-1]][j-1]);
			}
}

void query(int u, int v) {
	if(L[u] < L[v]) swap(u, v);
	int log = 0; for(; 1 << log <= L[u]; ++log); --log;
	int wmin = INT_MAX, wmax = INT_MIN;
	for(int i = log; i >= 0; --i)
		if(L[u] - (1 << i) >= L[v]) {
			wmin = min(wmin, Wmin[u][i]);
			wmax = max(wmax, Wmax[u][i]);
			u = P[u][i];
		}
	if(u != v) {
		for(int i = log; i >= 0; --i)
			if(P[u][i] != P[v][i]) {
				wmin = min(wmin, min(Wmin[u][i], Wmin[v][i]));
				wmax = max(wmax, max(Wmax[u][i], Wmax[v][i]));
				u = P[u][i]; v = P[v][i];
			}
		wmin = min(wmin, min(Wmin[u][0], Wmin[v][0]));
		wmax = max(wmax, max(Wmax[u][0], Wmax[v][0]));
	}
	printf("%d %d\n", wmin, wmax);
}

void enter() {
	scanf("%d", &n); g.resize(n);
	for(int i = 1; i < n; ++i) {
		int u, v, w; scanf("%d%d%d",&u,&v,&w);
		g[--u].push_back(make_pair(--v, w));
		g[v].push_back(make_pair(u, w));
	}
}

void solve() {
	int k; scanf("%d", &k);
	while(k--) {
		int u, v; scanf("%d%d",&u,&v);
		query(--u, --v);
	}
}

int main() {
	freopen("traffic.inp", "r", stdin);
	freopen("traffic.out", "w", stdout);
	enter();
	init();
	solve();
	return 0;
}
