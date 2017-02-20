#include <cstdio>
#include <iostream>
using namespace std;

int BIT[1025][1025];

int n;
int t;
int a,b,c,d;

void update(int x, int y, int val)
{
    int y1;
    while(x<=n)
    {
        y1=y;
        while(y1<=n)
        {
            BIT[x][y1]+=val;
            y1+=(y1&(-y1));
        }
        x+=(x&(-x));
    }
}

int get(int x1, int y1, int x2, int y2)
{
    if(x2==0||y2==0) return 0;
    if(x1==1&&y1==1)
    {
        int y3,rel=0;
        while(x2!=0)
        {
            y3=y2;
            while(y3!=0)
            {
                rel+=BIT[x2][y3];
                y3-=(y3&(-y3));
            }
            x2-=(x2&(-x2));
        }
        return rel;
    }
    return get(1,1,x2,y2)-get(1,1,x1-1,y2)-get(1,1,x2,y1-1)+get(1,1,x1-1,y1-1);
}

int main()
{
    freopen("mobiles.inp","r",stdin);
    freopen("mobiles.out","w",stdout);

    while(scanf("%d",&t)==1)
    {
        if(t==3) return 0;
        if(t==0) scanf("%d",&n);
        if(t==1)
        {
            scanf("%d%d%d",&a,&b,&c);
            a++;
            b++;
            update(a,b,c);
        }
        if(t==2)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            a++;
            b++;
            c++;
            d++;
            printf("%d\n",get(a,b,c,d));
        }
    }
}
