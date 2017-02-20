#include <iostream>
#include <cstdio>

using namespace std;
int n,a[35][35];

void INP()
{
    string S;
    scanf("%d\n",&n);
    for (int i=0;i<n;i++)
    {
        cin >> S;
        for (int j=0;j<S.size();j++)
        {
            if (S[j]=='+') a[i][j]=1;
            if (S[j]=='K') a[i][j]=2;
            if (S[j]=='o') a[i][j]=3;
        }
    }
}

void OUT()
{
    printf("impossible");
}

int main()
{
    freopen("chkr.inp","r",stdin);
    freopen("chkr.out","w",stdout);
    INP();
    OUT();
}
