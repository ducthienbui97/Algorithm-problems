#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define elif else if
using namespace std;
const int INF=100;
bool A[9][9];
string S;
bool done[9][9][1<<9][1<<3][2];
int F[9][9][1<<9][1<<3][2];
int f(int r,int c,int sc,int sb,int sr){
    if(r==9){
        if(sc) return INF;
        return 0;
    }
    if(c==9){
        if(sr) return INF;
        if(r%3==2&&sb) return INF;
        return f(r+1,0,sc,sb,sr);
    }
    if(done[r][c][sc][sb][sr]) return F[r][c][sc][sb][sr];
    done[r][c][sc][sb][sr]=true;
    return F[r][c][sc][sb][sr]=min(A[r][c]+f(r,c+1,sc,sb,sr),!A[r][c]+f(r,c+1,sc^(1<<c),sb^(1<<(c/3)),!sr));
}
main() {
#ifndef HYQ
    ios_base::sync_with_stdio(false);
    for(int i=0;i<9;i++){
        cin>>S;
        for(int j=0;j<9;j++)
            A[i][j]=S[j]=='1';
    }
    printf("%d",f(0,0,0,0,0));
    #endif

}
