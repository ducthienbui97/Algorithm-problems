#include<cstdio>
#include<cstring>

const int N = 500+7;
int arrive[N], leave[N][N], t[N][N], f[N][N], n, k;

void enter() {
	scanf("%d%d",&n,&k);
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j) {
			scanf("%d", &leave[i][j]);
			arrive[j] += leave[i][j];
			leave[i][j] += leave[i][j-1];
		}
}

int put[N];
void trace() {
	printf("%d\n", f[n][k]);
	int p = n;
	for(int i = k; i >= 1; --i) {
		put[i] = t[p][i];
		p = t[p][i];
	}
	for(int i = 1; i <= k; ++i) {
		if(i != 1) printf(" ");
		printf("%d", put[i]);
	}
	printf("\n");
}

void dp() {
	memset(f, 0x80, sizeof f);
	for(int c = 1; c <= n; ++c) {
		f[c][0] = 0;
		for(int r = 1; r <= k; ++r) {
			int add = arrive[c];
			for(int p = c-1; p >= 1; --p) {
				if(f[p][r-1] + add > f[c][r]) {
					f[c][r] = f[p][r-1] + add;
					t[c][r] = p;
				}
				add += arrive[p] - leave[p][c];
			}
		}
	}
}

int main() {
	enter();
	dp();
	trace();
	return 0;
}
