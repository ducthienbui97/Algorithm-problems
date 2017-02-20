#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

const int M = 150, N = 10, P = 59049;
int f[2][N+1][P], m, n, p3[N+1];
bool ban[M][N];

void checkmax(int &x, int y) {
	if(y > x) x = y;
}

void init() {
	p3[0] = 1;
	for(int i = 1; i <= N; ++i)
		p3[i] = p3[i-1] * 3;
}

void enter() {
	int k; cin >> m >> n >> k;
	memset(ban, 0, sizeof ban);
	for(int i = 0; i < k; ++i) {
		int x, y; cin >> x >> y;
		ban[x-1][y-1] = true;
	}
}

int get(int num, int pos) {
	return num / p3[pos] % 3;
}

int dec(int num, int pos) {
	if(get(num, pos) == 0) return num;
	return num - p3[pos];
}

void reset(int f[][P]) {
	for(int i = 0; i <= n; ++i)
		fill_n(f[i], p3[n], 0);
}

bool can(int x, int y, int mask, int r, int c) {
	if(x + r > m) return false;
	if(y + c > n) return false;
	for(int j = 0; j < c; ++j)
		if(get(mask, y + j) != 0) return false;
	for(int i = 0; i < r; ++i)
		for(int j = 0; j < c; ++j)
			if(ban[x + i][y + j]) return false;
	return true;
}

void dp() {
	reset(f[0]);
	for(int i = 0; i < m; ++i) {
		int x = i & 1, y = ~i & 1;
		reset(f[y]);
		for(int j = 0; j <= n; ++j)
			for(int mask = 0; mask < p3[n]; ++mask)
				if(j == n) checkmax(f[y][0][mask], f[x][j][mask]);
				else {
					checkmax(f[x][j+1][dec(mask, j)], f[x][j][mask]);
					if(can(i, j, mask, 2, 3))
						checkmax(f[x][j+3][mask + 13 * p3[j]], f[x][j][mask] + 1);
					if(can(i, j, mask, 3, 2))
						checkmax(f[x][j+2][mask + 8 * p3[j]], f[x][j][mask] + 1);
				}
	}
	cout << f[m & 1][0][0] << '\n';
}

int main() {
	freopen("bugs.inp", "r", stdin);
	freopen("bugs.out", "w", stdout);
	ios::sync_with_stdio(false);
	init();
	int tc; cin >> tc;
	while(tc--) enter(), dp();
	return 0;
}
