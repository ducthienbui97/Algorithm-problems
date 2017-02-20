#include <cstdio>
#include <algorithm>

using namespace std;
int a[30005],f[30005][505];
main()
{
      freopen("3.inp","r",stdin);
      freopen("3.out","w",stdout);
      int test,x;
      scanf("%d",&test);
      for(int i=1;i<=test;i++)
      {
            int n,k,w;
            a[0]=0;
            scanf("%d %d %d",&n,&k,&w);
            for(int i=1;i<=n;i++)
            {
                  scanf("%d",&x);  
                  a[i]=a[i-1]+x;
                  for(int j=1;j<=k;j++)
                  f[i][j]=0;
            }  
      a[0]=0;
      for(int i=1;i<=n;i++)
      for(int j=1;j<=k;j++)
      {
              if(i>=w) f[i][j]=max(f[i-1][j],f[i-w][j-1]+a[i]-a[i-w]);
              else f[i][j]=a[i]-a[0];
      }
      printf("%d\n",f[n][k]);
      }

}
