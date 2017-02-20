#include<cstdio>
using namespace std;
int a[110000];
int b[1001000];
int main()
{
    freopen("patheads.inp","r",stdin);
    freopen("patheads.out","w",stdout);
    int n,i,j,k,m,t;
    scanf("%d",&n);
    m=0;t=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (m<a[i]) m=a[i];
        if (a[i]==1) t+=1;
        }
    for(i=1;i<=n;i++)
    {
        if (a[i]!=1)
        {
            k=a[i];
            for(j=1;k<=m;j++)
            {
                b[k]+=1;
                k=k+a[i];
            }
        }
    }
    for(i=1;i<=n;i++)
    if (a[i]!=1) printf("%d\n",b[a[i]]-1+t);
    else printf("%d\n",t-1);


}
