#include <stdio.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <cstdio>
#include <map>
#include <string>
#include <utility>
#include <climits>
#include <vector>
#include <cstring>
#include <deque>
#include <queue>
#include <algorithm>
#include <map>
#include <stack>
#define elif else if
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
pii d[25111111];
bool k[25111111];
bool ch[5111][5111];
int a[5111][5111];
vector <pii> in;
main()
{
    int c,r;
    int i,j,x,y,z;
    scanf("%d%d",&r,&c);
    // c=1000,r=1000;
    // int xx=0;
    for(i=1; i<=r; i++)
        for(j=1; j<=c; j++)
        {
            //xx++;
            //   a[i][j]=xx;
            scanf("%d",&a[i][j]);
            d[a[i][j]]=mp(i,j);
            k[a[i][j]]=true;
            ch[i][j]=true;
        }
    for(i=0; i<=r+1; i++)
        ch[i][0]=ch[i][c+1]=0;
    for(i=0; i<=c+1; i++)
        ch[0][i]=ch[r+1][i]=0;
    k[0]=false;
    z=1;
    while(z<=c*r)
    {
        if(k[z])
        {
            in.push_back(d[z]);
            y=d[z].first;
            x=d[z].second;
            i=y+1;
            j=x-1;
            for(; j>0; j--)
            {
                if(ch[i][j]==true)
                {
                    while(i<=r&&ch[i][j]==true)
                    {
                        ch[i][j]=false;
                        k[a[i][j]]=false;
                        i++;
                    }
                    i=y+1;
                }
                else break;
            }
            i=y-1;
            j=x+1;
            for(; j<=c; j++)
            {
                if(ch[i][j]==true)
                {
                    while(i>0&&ch[i][j]==true)
                    {
                        ch[i][j]=false;
                        k[a[i][j]]=false;
                        i--;
                    }
                    i=y-1;
                }
                else break;
            }
        }
        z++;
    }
    sort(in.begin(),in.end());
    for(int i=0; i<in.size()-1; i++)
        printf("%d ",a[in[i].first][in[i].second]);
    printf("%d\n",a[in.back().first][in.back().second]);
}


