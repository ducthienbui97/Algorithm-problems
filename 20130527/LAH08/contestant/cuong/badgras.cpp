#include <cstdio>
int X[10005][10005];
int dd[10005][10005];
int m,n,dem=0;
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
void loang(int x,int y)
{
    dd[x][y]=1;
    for(int i=0;i<8;i++)
    {
        int x_=x+dx[i];
        int y_=y+dy[i];
        if(dd[x_][y_]==0 && x_>=1 && x_<=m
           && y_>=1 && y_<=n && X[x_][y_]>0)
        {
            dd[x_][y_]=1;
            loang(x_,y_);
        }
    }
}
int main()
{
    freopen("badgras.inp","r",stdin);
    freopen("badgras.out","w",stdout);
    scanf("%d%d",&m,&n);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&X[i][j]);
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(dd[i][j]==0 && X[i][j]>0)
            {
                dem++;
                loang(i,j);
            }
        }
    }
    printf("%d\n",dem);
}
