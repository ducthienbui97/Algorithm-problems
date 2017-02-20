#include<stdio.h>
int main()
{
    freopen("hayexp.inp","r",stdin);
    freopen("hayexp.out","w",stdout);
    int a[550],b[550]={0},x,y,n,q;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=b[i-1]+a[i];
    }
    for (int i=1;i<=q;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",b[y]-b[x]+a[x]);
    }
}
