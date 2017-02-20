#include <cstdio>
using namespace std;
int r,c;
int grass[6010][6010];
bool checked[6010][6010];
void process(int i, int j)
{
    if(checked[i][j]==true) return;
    if(grass[i][j]==0) return;
    checked[i][j]=true;
    process(i+1,j+1);
    process(i-1,j+1);
    process(i+1,j-1);
    process(i-1,j-1);
    process(i+1,j);
    process(i,j+1);
    process(i-1,j);
    process(i,j-1);
}

int main()
{
    freopen("badgras.inp","r",stdin);
    freopen("badgras.out","w",stdout);
    int ans=0;
    int i,j;
    scanf("%d%d",&r,&c);
    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++) scanf("%d",&grass[i][j]);
    }

    for(i=1;i<=r;i++)
    {
        for(j=1;j<=c;j++)
        {
            if(checked[i][j]==false&&grass[i][j]!=0)
            {
                ans++;
                process(i,j);
            }
        }
    }
    printf("%d",ans);
}
