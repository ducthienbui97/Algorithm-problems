#include <bits/stdc++.h>
using namespace std;
int n;
char c[9][9];
char w[22];
unordered_map<char, unordered_set<int> > nex[9][9];
int X[8] = {1, 1,-1,-1, 1, 0,-1, 0};
int Y[8] = {0,-1, 0, 1, 1, 1,-1,-1};
int ans = 0;
void bt(int i,int j, int idx){
    //cout << i << " " <<j <<"--" <<idx<<endl;
    if(c[i][j] != w[idx])
        return;
    for(auto&it : nex[i][j]){
        for(auto&v: it.second){
            nex[v >> 3][v & 7][w[idx]].erase((i << 3) + j);
        }
    }

    if(idx == n - 1){
        ans ++;
    }else{
        for(auto&v: nex[i][j][w[idx + 1]]){
            //cout << (v >> 3) <<" "<< (v & 7) <<endl;
            bt(v >> 3, v & 7, idx + 1);
        }
    }

    for(auto&it : nex[i][j]){
        for(auto&v: it.second){
            nex[v >> 3][v & 7][w[idx]].insert((i << 3) + j);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;
    for(int i=0;i<8;i++)
        cin >> c[i];
    for(int i = 0; i < 8; i++)
        for(int j = 0; j < 8; j++)
            for(int d=0; d < 8; d++){
                if(i + X[d] >= 0 && i + X[d] < 8 &&
                   j + Y[d] >= 0 && j + Y[d] < 8){
                    //cout <<i <<" "<<j <<" "<<i + X[d] <<" "<<j + Y[d]  <<" "<< ((i+X[d])<<3)+j+Y[d] <<endl;
                    nex[i][j][c[i + X[d]][j + Y[d]]].insert(((i + X[d]) << 3) + j + Y[d]);
                   }
            }
    for(int i = 0; i < 8; i++)
    for(int j = 0; j < 8; j++){
        bt(i,j,0);
       // cout << i <<" "<<j <<" "<< ans <<endl;
    }
    cout << ans;
    return 0;
}
