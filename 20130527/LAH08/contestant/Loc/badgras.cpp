#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int n,m,sum=0;
int G[1000][1000];

int lolo(int a,int b)
{
    G[a][b]=0;
    if(G[a][b+1]>0&&a<=n&&b<=m) lolo(a,b+1);
    if(G[a][b-1]>0&&a<=n&&b<=m) lolo(a,b-1);
    if(G[a-1][b]>0&&a<=n&&b<=m) lolo(a-1,b);
    if(G[a-1][b+1]>0&&a<=n&&b<=m) lolo(a-1,b+1);
    if(G[a-1][b-1]>0&&a<=n&&b<=m) lolo(a-1,b-1);
    if(G[a+1][b]>0&&a<=n&&b<=m) lolo(a+1,b);
    if(G[a+1][b+1]>0&&a<=n&&b<=m) lolo(a+1,b+1);
    if(G[a+1][b-1]>0&&a<=n&&b<=m) lolo(a+1,b-1);
}

int main()
{
    freopen("badgras.inp","r",stdin);
    freopen("badgras.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int ii=1;ii<=m;ii++)
        {
            cin>>G[i][ii];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int ii=1;ii<=m;ii++)
        {
            if(G[i][ii]>0)
            {
                lolo(i,ii);
                sum++;
            }
        }
    }
    cout<<sum<<endl;
    return 0;
}
