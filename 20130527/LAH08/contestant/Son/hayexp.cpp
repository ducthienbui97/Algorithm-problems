#include<cstdio>
using namespace std;
int s[1100];
int main()
{
    freopen("hayexp.inp","r",stdin);
    freopen("hayexp.out","w",stdout);
    int a[1100];
    int n,u,v,i,j,q;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];
    for(j=1;j<=q;j++)
    {
    scanf("%d%d",&u,&v);
    printf("%d\n",s[v]-s[u-1]);
    }
}
