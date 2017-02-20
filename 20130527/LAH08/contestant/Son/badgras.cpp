#include<stdio.h>
#include<vector>
using namespace std;
typedef vector <int> viv;
vector <int > vi;
vector <viv> v;
int n,m;
void f(int i,int j)
{
if (v[i][j]!=0)
    {
    v[i][j]=0;
    if (i!=n-1) f(i+1,j);
    if (i!=0) f(i-1,j);
    if (j!=m-1) f(i,j+1);
    if (j!=0) f(i,j-1);
    if (i!=n-1 and j!=m-1) f(i+1,j+1);
    if (i!=0 and j!=0)f(i-1,j-1);
    if (i!=0 and j!=m-1) f(i-1,j+1);
    if (i!= n-1 and j!=0) f(i+1,j-1);
    }
}

int main()
{
    freopen("badgras.inp","r",stdin);
    freopen("badgras.out","w",stdout);
int i,j,x;
scanf("%d%d",&n,&m);
for(i=0;i<=n-1;i++)
{
vi.clear();
for(j=0;j<=m-1;j++)
{
    scanf("%d",&x);
    vi.push_back(x);
}
v.push_back(vi);
}
int s=0;
for(i=0;i<=n-1;i++)
for(j=0;j<=m-1;j++)
{
    x=v[i][j];
    if (x!=0)
    {
        s=s+1;
        f(i,j);
    }
}
printf("%d",s);
}
