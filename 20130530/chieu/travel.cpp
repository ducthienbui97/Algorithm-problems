#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <list>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <climits>
#include <algorithm>
#include <utility>
#define elif else if
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> pi;
bool vs[2002][1<<7+1];
int n,m,k;
pi a;
vector <pii> d[2002];
bool iswonder[2222];
int wonder[2222];
priority_queue<pi> xyz;

int dij()
{
    pi l;
    int x,y,z;
    int j=0;
    while(!xyz.empty())
    {
        a=xyz.top();
        x=a.X;
        y=a.Y.X;
        z=a.Y.Y;
        j=0;
        xyz.pop();
        if(!vs[z][y])
        {
           // cout<<a.X<<" "<<a.Y.Y<<" "<<a.Y.X<<endl;
            vs[z][y]=true;
            if(y+1==1<<k) return abs(x);
            for(int i=0; i<k; i++)
                if((1<<i)&y) j+=10;
            l=a;
            j=100-j;
            for(int i=0; i<d[z].size(); i++)
            {
                if(iswonder[d[z][i].Y])
                {
                    if(!vs[d[z][i].Y][y|(1<<wonder[d[z][i].Y])]){
                        l.X=a.X-(d[z][i].X*j)/100;
                        l.Y.X=y|1<<wonder[d[z][i].Y];
                        l.Y.Y=d[z][i].Y;
                        xyz.push(l);
                    }
                }
                else
                {
                    if(!vs[d[z][i].Y][y]){
                        l.X=a.X-(d[z][i].X*j)/100;
                       // cout<<d[z][y].X*j/100<<endl;
                        l.Y.X=y;
                        l.Y.Y=d[z][i].Y;
                        xyz.push(l);
                    }

                }
            }
        }
    }
    return -1;
}
main()
{
    int x,y,z,t;
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++)
    {
        scanf("%d%d%d%d",&x,&y,&z,&t);
        d[x].push_back(pii(z,y));
        d[y].push_back(pii(t,x));
    }
    for(int i=0; i<k; i++)
    {
        scanf("%d",&x);
        iswonder[x]=true;
        wonder[x]=i;
        a.X=0;
        a.Y.X=1<<i;
        a.Y.Y=x;
        xyz.push(a);
    }
    printf("%d",dij());
}
