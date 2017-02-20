#include<cstdio>

const int C = 50000 + 7;
int list[C];
bool inlist[C];

int main() {
	freopen("hay4sale.inp", "r", stdin);
	freopen("hay4sale.out", "w", stdout);
	int c, h, cnt = 1;
	scanf("%d%d",&c,&h);
	list[0] = 0; inlist[0] = true;
	for(int i = 0; i < h; ++i) {
		int v; scanf("%d", &v);
		for(int i = cnt - 1; i >= 0; --i)
			if(list[i] + v <= c && !inlist[list[i] + v]) {
				list[cnt++] = list[i] + v;
				inlist[list[i] + v] = true;
			}
	}
	while(!inlist[c]) --c;
	printf("%d\n", c);
	return 0;
}
