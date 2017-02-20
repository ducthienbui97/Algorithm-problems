#include <cstdio>
#include <algorithm>
using namespace std;
	int n;
void solve(int i)
{
	int a[30],ia=0;
	for(int j=1;j<=n;j++) a[j]=0;
	do
	{
		ia++;
		a[ia]=i%2;
		i/=2;
	}while(i>0);
	for(int j=n;j>=1;j--) printf("%d",a[j]);
	printf("\n");
}
main()
{
	freopen("grey.inp","r",stdin);
	freopen("grey.out","w",stdout);
	scanf("%d",&n);
	int g, b;
	for(b=0; b<(1<<n); b++)
	{
    	g = b ^ (b >> 1);
    	solve(g);
	}
}
