#include<cstdio>

const int N = 1e5 + 7;
int nextRow[N], nextCol[N], prevRow[N], prevCol[N], m, n, k;
bool delRow[N], delCol[N], delDia1[N*2], delDia2[N*2];

int dia1(int x, int y) { return x+y-2; }
int dia2(int x, int y) { return n-y+x-1; }

void enter() {
	scanf("%d%d%d", &m, &n, &k);
	for(int i = 1; i <= m; ++i) {
		nextRow[i] = i+1;
		prevRow[i] = i-1;
	}
	nextRow[0] = 1;
	for(int i = 1; i <= n; ++i) {
		nextCol[i] = i+1;
		prevCol[i] = i-1;
	}
	nextCol[0] = 1;
	while(k--) {
		int x, y; scanf("%d%d", &x, &y);
		nextRow[prevRow[x]] = nextRow[x];
		prevRow[nextRow[x]] = prevRow[x];
		nextCol[prevCol[y]] = nextCol[y];
		prevCol[nextCol[y]] = prevCol[y];
		delDia1[dia1(x, y)] = true;
		delDia2[dia2(x, y)] = true;
	}
}

void solve() {
	int res = 0;
	for(int x = nextRow[0]; x <= m; x = nextRow[x])
		for(int y = nextCol[0]; y <= n; y = nextCol[y])
			if(!delDia1[dia1(x, y)] && !delDia2[dia2(x, y)])
				++res;
	printf("%d\n", res);
}

int main() {
	enter();
	solve();
	return 0;
}
