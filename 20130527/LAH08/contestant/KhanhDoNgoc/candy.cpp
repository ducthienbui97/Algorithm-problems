#include<cstdio>
#include<algorithm>
using namespace std;

const int C = 100+7, B = 10+7, N = C * B;
int a[N], f[N][N], t[N][N][2], c, b, n;

void enter() {
	scanf("%d%d",&c,&b);
	n = c * b;
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
}

void solve() {
	for(int i = 0; i < n; ++i) {
		f[i][i] = 1;
		t[i][i][0] = t[i][i][1] = -1;
	}
	for(int len = 2; len <= n; ++len)
		for(int i = 0; i < n; ++i) {
			int j = (i + len - 1) % n;
			bool same = true;
			for(int k = i, cont = 1; cont == 1; k = (k+1) % n) {
				if(a[k] != a[i]) same = false;
				if(k == j) cont = false;
			}
			if(same) {
				f[i][j] = 0;
				t[i][j][0] = t[i][j][1] = -1;
			} else {
				int u = (i+1)%n, v = (j+n-1)%n, du = 1, dv = 1;
				while(a[u] == a[i]) u = (u+1)%n, ++du;
				while(a[v] == a[j]) v = (v+n-1)%n, ++dv;
				if(a[i] != a[j]) {
					if(f[u][j] + (du == 1) < f[i][v] + (dv == 1)) {
						f[i][j] = f[u][j] + (du == 1);
						t[i][j][0] = u; t[i][j][1] = j;
					} else {
						f[i][j] = f[i][v] + (dv == 1);
						t[i][j][0] = i; t[i][j][1] = v;
					}
				} else {
					f[i][j] = f[u][v];
					t[i][j][0] = u; t[i][j][1] = v;
				}
			}
		}
}

void trace() {
	int res = f[0][n-1], u = 0;
	for(int i = 1; i < n; ++i) res = min(res, f[i][i-1]), u = res == f[i][i-1] ? i : u;
	printf("%d\n", res);
	int v = (u+n-1)%n;
	while(u != -1 && v != -1) {
		int U = u, V = v;
		u = t[U][V][0]; v = t[U][V][1];
		if(u == -1 && v == -1) printf("%d %d\n", U, V);
		else if(f[u][v] + 1 == f[U][V]) {
			if((U+1)%n == u) printf("%d %d\n", U, U);
			else printf("%d %d\n", V, V);
		} else printf("%d %d\n", (v+1)%n, (u+n-1)%n);
	}
}

int main() {
	enter();
	solve();
	trace();
	return 0;
}
