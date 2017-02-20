#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define FORE(i, v) for (__typeof ((v).begin ()) i = (v).begin (); i != (v).end (); ++i)
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define fi first
#define se second
#define PB push_back
#define MP make_pair
typedef pair <int, int> PII;
typedef long long LL;

const int N = 1e5 + 5, L = 18;
int n, par [N][L], lg2 [N], depth [N];
PII up [N][L];
vector <PII> adj [N];

void check (PII &a, PII b) {
	a.fi = min (a.fi, b.fi);
	a.se = max (a.se, b.se);
}

void dfs (int u, int p) {
	FORE (i, adj [u]) if (i->fi != p) {
		par [i->fi][0] = u;
		up [i->fi][0] = PII (i->se, i->se);
		depth [i->fi] = depth [u] + 1;
		dfs (i->fi, u);
	}
}

int main () {
	freopen ("traffic.inp", "r", stdin);
	freopen ("traffic.out", "w", stdout);
	lg2 [1] = 0;
	FOR (i, 2, N - 1) lg2 [i] = lg2 [i - 1] + (i == (1 << lg2 [i - 1] + 1));
//	FOR (i, 1, 30) cerr << i << " " << lg2 [i] << endl;

	scanf ("%d", &n);
	FOR (i, 2, n) {
		int u, v, w; scanf ("%d%d%d", &u, &v, &w);
		adj [u].PB (PII (v, w));
		adj [v].PB (PII (u, w));
	}

	dfs (1, 0);
	FOR (j, 1, lg2 [n]) FOR (i, 1, n)
		if (par [i][j - 1] && par [par [i][j - 1]][j - 1]) {
			par [i][j] = par [par [i][j - 1]][j - 1];
			up [i][j] = up [i][j - 1];
			check (up [i][j], up [par [i][j - 1]][j - 1]);
		}

	int q; scanf ("%d", &q);
	REP (zz, q) {
		int u, v; scanf ("%d%d", &u, &v);

		if (depth [u] < depth [v]) swap (u, v);
		PII ans (1e9, -1e9);

		for (int i = lg2 [n]; i >= 0; --i)
			if (par [u][i] && depth [par [u][i]] >= depth [v]) {
				check (ans, up [u][i]);
				u = par [u][i];
			}

		for (int i = lg2 [n]; i >= 0; --i)
			if (par [u][i] != par [v][i]) {
				check (ans, up [u][i]);
				check (ans, up [v][i]);
				u = par [u][i];
				v = par [v][i];
			}

		if (u != v) {
			check (ans, up [u][0]);
			check (ans, up [v][0]);
		}

		printf ("%d %d\n", ans.fi, ans.se);
	}
	return 0;
}
