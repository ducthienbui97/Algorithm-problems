#include <iostream>
#include <cstdio>

using namespace std;

int a[5005];
bool F[50005];

int main()
{
    freopen("hay4sale.inp","r",stdin);
    freopen("hay4sale.out","w",stdout);
    int n,kq,S;
    scanf("%d%d",&S,&n);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for (int i=0;i<=S;i++) F[i]=false;
    F[0]=true;
    for (int i=1;i<=n;i++)
    {
        for (int j=S;j>=a[i];j--)
        {
            if ((F[j-a[i]])&&(!F[j]))  F[j]=true;
        }
    }
            kq=S;
            while (!F[kq]) kq--;
    printf("%d",kq);

}
