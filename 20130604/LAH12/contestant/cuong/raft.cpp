#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <complex>
#define X real()
#define Y imag()
using namespace std;
const double eps=1e-9;
typedef complex<double> point;
int main()
{
	freopen("raft.inp","r",stdin);
	freopen("raft.out","w",stdout);
	int n,m,k;
	point A[1000],B[1000];
	point C[1000];
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf%lf",&A[i].X,&A[i].Y);		
	}
	scanf("%d",&m);
	double min1=1000000000000.000;
	for(int i=1;i<=m;i++)
	{
		scanf("%lf%lf",&B[i].X,&B[i].Y);		
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			point u=A[i]-B[j];
			if(j-1==0)
				{
					k=m;
				}
			else k=j-1;
			if((conj(B[j]-B[k])*u).real()<0)
			{
				min1=min(min1,abs(B[j]-B[k]));
			}
			else min1=min1=min(min1,abs(B[j]-A[i]));
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			point u=B[i]-A[j];
			if(j-1==0)
				{
					k=n;
				}
			else k=j-1;
			if((conj(A[j]-A[k])*u).real()<0)
			{
				min1=min(min1,abs(A[j]-A[k]));
			}
			else min1=min1=min(min1,abs(A[j]-B[i]));
		}
	}
	printf("%lf\n",min1);
}
