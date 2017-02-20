#include <stdio.h>
#include <algorithm>
#include <string.h>

using namespace std;

long re[30005][505], w, n, a[30005], sum[30005];
bool sign[30005][505];

long f(long i, long j){
	if(sign[i][j]==true) return re[i][j];
	if(j==0) return 0;
	if(i==n+1) return 0;
	if(n-i+1==j*w) return sum[n]-sum[i-1];
	if(n-i+1<j*w) return 0;
	re[i][j]= max(f(i+1,j), f(i+w,j-1)+ sum[i+w-1]- sum[i-1]);
	sign[i][j]= true;
	return re[i][j];
}


main(){
	freopen("3.inp","r",stdin);
	freopen("3.out","w",stdout);
	long test, i, k, j;
	scanf("%ld", &test);
	for(;test>=1;test--){
		sum[0]= 0;
		scanf("%ld %ld %ld", &n, &k, &w);
		for(i=1;i<=n+1;i++) for(j=0;j<=k;j++) sign[i][j]= false;
		for(i=1;i<=n;i++) {scanf("%ld", &a[i]); sum[i]= sum[i-1] + a[i];}
		if(k*w>=n) printf("%ld\n", sum[n]);
		else printf("%ld\n", f(1,k));
	}
}
