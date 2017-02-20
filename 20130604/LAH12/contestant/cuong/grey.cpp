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
void in(int x)
{
	int i=0;
	for(int i=0;i<n;i++)A[i]=0;
	while(x>0)
	{
		A[i]=x%2;
		x=x/2;
		i++;
	}
	for(int j=n-1;j>=0;j--)
	{
		printf("%d",A[j]);
	}
	printf("\n");
}

int main()
{
	freopen("grey.inp","r",stdin);
	freopen("grey.out","w",stdout);
	long long a,b;
	scanf("%d",&n);
	for(long long a=0;a<(1ll<<n);a++)
	{
		b=(a>>1)^a;
		in(b);
	}
}
