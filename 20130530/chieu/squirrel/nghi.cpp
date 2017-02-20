#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

long long unsigned MAX=10000000000000ll;

int n,m,k;
long long t[50010],p[50010];
long long a[50010];

bool check(long long mid){
	for(int i=0;i<m;i++) a[i]=(mid-t[i])/p[i]+1;
	sort(a,a+m);
	long long res=0;
	for(int i=m-1,j=0;j<n;i--,j++) res+=a[i];
	return res>=k;
}

int main()
{
	//freopen("a.inp","r",stdin);
	freopen("SQUIRREL.INP","r",stdin);
	freopen("SQUIRREL.OUT","w",stdout);
	cin >> m >> n >> k;
	n=min(n,m);
	for(int i=0;i<m;i++) cin >> t[i];
	for(int i=0;i<m;i++) cin >> p[i];
	long long l=0,r=MAX,mid;
	while(r-l>1){
		mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid;
	}
	cout << l;
 	return 0;
}

