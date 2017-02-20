#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 10;
long long f[2][1 << N][1 << N];
int ban[N+2], m, n, k;

void enter() {
	scanf("%d%d%d", &m, &n, &k);
	for(int i = 0; i < k; ++i) {
		int x, y; scanf("%d%d", &x, &y);
		ban[x-1] |= 1 << (y-1);
	}
}

void solve() {
	f[0][ban[0]][ban[1]] = 1;
	const int Omega = 1 << n;
	for(int i = 0; i < m; ++i) {
		for(int s = 0; s < Omega; ++s)
			fill(f[(i+1)%2][s], f[(i+1)%2][s]+Omega, 0);
		for(int s1 = 0; s1 < Omega; ++s1)
			for(int s2 = 0; s2 < Omega; ++s2)
				if(f[i%2][s1][s2] > 0) {
					const long long &now = f[i%2][s1][s2];
					if(s1 == Omega - 1)
						f[(i+1)%2][s2][ban[i+2]] += now;
					else {
						int fst = ~s1 & -~s1;
						if((s1 & fst << 1) == 0 && (fst << 1) < Omega)
							f[i%2][s1 | fst | fst << 1][s2] += now;
						if((s2 & fst) == 0)
							f[i%2][s1 | fst][s2 | fst] += now;
					}
				}
	}
	printf("%lld\n", f[m%2][0][0]);
}

int main() {
	enter();
	solve();
	return 0;
}
