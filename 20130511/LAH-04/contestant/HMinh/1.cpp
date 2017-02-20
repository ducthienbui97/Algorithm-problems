#include <cstdio>
#include <vector>
int x, f[100000], ch[100000];
int ans=-1;
void che (int i, int j)
{
    if (i==j)
        return;
    else if (ch[i]==1)
        ans=-1;
    else{
        ch[i]=1;
        ans++;
        che(f[i], j);
    }
}

int main()
{
freopen("1.inp","r", stdin);
    freopen("1.out","w", stdout);
        int t1, t2;
    scanf("%d", &x);
    for(int i=1; i<=100000; i++){
        f[i]=0;
        ch[i]=0;
    }
    for(int i=1; i<=x; i++){
        scanf("%d%d", &t1, &t2);
        f[t1]=t2;
    }
    while(1)
    {
        scanf("%d%d", &t1, &t2);
        if (t1==0&&t2==0)
        break;
        che(t1, t2);
        if (ans>=0)
        printf("Yes %d\n", ans);
        else printf("No\n");
        ans=-1;
        for(int i=1; i<=100000; i++){
        ch[i]=-1;
    }
    }

}
