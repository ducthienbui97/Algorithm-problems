#include <cstdio>


int p[10001];
main()
{
      freopen("1.inp","r",stdin);
      freopen("1.out","w",stdout);
      int n,a,b,maxxx=-1;
      scanf("%d",&n);
      for(int i=1;i<=10000;i++) p[i]=-1;
      for(int i=1;i<=n;i++)
      {
              int x,y;
              scanf("%d %d",&x,&y);
              p[y]=x;
      }
      while(scanf("%d %d",&a,&b)==2)
      {
           if(a==0&&b==0) break;
           int test=0;
           int x=b,sum=-1;
           if(a!=b)
           do
           {
                 x=p[x];
                 if(x==-1) {test=-1;break;}
                 if(test==0) sum++;
                 if(x==a) test=1;
                 //maxxx++;
                 //if(maxxx>10000) {test=-1;break;}
           }while(x!=b);
           if(test==1) printf("Yes %d",sum);
           else printf("No");
           printf("\n");
      }
}
      
