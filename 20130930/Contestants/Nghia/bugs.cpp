#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
bool bad[160][12];
ll f[12][70000];
int pow3[12];
int d[12];

int main() {
    freopen("bugs.inp","r",stdin);
    freopen("bugs.out","w",stdout);
	pow3[0] = 1;
	for(int i = 1; i <= 10; i++)
		pow3[i] = pow3[i-1] * 3;
	int D,M,N,K;
	scanf("%d",&D);
	while(D--) {
		int x,y;
		memset(bad,0,sizeof bad);
		memset(f,0,sizeof f);
		scanf("%d %d %d",&N,&M,&K);
		while(K--) {
			scanf("%d %d",&x,&y);
			x--,y--;
			bad[x][y] = true;
		}
		int base,back1,back2,back3;
		base = 0;
		for(int i = 1; i < N; i++)
			for(int j = 0; j < M; j++) {
				base = (base + 1) % 4;
				back1 = (base + 3) % 4;
				back2 = (base + 2) % 4;
				back3 = (base + 1) % 4;
				for(int s = 0; s < pow3[M]; s++)
					f[base][s] = 0;
				memset(d,0,sizeof d);
				bool lie,stand;
				lie = (i>=2) && (j>=1) &&
					not (bad[i][j] or bad[i-1][j] or bad[i-2][j] or
						bad[i][j-1] or bad[i-1][j-1] or bad[i-2][j-1]);
				stand = (i>=1) && (j>=2) &&
					not (bad[i][j] or bad[i-1][j] or
						bad[i][j-1] or bad[i-1][j-1] or
						bad[i][j-2] or bad[i-1][j-2]);
				for(int s = 0; s < pow3[M]; s++) {
					if(d[j]) f[base][s] = f[back1][s-pow3[j]];
					else {
						f[base][s] = f[back1][s];
						if(lie && (d[j-1]==0))
							f[base][s] = max(f[base][s], f[back2][s+8*pow3[j-1]] + 1);
						if(stand && (d[j-1]==0) && (d[j-2]==0))
							f[base][s] = max(f[base][s], f[back3][s+13*pow3[j-2]] + 1);
					}
					int k = 0;
					while(d[k]==2) d[k++] = 0;
					d[k]++;
				}
			}
		printf("%lld\n",f[base][0]);
	}
	return 0;
}
