#include<cstdio>
#include<map>
#include<vector>
using namespace std;

const int N = 3000;
map<int, vector<int> > mp;
int n, a[N], f[N][N], t[N][N], res[N];

void enter() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) scanf("%d", &a[i]);
}

void dp() {
	for(int i = 0; i < n; ++i) mp[a[i]].push_back(i);
	for(int u = 0; u < n; ++u) {
		f[u][u] = 1; t[u][u] = -1;
		for(int v = u+1; v < n; ++v) {
			f[u][v] = 2; t[u][v] = u;
			int val = a[v] - a[u];
			if(mp.count(val)) {
				vector<int> &vec = mp[val];
				vector<int>::iterator k = lower_bound(vec.begin(), vec.end(), u);
				if(k != vec.begin()) {
					--k; t[u][v] = *k;
					f[u][v] = max(f[u][v], f[*k][u] + 1);
				}
			}
		}
	}
}

void trace() {
	int x = 0, y = 0;
	for(int u = 0; u < n; ++u)
		for(int v = u+1; v < n; ++v)
			if(f[u][v] > f[x][y]) x = u, y = v;
	printf("%d\n", f[x][y]); int r = f[x][y];
	int *pnt = res + f[x][y] - 1;
	do {
		*pnt = a[y]; --pnt;
		int tmp = t[x][y]; y = x; x = tmp;
	} while(x != -1);
	for(int i = 0; i < r; ++i) {
		if(i) printf(" ");
		printf("%d", res[i]);
	}
}

int main() {
	enter();
	dp();
	trace();
	return 0;
}
