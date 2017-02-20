#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int n,x,y;
vector<int> G[10005];
vector<int>lo;
int lolo(int a,int b,int sum)
{
    if(a==x&&sum!=0) cout<<"No"<<endl;
    else if(lo.size()==n&&a!=b) cout<<"No"<<endl;
    else if(a==b)
    {
        //if(G[b][0]==x) cout<<"Yes 1"<<endl;
        cout<<"Yes "<<sum-1<<endl;
    }
    else
    {
        sum++;
        lolo(G[a][0],b,sum);
    }
}

int main(void)
{
    freopen("1.inp","r",stdin);
    freopen("1.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y;
        G[x].push_back(y);
    }
    while(scanf("%d %d", &x,&y)==2)
    {
        if(x==0&&y==0)  break;
        else
        {
            if(G[x][0]==y) cout<<"Yes 0"<<endl;
            else lolo(x,y,0);
        }
    }
    return 0;
}
