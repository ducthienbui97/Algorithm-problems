#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <climits>
#include <cstdlib>
#include <stack>
#include <vector>
#define Max 10050

using namespace std;

bool a[Max][Max],dd[Max];
int n,front,back,Q[Max],d,c,ll[Max];

void INPUT()
{
    int x,y;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        a[x][y]=true;
    }
}

void process()
{
    for (int i=0;i<n;i++) dd[i]=false;
    front=0;
    back=0;
    Q[back]=d;
    dd[Q[back]]=true;
    ll[Q[back]]=0;
    while (front<= back)
    {
        for (int i=1;i<=n;i++)
        {
            if ( a[Q[front]][i] && !dd[i])
            {
                back++;
                Q[back]=i;
                dd[i]=true;
                ll[i]=Q[front];
            }
        }
        front++;
    }
}

void OUTPUT()
{
    int i=0;
    int vt=n;
    while (vt!=0)
    {
        i++;
        Q[i]=vt;
        vt=ll[vt];
    }
    if (!dd[c]) cout << "No" << endl;
    else cout << "Yes " << i << endl;
}

int main()
{
    freopen("1.inp","r",stdin);
    freopen("1.out","w",stdout);
    INPUT();
    while (scanf("%d%d",&d,&c)!=0)
    {
        process();
        OUTPUT();
    }
}
