#include<iostream>
#include<cstring>
#include<cassert>
#include<vector>
#include<cstdio>
#include<queue>
using namespace std;

const int N = 5000;
vector<int> c[N - 1], g[N];
bool vst[N];
int n;

void enter() {
	cin >> n;
	for(int i = 1; i < n; ++i) {
		int u, v; cin >> u >> v; --u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
}

void bfs(int u) {
	queue<int> q; q.push(u); vst[u] = true;
	for(int layer = 0; !q.empty(); ++layer) {
		c[layer].push_back(q.size());
		for(int Z = q.size(); Z > 0; --Z) {
			int u = q.front(); q.pop();
			for(unsigned i = 0; i < g[u].size(); ++i) {
				int v = g[u][i];
				if(!vst[v]) {
					vst[v] = true;
					q.push(v);
				}
			}
		}
	}
}

long long dp(const vector<int> &c) {
	long long f[4] = {1, 0, 0, 0};
	for(unsigned i = 0; i < c.size(); ++i)
		for(int j = 3; j > 0; --j) f[j] += f[j - 1] * c[i];
	return f[3];
}

void solve() {
	long long res = 0;
	for(int root = 0; root < n; ++root) if(g[root].size() >= 3) {
		for(int i = 0; i < n - 1; ++i) c[i].clear();
		memset(vst, 0, sizeof vst); vst[root] = true;
		for(unsigned i = 0; i < g[root].size(); ++i) bfs(g[root][i]);
		for(int i = 0; i < n - 1; ++i) res += dp(c[i]);
	}
	cout << res;
}

int main() {
	//assert(freopen("hotels.inp", "r", stdin));
	//assert(freopen("hotels.out", "w", stdout));
	ios::sync_with_stdio(false);
	enter();
	solve();
	return 0;
}
