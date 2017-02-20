#include <cstdio>
#define NMAX 501
#define QMAX 501
#define fi "hayexp.inp"
#define fo "hayexp.out"
int N, Q, h[NMAX], s[QMAX], e[QMAX], ans[QMAX];

void enter()
{
    scanf ("%d %d", &N, &Q);
    for (int i=1; i<=N; i++)
        scanf ("%d", &h[i]);
    for (int j=1; j<=Q; j++)
        scanf ("%d %d", &s[j], &e[j]);
}

void process()
{
    for (int i=1; i<=Q; i++)
    {
        int sum=0;
        for (int j=s[i]; j<=e[i]; j++)
        {
            sum+=h[j];
        }
        ans[i]=sum;
    }
}

void exit()
{
    for (int i=1; i<=Q; i++)
        printf("%d\n", ans[i]);
}

int main()
{
    freopen (fi, "r", stdin);
    freopen (fo, "w", stdout);
    enter();
    process();
    exit();
}
