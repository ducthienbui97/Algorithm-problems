#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;
long long sum[200000];
long long n,s,x;
long long l,r,mid;
long long chat(long long x)
{
	l=x;
	r=n;
	while(l<=r)
	{
		mid=(l+r)/2;
		if(sum[mid]-sum[x]<s)l=mid+1;
		else if(sum[mid]-sum[x]>s)r=mid-1;
		else break;
	}
	if(sum[mid]-sum[x]>s)
	{
		while(sum[mid]-sum[x]>s)
		{
			mid--;
		}
	}
	return mid;
}

main()
{
	scanf("%lld%lld",&n,&s);
	s=s*2;
	sum[0]=0;
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&x);
		sum[i]=sum[i-1]+x;
	}
	for(long long i=1;i<=n;i++)
	{
		long long t=chat(i-1);
		if(t<i)printf("0\n");
		else if((t-i+1)%2==0)printf("%lld\n",t-i+1);
		else printf("%lld\n",t-i);
	}
}
