#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>

using namespace std;

int n,N[1000005],sum=0,x,F[1000005];
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
priority_queue<ii,vector<ii>, greater<ii> >lo;
priority_queue<ii,vector<ii>, greater<ii> >lolo;
vector<int> G;
int main()
{
    freopen("patheads.inp","r",stdin);
    freopen("patheads.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        lo.push(ii(x,i));
        N[x]++;
    }
    int m=lo.size();
    for(int i=0;i<m;i++)
    {
       ii a=lo.top() ;lo.pop();
       if(F[a.first]==0)
       {
            G.push_back(a.first);
            F[a.first]=1;
       }
       for(int j=0;j<G.size();j++)
       {
           if(a.first%G[j]==0) sum+=N[G[j]];
       }
       lolo.push(ii(a.second,sum-1));
       sum=0;
    }
    while(lolo.size()!=0)
    {
        cout<<(lolo.top()).second<<endl;
        lolo.pop();
    }
    return 0;
}
