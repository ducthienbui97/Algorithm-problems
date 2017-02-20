#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;

const int maxn=700+5;
const int len=50;
const int base=1000;

bool e[maxn][maxn];
int opt[maxn][maxn][len];
int cnt[maxn];
int tmp[maxn][len*2];
int xxx[len*2],c[len*2];
int n;

void process(int a[])
{
        while (a[0] && !a[a[0]]) a[0]--;
        if (!a[0]) a[0]=1,a[1]=0;
}

void move(int a[],int b[])
{
        process(b);
        for (int i=0;i<=b[0];i++) a[i]=b[i];
}

void mul(int a[],int x)
{
        process(a);
        int k=0;
        for (int i=1;i<=a[0];i++)
        {
                a[i]=a[i]*x+k;
                k=a[i]/base;a[i]%=base;
        }
        while (k) {a[++a[0]]=k%base;k/=base;}
}

void mul2(int a[],int b[])
{
        process(a);
        process(b);
        for (int i=0;i<=a[0]+b[0];i++) c[i]=0;
        for (int i=1;i<=a[0];i++)
        for (int j=1;j<=b[0];j++)
                c[i+j-1]+=a[i]*b[j];
        c[0]=a[0]+b[0]-1;
        for (int i=1;i<c[0];i++) 
        {
                c[i+1]+=c[i]/base;
                c[i]%=base;
        }

        while (c[c[0]]>=base)
        {
                c[c[0]+1]=c[c[0]]/base;
                c[c[0]]%=base;
                c[0]++;
        }
        move(a,c);
}

int cmp(int a[],int b[])
{
        process(a);
        process(b);
        if (a[0]>b[0]) return 1;
        if (a[0]<b[0]) return -1;
        for (int i=a[0];i;i--)
        if (a[i]>b[i]) return 1;else
        if (a[i]<b[i]) return -1;
        return 0;
}

void dfs(int u)
{
        opt[u][1][0]=opt[u][1][1]=1;cnt[u]=1;
        for (int v=1;v<=n;v++)
        if (e[u][v])
        {
                e[v][u]=0;dfs(v);
                for (int i=1;i<=cnt[u];i++) move(tmp[i],opt[u][i]);
                for (int i=1;i<=cnt[u];i++)
                for (int j=0;j<=cnt[v];j++)
                {
                        move(xxx,tmp[i]);
                        mul2(xxx,opt[v][j]);
                        if (cmp(opt[u][i+j],xxx)==-1) move(opt[u][i+j],xxx);
                }
                cnt[u]+=cnt[v];
        }

        for (int i=1;i<=cnt[u];i++)
        {
                move(xxx,opt[u][i]);
                mul(xxx,i);
                if (cmp(opt[u][0],xxx)==-1) 
                        move(opt[u][0],xxx);
        }
}

int main()
{
        //freopen("e.in","r",stdin);

        scanf("%d",&n);
        for (int i=0,a,b;i<n-1;i++)
        {
                scanf("%d%d",&a,&b);
                e[a][b]=e[b][a]=1;
        }

        dfs(1);
        printf("%d",opt[1][0][opt[1][0][0]]);
        for (int i=opt[1][0][0]-1;i;i--) printf("%.3d",opt[1][0][i]);
        printf("\n");
}
