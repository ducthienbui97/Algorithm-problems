#include<cstdio>
#include<algorithm>
#include<cstring>
#include<numeric>
using namespace std;

const int N = 2000 + 7;
int f[N][N][2], n, k, a[N], b[N];

void enter() {
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
}

int dp(int a[], int n, int k, int f[][N][2]) {
	for(int i = 0; i <= n; ++i)
		for(int j = 0; j <= k; ++j)
			for(int c = 0; c <= 1; ++c)
				f[i][j][c] = 0;
	for(int j = 1; j <= k; ++j) {
		f[1][j][0] = a[1];
		f[1][j][1] = a[1] + a[2];
	}
	for(int i = 2; i <= n; ++i)
		for(int j = 1; j <= k; ++j)
			for(int c = 0; c <= 1; ++c)
				f[i][j][c] = max(f[i-1][j][0], f[i-2][j-1][1] + a[i] + (c == 1 ? a[i+1] : 0));
	return f[n][k][0];
}

void solve() {
	if(k >= n/2 + 1) printf("%d\n", accumulate(a+1, a+n+1, 0));
	else if(n < 4) printf("%d\n", *max_element(a+1, a+n+1));
	else {
		int res = 0;
		copy(a+1, a+n+1, b+1); b[1] = b[n] = 0;
		res = max(res, dp(b, n, k, f));
		copy(a+1, a+n+1, b+1); b[3] += b[2]; b[n-1] += b[n]; b[1] = b[2] = b[n] = 0;
		res = max(res, dp(b, n, k-1, f) + a[1]);
		copy(a+1, a+n+1, b+1); b[2] += b[1]; b[n-2] += b[n-1]; b[1] = b[n-1] = b[n] = 0;
		res = max(res, dp(b, n, k-1, f) + a[n]);
		printf("%d\n", res);
	}
}

int main() {
	enter();
	solve();
	return 0;
}
