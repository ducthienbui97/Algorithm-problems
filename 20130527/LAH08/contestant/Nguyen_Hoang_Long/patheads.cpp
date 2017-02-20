#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("patheads.inp","r",stdin);
    freopen("patheads.out","w",stdout);
    int n,a[100005],count;
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i=1;i<=n;i++)
    {
        count=0;
        int tmp=i+1;
        for (int j=0;j<n-1;j++)
        {
            if (tmp>n) tmp=1;
            if (a[i]%a[tmp]==0) count++;
            tmp++;
        }
        printf("%d\n",count);
    }
}
