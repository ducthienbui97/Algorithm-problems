#include <cstdio>
#include <vector>

int point, a[10001], ans=0, b[10001][10000];

void dfs(int i)
{
    if (i==point)
        ans++;
    for (int j=1; j<a[i]; j++){
        dfs (b[i][j]);
    }
}

int main()
{
    freopen("2.inp","r", stdin);
    freopen("2.out","w", stdout);
    int t1, t2;
    scanf("%d", &point);
    for(int i=1; i<=10000; i++)
        a[i]=1;
    for(int i=1; i<=10000;i++){
        scanf("%d%d", &t1, &t2);
        if (t1==0&&t2==0)
            break;
        if (t1>t2){
            b[t2][a[t2]]=t1;
            a[t2]++;
        }
        else if (t1<t2){
            b[t1][a[t1]]=t2;
            a[t1]++;
        }
    }
    dfs(1);
    printf("%d", ans);
}
