#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int x[5005];
int c,h;
int dp(int h,int c)
{
    if(h==0 || c<=0) return 0;
    if(c<x[h])return dp(h-1,c);
    else return max(dp(h-1,c-x[h])+x[h],dp(h-1,c));
}
int main()
{
    freopen("hay4sale.inp","r",stdin);
    freopen("hay4sale.out","w",stdout);
    scanf("%d%d",&c,&h);
    for(int i=1;i<=h;i++)
    {
        scanf("%d",&x[i]);
    }
    printf("%d\n",dp(h,c));
}
