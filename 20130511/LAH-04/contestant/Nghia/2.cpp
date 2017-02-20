#include <stdio.h>

int m[10001],xh[10001],d[10001];
int ne[10001][10001];

int form (int k)
{
    if(m[k]==-1) 
    {
                 if(k==1) m[k]=1;
                 else{
                 m[k]=0;
                 for(int i=1;i<d[k];i++)  m[k]+=form(ne[k][i]);
                 }
    }
    return m[k];
}
main()
{
      freopen("2.inp","r",stdin);
      freopen("2.out","w",stdout);
      int n,x,y;
      scanf("%d",&n);
      for(int i=1;i<=n;i++) m[i]=-1;
      while(scanf("%d %d",&x,&y)==2)
      {
                       if(x==0&&y==0) break;
                       if(xh[y]!=1) {d[y]=1;xh[y]=1;}
                       ne[y][d[y]]=x;d[y]++;
      }
      printf("%d",form(n)); 
}
