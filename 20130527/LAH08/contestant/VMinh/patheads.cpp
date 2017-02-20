#include <cstdio>
#include <cstring>
#define NMAX 100000
#define MAX 1000000
#define fi "patheads.inp"
#define fo "patheads.out"
int N, a[NMAX], b[NMAX];

void enter()
{
    memset(b, 0, sizeof(b));
    scanf ("%d", &N);
    for (int i=1; i<=N; i++)
    {
        scanf ("%d", &a[i]);
    }
}

void process()
{
    for (int i=1; i<=N; i++)
        for (int j=i+1; j<=N; j++)
        {
            if (a[i]%a[j]==0)
                b[i]++;
            if (a[j]%a[i]==0)
                b[j]++;
        }
    for (int i=1; i<=N; i++)
        printf ("%d\n", b[i]);
}

int main()
{
    freopen (fi, "r", stdin);
    freopen (fo, "w", stdout);
    enter();
    process();
}
