#include<cstdio>

const int N = 1025;

int bit[N][N], s;

void update(int x, int y, int v) {
	for(int i=x; i<=s; i+=i&-i)
		for(int j=y; j<=s; j+=j&-j)
			bit[i][j] += v;
}

int sum(int x, int y) {
	int res = 0;
	for(int i=x; i>0; i-=i&-i)
		for(int j=y; j>0; j-=j&-j)
			res += bit[i][j];
	return res;
}

int main() {
	freopen( "mobiles.inp", "r", stdin );
	freopen( "mobiles.out", "w", stdout );
	scanf("%*d%d",&s);
	int control;
	while(scanf("%d",&control) && control != 3) 
		if(control == 1) {
			int x, y, a; scanf("%d%d%d",&x,&y,&a);
			update(++x, ++y, a);
		} else {
			int l, b, r, t; scanf("%d%d%d%d",&l,&b,&r,&t);
			++l; ++b; ++r; ++t;
			printf("%d\n",sum(r,t)-sum(r,b-1)-sum(l-1,t)+sum(l-1,b-1));
		}
	return 0;
}
