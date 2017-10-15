#include <bits/stdc++.h>

using namespace std;

const int maxN = 2e3+10;
const int inc = maxN /2;
int BIT[maxN + 1][maxN + 1];

void update(int x1,int y1,int x2,int y2){
    if(x1 <= 0) x1 = 1;
    if(y1 <= 0) y1 = 1;
    if(x2 >= maxN) x2 = maxN - 1;
    if(y2 >= maxN) y2 = maxN - 1;
    BIT[x2 + 1][y2 + 1] += 1;
    BIT[x1][y1] += 1;
    BIT[x1][y2 + 1] -= 1;
    BIT[x2 + 1][y1] -= 1;
}
int main() {
    ios_base::sync_with_stdio(false);
    int n,m,k;
    vector<pair<int,int> > lions;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++){
        int x,y, d;
        cin >> x >> y >> d;
        int newX = (x + y);
        int newY = (y  - x + inc);
        update(newX - d, newY - d, newX + d, newY + d);
        lions.emplace_back(newX,newY);
    }
    for(int i = 1; i < maxN; i++)
    for(int j = 1; j < maxN; j++){
        BIT[i][j] += BIT[i - 1][j] + BIT[i][j - 1] - BIT[i-1][j - 1];
    }
    int ans = 0;
    int Max = 0;
    for(int i =0 ; i < k; i++){
        int X = lions[i].first;
        int Y = lions[i].second;
        int cal = BIT[X][Y] - 1;
        if(cal > Max){
            Max = cal;
            ans = i + 1;
        }
    }
    cout << ans <<" "<<Max;
}

