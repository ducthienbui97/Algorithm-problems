#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 30000 + 5, K = 500 + 5;
int n, k, w, f[N][K], a[N];

void enter() {
	scanf("%d%d%d",&n,&k,&w);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a[i]);
		a[i] += a[i-1];
	}
}

void solve() {
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= k; ++j)
			if(j * w >= i) f[i][j] = a[i];
			else f[i][j] = max(f[i-1][j], f[i-w][j-1] + a[i] - a[i-w]);
	printf("%d\n", f[n][k]);
}

int main() {
	freopen("3.inp", "r", stdin);
	freopen("3.out", "w", stdout);
	int T; scanf("%d", &T);
	while(T--) {
		enter();
		solve();
	}
	return 0;
}
