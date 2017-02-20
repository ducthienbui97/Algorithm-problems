#include <stdio.h>
#include <vector>

using namespace std;
long x, y;
vector<vector<long> > a(10005);

main(){
	freopen("2.inp","r",stdin);
	freopen("2.out","w",stdout);
	long n, i, f[10005], j;
	scanf("%ld", &n);
	for(;;){
		scanf("%ld %ld", &x, &y);
		if(x==0 && y==0) break;
		a[y].push_back(x);
	}
	f[1]= 1;
	for(i=2;i<=n;i++){
		f[i]= 0;
		for(j=0;j<a[i].size();j++) f[i]+= f[a[i][j]];
	}
	printf("%ld\n", f[n]);
}
