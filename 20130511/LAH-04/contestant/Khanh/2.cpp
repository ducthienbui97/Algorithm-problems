#include<cstdio>
#include<vector>
using namespace std;

const int N = 1e4;
int n;
long long f[N];
vector<vector<int> > g;

void enter() {
	scanf("%d", &n); g.resize(n);
	for(int u, v; scanf("%d%d",&u,&v) == 2 && (u | v); )
		g[--v].push_back(--u);
}

void solve() {
	f[0] = 1;
	for(int u = 1; u < n; ++u)
		for(vector<int>::iterator v = g[u].begin(); v != g[u].end(); ++v)
			f[u] += f[*v];
	printf("%lld\n", f[n-1]);
}

int main() {
	freopen("2.inp", "r", stdin);
	freopen("2.out", "w", stdout);
	enter();
	solve();
	return 0;
}
