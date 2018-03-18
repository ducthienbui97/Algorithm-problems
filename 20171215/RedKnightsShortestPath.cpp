#include <bits/stdc++.h>

using namespace std;
int Y[] = {-1,1,2,1,-1,-2};
int X[] = {-2,-2,0,2,2,0};
string mv[] = {"UL ","UR ","R ","LR ","LL ","L "};
int vs[222][222];
pair<int,int> pr[222][222];
string moved[222][222];
bool between(int a,int b,int c){
    return a <= b && b < c;
}
void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end) {
    //  Print the distance along with the sequence of moves.
    queue<pair<int,int> > q;
    q.emplace(i_start,j_start);
    vs[i_start][j_start] = 1;
    pr[i_start][j_start] = {-1,-1};
    while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(int idx = 0; idx < 6;idx ++){
            if(between(0,x + X[idx], n) && between(0, y + Y[idx], n) &&
               !vs[x + X[idx]][y + Y[idx]]){
                vs[x + X[idx]][y + Y[idx]] = vs[x][y] + 1;
                pr[x + X[idx]][y + Y[idx]] = {x,y};
                moved[x + X[idx]][y + Y[idx]] = mv[idx];
                q.emplace(x + X[idx],y + Y[idx]);
            }
        }
    }
    vector<string> ans;
    if(vs[i_end][j_end] < 1){
        cout << "Impossible\n";
    }else{
        cout << vs[i_end][j_end] - 1 << '\n';
        while(i_end != -1 && j_end != -1){
            ans.push_back(moved[i_end][j_end]);
            auto&p = pr[i_end][j_end];
            i_end = p.first;
            j_end = p.second;
        }
        reverse(ans.begin(),ans.end());
        for(auto&s:ans)
            cout << s;
    }
}

int main() {
    int n;
    cin >> n;
    int i_start;
    int j_start;
    int i_end;
    int j_end;
    cin >> i_start >> j_start >> i_end >> j_end;
    printShortestPath(n, i_start, j_start, i_end, j_end);
    return 0;
}
