#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define elif else if
#define input "xlines.inp"
#define output "xlines.out"
using namespace std;
inline void openfile() {
    freopen(input,"r",stdin);
    freopen(output,"w",stdout);
    }
struct line{
    int x1,x2,y1,y2;
    bool N;
    line(){};
    line(int a,int b,int c,int d){
        if(a==c&&b>d) swap(b,d);
        if(b==d&&a>c) swap(a,c);
        x1=a;
        y1=b;
        x2=c;
        y2=d;
        N=(x1==x2);
    }
    bool operator < (const line& X) const{
        return x1<=X.x1&&X.x1<=x2&&X.y1<=y1&&y1<=X.y2;
    }
};
vector<line> M[2];
vector<int> d[555];
bool vs[555];
int Next[555][2];
bool dfs(int t){
    if(t<0) return true;
    if(vs[t]) return false;
    vs[t]=true;
    for(int j=0;j<d[t].size();j++)
    if(dfs(Next[d[t][j]][1])){
        Next[d[t][j]][1]=t;
        Next[t][0]=d[t][j];
        return true;
    }
    return false;
}
main() {
#ifdef HYQ
    openfile();
#endif
    ios_base::sync_with_stdio(false);
    int x1,x2,y1,y2;
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>x1>>y1>>x2>>y2;
        line t(x1,y1,x2,y2);
        M[t.N].push_back(t);
    }
    for(int i=0;i<M[0].size();i++){
        for(int j=0;j<M[1].size();j++)
            if(M[0][i]<M[1][j]) d[i].push_back(j);
    }
    memset(Next,-1,sizeof Next);

    int c=0,cc=-1;
    while(cc<c){
        cc=c;
        memset(vs,0,sizeof vs);
        for(int i=0;i<M[0].size();i++) if(Next[i][0]<0&&dfs(i)) c++;
    }
    printf("%d",M[0].size()+M[1].size()-c);
}
/*
3
4 5 10 5
6 2 6 12
8 3 8 5
*/
