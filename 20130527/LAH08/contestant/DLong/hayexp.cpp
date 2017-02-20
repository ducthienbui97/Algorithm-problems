#include <cstdio>
#include <iostream>
using namespace std;

int main()
{
    freopen("hayexp.inp","r",stdin);
    freopen("hayexp.out","w",stdout);
    int n,q,a[1001],i,ans;
    scanf("%d%d",&n,&q);
    for(i=1;i<=n;i++) cin>>a[i];
    for(i=1;i<=q;i++)
    {
        ans=0;
        int s,f,j;
        scanf("%d%d",&s,&f);
        for(j=s;j<=f;j++) ans+=a[j];
        printf("%d\n",ans);
    }
}
