#include<stdio.h>
int d=0;
bool kt[10005][10005]={false};
int a[10005][10005];
void function(int x,int y)
{
    if (kt[x][y]==true) return;
    if (a[x][y]==0) return;
    kt[x][y]=true;
    function(x+1,y+1);
    function(x,y+1);
    function(x+1,y);
    function(x+1,y-1);
    function(x-1,y+1);
    function(x-1,y);
}
int main()
{
    int r,c;
    freopen("badgras.inp","r",stdin);
    freopen("badgras.out","w",stdout);
    scanf("%d%d",&r,&c);
    for (int i=1;i<=r;i++)
        for (int j=1;j<=c;j++) scanf("%d",&a[i][j]);
    for (int i=1;i<=r+1;i++) a[i][c+1]=0;
    for (int i=1;i<=c+1;i++) a[r+1][i]=0;
    for (int i=1;i<=r;i++)
        for (int j=1;j<=c;j++)
        if ((a[i][j]>0) and (kt[i][j]==false)) {
            d++;
            function(i,j);
        }
    printf("%d\n",d);
}
