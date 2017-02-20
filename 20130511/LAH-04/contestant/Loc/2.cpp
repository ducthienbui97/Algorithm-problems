#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n,a,b,sum=0;
queue <int> lo;
vector<int> G[10005];

int main()
{
    freopen("2.inp","r",stdin);
    freopen("2.out","w",stdout);
    cin>>n;
    while(scanf("%d %d", &a,&b)==2)
    {
        if(a==0&&b==0)
        {
            lo.push(1);
            while(lo.size())
            {
                int x=lo.front(); lo.pop();
                for(int i=0;i<G[x].size();i++)
                {
                    if(G[x][i]==n) sum++;
                    else
                    {
                        lo.push(G[x][i]);
                    }
                }
            }
            cout<<sum<<endl;
            break;
        }
        else
        {
            G[a].push_back(b);
        }
    }
    return 0;
}
