#include<stdio.h>
int n,k,w;
int max(int a,int b)
{
    if (a>b) return a;else return b;
}
int F[600][31000];
int a[31000];
int f(int i,int j) 
{
    int l;
    int s=0;
    
    if (j<=0) return 0;
    if (i==0) return 0;
    if (i>0 and j>0) if (F[i][j]!=0) return F[i][j];
    if (j<w) return F[i][j]=f(i,j-1)+a[j];
    for(l=1;l<=w;l++)
    s=s+a[j-l+1];
    return F[i][j]=max(f(i,j-1),f(i-1,j-w)+s);
}
void refresh()
{
    for(int i=0;i<=550;i++)
    for(int j=0;j<=30100;j++)
    F[i][j]=0;
}
int main()
{
    freopen("3.inp","r",stdin);
    freopen("3.out","w",stdout);
    int i,t,s;
    scanf("%d",&t);
    for(int j=1;j<=t;j++)
    {
    refresh();
    s=0;
    scanf("%d%d%d",&n,&k,&w);
    for(i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        s=s+a[i];
    }
    if (k*w>=n) printf("%d",s);
    else
    printf("%d\n",f(k,n));
    }
}    
