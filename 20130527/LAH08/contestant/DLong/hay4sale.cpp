#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

vector <int> G;

bool have[50010];

int main()
{
    freopen("hay4sale.inp","r",stdin);
    freopen("hay4sale.out","w",stdout);
    have[0]=true;
    G.push_back(0);
    int c,h,i;
    scanf("%d%d",&c,&h);
    for(i=1;i<=h;i++)
    {
        int temp;
        cin>>temp;
        int a=G.size();
        for(int j=0;j<a;j++)
        {
            //cout<<G[j];
            if(G[j]+temp<=c&&have[G[j]+temp]==false)
            {
                have[G[j]+temp]=true;
                //cout<<G[j]+temp;
                G.push_back(G[j]+temp);
            }
        }
    }
    for(i=c;i>=0;i--)
    {
        if(have[i]==true)
        {
            printf("%d",i);
            break;
        }
    }
}
