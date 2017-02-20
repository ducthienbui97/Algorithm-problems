#include<cstdio>

int a[10000], n;

void check(int x, int y) {
	int res = 0, oriY = y;
	while(y != 0) {
		if(a[y] == x) { printf("Yes %d\n", res); return; }
		else ++res, y = a[y];
		if(y == oriY) break;
	}
	printf("No\n");
}

int main() {
	freopen("1.inp", "r", stdin);
	freopen("1.out", "w", stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		int x, y; scanf("%d%d",&x,&y);
		a[y] = x;
	}
	for(int x, y; scanf("%d%d",&x,&y) == 2 && (x | y); ) check(x, y);
	return 0;
}
