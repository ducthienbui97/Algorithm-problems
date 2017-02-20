#include<cstdio>

const int N = 30000 + 5;
int a[N], stack[N], top, n, left[N], right[N];

void enter() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
}

void initLeft() {
	left[0] = 0; top = 0;
	for(int i = 1; i < n; ++i) 
		if(a[i] <= a[i-1]) left[i] = i, stack[top++] = i - 1;
		else {
			while(top != 0 && a[i] > a[stack[top-1]]) --top;
			left[i] = top != 0 ? stack[top-1] + 1 : 0;
		}
}

void initRight() {
	right[n-1] = n-1; top = 0;
	for(int i = n-2; i >= 0; --i)
		if(a[i] >= a[i+1]) right[i] = i, stack[top++] = i + 1;
		else {
			while(top != 0 && a[i] < a[stack[top-1]]) --top;
			right[i] = top != 0 ? stack[top-1] - 1 : n-1;
		}
}

void solve() {
	int p = -1, l = 0;
	for(int i = 0; i < n; ++i)
		if(left[i] < i && i < right[i] && right[i] - left[i] + 1 > l) {
			l = right[i] - left[i] + 1;
			p = i;
		}
	if(p == -1) printf("-1\n");
	else printf("%d %d\n", p+1, l);
}

int main() {
	enter();
	initLeft();
	initRight();
	solve();
	return 0;
}
