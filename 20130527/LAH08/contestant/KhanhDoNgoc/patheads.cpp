#include<cstdio>
#include<algorithm>
using namespace std;

const int MAX = 1000000, N = 100000;
int n, a[N+1], oriA[N+1], counting[MAX+1];

void enter() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
}

void solve() {
	copy(a, a + n, oriA);
	sort(a, a + n);
	for(int i = 0, j = 0; j <= n; ++j)
		if(a[i] != a[j]) {
			for(int k = 0; k <= MAX; k += a[i])
				counting[k] += j - i;
			i = j;
		}
}

void print() {
	for(int i = 0; i < n; ++i)
		printf("%d\n", counting[oriA[i]] - 1);
}

int main() {
	freopen("patheads.inp", "r", stdin);
	freopen("patheads.out", "w", stdout);
	enter();
	solve();
	print();
	return 0;
}
