#include<cstdio>
#include<cstdlib>
using namespace std;

const int N = 30, d[4][2] = {{-1, -1}, {-1, +1}, {+1, -1}, {+1, +1}};
char mat[N][N];
int n, nO, posX[N*N], posY[N*N];

void enter() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%s", mat[i]);
}

void backtrack(int x, int y, int step) {
	posX[step] = x; posY[step] = y;
	if(step == nO) {
		for(int i = 0; i <= nO; ++i)
			printf("%d %d\n", posX[i] + 1, posY[i] + 1);
		exit(EXIT_SUCCESS);
	} else {
		for(int move = 0; move < 4; ++move) {
			int ox = x + d[move][0], oy = y + d[move][1];
			if(ox >= 0 && ox < n && oy >= 0 && oy < n && mat[ox][oy] == 'o') {
				int px = ox + d[move][0], py = oy + d[move][1];
				if(px >= 0 && px < n && py >= 0 && py < n && mat[px][py] == '+') {
					mat[ox][oy] = '*';
					backtrack(px, py, step + 1);
					mat[ox][oy] = 'o';
				}
			}
		}
	}
}

void solve() {
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(mat[i][j] == 'o') ++nO;
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			if(mat[i][j] == 'K')
				backtrack(i, j, 0);
	puts("impossible");
}

int main() {
	freopen("chkr.inp", "r", stdin);
	freopen("chkr.out", "w", stdout);
	enter();
	solve();
	return 0;
}
