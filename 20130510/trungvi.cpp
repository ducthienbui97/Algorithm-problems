#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 200 + 5, L = 20000 + 5;
int a[N][L], n, l;

void enter() {
	scanf("%d%d",&n,&l);
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < l; ++j)
			scanf("%d", &a[i][j]);
}

int median(const int * a, const int * b, const int &n) {
	int l = 0, r = n-1, ans = -1;
	bool stop = false;
	while(l <= r) {
		int mid = (l+r)/2;
		int tmax = mid + (upper_bound(b, b+n, a[mid]) - b);
		int tmin = mid + (lower_bound(b, b+n, a[mid]) - b);
		if(tmax >= n-1) {
			r = mid;
			if(tmin <= n-1) ans = mid;
		} else l = mid+1;
		if(l == r) {
			if(stop) break;
			stop = true;
		}
	}
	return ans == -1 ? median(b, a, n) : a[ans];
}

void solve() {
	int res = 0;
	for(int i = 0; i < n; ++i) sort(a[i], a[i]+l);
	for(int i = 0; i < n; ++i)
		for(int j = i+1; j < n; ++j)
			res += median(a[i], a[j], l);
	printf("%d\n", res);
}

int main() {
	enter();
	solve();
	return 0;
}
