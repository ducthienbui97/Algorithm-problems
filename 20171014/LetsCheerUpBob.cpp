#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> > bob;
vector<pair<int,int> > ans;
vector<pair<int,int> > cur;
int filled[4][4];
bool isEqual(int x,int y,int z, int t){
    return x == y && y == z && z == t;
}
bool sbdWin(int t){
    return isEqual(filled[1][1],filled[2][2],filled[3][3], t)
            || isEqual(filled[1][1],filled[1][2],filled[1][3], t)
            || isEqual(filled[1][1],filled[2][1],filled[3][1], t)
            || isEqual(filled[1][2],filled[2][2],filled[3][2], t)
            || isEqual(filled[1][3],filled[2][3],filled[3][3], t)
            || isEqual(filled[1][3],filled[2][2],filled[3][1], t)
            || isEqual(filled[2][1],filled[2][2],filled[2][3], t)
            || isEqual(filled[3][1],filled[3][2],filled[3][3], t);
}
bool bobWin(){
    return sbdWin(1);
}
bool iWin(){
    return sbdWin(2);
}
void bt(int num){
    if(iWin())
        return;
    if(bobWin()){
        if(cur.size() < ans.size() || cur < ans)
            ans = cur;
        return;
    }
    if(num == 9)
        return;
    if(num&1){
        for(int i = 1; i <= 3; i++)
        for(int j = 1; j <= 3; j++)if(!filled[i][j]){
            cur.emplace_back(i,j);
            filled[i][j] = 2;
            bt(num + 1);
            cur.pop_back();
            filled[i][j] = 0;
        }
    }else{
        for(auto&u:bob)
        if(!filled[u.first][u.second]){
            filled[u.first][u.second] = 1;
            bt(num + 1);
            filled[u.first][u.second] = 0;
            return;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    ans.resize(10);
    bob.resize(9);
    for(auto&u:bob)
        cin >> u.first >> u.second;
    bt(0);
    for(auto&u:ans)
        cout << u.first <<" "<<u.second << endl;
    return 0;
}

