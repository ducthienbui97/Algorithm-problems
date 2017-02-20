#include <stdio.h>
#include <iostream>

using namespace std;

int N,Q,a;
int F[550];

int main()
{
    freopen("hayexp.inp","r",stdin);
    freopen("hayexp.out","w",stdout);
    cin>>N>>Q;
    F[0]=0;
    for(int i=1;i<=N;i++)
    {
        cin>>a;
        F[i]=F[i-1]+a;
    }
    for(int i=1;i<=Q;i++)
    {
        int x,y;
        cin>>x>>y;
        cout<<F[y]-F[x-1]<<endl;
    }
    return 0;
}
