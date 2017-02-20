#include <stdio.h>
#include <iostream>

using namespace std;

int C,H;
int G[5005];

int lolo(int x)
{
    if(x<=H)
    {
        int a=G[x]+lolo(x+1);
        int b=lolo(x+1);
        if(a<=C&&b<=C) return max(a,b);
        else if(a<=C&&b>C) return a;
        else if(a>C&&b<=C) return b;
    }
    else return 0;
}

int main()
{
    freopen("hay4sale.inp","r",stdin);
    freopen("hay4sale.out","w",stdout);
    cin>>C>>H;
    for(int i=1;i<=H;i++) cin>>G[i];
    cout<<lolo(1)<<endl;
    return 0;
}
