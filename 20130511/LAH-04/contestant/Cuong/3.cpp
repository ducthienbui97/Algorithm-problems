#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <cmath>
using namespace std;
int a[500000];
int f[50000][1000];
int main()
{
    freopen("3.inp","r",stdin);
    freopen("3.out","w",stdout);
    int t,n,k,w,x;
    scanf("%d",&t);
    while(t>0)
    {
        t--;
        scanf("%d%d%d",&n,&k,&w);
        for(int i=0;i<=n;i++)a[i]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&x);
            a[i]=a[i-1]+x;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)f[i][j]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(i>=w)f[i][j]=max(f[i-1][j],f[i-w][j-1]+a[i]-a[i-w]);
                else f[i][j]=a[i];
            }
        }
        printf("%d\n",f[n][k]);
    }
}
