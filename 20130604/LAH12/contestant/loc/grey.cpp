#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;
int n,C[30];
long long sum;
vector<string> lo[30];
int backtrack(int k)
{
    string s;
    for(int i=0;i<lo[k-1].size();i++)
    {
        s+="0";
        s+=lo[k-1][i];
        lo[k].push_back(s);
        s="";
    }
    for(int i=lo[k-1].size()-1;i>=0;i--)
    {
        s+="1";
        s+=lo[k-1][i];
        lo[k].push_back(s);
        s="";
    }
}
int main()
{
    freopen("grey.inp","r",stdin);
    freopen("grey.out","w",stdout);
    scanf("%d",&n);
    backtrack(0);
    lo[2].push_back("00");
    lo[2].push_back("01");
    lo[2].push_back("10");
    lo[2].push_back("11");
    if(n==2) for(int i=0;i<4;i++) cout<<lo[2][i]<<endl;
    else
    {
    for(int i=3;i<=n;i++)
    {
        backtrack(i);
    }
    for(int i=0;i<lo[n].size();i++) cout<<lo[n][i]<<endl;
    }
    return 0;
}
