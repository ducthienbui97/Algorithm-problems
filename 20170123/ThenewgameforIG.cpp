#include <bits/stdc++.h>
using namespace std;
bool F[33][33][33][33];
bool Win[33][33][33][33];
int done[33][33][33][33];
char c[33][33];
int t;
bool breakable(char c) {
    if(c=='A' ||
            c=='O' ||
            c=='I' ||
            c=='H' ||
            c=='M') return true;
    else return false;
}
bool DP(int x1,int y1,int x2,int y2) {

    if(done[x1][y1][x2][y2] == t) return Win[x1][y1][x2][y2];
    done[x1][y1][x2][y2] = t;
    if(!F[x1][y1][x2][y2]) return Win[x1][y1][x2][y2] = false;
    Win[x1][y1][x2][y2] = false;

    for(int i=x1; i<x2 && !Win[x1][y1][x2][y2]; i++) {
        Win[x1][y1][x2][y2] |= !(DP(x1,y1,i,y2)^DP(i+1,y1,x2,y2));
    }

    for(int i=y1; i<y2 && !Win[x1][y1][x2][y2]; i++) {
        Win[x1][y1][x2][y2] |= !(DP(x1,y1,x2,i)^DP(x1,i+1,x2,y2));

    }

    return Win[x1][y1][x2][y2];
}
void solve() {
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin>>c[i][j];
        }
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            for(int i2 = i;i2<n;i2++)
            for(int j2 = j;j2<n;j2++){
                F[i][j][i2][j2] = false;
                if(i2>i) F[i][j][i2][j2] |= F[i][j][i2-1][j2];
                if(j2>j) F[i][j][i2][j2] |= F[i][j][i2][j2-1];
                F[i][j][i2][j2] |= breakable(c[i2][j2]);
            }
        }
    if(!DP(0,0,n-1,n-1)) cout << "Rathi\n";
    else cout << "Moroney\n";
}
main() {
    ios_base::sync_with_stdio(false);
    for(cin>>t; t>0; t--) solve();
}
/*
2
2
O G
A L
3
L T R
L T R
T T T
*/
