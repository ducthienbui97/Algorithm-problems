#include <deque>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <string>
#define elif else if
#include <queue>
#include <vector>
using namespace std;
int n;
int x1,x2,y1,y2;
int xx[]= {-2,-2,2,2,-1,-1,1,1};
int yy[]= {-1,1,-1,1,-2,2,-2,2};
int cnt=0;
bool block[111][111];
queue<pair<int,int> > q[2][2];
int num;
vector<string> S;
int vs[111][111][2];
bool out(int x,int y) {
    return x<0||y<0||x>=n||y>=n||S[x][y]=='#';
    }
main() {
    freopen("MATOT.INP","r",stdin);
    freopen("MATOT.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    int x,y;
    cin>>n;
    S.resize(n);
    for(int i=0; i<n; i++) {
        cin>>S[i];
        for(int j=0; j<n; j++)
            if(S[i][j]=='T')
                q[num][0].push(make_pair(i,j)),
                        vs[i][j][0]=1;
        elif(S[i][j]=='M')
            q[num][1].push(make_pair(i,j)),
                vs[i][j][1]=1;
        }
    while(!q[num][0].empty()&&!q[num][1].empty()) {
        if(++cnt>5000){
            puts("-1");
            return 0;
        }
        while(!q[num][0].empty()) {
            x=q[num][0].front().first;
            y=q[num][0].front().second;
            q[num][0].pop();
            for(int i=-1; i<2; i++)
                for(int j=-1;j<2;j++)
                if(i||j)
                if(!out(x+i,y+j)&&vs[x+i][y+j][0]<=cnt) {
                    vs[x+i][y+j][0]=cnt+1;
                    q[!num][0].push(make_pair(x+i,y+j));
                    }
            }
        while(!q[num][1].empty()) {
            x=q[num][1].front().first;
            y=q[num][1].front().second;
            q[num][1].pop();
            for(int i=0; i<8; i++){
                if(!out(x+xx[i],y+yy[i])&&vs[x+xx[i]][y+yy[i]][1]<=cnt) {
                    vs[x+xx[i]][y+yy[i]][1]=cnt+1;
                    if(vs[x+xx[i]][y+yy[i]][0]==vs[x+xx[i]][y+yy[i]][1]) {
                        printf("%d",cnt);
                        return 0;
                        }
                    q[!num][1].push(make_pair(x+xx[i],y+yy[i]));
                    }
            }
        }
        num=!num;
        }
        puts("-1");
    }


