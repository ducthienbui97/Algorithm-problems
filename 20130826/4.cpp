#include <bits/stdc++.h>
#define elif else if
using namespace std;
const int Maxn=55;
int vs[Maxn][Maxn];
int water[Maxn][Maxn];
int t[Maxn][Maxn];
char c[Maxn][Maxn];
queue<pair<int,int> > q;
queue<pair<int,int> > bfs;
int xx[]= {-1,1,0,0};
int yy[]= {0,0,-1,1};
main() {
    ios_base::sync_with_stdio(false);
    int n,m;
    int ansx,ansy;
    cin>>n>>m;
    for(int i=0; i<n; i++) {
        cin>>c[i];
        for(int j=0; j<m; j++) {
            if(c[i][j]=='*') {
                q.push(make_pair(i,j));
                water[i][j]=1;
                }
            if(c[i][j]=='S') {
                bfs.push(make_pair(i,j));
                t[i][j]=1;
                }
            if(c[i][j]=='D') {
                ansx=i;
                ansy=j;
                }
            }
        }
    while(!q.empty()) {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int i=0; i<4; i++) {
            int _x=x+xx[i];
            int _y=y+yy[i];
            if(_x>=0&&_y>=0&&_x<n&&_y<m&&c[_x][_y]!='D'&&c[_x][_y]!='X'&&!water[_x][_y]) {
                water[_x][_y]=water[x][y]+1;
                q.push(make_pair(_x,_y));
                }
            }
        }
    while(!bfs.empty()) {
        int x=bfs.front().first;
        int y=bfs.front().second;
        bfs.pop();
        for(int i=0; i<4; i++) {
            int _x=x+xx[i];
            int _y=y+yy[i];
            if(_x>=0&&_y>=0&&_x<n&&_y<m&&c[_x][_y]!='*'&&c[_x][_y]!='X'&&!t[_x][_y]&&(t[x][y]+1<water[_x][_y]||water[_x][_y]==0)) {
                t[_x][_y]=t[x][y]+1;
                bfs.push(make_pair(_x,_y));
                }
            }

        }

    if(t[ansx][ansy]) printf("%d",t[ansx][ansy]-1);
    else puts("KAKTUS");
    }
