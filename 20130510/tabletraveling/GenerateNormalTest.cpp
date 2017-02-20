#include<cstdio>
#include<ctime>
#include<cstdlib>
#include<algorithm>
using namespace std;

int a[5007][5007];

int main() {
	srand(time(NULL));
	int m, n; scanf("%d%d",&m,&n);
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			a[i][j] = i * n + j + 1;
	for(int swp = 0; swp < 3*m*n; ++swp) {
		int r1 = rand() % m, r2 = rand() % m, c1 = rand() % n, c2 = rand() % n;
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
	return 0;
}
