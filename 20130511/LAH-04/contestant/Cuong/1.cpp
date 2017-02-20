#include <cstdio>
int cha[10000];
int dd[10000];
int main()
{
    freopen("1.inp","r",stdin);
    freopen("1.out","w",stdout);
    int n,i,x,y;
    int kt=0;
    int dem=0,TLE=0;
    for (i=0; i<=10000; i++)cha[i]=-1;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d%d",&x,&y);
        cha[y]=x;
    }
    while(scanf("%d%d",&x,&y) && x!=0 && y!=0)
    {
        if(x==y)
        {
            printf("NO\n");
        }
        else
        {
            int a=y;
            TLE=0;
            int dem=-1;
            do
            {
                if(kt==0)dem++;
                TLE++;
                a=cha[a];
                if(a==x)kt=1;
                else if(a<0){kt=-1;break;}
            }
            while(a!=y);
            if(kt!=1)printf("NO\n");
            else printf("YES %d\n",dem);
        }
    }
}
