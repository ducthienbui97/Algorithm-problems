#include<stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int a[5050];
long long abc(int x,int y)
{
    if ((x==0) || (y<=0)) return 0;
    if (y<a[x]) return abc(x-1,y);
    return max(abc(x-1,y-a[x])+a[x],abc(x-1,y));
}
int main()
{
    freopen("hay4sale.inp","r",stdin);
    freopen("hay4sale.out","w",stdout);
    int c,h;
    scanf("%d%d",&c,&h);
    for (int i=1;i<=h;i++) scanf("%d",&a[i]);
    printf("%lld",abc(h,c));
}
