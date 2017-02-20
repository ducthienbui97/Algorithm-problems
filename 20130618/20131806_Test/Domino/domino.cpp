#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<queue>
#include<stack>
#include<sstream>
#include<algorithm>
#include<complex>
using namespace std;
#define MP make_pair
#define F first
#define S second
#define PB push_back
int m, n, k;
int board[15][15];
void getinput() {
	memset(board, 0, sizeof(board));
	scanf("%d%d%d", &m, &n, &k);
	for(int i = 0; i < k; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--;
		v--;
		board[u][v] = 1;		
	}
}
int boardmask[13];
long long f[13][1 << 11];
void update(int i, int mask, int cur, int curmask) {
	if (cur == m) {
//		cout << i << " " << mask << " " <<  i + 1 << " " << curmask  << endl;
		f[i + 1][curmask] += f[i][mask];
		return;
	}
	if (cur + 2 <= m)
		if ((mask & (1 << cur)) == 0 && (mask & (1 << (cur + 1))) == 0) 
			if ((boardmask[i] & (1 << cur)) == 0 && (boardmask[i] & (1 << (cur + 1))) == 0) {
				int newcur = cur + 2;
				int newmask = curmask;
				update(i, mask, newcur, newmask);
			}
	if ((mask & (1 << cur)) || (boardmask[i] & (1 << cur))) update(i, mask, cur + 1, curmask);
	if ((mask & (1 << cur)) || (boardmask[i] & (1 << cur)) || (boardmask[i + 1] & (1 << cur))) return;	
	int newmask = curmask | (1 << cur);
	int newcur = cur + 1;
//	cout << "updatemask: " << i + 1 << " " << cur << " " << newmask << " " << curmask << endl;
	update(i, mask, newcur, newmask);
}
long long sum = 0;
void get(int mask, int cur) {
//	cout << mask << " " << cur << endl;
	if (cur == m) {
		sum += f[n - 1][mask];
		return;
	}
	if (cur + 2 <= m)
		if ((mask & (1 << cur)) == 0 && (mask & (1 << (cur + 1))) == 0) 
			if ((boardmask[n - 1] & (1 << cur)) == 0 && (boardmask[n - 1] & (1 << (cur + 1))) == 0) {
				int newcur = cur + 2;
				get(mask, newcur);
			}
	if ((mask & (1 << cur)) || (boardmask[n - 1] & (1 << cur))) get(mask, cur + 1);
}
void process() {
	for(int j = 0; j < n; j++) {
		boardmask[j] = 0;
		for(int i = 0; i < m; i++) 
			if (board[i][j] > 0) boardmask[j] |= (1 << i);
	}
	memset(f, 0, sizeof(f));
	f[0][0] = 1;
	for(int i = 0; (i + 1) < n; i++) 
		for(int mask = 0; mask < (1 << m); mask ++) {
			if (f[i][mask] > 0) update(i, mask, 0, 0);
		}
//	for(int mask = 0; mask < (1 << m); mask ++)
//		if (f[n - 1][mask] > 0) cout << mask << " " << f[n - 1][mask] << endl; 
	for(int mask = 0; mask < (1 << m); mask ++) {
		if (f[n - 1][mask] > 0) get(mask, 0);
	}
	cout << sum << endl;
}
int main() {
	freopen("domino.inp", "r", stdin);
	freopen("domino.out", "w", stdout);
	getinput();
	process();
	return 0;
}
