#include<stdio.h>
#include<vector>
using namespace std;
vector <int > a[11000];
int n;
int f(int i)
{
    int s,j,u,k;
    if (i==n) return 1;
    s=0;
    k=a[i].size();
    if (k==0) return 0;
    for(j=0;j<=k-1;j++)
    {
        u=a[i][j];
        s=s+f(u);
    }
    return s;
}
    
    
int main()
{
    freopen("2.inp","r",stdin);
    freopen("2.out","w",stdout);
    int x,y,i,j;
    scanf("%d",&n);
    while(scanf("%d%d",&x,&y)!=0)
    {
        if (x==0 and y==0) break;
        a[x].push_back(y);
    }
    printf("%d\n",f(1));
}
