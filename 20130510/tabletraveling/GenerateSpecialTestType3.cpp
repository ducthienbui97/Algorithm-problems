#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[5007][5007];

int main() {
	int m = 1000, n = 1000;
	int p = 1;
	for(int i = 0; i < m; ++i) a[i][0] = p++;
	for(int j = 1; j < n; ++j) a[m-1][j] = p++;
	for(int i = 0; i < m-1; ++i)
		for(int j = 1; j < n; ++j)
			a[i][j] = p++;
	for(int swp = 0; swp < 3*m*n; ++swp) {
		int r1 = rand() % (m-1), r2 = rand() % (m-1), c1 = rand() % (n-1) + 1, c2 = rand() % (n-1) + 1;
		swap(a[r1][c1], a[r2][c2]);
	}
	printf("%d %d\n", m, n);
	for(int i = 0; i < m; ++i) {
		for(int j = 0; j < n; ++j) {
			if(j) printf(" ");
			printf("%d", a[i][j]);
		}
		printf("\n");
	}
}
