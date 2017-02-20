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
#define elif else if
using namespace std;
const int Maxn=1e6+10;
bool vs[Maxn][2];
char c[Maxn];
int n;
typedef pair<int,pair <int,int> > pii;
priority_queue<pii,vector<pii>, greater <pii> > dijj;
int dij(){
    dijj.push(make_pair(0,make_pair(0,0)));
    int x,y,z;
    while(!dijj.empty()){
        x=dijj.top().first;
        y=dijj.top().second.first;
        z=dijj.top().second.second;
        dijj.pop();
        if(!vs[y][z]){
            if(y==n&&z==1) return x;
            vs[y][z]=true;
            if(!vs[y][!z]) dijj.push(make_pair(x+1,make_pair(y,!z)));
            if(!vs[y+1][z]){
                if(z==1&&(c[y]=='R'||c[y]=='B')) dijj.push(make_pair(x+1,make_pair(y+1,z)));
                elif(z==0&&(c[y]=='L'||c[y]=='B')) dijj.push(make_pair(x+1,make_pair(y+1,z)));
                else dijj.push(make_pair(x,make_pair(y+1,z)));
            }
        }
    }
}
main(){
    freopen("zcross.inp","r",stdin);
    freopen("zcross.out","w",stdout);
    scanf("%s",c);
    n=strlen(c);
    printf("%d",dij());
}
