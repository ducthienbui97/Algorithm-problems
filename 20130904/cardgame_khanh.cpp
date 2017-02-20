#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int f[N+1][N+1];

int dp(int c, int r, int b) {
    for(int i = 0; i <= r; ++i)
    for(int j = 0; j <= b; ++j)
        if(i == 0 && j == 0) f[i][j] = c;
        else if(i == 0) f[i][j] = (f[i][j-1] + 1) / 2;
        else if(j == 0) f[i][j] = (f[i-1][j] + 1) / 2;
        else f[i][j] = (f[i][j-1] + f[i-1][j] + 1) / 2;
    return f[r][b];
}

int main() {
    for(int r, b, c; cin >> r >> b >> c; ) {
        int l = 0, h = 30720;
        while(l < h) {
            int mid = (l + h + 1) / 2;
            if(dp(mid, r, b) <= c) l = mid;
            else h = mid-1;
        }
        cout << l << endl;
    }
    return 0;
}
