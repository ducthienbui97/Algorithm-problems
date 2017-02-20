#include <cstdio>
#include <algorithm>
#include <queue>
#include <iostream>
#include <utility>
#include <cmath>
#include <climits>
#include <cstring>
#include <climits>
#include <ctime>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define elif else if
using namespace std;
char s[33][33];
vector <pair<int,int> > k;
bool done;
int x[]= {1,1,-1,-1};
int y[]= {-1,1,1,-1};
pair<int,int> did[999];
int no;
void bk(int x1,int y1,int n)
{
    did[n]=make_pair(x1,y1);
    if(done) return;
    if(n>0)
    {
        for(int i=0; i<4; i++)
            if(s[x1+x[i]][y1+y[i]]=='o'&&s[x1+2*x[i]][y1+2*y[i]]=='+')
            {
                s[x1][y1]='+';
                s[x1+2*x[i]][y1+2*y[i]]='K';
                s[x1+x[i]][y1+y[i]]='+';
                bk(x1+2*x[i],y1+2*y[i],n-1);
                s[x1][y1]='K';
                s[x1+2*x[i]][y1+2*y[i]]='+';
                s[x1+x[i]][y1+y[i]]='o';
            }
    }
    else
    {
        done=true;
        return;
    }
}
void doit(int i)
{
    bk(k[i].first,k[i].second,no);
}
main()
{
    freopen("chkr.inp","r",stdin);
    freopen("chkr.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=0; i<n; i++)
        scanf("%s",s[i]);
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(s[i][j]=='K') k.push_back(make_pair(i,j));
    elif(s[i][j]=='o') no++;
    for(int i=0; i<k.size(); i++)
        if(!done) doit(i);
    if(!done) printf("impossible");
    else for(int i=no; i>=0; i--)
            printf("%d %d\n",did[i].first+1,did[i].second+1);
}

