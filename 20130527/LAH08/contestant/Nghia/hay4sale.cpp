#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;
int h[5005];
int sum[50002];
int ss[50002];
main()
{
    freopen("hay4sale.inp","r",stdin);
    freopen("hay4sale.out","w",stdout);
    int C,H;
    scanf("%d %d",&C,&H);
    for(int i=1;i<=H;i++)
    {
        scanf("%d",&h[i]);
    }
    sort(h+1,h+1+H);
    int ns=0;
    for(int i=1;i<=H;i++)
    {
        ns++;
        for(int j=1;j<=ns;j++)
        {
            sum[j]+=h[i];
            ss[sum[j]]=1;
        }
    }
    while(C>0)
    {
        if(ss[C]==1)
        {
            printf("%d",C);
            break;
        }
        C--;
    }
}
