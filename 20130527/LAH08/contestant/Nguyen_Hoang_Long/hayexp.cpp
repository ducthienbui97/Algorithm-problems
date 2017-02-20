#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("hayexp.inp","r",stdin);
    freopen("hayexp.out","w",stdout);
    int S[505],n,q;
    S[0]=0;
    int tmp1,tmp2;
    scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&tmp1);
        S[i]=S[i-1]+tmp1;
    }
    for (int i=0;i<q;i++)
    {
        scanf("%d%d",&tmp1,&tmp2);
        printf("%d\n",S[tmp2]-S[tmp1-1]);
    }
}
