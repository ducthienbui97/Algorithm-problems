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
#include <deque>
#define elif else if
#define pb push_back
#define mp make_pair
#include <utility>
#include <complex>
#define X real()
#define Y imag()
const int  Maxn = 55555;
using namespace std;
typedef pair <int,int> pii;
bool vs[Maxn][2];
vector<pii> d[Maxn];
int doit(){
        int n,m,s,f,x,y,z;
    scanf("%d%d%d%d",&n,&m,&s,&f);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&x,&y,&z);
        d[x].pb(pii(y,z));
        d[y].pb(pii(x,z));
    }
    priority_queue<pair<int,pii> ,vector<pair<int,pii> >, greater< pair<int,pii> > > dij;
    dij.push(mp(0,pii(0,s)));
    while(!dij.empty()){
        x=dij.top().first;
        y=dij.top().second.first;
        z=dij.top().second.second;
        dij.pop();
        if(!vs[z][y]){
            if(z==f) return x;
            vs[z][y]=true;
            for(int i=0;i<d[z].size();i++)
                if(!vs[d[z][i].first][y])
                    dij.push(mp(x+d[z][i].second,pii(y,d[z][i].first)));
            if(!y){
                for(int i=0;i<d[z].size();i++)
                    if(!vs[d[z][i].first][1])
                            dij.push(mp(x,pii(1,d[z][i].first)));

            }
        }
    }
    return -1;
}
main(){
        printf("%d",doit());
}
