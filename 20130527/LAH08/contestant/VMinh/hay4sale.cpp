#include <cstdio>
#include <cstring>
#include <algorithm>
#define NMAX 5001
#define CMAX 50001
#define fi "hay4sale.inp"
#define fo "hay4sale.out"
using namespace std;
int n, a[NMAX], f[CMAX][NMAX], c;

void enter()
{
    scanf ("%d%d", &c, &n);
    for (int i=1; i<=n; i++)
    {
        scanf ("%d", &a[i]);
    }
}

void process()
{
    memset(f, sizeof(f), 0);
    for (int i=0; i<=c; i++)
    {
        f[i][0]=c-i;
    }
    for (int i=1; i<=n; i++)
    {
        for (int j=0; j<=c; j++)
        {
            if (j>=a[i])
                f[j][i]=max(f[j][i-1], f[j-a[i]][i-1]);
            else
                f[j][i]=f[j][i-1];
        }
    }
}

void result()
{
    printf("%d", f[c][n]);
}

int main()
{
    freopen (fi, "r", stdin);
    freopen (fo, "w", stdout);
    enter();
    process();
    result();
}
