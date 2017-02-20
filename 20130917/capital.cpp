#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

#define TR(v,i) for(__typeof((v).begin())i=(v).begin();i!=(v).end();++i)
const int N = 3e5;
vector<int> g[N];
int n, d[N], low[N], cmax, c, ttime;

void dfs(int u, int p) {
	d[u] = low[u] = ttime++;
	int nchild = 0, cnt = 0;
	TR(g[u], v) if(d[*v] == -1) {
		dfs(*v, u); ++nchild;
		low[u] = min(low[u], low[*v]);
		if(low[*v] >= d[u]) ++cnt;
	} else if(*v != p)
		low[u] = min(low[u], d[*v]);
	int nComp = p == -1 ? nchild - 1 : cnt;
	if(nComp > cmax) cmax = nComp, c = u;
	else if(nComp == cmax && u < c) c = u;
}

void enter() {
	int m; cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void solve() {
	ttime = 0; cmax = -n;
	memset(d, -1, sizeof d);
	int nComp = 0;
	for(int u = 0; u < n; ++u)
		if(d[u] == -1) dfs(u, -1), ++nComp;
	cout << cmax + nComp << ' ' << c + 1 << endl;
}

int main() {
	freopen("capital.inp", "r", stdin);
	freopen("capital.out", "w", stdout);
	ios::sync_with_stdio(false);
	enter();
	solve();
	return 0;
}
