#include <iostream>
#include <stdio.h>

using namespace std;

int const MAX = 30000+1;
int A[MAX], n, k, w;
int B[MAX];
bool C[MAX];
int ans=0;

void generateB()
{
    int i, j;
    for(i=1; i<=n-w+1; i++)
    {
        for(j=i; j<i+w; j++)
        {
            B[i]+=A[j];
        }
    }
}

void process()
{
    int i, index=1;
    int _max = B[1];
    for(i=2; i<=n-w+1; i++)
    {
        if(B[i]>_max)
        {
            _max=B[i];
            index=i;
        }
    }
    ans+=_max;
    for(i=index; i<index+w; i++)
        A[i]=0;
    for(i=1; i<=n-w+1; i++)
        B[i]=0;
    generateB();
}

int main()
{
    freopen("3.inp", "r", stdin);
    freopen("3.out", "w", stdout);
    int nt;
    cin >> nt;
    while(nt--)
    {
        int i;
        for(i=1; i<=n-w+1; i++)
            B[i]=0;
        cin >> n >> k >> w;
        for(i=1; i<=n; i++)
            cin >> A[i];
        generateB();
        for(i=0; i<k; i++)
            process();
        cout << ans << endl;
        ans=0;
    }
    return 0;
}
