#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int N = 5000, INF = 1e9;
const long long LINF = 1LL * INF * INF;
long long f[2][N+1];
int a[N], b[N], n;

void enter() {
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
}

void solve() {
	copy(a, a + n, b); sort(b, b + n);
	int m = unique(b, b + n) - b;
	for(int i = 1; i <= n; ++i) {
		f[i&1][0] = LINF;
		for(int j = 1; j <= m; ++j)
			f[i&1][j] = min(f[i&1][j-1], f[~i&1][j] + abs(a[i-1]-b[j-1]));
	}
	cout << f[n & 1][m] << endl;
}

int main() {
	freopen("stairs.inp", "r", stdin);
	freopen("stairs.out", "w", stdout);
	ios::sync_with_stdio(false);
	enter();
	solve();
	return 0;
}
