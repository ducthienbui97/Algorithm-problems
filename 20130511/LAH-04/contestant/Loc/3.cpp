#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int,int> ii;
int a,b,c,G[30001],d,sum=0,s=0,f[30001];
priority_queue<ii,vector<ii>,greater<ii> > lol;

int dd(int t)
{
    for(int r=t;r>t-c;r--)
    {
        f[r]=1;
        //cout<<r<<endl;
    }
     for(int u=t+1;u<t+c;u++)
     {
         f[u]=1;
     }
}

int lolo(int k)
{
    int ss=0;
    for(int u=k;u>k-c;u--)
    {
        ss+=G[u];
        //cout<<"1"<<endl;
    }
    return ss;
}

int main()
{freopen("3.inp","r",stdin);
    freopen("3.out","w",stdout);
    int test;
    cin>>test;
    for(int h=1;h<=test;h++)
    {
    cin>>a>>b>>c;
    for(int j=1;j<=a;j++) f[j]=0;
    for(int i=1;i<=a;i++)
    {
        cin>>G[i];
        if(i>=c)
        {
            int x=lolo(i);
            //cout<<i<<" "<<x<<endl;
            lol.push(ii(-x,i-1));
        }
    }
    int i=0;
    while(i<b)
    {
        //cout<<lol.top().first;
        ii y=lol.top(); lol.pop();
        if(f[y.second]==0)
        {
            //cout<<"1"<<endl;
            dd(y.second);
            sum+=-y.first;
            //cout<<-y.first<<endl;
            i++;
        }
    }
    cout<<sum<<endl;
    sum=0;s=0;
    while(lol.size()!=0) lol.pop();
    }
    return 0;
}
