#include<stdio.h>

int s, n, p[100];
int f[10000][10000];

int dfs (int k)
{
    if (k==n)  return 1;
    p[k]=1;
    for (int i=1; i<=n; i++)
        if (f[k][i]==1 && p[i]==0) {
            p[i]=1;
            if (dfs(i)==1) s++;
            p[i]=0;
        }
}
main ()
{
    int i, j;
    scanf ("%d" ,&n);
    while (i!=0) {
        scanf ("%d%d" ,&i, &j);
        f[i][j]=1;
    }
    dfs(1);
    printf ("%d\n" ,s);
}
