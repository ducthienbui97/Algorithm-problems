#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <stack>
using namespace std;
int A[100];
int n;
double S,H,V,a,b,H1,res;
int main()
{
	freopen("barrel.inp","r",stdin);
	freopen("barrel.out","w",stdout);
	scanf("%lf%lf%lf",&S,&H,&V);
	scanf("%d",&n);
	res=S*H;
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&a,&b);
		if(b<1)
		{
			V+=a*a*a*b;
			if(V>res)V=res;
			printf("%.7lf\n",V/S);
		}
	}
}
