#include <bits/stdc++.h>
using namespace std;
int X[]={1,-1,0,0};
int Y[]={0,0,1,-1};
/***
     1
     ^
     |
3 <--  --> 2
     |
     v
     0
***/
int Next[4][2] = {{2,3},{2,3},{0,1},{0,1}};
int n;
const int BASE = 1e9+7;
int vs[3][1111];
int F[3][1111][4];
string s[3];
int cal(int x,int y,int d){
    if(d == 3 || x >= 3 || x < 0 || y >= n || y < 0 || vs[x][y] || s[x][y] == '#')
        return 0;

    if(x == 2 && y == n - 1){
        if(d == 2) return 1;
        else return 0;
    }
    //if(x == 1)


    if(F[x][y][d] >= 0)
        return F[x][y][d];
    vs[x][y] = true;
    F[x][y][d] = 0;
    for(int i = 0; i < 2 ; i++) {

        F[x][y][d] = ( F[x][y][d] + cal(x + X[d], y + Y[d], Next[d][i]))%BASE;

    }
    vs[x][y] = false;
    return F[x][y][d] ;
}

void solve(int ntest){
    cin >> n;
    memset(vs,0,sizeof vs);
    memset(F,-1, sizeof F);
    cin >> s[0] >> s[1] >> s[2];
    cout <<"Case #"<<ntest<<": "<< cal(0,0,0) << endl;;
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    for(int i = 1; i <= t; i++)
        solve(i);
}
