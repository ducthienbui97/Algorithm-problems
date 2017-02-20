#include <cstdio>

int sum[600];
main()
{
    freopen("hayexp.inp","r",stdin);
    freopen("hayexp.out","w",stdout);
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        sum[i]=sum[i-1]+x;
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        printf("%d\n",sum[y]-sum[x-1]);
    }
}
