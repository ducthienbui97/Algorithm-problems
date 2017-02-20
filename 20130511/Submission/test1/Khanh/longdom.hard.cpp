#include<cstdio>
#include<algorithm>
using namespace std;

const int M = 30, N = 9;
int m, n;
long long f[M+1][1 << (N << 1)];

int main() {
	while(scanf("%d%d",&m,&n) == 2 && (m | n)) {
		if(m * n % 3 != 0) { printf("0\n"); continue; }
		if(n > m) swap(n, m);
		const int Omega = 1 << (n << 1);
		for(int r = 0; r <= m; ++r) for(int k = 0; k < Omega; ++k) f[r][k] = 0;
		f[0][0] = 1;
		int minus = 0; for(int i = 0; i < n; ++i) minus |= 1 << (i << 1);
		for(int r = 0; r < m; ++r)
			for(int k = 0; k < Omega; ++k) if(f[r][k]) {
				bool stop = false;
				for(int i = 0; i < n; ++i)
					if((k & 3 << (i << 1)) == 0) {
						f[r][k | 3 << (i << 1)] += f[r][k];
						if(i + 2 < n && (k & 3 << ((i+1) << 1)) == 0 && (k & 3 << ((i+2) << 1)) == 0)
							f[r][k | 21 << (i << 1)] += f[r][k];
						stop = true; break;
					}
				if(!stop) f[r+1][k - minus] += f[r][k];
			}
		printf("%lld\n", f[m][0]);
	}
	return 0;
}
