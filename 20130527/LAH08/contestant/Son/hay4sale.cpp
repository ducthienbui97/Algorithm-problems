#include<cstdio>
using namespace std;
int a[5100];
bool f(int i,int s)
{
    if (s==0) return true;
    if (s<0) return 0;
    if (i==0) return false;
    if (f(i-1,s)==true) return true;
    if (f(i-1,s-a[i])==true) return true;
    return false;

}


int main()
{
    freopen("hay4sale.inp","r",stdin);
    freopen("hay4sale.out","w",stdout);
    int n,s,i;
    scanf("%d%d",&s,&n);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);

    for(i=s;i>=1;i--)
    if ( f(n,i)==true ) {printf("%d\n",i);break;}
}
