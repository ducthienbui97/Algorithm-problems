#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
long long a[100005];
long long dd[1000005];
long long dem[1000005];
long long max1=-1;
main()
{
    freopen("patheads.inp","r",stdin);
    freopen("patheads.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=1000000;i++)dd[i]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        dd[a[i]]++;
        max1=max(max1,a[i]);
    }
    int tam,tam1;
    for(int i=1;i<=n;i++)
    {
        for(int j=a[i];j<1000000;j+=a[i])
        {
            if(j<=max1)
            {
                if(dd[j]>0 && a[i]!=j)
                {
                    dem[j]++;
                }
                else if(dd[j]>0 && a[i]==j)
                {
                    dem[j]++;
                }
            }
            else break;
        }
    }
    for(int i=1;i<=n;i++)
    {
        printf("%lld\n",dem[a[i]]-1);
    }
}
