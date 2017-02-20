#include<cstdio>

const int N = 1e6+7;
int pos[2*N], sum[N], nextOne[N], n, m;
char lo[N];

void enter() {
	scanf("%d%d%s",&n,&m,lo+1);
}

void init() {
	for(int i = 1; i <= n; ++i) {
		sum[i] = sum[i-1] + (lo[i] == 'T' ? 2 : 1);
		pos[sum[i]] = i;
	}
	for(int i = n; i >= 1; --i)
		nextOne[i] = lo[i] == 'W' ? i : nextOne[i+1];
}

void query(int k) {
	if(k > sum[n]) puts("NIE");
	else if(pos[k] != 0) printf("1 %d\n", pos[k]);
	else {
		int p = pos[k+1];
		if(nextOne[1] != 0 && sum[nextOne[1]] + k <= sum[n] && pos[sum[nextOne[1]] + k] != 0)
			printf("%d %d\n", nextOne[1] + 1, pos[sum[nextOne[1]] + k]);
		else if(nextOne[p] != 0)
			printf("%d %d\n", pos[sum[nextOne[p]] - k] + 1, nextOne[p]);
		else puts("NIE");
	}
}

void solve() {
	for(int i = 0; i < m; ++i) {
		int k; scanf("%d", &k);
		query(k);
	}
}

int main() {
	enter();
	init();
	solve();
	return 0;
}
