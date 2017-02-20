#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <utility>
#include <climits>
#include <vector>
#include <cstring>
#include <deque>
#include <queue>
#include <algorithm>
#include <map>
#define elif else if
using namespace std;
typedef pair<int,int> pii;

	int a[2222];
	int sum[2222][2222];
	int s[2222];
	int f[2222][2222];
	int n,m;
int findmax(int x[],int l,int r,int t)
	{
	if(l<r){
	if(r-l==1)
		{
		if(x[l]==t) return l;
		if(x[r]<=t) return r;
		else return l;
		}
	int k=(l+r)/2;
	if(x[k]<=t) return findmax(x,k,r,t);
	else return findmax(x,l,k,t);}
	}

int findmin(int x[],int l,int r,int t)
	{
	if(l<r){
	if(r-l==1)
		{
		if(x[l]>=t) return l;
		else return r;
		}
	int k=(l+r)/2;
	if(x[k]>=t) return findmin(x,l,k,t);
	else return findmin(x,k,r,t);}
	}
main()
{
	int c=5;
	int k;
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	s[0]=0;
	memset(f,0x5f,sizeof f);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(s[i]>m) break;
		f[1][i]=0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=i;j++)
			sum[j][i]=s[i]-s[j-1]+i-j;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++){
		k=findmin(sum[j+1],1,n,sum[i][j]);
		for(int l=k-5;l<k+5;l++)
		{
		if(sum[j+1][l]<=m||sum[j+1][l]>0||l>n)
		f[j+1][l]=min(f[j+1][l],f[i][j]+abs(sum[j+1][l]-sum[i][j]));
		}
		k=findmax(sum[j+1],1,n,sum[i][j]);
		for(int l=k-5;l<k+5;l++)
		{
		if(sum[j+1][l]<=m||sum[j+1][l]>0||l>n)
		f[j+1][l]=min(f[j+1][l],f[i][j]+abs(sum[j+1][l]-sum[i][j]));
		}
	}
k=INT_MAX;
for(int i=1;i<=n;i++){
if(sum[i][n]<=m) k=min(k,f[i][n]);}
printf("%d",k);
}
