#include <cstdio>
int s[505];
int main()
{
    freopen("hayexp.inp","r",stdin);
    freopen("hayexp.out","w",stdout);
    int n,q,x,y;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&x);
        s[i]=s[i-1]+x;
    }
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&x,&y);
        printf("%d\n",s[y]-s[x-1]);
    }
}
