#include <iostream>
#include <cstdio>

using namespace std;

int a[1000][1000],r,c,dd[1000][1000];
int xx[]={-1,-1,-1,0,0,1,1,1};
int yy[]={-1,0,1,-1,1,-1,0,1};

void dfs(int x,int y)
{
    dd[x][y]=1;
    for (int i=0;i<8;i++)
    {
        if ((dd[x+xx[i]][y+yy[i]]==0) && (a[x+xx[i]][y+yy[i]]!=0))
        {
            dfs(x+xx[i],y+yy[i]);
        }
    }
}

int main()
{
    freopen("badgras.inp","r",stdin);
    freopen("badgras.out","w",stdout);
    scanf("%d%d",&r,&c);
    for (int i=1;i<=r;i++)
    {
        for (int j=1;j<=c;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    int count=0;
    for (int i=1;i<=r;i++)
    {
        for (int j=1;j<=c;j++)
        {
            if ((a[i][j]!=0)&&(dd[i][j]==0))
            {
                count++;
                dfs(i,j);
            }
        }
    }
    printf("%d\n",count);

}
