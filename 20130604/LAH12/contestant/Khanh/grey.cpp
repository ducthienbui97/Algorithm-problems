#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 20;
char res[1 << N][N+1];
int n;

int main() {
	freopen("grey.inp", "r", stdin);
	freopen("grey.out", "w", stdout);
	scanf("%d", &n);
	for(int p = n-1; p >= 0; --p) {
		int rep = 1 << (n-1-p), rol = 1 << p, pos = 0;
		char one = '1', zero = '0';
		for(int i = 0; i < rol; ++i) {
			for(int j = 0; j < rep; ++j) res[pos++][p] = zero;
			for(int j = 0; j < rep; ++j) res[pos++][p] = one;
			swap(one, zero);
		}
	}
	for(int i = (1 << n) - 1; i >= 0; --i)
		puts(res[i]);
	return 0;
}
