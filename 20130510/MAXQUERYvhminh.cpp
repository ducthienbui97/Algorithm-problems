#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX 100000
#define re(i, a, b) for(int i=a; i<=b; i++)
using namespace std;
int a[MAX], RMQ[MAX][20], n, k;

int main()
{
	scanf ("%d%d", &n, &k);
	re (i,1,n){
		scanf ("%d", &a[i]);
		RMQ[i][0]=a[i];
	}
	for(int j=1; 1<<j<n; j++)
		re (i, 1, n-(1<<j)+1)
			RMQ[i][j]=max(RMQ[i][j-1], RMQ[i+(1<<(j-1))][j-1]);
	int u,v;
	re (i, 1, k){
		scanf("%d%d", &u, &v);
		int tm1=log(v-u-1)/log(2);
		printf ("%d\n", max(RMQ[u][tm1],RMQ[v-(1<<tm1)+1][tm1]));
	}
}
