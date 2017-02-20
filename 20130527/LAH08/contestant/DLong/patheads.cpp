#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    freopen("patheads.inp","r",stdin);
    freopen("patheads.out","w",stdout);
    int n,i,j,a[100010];
    int ans[100010];
    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&a[i]);
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if(a[i]%a[j]==0) ans[i]++;
            if(a[j]%a[i]==0) ans[j]++;
        }
    }
    for(i=1;i<=n;i++) printf("%d\n",ans[i]);
}
